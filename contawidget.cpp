#include "contawidget.h"

ContaWidget::ContaWidget(Conta conta, QWidget* parent) :
    QWidget(parent),
    _conta(conta)
{
    _layout = new QVBoxLayout(this);
    _titulo = new QLabel(this);
    _senha = new QLabel(this);
    _opcaoVerSenha = new QCheckBox(this);

    connect(_opcaoVerSenha, &QCheckBox::checkStateChanged, this, [=](Qt::CheckState estado){
        if(estado == Qt::Checked)
            _senha->setText("Senha: " + _conta.getSenha());
        else if(estado == Qt::Unchecked)
            _senha->setText("Senha: ******");
    });

    configuraLabels();
    configuraCheckBox();

    setLayout(_layout);
    setStyleSheet("QWidget { border: 1px solid gray; padding: 8px; border-radius: 8px; }");
}

ContaWidget::~ContaWidget()
{
    if(_layout != nullptr){
        delete _layout;
        _layout = nullptr;
    }

    if(_titulo != nullptr){
        delete _titulo;
        _titulo = nullptr;
    }

    if(_senha != nullptr){
        delete _senha;
        _senha = nullptr;
    }

    if(_opcaoVerSenha != nullptr){
        delete _opcaoVerSenha;
        _opcaoVerSenha = nullptr;
    }
}

void ContaWidget::configuraLabels()
{
    _titulo->setText(_conta.getTitulo());
    _senha->setText("Senha: ********");

    _layout->addWidget(_titulo);
    _layout->addWidget(_senha);
}

void ContaWidget::configuraCheckBox()
{
    _opcaoVerSenha->setText("Ver senha");

    _layout->addWidget(_opcaoVerSenha);
}
