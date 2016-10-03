#include "ventanacarritos.h"
#include "ui_ventanacarritos.h"

VentanaCarritos::VentanaCarritos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VentanaCarritos)
{
    ui->setupUi(this);
}

VentanaCarritos::~VentanaCarritos()
{
    delete ui;
}
