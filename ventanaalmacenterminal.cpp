#include "ventanaalmacenterminal.h"
#include "ui_ventanaalmacenterminal.h"

VentanaAlmacenTerminal::VentanaAlmacenTerminal(QWidget *parent, AlmacenTerminal* pAlmacen) :
    QWidget(parent),
    ui(new Ui::VentanaAlmacenTerminal)
{
    ui->setupUi(this);
    almacenTerminal = pAlmacen;
}

VentanaAlmacenTerminal::~VentanaAlmacenTerminal()
{
    delete ui;
}

void VentanaAlmacenTerminal::actualizarVentana(){
    ui->cuadroDepositos->setText(almacenTerminal->depositos->imprimirMonticulos());
    ui->totalValor->setText(QString::number(almacenTerminal->determinarTotal()));
}
