#include "conexaobd.h"

ConexaoBD* ConexaoBD::instancia = nullptr;

ConexaoBD *ConexaoBD::getInstancia()
{
    if(instancia == nullptr){
        instancia = new ConexaoBD();
        instancia->setBD();
    }
    return instancia;
}

void ConexaoBD::destruirInstancia()
{
    if(instancia != nullptr){
        // Apaga a chave
        //clearKey();

        delete instancia;
        instancia = nullptr;
    }
}

void ConexaoBD::setKey(QString usuario, QString senha)
{
    QSqlQuery query(BD);

    // Procuro o salt a partir do nome de usuario
    // Sem risco do nome nao existir
    query.prepare
    (R"(
        SELECT Salt FROM Usuarios
        WHERE Nome = ?
    )");

    query.addBindValue(usuario);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em setKey de ConexaoBD: " << query.lastError().text();
        return;
    }

    query.next();

    // Recupero a chave
    size_t key_len = 32;
    unsigned long long opslimit = crypto_pwhash_OPSLIMIT_INTERACTIVE;
    size_t memlimit = crypto_pwhash_MEMLIMIT_INTERACTIVE;
    int alg = crypto_pwhash_ALG_DEFAULT;

    key.resize(key_len);

    QByteArray password = senha.toUtf8();
    QByteArray saltArray = query.value(0).toByteArray();
    const unsigned char* salt = reinterpret_cast<const unsigned char*>(saltArray.constData());

    if (crypto_pwhash(
            key.data(), key.size(),
            password.constData(),
            password.size(),
            salt,
            opslimit,
            memlimit,
            alg
            ) != 0) {
        qDebug() << "Erro ao derivar a chave com crypto_pwhash.";
        return;
    }
}

void ConexaoBD::clearKey()
{
    sodium_memzero(key.data(), key.size());
}

const bool ConexaoBD::verificarSenha(QString usuario, QString senha)
{
    QSqlQuery query(BD);

    // Procuro a senha a partir do nome de usuario
    // Sem risco do nome nao existir
    query.prepare
    (R"(
        SELECT Senha FROM Usuarios
        WHERE Nome = ?
    )");

    query.addBindValue(usuario);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em verificarSenha de ConexaoBD: " << query.lastError().text();
        return false;
    }

    query.next();

    // Comparo a tentativa de senha com o hash guardado
    QString hashStr = query.value(0).toString();
    const char* hash = hashStr.toUtf8().constData();

    // inverto, pois a função abaixo tem retorno 0 para sucesso
    if(!crypto_pwhash_str_verify(hash, senha.toUtf8().constData(), senha.size())){
        // Caso outro usuario faça login em seguida, sem fechar o programa
        clearKey();

        // Recupero a chave do usuario atual
        setKey(usuario, senha);
        return true;
    }
    else{
        return false;
    }
}

const bool ConexaoBD::verificarUsuario(QString usuario)
{
    QSqlQuery query(BD);

    query.prepare
    (R"(
        SELECT Nome FROM Usuarios
        WHERE Nome = ?
    )");

    query.addBindValue(usuario);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em verificarUsuario de ConexaoBD: " << query.lastError().text();
        return false;
    }

    // retorna true se encontrar o nome de usuario
    return query.next();
}

const bool ConexaoBD::existeTituloConta(QString usuario, QString titulo)
{
    QSqlQuery query(BD);

    query.prepare
    (R"(
        SELECT Titulo FROM Contas
        WHERE Usuario = ? AND Titulo = ?
    )");

    query.addBindValue(usuario);
    query.addBindValue(titulo);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em existeTituloConta de ConexaoBD: " << query.lastError().text();
        return false;
    }

    // retorna true se encontrar o titulo
    return query.next();
}

const bool ConexaoBD::adicionarConta(QString usuario, QString titulo, QString senha, QString descricao, QString tag)
{
    // Gero um nonce
    unsigned char nonce[crypto_secretbox_NONCEBYTES];
    randombytes_buf(nonce, sizeof(nonce));

    // Criptografo a senha
    size_t cipher_len = crypto_secretbox_MACBYTES + senha.size();
    unsigned char ciphertext[cipher_len];

    QByteArray plainTextArray = senha.toUtf8();

    if (crypto_secretbox_easy(
            ciphertext,
            reinterpret_cast<const unsigned char*>(plainTextArray.constData()),
            plainTextArray.size(),
            nonce,
            key.data()) != 0) {
        qDebug() << "Erro na criptografia da senha.";
        return false;
    }

    // converto o nonce para o tipo aceito no BD (BLOB)
    QByteArray nonceArray(reinterpret_cast<const char*>(nonce), crypto_secretbox_NONCEBYTES);

    // converto o ciphertext para o tipo aceito no BD (BLOB)
    QByteArray cipherTextArray(reinterpret_cast<const char*>(ciphertext), cipher_len);

    // Salvo no BD
    QSqlQuery query(BD);

    query.prepare
    (R"(
        INSERT INTO Contas (Usuario, Titulo, Senha, Nonce, Descricao, Tag)
        VALUES (?, ?, ?, ?, ?, ?);
    )");

    query.addBindValue(usuario);
    query.addBindValue(titulo);
    query.addBindValue(cipherTextArray);
    query.addBindValue(nonceArray);
    query.addBindValue(descricao);
    query.addBindValue(tag);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em adicionarConta de ConexaoBD: " << query.lastError().text();
        return false;
    }

    return true;
}

