#include "ventanamezcladoras.h"
#include "ui_ventanamezcladoras.h"

VentanaMezcladoras::VentanaMezcladoras(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaMezcladoras)
{
    ui->setupUi(this);
}

VentanaMezcladoras::~VentanaMezcladoras()
{
    delete ui;
}

void VentanaMezcladoras::on_configurar_clicked()
{
    ui->editorMinimo->setEnabled(true);
    ui->editorMaximo->setEnabled(true);
    ui->editorCantidad->setEnabled(true);
    ui->editorTiempo->setEnabled(true);
    ui->configurar->setEnabled(false);
    ui->aceptar->setEnabled(true);
}

void VentanaMezcladoras::on_aceptar_clicked()
{
    ui->editorMinimo->setEnabled(false);
    ui->editorMaximo->setEnabled(false);
    ui->editorCantidad->setEnabled(false);
    ui->editorTiempo->setEnabled(false);
    ui->configurar->setEnabled(true);
    ui->aceptar->setEnabled(false);
}
