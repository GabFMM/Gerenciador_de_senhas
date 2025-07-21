#ifndef CRIARUSUARIO_H
#define CRIARUSUARIO_H

#include <QDialog>
#include <QMessageBox>
#include "conexaobd.h"

namespace Ui {
class CriarUsuario;
}

class CriarUsuario : public QDialog
{
    Q_OBJECT

public:
    explicit CriarUsuario(QWidget *parent = nullptr);
    ~CriarUsuario();

private slots:
    void on_BotaoCriarUsuario_clicked();

private:
    Ui::CriarUsuario *ui;
};

#endif // CRIARUSUARIO_H
