#include "ventanaalmacenprima.h"
#include "ui_ventanaalmacenprima.h"

VentanaAlmacenPrima::VentanaAlmacenPrima(QWidget *parent, AlmacenPrima* pAlmacen) :
    QMainWindow(parent),
    ui(new Ui::VentanaAlmacenPrima)
{
    ui->setupUi(this);
    almacen = pAlmacen;
}

VentanaAlmacenPrima::~VentanaAlmacenPrima()
{
    delete ui;
}

void VentanaAlmacenPrima::actualizarVentana(QStringList pMensaje){
    ui->cuadroEspera->setText(pMensaje.at(0));
    ui->cuadroRealizadas->setText(pMensaje.at(1));
}
