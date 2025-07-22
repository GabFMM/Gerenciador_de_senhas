/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QStackedWidget *stackedWidget;
    QWidget *Padrao;
    QWidget *MostrarContas;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *SelecTagMC;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QWidget *WidgetContainer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QWidget *AdicionarConta;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *SenhaAC;
    QLabel *label_3;
    QTextEdit *DescricaoAC;
    QLabel *label_4;
    QComboBox *TagAC;
    QPushButton *BotaoConfirmarAC;
    QLabel *label_5;
    QLineEdit *TituloAC;
    QWidget *EditarConta;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QLineEdit *TituloEC;
    QLabel *label_7;
    QLineEdit *SenhaEC;
    QLabel *label_8;
    QTextEdit *DescricaoEC;
    QLabel *label_9;
    QPushButton *BotaoConfirmaEC;
    QComboBox *SelecTituloEC;
    QComboBox *SelecTagEC;
    QComboBox *TagEC;
    QWidget *RemoverConta;
    QFormLayout *formLayout_3;
    QComboBox *SelecTagRC;
    QLabel *label_11;
    QLineEdit *TituloRC;
    QLabel *label_12;
    QLineEdit *SenhaRC;
    QLabel *label_10;
    QTextEdit *DescricaoRC;
    QLabel *label_13;
    QPushButton *BotaoConfirmaRC;
    QComboBox *SelecTituloRC;
    QLineEdit *TagRC;
    QWidget *SenhaAleatoria;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_14;
    QSpinBox *spinBox;
    QToolButton *toolButton_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBoxabc;
    QCheckBox *checkBoxABC;
    QCheckBox *checkBox123;
    QCheckBox *checkBoxExtras;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_15;
    QLineEdit *SenhaGerada;
    QToolButton *toolButton;
    QWidget *AdicionarTag;
    QFormLayout *formLayout_4;
    QLabel *label_17;
    QComboBox *TagsExistentes;
    QLabel *label_16;
    QLineEdit *NomeTagNova;
    QPushButton *BotaoConfirmarAT;
    QWidget *RemoverTag;
    QVBoxLayout *verticalLayout_4;
    QComboBox *SelecTagRT;
    QPushButton *BotaoConfirmaRT;
    QWidget *ExcluirUsuario;
    QGridLayout *gridLayout_2;
    QPushButton *BotaoExcluirUsuario;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_18;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *BotaoSair;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *tempo;

    void setupUi(QDialog *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName("Menu");
        Menu->resize(376, 305);
        verticalLayout = new QVBoxLayout(Menu);
        verticalLayout->setObjectName("verticalLayout");
        comboBox = new QComboBox(Menu);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        verticalLayout->addWidget(comboBox);

        stackedWidget = new QStackedWidget(Menu);
        stackedWidget->setObjectName("stackedWidget");
        Padrao = new QWidget();
        Padrao->setObjectName("Padrao");
        stackedWidget->addWidget(Padrao);
        MostrarContas = new QWidget();
        MostrarContas->setObjectName("MostrarContas");
        verticalLayout_3 = new QVBoxLayout(MostrarContas);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        SelecTagMC = new QComboBox(MostrarContas);
        SelecTagMC->addItem(QString());
        SelecTagMC->addItem(QString());
        SelecTagMC->setObjectName("SelecTagMC");

        horizontalLayout_7->addWidget(SelecTagMC);


        verticalLayout_3->addLayout(horizontalLayout_7);

        scrollArea = new QScrollArea(MostrarContas);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 110, 32));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName("gridLayout");
        WidgetContainer = new QWidget(scrollAreaWidgetContents);
        WidgetContainer->setObjectName("WidgetContainer");

        gridLayout->addWidget(WidgetContainer, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        stackedWidget->addWidget(MostrarContas);
        AdicionarConta = new QWidget();
        AdicionarConta->setObjectName("AdicionarConta");
        formLayout = new QFormLayout(AdicionarConta);
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(AdicionarConta);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        SenhaAC = new QLineEdit(AdicionarConta);
        SenhaAC->setObjectName("SenhaAC");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, SenhaAC);

        label_3 = new QLabel(AdicionarConta);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        DescricaoAC = new QTextEdit(AdicionarConta);
        DescricaoAC->setObjectName("DescricaoAC");
        DescricaoAC->setMaximumSize(QSize(122, 91));
        DescricaoAC->setOverwriteMode(false);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, DescricaoAC);

        label_4 = new QLabel(AdicionarConta);
        label_4->setObjectName("label_4");
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        TagAC = new QComboBox(AdicionarConta);
        TagAC->addItem(QString());
        TagAC->setObjectName("TagAC");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TagAC->sizePolicy().hasHeightForWidth());
        TagAC->setSizePolicy(sizePolicy1);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, TagAC);

        BotaoConfirmarAC = new QPushButton(AdicionarConta);
        BotaoConfirmarAC->setObjectName("BotaoConfirmarAC");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(BotaoConfirmarAC->sizePolicy().hasHeightForWidth());
        BotaoConfirmarAC->setSizePolicy(sizePolicy2);

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, BotaoConfirmarAC);

        label_5 = new QLabel(AdicionarConta);
        label_5->setObjectName("label_5");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_5);

        TituloAC = new QLineEdit(AdicionarConta);
        TituloAC->setObjectName("TituloAC");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, TituloAC);

        stackedWidget->addWidget(AdicionarConta);
        EditarConta = new QWidget();
        EditarConta->setObjectName("EditarConta");
        formLayout_2 = new QFormLayout(EditarConta);
        formLayout_2->setObjectName("formLayout_2");
        label_6 = new QLabel(EditarConta);
        label_6->setObjectName("label_6");

        formLayout_2->setWidget(2, QFormLayout::ItemRole::LabelRole, label_6);

        TituloEC = new QLineEdit(EditarConta);
        TituloEC->setObjectName("TituloEC");

        formLayout_2->setWidget(2, QFormLayout::ItemRole::FieldRole, TituloEC);

        label_7 = new QLabel(EditarConta);
        label_7->setObjectName("label_7");

        formLayout_2->setWidget(3, QFormLayout::ItemRole::LabelRole, label_7);

        SenhaEC = new QLineEdit(EditarConta);
        SenhaEC->setObjectName("SenhaEC");

        formLayout_2->setWidget(3, QFormLayout::ItemRole::FieldRole, SenhaEC);

        label_8 = new QLabel(EditarConta);
        label_8->setObjectName("label_8");

        formLayout_2->setWidget(4, QFormLayout::ItemRole::LabelRole, label_8);

        DescricaoEC = new QTextEdit(EditarConta);
        DescricaoEC->setObjectName("DescricaoEC");

        formLayout_2->setWidget(4, QFormLayout::ItemRole::FieldRole, DescricaoEC);

        label_9 = new QLabel(EditarConta);
        label_9->setObjectName("label_9");

        formLayout_2->setWidget(5, QFormLayout::ItemRole::LabelRole, label_9);

        BotaoConfirmaEC = new QPushButton(EditarConta);
        BotaoConfirmaEC->setObjectName("BotaoConfirmaEC");

        formLayout_2->setWidget(6, QFormLayout::ItemRole::FieldRole, BotaoConfirmaEC);

        SelecTituloEC = new QComboBox(EditarConta);
        SelecTituloEC->addItem(QString());
        SelecTituloEC->setObjectName("SelecTituloEC");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::FieldRole, SelecTituloEC);

        SelecTagEC = new QComboBox(EditarConta);
        SelecTagEC->addItem(QString());
        SelecTagEC->addItem(QString());
        SelecTagEC->setObjectName("SelecTagEC");

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, SelecTagEC);

        TagEC = new QComboBox(EditarConta);
        TagEC->setObjectName("TagEC");

        formLayout_2->setWidget(5, QFormLayout::ItemRole::FieldRole, TagEC);

        stackedWidget->addWidget(EditarConta);
        RemoverConta = new QWidget();
        RemoverConta->setObjectName("RemoverConta");
        formLayout_3 = new QFormLayout(RemoverConta);
        formLayout_3->setObjectName("formLayout_3");
        SelecTagRC = new QComboBox(RemoverConta);
        SelecTagRC->addItem(QString());
        SelecTagRC->addItem(QString());
        SelecTagRC->setObjectName("SelecTagRC");

        formLayout_3->setWidget(1, QFormLayout::ItemRole::LabelRole, SelecTagRC);

        label_11 = new QLabel(RemoverConta);
        label_11->setObjectName("label_11");

        formLayout_3->setWidget(2, QFormLayout::ItemRole::LabelRole, label_11);

        TituloRC = new QLineEdit(RemoverConta);
        TituloRC->setObjectName("TituloRC");
        TituloRC->setReadOnly(true);

        formLayout_3->setWidget(2, QFormLayout::ItemRole::FieldRole, TituloRC);

        label_12 = new QLabel(RemoverConta);
        label_12->setObjectName("label_12");

        formLayout_3->setWidget(3, QFormLayout::ItemRole::LabelRole, label_12);

        SenhaRC = new QLineEdit(RemoverConta);
        SenhaRC->setObjectName("SenhaRC");
        SenhaRC->setReadOnly(true);

        formLayout_3->setWidget(3, QFormLayout::ItemRole::FieldRole, SenhaRC);

        label_10 = new QLabel(RemoverConta);
        label_10->setObjectName("label_10");

        formLayout_3->setWidget(4, QFormLayout::ItemRole::LabelRole, label_10);

        DescricaoRC = new QTextEdit(RemoverConta);
        DescricaoRC->setObjectName("DescricaoRC");
        DescricaoRC->setReadOnly(true);

        formLayout_3->setWidget(4, QFormLayout::ItemRole::FieldRole, DescricaoRC);

        label_13 = new QLabel(RemoverConta);
        label_13->setObjectName("label_13");

        formLayout_3->setWidget(5, QFormLayout::ItemRole::LabelRole, label_13);

        BotaoConfirmaRC = new QPushButton(RemoverConta);
        BotaoConfirmaRC->setObjectName("BotaoConfirmaRC");

        formLayout_3->setWidget(6, QFormLayout::ItemRole::FieldRole, BotaoConfirmaRC);

        SelecTituloRC = new QComboBox(RemoverConta);
        SelecTituloRC->addItem(QString());
        SelecTituloRC->setObjectName("SelecTituloRC");

        formLayout_3->setWidget(1, QFormLayout::ItemRole::FieldRole, SelecTituloRC);

        TagRC = new QLineEdit(RemoverConta);
        TagRC->setObjectName("TagRC");
        TagRC->setReadOnly(true);

        formLayout_3->setWidget(5, QFormLayout::ItemRole::FieldRole, TagRC);

        stackedWidget->addWidget(RemoverConta);
        SenhaAleatoria = new QWidget();
        SenhaAleatoria->setObjectName("SenhaAleatoria");
        verticalLayout_2 = new QVBoxLayout(SenhaAleatoria);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_14 = new QLabel(SenhaAleatoria);
        label_14->setObjectName("label_14");

        horizontalLayout_2->addWidget(label_14);

        spinBox = new QSpinBox(SenhaAleatoria);
        spinBox->setObjectName("spinBox");
        spinBox->setMinimum(1);
        spinBox->setMaximum(64);

        horizontalLayout_2->addWidget(spinBox);

        toolButton_2 = new QToolButton(SenhaAleatoria);
        toolButton_2->setObjectName("toolButton_2");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::HelpAbout));
        toolButton_2->setIcon(icon);

        horizontalLayout_2->addWidget(toolButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        checkBoxabc = new QCheckBox(SenhaAleatoria);
        checkBoxabc->setObjectName("checkBoxabc");

        horizontalLayout_4->addWidget(checkBoxabc);

        checkBoxABC = new QCheckBox(SenhaAleatoria);
        checkBoxABC->setObjectName("checkBoxABC");

        horizontalLayout_4->addWidget(checkBoxABC);

        checkBox123 = new QCheckBox(SenhaAleatoria);
        checkBox123->setObjectName("checkBox123");

        horizontalLayout_4->addWidget(checkBox123);

        checkBoxExtras = new QCheckBox(SenhaAleatoria);
        checkBoxExtras->setObjectName("checkBoxExtras");

        horizontalLayout_4->addWidget(checkBoxExtras);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_15 = new QLabel(SenhaAleatoria);
        label_15->setObjectName("label_15");

        horizontalLayout_3->addWidget(label_15);

        SenhaGerada = new QLineEdit(SenhaAleatoria);
        SenhaGerada->setObjectName("SenhaGerada");
        SenhaGerada->setReadOnly(true);

        horizontalLayout_3->addWidget(SenhaGerada);

        toolButton = new QToolButton(SenhaAleatoria);
        toolButton->setObjectName("toolButton");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditCopy));
        toolButton->setIcon(icon1);

        horizontalLayout_3->addWidget(toolButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(SenhaAleatoria);
        AdicionarTag = new QWidget();
        AdicionarTag->setObjectName("AdicionarTag");
        formLayout_4 = new QFormLayout(AdicionarTag);
        formLayout_4->setObjectName("formLayout_4");
        label_17 = new QLabel(AdicionarTag);
        label_17->setObjectName("label_17");

        formLayout_4->setWidget(0, QFormLayout::ItemRole::LabelRole, label_17);

        TagsExistentes = new QComboBox(AdicionarTag);
        TagsExistentes->setObjectName("TagsExistentes");

        formLayout_4->setWidget(0, QFormLayout::ItemRole::FieldRole, TagsExistentes);

        label_16 = new QLabel(AdicionarTag);
        label_16->setObjectName("label_16");

        formLayout_4->setWidget(1, QFormLayout::ItemRole::LabelRole, label_16);

        NomeTagNova = new QLineEdit(AdicionarTag);
        NomeTagNova->setObjectName("NomeTagNova");
        NomeTagNova->setMaxLength(20);

        formLayout_4->setWidget(1, QFormLayout::ItemRole::FieldRole, NomeTagNova);

        BotaoConfirmarAT = new QPushButton(AdicionarTag);
        BotaoConfirmarAT->setObjectName("BotaoConfirmarAT");

        formLayout_4->setWidget(2, QFormLayout::ItemRole::FieldRole, BotaoConfirmarAT);

        stackedWidget->addWidget(AdicionarTag);
        RemoverTag = new QWidget();
        RemoverTag->setObjectName("RemoverTag");
        verticalLayout_4 = new QVBoxLayout(RemoverTag);
        verticalLayout_4->setObjectName("verticalLayout_4");
        SelecTagRT = new QComboBox(RemoverTag);
        SelecTagRT->addItem(QString());
        SelecTagRT->setObjectName("SelecTagRT");

        verticalLayout_4->addWidget(SelecTagRT);

        BotaoConfirmaRT = new QPushButton(RemoverTag);
        BotaoConfirmaRT->setObjectName("BotaoConfirmaRT");

        verticalLayout_4->addWidget(BotaoConfirmaRT);

        stackedWidget->addWidget(RemoverTag);
        ExcluirUsuario = new QWidget();
        ExcluirUsuario->setObjectName("ExcluirUsuario");
        gridLayout_2 = new QGridLayout(ExcluirUsuario);
        gridLayout_2->setObjectName("gridLayout_2");
        BotaoExcluirUsuario = new QPushButton(ExcluirUsuario);
        BotaoExcluirUsuario->setObjectName("BotaoExcluirUsuario");

        gridLayout_2->addWidget(BotaoExcluirUsuario, 3, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 1, 1, 1);

        label_18 = new QLabel(ExcluirUsuario);
        label_18->setObjectName("label_18");

        gridLayout_2->addWidget(label_18, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 1, 1, 1);

        stackedWidget->addWidget(ExcluirUsuario);

        verticalLayout->addWidget(stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        BotaoSair = new QPushButton(Menu);
        BotaoSair->setObjectName("BotaoSair");

        horizontalLayout->addWidget(BotaoSair);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(Menu);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        tempo = new QLabel(Menu);
        tempo->setObjectName("tempo");

        horizontalLayout->addWidget(tempo);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(comboBox, TituloAC);
        QWidget::setTabOrder(TituloAC, SenhaAC);
        QWidget::setTabOrder(SenhaAC, DescricaoAC);
        QWidget::setTabOrder(DescricaoAC, TagAC);
        QWidget::setTabOrder(TagAC, BotaoConfirmarAC);
        QWidget::setTabOrder(BotaoConfirmarAC, TagsExistentes);
        QWidget::setTabOrder(TagsExistentes, NomeTagNova);
        QWidget::setTabOrder(NomeTagNova, BotaoConfirmarAT);
        QWidget::setTabOrder(BotaoConfirmarAT, SelecTagMC);
        QWidget::setTabOrder(SelecTagMC, TituloEC);
        QWidget::setTabOrder(TituloEC, SenhaEC);
        QWidget::setTabOrder(SenhaEC, DescricaoEC);
        QWidget::setTabOrder(DescricaoEC, BotaoConfirmaEC);
        QWidget::setTabOrder(BotaoConfirmaEC, TituloRC);
        QWidget::setTabOrder(TituloRC, SenhaRC);
        QWidget::setTabOrder(SenhaRC, DescricaoRC);
        QWidget::setTabOrder(DescricaoRC, BotaoConfirmaRC);
        QWidget::setTabOrder(BotaoConfirmaRC, spinBox);
        QWidget::setTabOrder(spinBox, toolButton_2);
        QWidget::setTabOrder(toolButton_2, checkBoxabc);
        QWidget::setTabOrder(checkBoxabc, checkBoxABC);
        QWidget::setTabOrder(checkBoxABC, checkBox123);
        QWidget::setTabOrder(checkBox123, checkBoxExtras);
        QWidget::setTabOrder(checkBoxExtras, SenhaGerada);
        QWidget::setTabOrder(SenhaGerada, toolButton);
        QWidget::setTabOrder(toolButton, scrollArea);
        QWidget::setTabOrder(scrollArea, SelecTagRT);
        QWidget::setTabOrder(SelecTagRT, BotaoConfirmaRT);
        QWidget::setTabOrder(BotaoConfirmaRT, BotaoSair);

        retranslateUi(Menu);
        QObject::connect(BotaoSair, &QPushButton::clicked, Menu, qOverload<>(&QDialog::close));

        stackedWidget->setCurrentIndex(8);


        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QDialog *Menu)
    {
        Menu->setWindowTitle(QCoreApplication::translate("Menu", "Dialog", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Menu", "Selecione uma op\303\247\303\243o:", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Menu", "Mostrar conta(s)", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Menu", "Adicionar conta", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Menu", "Editar conta", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Menu", "Remover conta", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("Menu", "Gerar senha aleat\303\263ria", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("Menu", "Adicionar tag", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("Menu", "Remover tag", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("Menu", "Excluir usuario", nullptr));

        SelecTagMC->setItemText(0, QCoreApplication::translate("Menu", "Selecione uma tag:", nullptr));
        SelecTagMC->setItemText(1, QCoreApplication::translate("Menu", "Banco", nullptr));

        label_2->setText(QCoreApplication::translate("Menu", "Senha:      ", nullptr));
        label_3->setText(QCoreApplication::translate("Menu", "Descri\303\247\303\243o:", nullptr));
        DescricaoAC->setHtml(QCoreApplication::translate("Menu", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Menu", "Tag:          ", nullptr));
        TagAC->setItemText(0, QCoreApplication::translate("Menu", "Selecione uma op\303\247\303\243o:", nullptr));

        BotaoConfirmarAC->setText(QCoreApplication::translate("Menu", "Confirmar", nullptr));
        label_5->setText(QCoreApplication::translate("Menu", "T\303\255tulo:", nullptr));
        label_6->setText(QCoreApplication::translate("Menu", "T\303\255tulo:", nullptr));
        label_7->setText(QCoreApplication::translate("Menu", "Senha:", nullptr));
        label_8->setText(QCoreApplication::translate("Menu", "Descri\303\247\303\243o:", nullptr));
        label_9->setText(QCoreApplication::translate("Menu", "Tag:", nullptr));
        BotaoConfirmaEC->setText(QCoreApplication::translate("Menu", "Confirmar edi\303\247\303\243o", nullptr));
        SelecTituloEC->setItemText(0, QCoreApplication::translate("Menu", "Selecione um t\303\255tulo de uma conta:", nullptr));

        SelecTagEC->setItemText(0, QCoreApplication::translate("Menu", "Selecione uma tag:", nullptr));
        SelecTagEC->setItemText(1, QCoreApplication::translate("Menu", "Banco", nullptr));

        SelecTagRC->setItemText(0, QCoreApplication::translate("Menu", "Selecione uma tag:", nullptr));
        SelecTagRC->setItemText(1, QCoreApplication::translate("Menu", "Banco", nullptr));

        label_11->setText(QCoreApplication::translate("Menu", "T\303\255tulo:", nullptr));
        label_12->setText(QCoreApplication::translate("Menu", "Senha:", nullptr));
        label_10->setText(QCoreApplication::translate("Menu", "Descri\303\247\303\243o:", nullptr));
        label_13->setText(QCoreApplication::translate("Menu", "Tag:", nullptr));
        BotaoConfirmaRC->setText(QCoreApplication::translate("Menu", "Confirmar remo\303\247\303\243o", nullptr));
        SelecTituloRC->setItemText(0, QCoreApplication::translate("Menu", "Selecione um t\303\255tulo de uma conta:", nullptr));

        label_14->setText(QCoreApplication::translate("Menu", "N\303\272mero de caracteres:   ", nullptr));
        toolButton_2->setText(QCoreApplication::translate("Menu", "...", nullptr));
        checkBoxabc->setText(QCoreApplication::translate("Menu", "abc...", nullptr));
        checkBoxABC->setText(QCoreApplication::translate("Menu", "ABC...", nullptr));
        checkBox123->setText(QCoreApplication::translate("Menu", "123...", nullptr));
        checkBoxExtras->setText(QCoreApplication::translate("Menu", "%#@...", nullptr));
        label_15->setText(QCoreApplication::translate("Menu", "Senha gerada:", nullptr));
        toolButton->setText(QCoreApplication::translate("Menu", "...", nullptr));
        label_17->setText(QCoreApplication::translate("Menu", "Tag's j\303\241 existentes:", nullptr));
        label_16->setText(QCoreApplication::translate("Menu", "Nome da nova tag:", nullptr));
        NomeTagNova->setPlaceholderText(QCoreApplication::translate("Menu", "M\303\241ximo de 20 caracteres", nullptr));
        BotaoConfirmarAT->setText(QCoreApplication::translate("Menu", "Confirmar", nullptr));
        SelecTagRT->setItemText(0, QCoreApplication::translate("Menu", "Selecione uma tag:", nullptr));

        BotaoConfirmaRT->setText(QCoreApplication::translate("Menu", "Confirmar remo\303\247\303\243o", nullptr));
        BotaoExcluirUsuario->setText(QCoreApplication::translate("Menu", "Sim", nullptr));
        label_18->setText(QCoreApplication::translate("Menu", "Deseja excluir seu usu\303\241rio?", nullptr));
        BotaoSair->setText(QCoreApplication::translate("Menu", "Sair", nullptr));
        label->setText(QCoreApplication::translate("Menu", "Tempo restante da sess\303\243o:", nullptr));
        tempo->setText(QCoreApplication::translate("Menu", "mm:ss", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
