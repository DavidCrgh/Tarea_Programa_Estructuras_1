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

void VentanaAlmacenPrima::actualizarCuadroEspera(QString pMensaje){
    ui->cuadroEspera->setText(pMensaje);
}

void VentanaAlmacenPrima::actualizarCuadroRealizadas(QString pMensaje){
    ui->cuadroEspera->setText(pMensaje);
}
