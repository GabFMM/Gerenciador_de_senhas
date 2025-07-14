#include "fazerlogin.h"

// Qt
#include <QApplication>
#include <QSqlDatabase>

// libsodium
#include <sodium.h>
#include <string>

// Projeto
#include "conexaobd.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FazerLogin w;
    w.show();

    const bool saida = a.exec();

    ConexaoBD* conexao = ConexaoBD::getInstancia();
    conexao->destruirInstancia();

    return saida;
}
