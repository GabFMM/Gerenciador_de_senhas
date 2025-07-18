#include "conta.h"

Conta::Conta(QString titulo, QString senha, QString descricao, QString tag) :
    _titulo(titulo),
    _senha(senha),
    _descricao(descricao),
    _tag(tag)
{

}

Conta::~Conta()
{
    _titulo.clear();
    _senha.clear();
    _descricao.clear();
}

QString Conta::getTitulo() const
{
    return _titulo;
}

QString Conta::getSenha() const
{
    return _senha;
}

QString Conta::getDescricao() const
{
    return _descricao;
}

QString Conta::getTag() const
{
    return _tag;
}
