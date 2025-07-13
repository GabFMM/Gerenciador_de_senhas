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

class ConexaoBD
{
private:

    static ConexaoBD* instancia;
    ConexaoBD() = default;
    ~ConexaoBD() = default;

    ConexaoBD(const ConexaoBD&) = delete;
    ConexaoBD& operator=(const ConexaoBD&) = delete;

    QSqlDatabase BD;

public:
    void setBD();

    static ConexaoBD* getInstancia();
    static void destruirInstancia();

    const bool verificarSenha(QString usuario, QString senha);
    const bool verificarUsuario(QString usuario);
    std::vector<QString> getTags(QString usuario);
    const bool adicionarTag(QString usuario, QString tag);
    const bool removerTag(QString usuario, QString tag);
};

#endif // CONEXAOBD_H
