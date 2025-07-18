#ifndef CONTA_H
#define CONTA_H

#include <QString>

class Conta
{
private:
    QString _titulo;
    QString _senha;
    QString _descricao;
    QString _tag;

public:
    Conta(QString titulo, QString senha, QString descricao, QString tag);
    ~Conta();

    QString getTitulo() const;
    QString getSenha() const;
    QString getDescricao() const;
    QString getTag() const;
};

#endif // CONTA_H
