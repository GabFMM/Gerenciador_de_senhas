#ifndef CONEXAOBD_H
#define CONEXAOBD_H

// Qt
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

// libsodium
#include <sodium.h>

// outros
#include <vector>
#include <string>

class ConexaoBD
{
private:

    static ConexaoBD* instancia;
    ConexaoBD() = default;
    ~ConexaoBD() = default;

    ConexaoBD(const ConexaoBD&) = delete;
    ConexaoBD& operator=(const ConexaoBD&) = delete;

    QSqlDatabase BD;

    // key do usuario. NUNCA salvar em heap. SEMPRE limpar da memória
    std::vector<unsigned char> key;

public:
    void setBD();

    static ConexaoBD* getInstancia();
    static void destruirInstancia();

    void setKey(QString usuario, QString senha);
    void clearKey();

    const bool verificarSenha(QString usuario, QString senha);
    const bool verificarUsuario(QString usuario);
    const bool existeTituloConta(QString usuario, QString titulo);
    const bool adicionarConta(QString usuario, QString titulo, QString senha, QString descricao = "", QString tag = "");
    std::vector<QString> getTags(QString usuario);
    const bool adicionarTag(QString usuario, QString tag);
    const bool removerTag(QString usuario, QString tag);
};

#endif // CONEXAOBD_H
