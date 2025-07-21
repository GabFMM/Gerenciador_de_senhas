#include "fazerlogin.h"
#include "ui_fazerlogin.h"

FazerLogin::FazerLogin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FazerLogin)
{
    ui->setupUi(this);
}

FazerLogin::~FazerLogin()
{
    delete ui;
}

const bool FazerLogin::verificarSenha()
{
    ConexaoBD* conexao = ConexaoBD::getInstancia();

    return conexao->verificarSenha(ui->NomeUsuario->text(), ui->Senha->text());
}

const bool FazerLogin::verificarUsuario()
{
    ConexaoBD* conexao = ConexaoBD::getInstancia();

    return conexao->verificarUsuario(ui->NomeUsuario->text());
}

void FazerLogin::entrarMenu()
{
    hide();

    Menu menu(this, ui->NomeUsuario->text());
    menu.exec();

    show();
}

// por enquanto, limpa somente o campo senha
void FazerLogin::limparCampos()
{
    ui->Senha->clear();
    ui->Senha->setFocus();
}

void FazerLogin::on_BotaoEntrar_clicked()
{
    if(!verificarUsuario()){
        QMessageBox::warning(this, "Erro", "Nome de usuário inexistente ou inválido");
        limparCampos();
    }
    else if(!verificarSenha()){
        QMessageBox::warning(this, "Erro", "Senha incorreta ou inválida");
        limparCampos();
    }
    else{
        limparCampos();
        entrarMenu();
    }
}


void FazerLogin::on_MostrarSenha_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
        ui->Senha->setEchoMode(QLineEdit::Normal);
    else if(arg1 == Qt::Unchecked)
        ui->Senha->setEchoMode(QLineEdit::Password);
}

void FazerLogin::on_BotaoCriarUsuario_clicked()
{
    CriarUsuario criarUsuario(this);

    hide();
    criarUsuario.exec();
    show();
}

