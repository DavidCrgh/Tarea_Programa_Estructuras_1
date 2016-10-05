#include "ventanaempacadora.h"
#include "ui_ventanaempacadora.h"

VentanaEmpacadora::VentanaEmpacadora(QWidget *parent, Simulacion* pSimulacion) :
    QWidget(parent),
    ui(new Ui::VentanaEmpacadora)
{
    ui->setupUi(this);
    simulacion = pSimulacion;
    empacadora = simulacion->empacadora;
}

VentanaEmpacadora::~VentanaEmpacadora()
{
    delete ui;
}

void VentanaEmpacadora::resetearVentana(){
    ui->cuadroMonticulos->setText("");
}

void VentanaEmpacadora::actualizarVentana(){
    ui->cuadroMonticulos->setText(empacadora->monticulosEmpacadora->imprimirMonticulos());
    ui->procesandoValor->setText(QString::number(empacadora->galletasActuales));
    ui->encendido->setChecked(!(simulacion->hiloEmpacadora->pause));
    ui->apagado->setChecked(simulacion->hiloEmpacadora->pause);
}

void VentanaEmpacadora::on_apagado_clicked()
{
    simulacion->hiloEmpacadora->pause = true;
    empacadora->estaActiva = false;
}

void VentanaEmpacadora::on_encendido_clicked()
{
    simulacion->hiloEmpacadora->pause = false;
    empacadora->estaActiva = true;
}
