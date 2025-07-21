#ifndef CONEXAOBD_H
#define CONEXAOBD_H

// Projeto
#include "conta.h"

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
    const bool removerConta(QString usuario, QString titulo);
    const bool editarConta(QString usuario, QString tituloOriginal, QString tituloEditado, QString senha, QString descricao, QString tag);
    const bool excluirUsuario(QString usuario);

    // Tag
    std::vector<QString> getTags(QString usuario);
    QString getTag(QString usuario, QString titulo);
    const bool adicionarTag(QString usuario, QString tag);
    const bool removerTag(QString usuario, QString tag);
    // --

    // Titulo
    std::vector<QString> getTituloContas(QString usuario);
    std::vector<QString> getTituloContas(QString usuario, QString tag);
    // --

    // Descricao
    QString getDescricao(QString usuario, QString titulo);
    // --

    // Senha
    QString getSenhaConta(QString usuario, QString titulo);
    QString descriptografar(QByteArray senhaArray, QByteArray nonceArray);
    // --

    // Conta
    std::vector<Conta> getContas(QString usuario);
    std::vector<Conta> getContas(QString usuario, QString tag);
    // --
};

#endif // CONEXAOBD_H
