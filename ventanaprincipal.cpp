#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include <QDebug>
#include <QRegion>
#include <QRect>


VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
}

void VentanaPrincipal::openNewWindow(){
    ventanaCarrito = new VentanaCarritoEntrega();
    ventanaCarrito->show();
}


VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_botonCarritoEntrega_clicked()
{
    ventanaCarrito = new VentanaCarritoEntrega();
    ventanaCarrito->show();
}


void VentanaPrincipal::on_botonMezcladora1_clicked()
{
    ventanaMezcladora1 = new VentanaMezcladoras();
    ventanaMezcladora1->setWindowIcon(QIcon(":/imagenes/Imagenes/iconoMezcladoraC.png"));
    ventanaMezcladora1->show();
}

void VentanaPrincipal::on_botonMezcladora2_clicked()
{
    ventanaMezcladora2 = new VentanaMezcladoras();
    ventanaMezcladora2->setWindowIcon(QIcon(":/imagenes/Imagenes/iconoMezcladoraC.png"));
    ventanaMezcladora2->show();
}

void VentanaPrincipal::on_botonMezcladoraChocolate_clicked()
{
    ventanaMezcladoraChocolate = new VentanaMezcladoras();
    ventanaMezcladoraChocolate->setWindowIcon(QIcon(":/imagenes/Imagenes/Imagen1.png"));
    ventanaMezcladoraChocolate->show();

}

void VentanaPrincipal::on_botonEnsambladora_clicked()
{
    ventanaEnsambladoraSimulador= new ventanaEnsambladora();
    ventanaEnsambladoraSimulador->setWindowIcon(QIcon(":/imagenes/Imagenes/iconoEnsambladora.png"));
    ventanaEnsambladoraSimulador->show();
}

void VentanaPrincipal::on_botonAlmacenPrima_clicked()
{
    ventanaAlmacen= new VentanaAlmacenPrima;
    ventanaAlmacen->show();
}

void VentanaPrincipal::on_botonHorno_clicked()
{
    ventanaHorno = new VentanaHorno();
    ventanaHorno->show();
}
