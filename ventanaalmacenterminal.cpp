#include "ventanaalmacenterminal.h"
#include "ui_ventanaalmacenterminal.h"

VentanaAlmacenTerminal::VentanaAlmacenTerminal(QWidget *parent, Simulacion* pSimulacion) :
    QWidget(parent),
    ui(new Ui::VentanaAlmacenTerminal)
{
    ui->setupUi(this);
    simulacion = pSimulacion;
    almacenTerminal = simulacion->almacenTerminal;
}

VentanaAlmacenTerminal::~VentanaAlmacenTerminal()
{
    delete ui;
}

void VentanaAlmacenTerminal::resetearVentana(){
    ui->cuadroDepositos->setText("");
    ui->totalValor->setText("0");
}

void VentanaAlmacenTerminal::actualizarVentana(){
    ui->cuadroDepositos->setText(almacenTerminal->depositos->imprimirMonticulos());
    ui->totalValor->setText(QString::number(almacenTerminal->determinarTotal()));
}
