#include "ventanaalmacenprima.h"
#include "ui_ventanaalmacenprima.h"

VentanaAlmacenPrima::VentanaAlmacenPrima(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaAlmacenPrima)
{
    ui->setupUi(this);
}

VentanaAlmacenPrima::~VentanaAlmacenPrima()
{
    delete ui;
}
