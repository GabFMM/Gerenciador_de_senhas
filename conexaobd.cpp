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
        delete instancia;
        instancia = nullptr;
    }
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
    return !crypto_pwhash_str_verify(hash, senha.toUtf8().constData(), senha.size());
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
    else
        qDebug() << "Banco aberto com sucesso";
}
