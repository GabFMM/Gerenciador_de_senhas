#include "criarusuario.h"
#include "ui_criarusuario.h"

CriarUsuario::CriarUsuario(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CriarUsuario)
{
    ui->setupUi(this);
}

CriarUsuario::~CriarUsuario()
{
    delete ui;
}


void CriarUsuario::on_BotaoCriarUsuario_clicked()
{
    // Verifico os campos
    if(ui->NomeUsuario->text().isEmpty()){
        QMessageBox::warning(this, "Erro", "Campo nome de usuário não preenchido");
        return;
    }
    if(ui->Senha1->text().isEmpty()){
        QMessageBox::warning(this, "Erro", "Campo senha principal não preenchido");
        return;
    }
    if(ui->Senha2->text().isEmpty()){
        QMessageBox::warning(this, "Erro", "Campo confima senha não preenchido");
        return;
    }
    if(ui->Senha1->text() != ui->Senha2->text()){
        QMessageBox::warning(this, "Erro", "Campo senha principal e confirma senha não são iguais");
        return;
    }

    ConexaoBD* conexao = ConexaoBD::getInstancia();
    if(conexao->verificarUsuario(ui->NomeUsuario->text())){
        QMessageBox::warning(this, "Erro", "Nome de usuário já existe");
        return;
    }

    // Crio no BD
    if(!conexao->criarUsuario(ui->NomeUsuario->text(), ui->Senha1->text())){
        QMessageBox::warning(this, "Erro", "Não foi possível criar novo usuário");
    }
    else{
        QMessageBox::information(this, "Sucesso", "Usuário criado com sucesso");
        close();
    }
}

