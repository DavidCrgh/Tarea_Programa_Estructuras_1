#include "ventanaempacadora.h"
#include "ui_ventanaempacadora.h"

VentanaEmpacadora::VentanaEmpacadora(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VentanaEmpacadora)
{
    ui->setupUi(this);
}

VentanaEmpacadora::~VentanaEmpacadora()
{
    delete ui;
}
