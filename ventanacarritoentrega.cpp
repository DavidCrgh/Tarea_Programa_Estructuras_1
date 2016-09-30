#include "ventanacarritoentrega.h"
#include "ui_ventanacarritoentrega.h"

VentanaCarritoEntrega::VentanaCarritoEntrega(QWidget *parent, CarritoEntrega* pCarrito) :
    QMainWindow(parent),
    ui(new Ui::VentanaCarritoEntrega)
{
    ui->setupUi(this);
    carrito = pCarrito;
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
    QString capacidadMaxima = ui->editorCapacidad->text();
    QString tiempo = ui->editorTiempo->text();
    carrito->capacidadMaxima = capacidadMaxima.toFloat();
    carrito->tiempoViaje = tiempo.toFloat();
    ui->configurar->setEnabled(true);
    ui->editorCapacidad->setEnabled(false);
    ui->editorTiempo->setEnabled(false);
    ui->aceptar->setEnabled(false);
}
void VentanaCarritoEntrega::actualizarVentana(QStringList pMensaje){
    ui->maquinaValor->setText(pMensaje[0]);
    ui->contenidoValor->setText(pMensaje[1]);
}
