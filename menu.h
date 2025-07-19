#ifndef MENU_H
#define MENU_H

// Projeto
#include "conexaobd.h"
#include "conta.h"
#include "contawidget.h"

// Qt
#include <QDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QTimer>
#include <QTextEdit>
#include <QClipboard>
#include <QVBoxLayout>
#include <QLabel>

// Outros
#include <random>
#include <string>
#include <vector>

#define TEMPO_LIMITE 1800 // define o tempo limite da janela em segundos

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public slots:
    void atualizarTemporizador();
    void limitarTexto();

public:
    explicit Menu(QWidget *parent = nullptr, QString usuario = " ");
    ~Menu();

    void configurarAC();
    void configurarEC();
    void configurarRC();
    void configurarMC();
    void configurarAT();
    void configurarRT();
    void configurarWidgets();
    void gerarSenha();

protected:
    // Eventos que resetão o tempo decorrido da janela para o limite
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private slots:
    void on_comboBox_activated(int index);

    void on_BotaoConfirmarAC_clicked();

    void on_BotaoConfirmaEC_clicked();

    void on_BotaoConfirmaRC_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_checkBoxabc_stateChanged(int arg1);

    void on_checkBoxABC_stateChanged(int arg1);

    void on_checkBox123_stateChanged(int arg1);

    void on_checkBoxExtras_stateChanged(int arg1);

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_BotaoConfirmarAT_clicked();

    void on_BotaoConfirmaRT_clicked();

    void on_SelecTituloEC_textActivated(const QString &arg1);

    void on_SelecTituloRC_textActivated(const QString &arg1);

    void on_SelecTagMC_textActivated(const QString &arg1);

    void on_SelecTagEC_textActivated(const QString &arg1);

    void on_SelecTagRC_textActivated(const QString &arg1);

private:
    Ui::Menu *ui;

    QString usuario;

    QTimer* tempo;
    int segundosRestantes;

    QVBoxLayout* layout;
};

#endif // MENU_H
