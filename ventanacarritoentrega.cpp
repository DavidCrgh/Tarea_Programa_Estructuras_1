#include "ventanacarritoentrega.h"
#include "ui_ventanacarritoentrega.h"

VentanaCarritoEntrega::VentanaCarritoEntrega(QWidget *parent/*, CarritoEntrega* pCarrito*/) :
    QMainWindow(parent),
    ui(new Ui::VentanaCarritoEntrega)
{
    ui->setupUi(this);
    //carrito = pCarrito;

}

VentanaCarritoEntrega::~VentanaCarritoEntrega()
{
    delete ui;
}

void VentanaCarritoEntrega::on_configurar_clicked()
{
    ui->editorCapacidad->setEnabled(true);
    ui->editorTiempo->setEnabled(true);
    ui->aceptar->setEnabled(true);
    ui->configurar->setEnabled(false);

}

void VentanaCarritoEntrega::on_aceptar_clicked()
{
    ui->configurar->setEnabled(true);
    ui->editorCapacidad->setEnabled(false);
    ui->editorTiempo->setEnabled(false);
    ui->aceptar->setEnabled(false);
}
