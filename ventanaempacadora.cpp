#include "ventanaempacadora.h"
#include "ui_ventanaempacadora.h"

VentanaEmpacadora::VentanaEmpacadora(QWidget *parent, Empacadora* pEmpacadora) :
    QWidget(parent),
    ui(new Ui::VentanaEmpacadora)
{
    ui->setupUi(this);
    empacadora = pEmpacadora;
}

VentanaEmpacadora::~VentanaEmpacadora()
{
    delete ui;
}

void VentanaEmpacadora::actualizarVentana(){
    ui->cuadroMonticulos->setText(empacadora->monticulosEmpacadora->imprimirMonticulos());
}