const bool ConexaoBD::removerConta(QString usuario, QString titulo)
{
    QSqlQuery query(BD);

    query.prepare
    (R"(
        DELETE FROM Contas
        WHERE Usuario = ? AND Titulo = ?
    )");

    query.addBindValue(usuario);
    query.addBindValue(titulo);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em removerConta de ConexaoBD: " << query.lastError().text();
        return false;
    }

    return true;
}

const bool ConexaoBD::editarConta(QString usuario, QString tituloOriginal, QString tituloEditado, QString senha, QString descricao, QString tag)
{
    // Gero um nonce
    unsigned char nonce[crypto_secretbox_NONCEBYTES];
    randombytes_buf(nonce, sizeof(nonce));

    // Criptografo a senha
    size_t cipher_len = crypto_secretbox_MACBYTES + senha.size();
    unsigned char ciphertext[cipher_len];

    QByteArray plainTextArray = senha.toUtf8();

    if (crypto_secretbox_easy(
            ciphertext,
            reinterpret_cast<const unsigned char*>(plainTextArray.constData()),
            plainTextArray.size(),
            nonce,
            key.data()) != 0) {
        qDebug() << "Erro na criptografia da senha.";
        return false;
    }

    // converto o nonce para o tipo aceito no BD (BLOB)
    QByteArray nonceArray(reinterpret_cast<const char*>(nonce), crypto_secretbox_NONCEBYTES);

    // converto o ciphertext para o tipo aceito no BD (BLOB)
    QByteArray cipherTextArray(reinterpret_cast<const char*>(ciphertext), cipher_len);

    // Salvo no BD
    QSqlQuery query(BD);

    query.prepare
    (R"(
        UPDATE Contas
        SET Titulo=?, Senha=?, Nonce=?, Descricao=?, Tag=?
        WHERE Usuario=? AND Titulo=?
    )");

    query.addBindValue(tituloEditado);
    query.addBindValue(cipherTextArray);
    query.addBindValue(nonceArray);
    query.addBindValue(descricao);
    query.addBindValue(tag);
    query.addBindValue(usuario);
    query.addBindValue(tituloOriginal);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em editarConta de ConexaoBD: " << query.lastError().text();
        return false;
    }

    return true;
}

std::vector<QString> ConexaoBD::getTags(QString usuario)
{
    QSqlQuery query(BD);

    query.prepare
    (R"(
        SELECT Nome FROM Tags
        WHERE Usuario = ?
    )");

    query.addBindValue(usuario);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em getTags de ConexaoBD: " << query.lastError().text();
        std::vector<QString> erro;
        erro.clear();
        return erro;
    }

    std::vector<QString> tags;

    while(query.next())
        tags.push_back(query.value(0).toString());

    return tags;
}

QString ConexaoBD::getTag(QString usuario, QString titulo)
{
    QSqlQuery query(BD);

    query.prepare
    (R"(
        SELECT Tag FROM Contas
        WHERE Usuario = ? AND Titulo = ?
    )");

    query.addBindValue(usuario);
    query.addBindValue(titulo);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em getTag de ConexaoBD: " << query.lastError().text();
        QString erro = " ";
        return erro;
    }

    query.next();

    return query.value(0).toString();
}

std::vector<QString> ConexaoBD::getTituloContas(QString usuario)
{
    QSqlQuery query(BD);

    query.prepare
    (R"(
        SELECT Titulo FROM Contas
        WHERE Usuario = ?
    )");

    query.addBindValue(usuario);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em getTituloContas de ConexaoBD: " << query.lastError().text();
        std::vector<QString> erro;
        erro.clear();
        return erro;
    }

    std::vector<QString> titulos;

    while(query.next())
        titulos.push_back(query.value(0).toString());

    return titulos;
}

std::vector<QString> ConexaoBD::getTituloContas(QString usuario, QString tag)
{
    QSqlQuery query(BD);

    query.prepare
    (R"(
        SELECT Titulo FROM Contas
        WHERE Usuario = ? AND Tag = ?
    )");

    query.addBindValue(usuario);
    query.addBindValue(tag);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em getTituloContas de ConexaoBD: " << query.lastError().text();
        std::vector<QString> erro;
        erro.clear();
        return erro;
    }

    std::vector<QString> titulos;

    while(query.next())
        titulos.push_back(query.value(0).toString());

    return titulos;
}

