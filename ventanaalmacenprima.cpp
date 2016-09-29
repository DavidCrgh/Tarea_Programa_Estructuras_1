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

void VentanaAlmacenPrima::actualizarVentana(std::string pMensaje[]){
    ui->cuadroEspera->setText(pMensaje[0]);
    ui->cuadroEspera->setText(pMensaje[1]);
}
