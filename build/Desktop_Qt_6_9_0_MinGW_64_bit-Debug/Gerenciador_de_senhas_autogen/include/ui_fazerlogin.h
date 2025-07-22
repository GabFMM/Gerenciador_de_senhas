/********************************************************************************
** Form generated from reading UI file 'fazerlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAZERLOGIN_H
#define UI_FAZERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FazerLogin
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *NomeUsuario;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *Senha;
    QCheckBox *MostrarSenha;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *BotaoEntrar;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *BotaoCriarUsuario;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QMainWindow *FazerLogin)
    {
        if (FazerLogin->objectName().isEmpty())
            FazerLogin->setObjectName("FazerLogin");
        FazerLogin->resize(237, 242);
        centralwidget = new QWidget(FazerLogin);
        centralwidget->setObjectName("centralwidget");
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName("formLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        NomeUsuario = new QLineEdit(centralwidget);
        NomeUsuario->setObjectName("NomeUsuario");

        horizontalLayout_2->addWidget(NomeUsuario);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        Senha = new QLineEdit(centralwidget);
        Senha->setObjectName("Senha");
        Senha->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout->addWidget(Senha);


        verticalLayout->addLayout(horizontalLayout);

        MostrarSenha = new QCheckBox(centralwidget);
        MostrarSenha->setObjectName("MostrarSenha");

        verticalLayout->addWidget(MostrarSenha);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        BotaoEntrar = new QPushButton(centralwidget);
        BotaoEntrar->setObjectName("BotaoEntrar");

        horizontalLayout_3->addWidget(BotaoEntrar);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_3 = new QSpacerItem(60, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        BotaoCriarUsuario = new QPushButton(centralwidget);
        BotaoCriarUsuario->setObjectName("BotaoCriarUsuario");

        horizontalLayout_6->addWidget(BotaoCriarUsuario);

        horizontalSpacer_4 = new QSpacerItem(60, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_6);


        formLayout->setLayout(0, QFormLayout::ItemRole::SpanningRole, verticalLayout);

        FazerLogin->setCentralWidget(centralwidget);

        retranslateUi(FazerLogin);

        QMetaObject::connectSlotsByName(FazerLogin);
    } // setupUi

    void retranslateUi(QMainWindow *FazerLogin)
    {
        FazerLogin->setWindowTitle(QCoreApplication::translate("FazerLogin", "FazerLogin", nullptr));
        label_2->setText(QCoreApplication::translate("FazerLogin", "Gerenciador de Senhas", nullptr));
        label_3->setText(QCoreApplication::translate("FazerLogin", "Nome de usu\303\241rio:", nullptr));
        label->setText(QCoreApplication::translate("FazerLogin", "Senha:                  ", nullptr));
        MostrarSenha->setText(QCoreApplication::translate("FazerLogin", "Mostrar senha", nullptr));
        BotaoEntrar->setText(QCoreApplication::translate("FazerLogin", "Entrar", nullptr));
        BotaoCriarUsuario->setText(QCoreApplication::translate("FazerLogin", "Criar novo usu\303\241rio", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FazerLogin: public Ui_FazerLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAZERLOGIN_H
