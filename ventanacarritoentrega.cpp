#include "ventanacarritoentrega.h"
#include "ui_ventanacarritoentrega.h"

VentanaCarritoEntrega::VentanaCarritoEntrega(QWidget *parent, Simulacion* pSimulacion) :
    QMainWindow(parent),
    ui(new Ui::VentanaCarritoEntrega)
{
    ui->setupUi(this);
    simulacion = pSimulacion;
    carrito = simulacion->carritoEntrega;
}

VentanaCarritoEntrega::~VentanaCarritoEntrega()
{
    delete ui;
}

void VentanaCarritoEntrega::resetearVentana(){
    ui->editorCapacidad->setText("");
    ui->editorTiempo->setText("");
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
    ui->encendido->setChecked(!(simulacion->hiloCarritoEntrega->pause));
    ui->apagado->setChecked(simulacion->hiloCarritoEntrega->pause);
}

void VentanaCarritoEntrega::on_apagado_clicked()
{
    simulacion->hiloCarritoEntrega->pause = true;
}

void VentanaCarritoEntrega::on_encendido_clicked()
{
    simulacion->hiloCarritoEntrega->pause = false;
}