QString ConexaoBD::getDescricao(QString usuario, QString titulo)
{
    QSqlQuery query(BD);

    query.prepare
    (R"(
        SELECT Descricao FROM Contas
        WHERE Usuario = ? AND Titulo = ?
    )");

    query.addBindValue(usuario);
    query.addBindValue(titulo);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em getDescricao de ConexaoBD: " << query.lastError().text();
        QString erro = " ";
        return erro;
    }

    query.next();

    return query.value(0).toString();
}

QString ConexaoBD::getSenhaConta(QString usuario, QString titulo)
{
    QSqlQuery query(BD);

    query.prepare
    (R"(
        SELECT Senha, Nonce FROM Contas
        WHERE Usuario = ? AND Titulo = ?
    )");

    query.addBindValue(usuario);
    query.addBindValue(titulo);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em getDescricao de ConexaoBD: " << query.lastError().text();
        QString erro = " ";
        return erro;
    }

    query.next();

    // Recupero dados do BD
    QByteArray cipherTextArray = query.value(0).toByteArray();
    QByteArray nonceArray = query.value(1).toByteArray();

    return descriptografar(cipherTextArray, nonceArray);
}

QString ConexaoBD::descriptografar(QByteArray senhaArray, QByteArray nonceArray)
{
    // Dados para descriptografia
    const unsigned char* ciphertext = reinterpret_cast<const unsigned char*>(senhaArray.constData());
    unsigned long long ciphertext_len = senhaArray.size();

    const unsigned char* nonce = reinterpret_cast<const unsigned char*>(nonceArray.constData());

    // O plaintext terá no máximo (ciphertext_len - MACBYTES) bytes
    size_t plaintext_len = ciphertext_len - crypto_secretbox_MACBYTES;
    QByteArray plainTextArray;
    plainTextArray.resize(static_cast<int>(plaintext_len));

    if (crypto_secretbox_open_easy(
            reinterpret_cast<unsigned char*>(plainTextArray.data()),
            ciphertext,
            ciphertext_len,
            nonce,
            key.data()) != 0)
    {
        qDebug() << "Erro na descriptografia da senha.";
        return QString(" ");
    }

    // Converto o QByteArray de volta para QString
    return (QString::fromUtf8(plainTextArray));
}

std::vector<Conta> ConexaoBD::getContas(QString usuario)
{
    QSqlQuery query(BD);

    query.prepare
    (R"(
        SELECT Titulo, Senha, Nonce, Descricao, Tag FROM Contas
        WHERE Usuario = ?
    )");

    query.addBindValue(usuario);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em getContas de ConexaoBD: " << query.lastError().text();
        std::vector<Conta> erro;
        erro.clear();
        return erro;
    }

    std::vector<Conta> contas;
    while(query.next()){
        Conta conta(
            query.value(0).toString(),
            descriptografar(query.value(1).toByteArray(), query.value(2).toByteArray()),
            query.value(3).toString(),
            query.value(4).toString()
        );

        contas.push_back(conta);
    }

    return contas;
}

std::vector<Conta> ConexaoBD::getContas(QString usuario, QString tag)
{
    QSqlQuery query(BD);

    query.prepare
    (R"(
        SELECT Titulo, Senha, Nonce, Descricao, Tag FROM Contas
        WHERE Usuario = ? AND Tag = ?
    )");

    query.addBindValue(usuario);
    query.addBindValue(tag);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em getContas de ConexaoBD: " << query.lastError().text();
        std::vector<Conta> erro;
        erro.clear();
        return erro;
    }

    std::vector<Conta> contas;
    while(query.next()){
        Conta conta(
            query.value(0).toString(),
            descriptografar(query.value(1).toByteArray(), query.value(2).toByteArray()),
            query.value(3).toString(),
            query.value(4).toString()
        );

        contas.push_back(conta);
    }

    return contas;
}

const bool ConexaoBD::adicionarTag(QString usuario, QString tag)
{
    QSqlQuery query(BD);

    query.prepare
    (R"(
        INSERT INTO Tags (nome, usuario)
        VALUES (?, ?);
    )");

    query.addBindValue(tag);
    query.addBindValue(usuario);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em adicionarTag de ConexaoBD: " << query.lastError().text();
        return false;
    }

    return true;
}

const bool ConexaoBD::removerTag(QString usuario, QString tag)
{
    QSqlQuery query(BD);

    query.prepare
    (R"(
        DELETE FROM Tags
        WHERE Usuario = ? AND Nome = ?
    )");

    query.addBindValue(usuario);
    query.addBindValue(tag);

    if(!query.exec())
    {
        qDebug() << "Erro na execução da query em removerTag de ConexaoBD: " << query.lastError().text();
        return false;
    }

    return true;
}

void ConexaoBD::setBD()
{
    BD = QSqlDatabase::addDatabase("QSQLITE");
    BD.setDatabaseName("../../GerenciadorDB.db");

    if (!BD.open())
        qDebug() << "Erro ao abrir banco:" << BD.lastError().text();
}
