#ifndef FAZERLOGIN_H
#define FAZERLOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include "conexaobd.h"
#include "menu.h"
#include "criarusuario.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class FazerLogin;
}
QT_END_NAMESPACE

class FazerLogin : public QMainWindow
{
    Q_OBJECT

public:
    FazerLogin(QWidget *parent = nullptr);
    ~FazerLogin();

    const bool verificarSenha();
    const bool verificarUsuario();
    void entrarMenu();

    void limparCampos();

private slots:
    void on_BotaoEntrar_clicked();

    void on_MostrarSenha_stateChanged(int arg1);

    void on_BotaoCriarUsuario_clicked();

private:
    Ui::FazerLogin *ui;

};
#endif // FAZERLOGIN_H
