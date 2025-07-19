#ifndef CONTAWIDGET_H
#define CONTAWIDGET_H

#include "conta.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>

class ContaWidget : public QWidget
{
    Q_OBJECT

private:
    Conta _conta;

    QVBoxLayout* _layout;
    QLabel* _titulo;
    QLabel* _senha;
    QCheckBox* _opcaoVerSenha;

protected:
    void configuraLabels();
    void configuraCheckBox();

public:
    explicit ContaWidget(Conta conta, QWidget* parent = nullptr);
    ~ContaWidget();
};

#endif // CONTAWIDGET_H
