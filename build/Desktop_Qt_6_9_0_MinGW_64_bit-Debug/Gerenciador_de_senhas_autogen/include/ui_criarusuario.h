/********************************************************************************
** Form generated from reading UI file 'criarusuario.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRIARUSUARIO_H
#define UI_CRIARUSUARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CriarUsuario
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *NomeUsuario;
    QLabel *label_2;
    QLineEdit *Senha1;
    QLabel *label_3;
    QLineEdit *Senha2;
    QPushButton *BotaoVoltar;
    QPushButton *BotaoCriarUsuario;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *CriarUsuario)
    {
        if (CriarUsuario->objectName().isEmpty())
            CriarUsuario->setObjectName("CriarUsuario");
        CriarUsuario->resize(249, 148);
        formLayout = new QFormLayout(CriarUsuario);
        formLayout->setObjectName("formLayout");
        label = new QLabel(CriarUsuario);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        NomeUsuario = new QLineEdit(CriarUsuario);
        NomeUsuario->setObjectName("NomeUsuario");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, NomeUsuario);

        label_2 = new QLabel(CriarUsuario);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        Senha1 = new QLineEdit(CriarUsuario);
        Senha1->setObjectName("Senha1");
        Senha1->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, Senha1);

        label_3 = new QLabel(CriarUsuario);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        Senha2 = new QLineEdit(CriarUsuario);
        Senha2->setObjectName("Senha2");
        Senha2->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, Senha2);

        BotaoVoltar = new QPushButton(CriarUsuario);
        BotaoVoltar->setObjectName("BotaoVoltar");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, BotaoVoltar);

        BotaoCriarUsuario = new QPushButton(CriarUsuario);
        BotaoCriarUsuario->setObjectName("BotaoCriarUsuario");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, BotaoCriarUsuario);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        formLayout->setItem(3, QFormLayout::ItemRole::LabelRole, verticalSpacer);


        retranslateUi(CriarUsuario);
        QObject::connect(BotaoVoltar, &QPushButton::clicked, CriarUsuario, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(CriarUsuario);
    } // setupUi

    void retranslateUi(QDialog *CriarUsuario)
    {
        CriarUsuario->setWindowTitle(QCoreApplication::translate("CriarUsuario", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CriarUsuario", "Nome de usu\303\241rio:", nullptr));
        label_2->setText(QCoreApplication::translate("CriarUsuario", "Senha principal:", nullptr));
        label_3->setText(QCoreApplication::translate("CriarUsuario", "Confirma senha:", nullptr));
        BotaoVoltar->setText(QCoreApplication::translate("CriarUsuario", "Voltar", nullptr));
        BotaoCriarUsuario->setText(QCoreApplication::translate("CriarUsuario", "Criar usu\303\241rio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CriarUsuario: public Ui_CriarUsuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRIARUSUARIO_H
