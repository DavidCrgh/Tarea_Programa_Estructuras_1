#include "ventanaensambladora.h"
#include "ui_ventanaensambladora.h"

ventanaEnsambladora::ventanaEnsambladora(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ventanaEnsambladora)
{
    ui->setupUi(this);
}

ventanaEnsambladora::~ventanaEnsambladora()
{
    delete ui;
}

void ventanaEnsambladora::on_configurar_clicked()
{
  ui->editorMasa->setEnabled(true);
  ui->editorChocolate->setEnabled(true);
  ui->editorTiempo->setEnabled(true);
  ui->editorCantidad->setEnabled(true);
  ui->aceptar->setEnabled(true);
  ui->configurar->setEnabled(false);
}

void ventanaEnsambladora::on_aceptar_clicked()
{
    ui->editorMasa->setEnabled(false);
    ui->editorChocolate->setEnabled(false);
    ui->editorTiempo->setEnabled(false);
    ui->editorCantidad->setEnabled(false);
    ui->aceptar->setEnabled(false);
    ui->configurar->setEnabled(true);
}
