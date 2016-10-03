#include "ventanacarritos.h"
#include "ui_ventanacarritos.h"

VentanaCarritos::VentanaCarritos(QWidget *parent, Simulacion* pSimulacion) :
    QWidget(parent),
    ui(new Ui::VentanaCarritos)
{
    ui->setupUi(this);
    carritosSalida = pSimulacion->carritosSalida;
    simulacion = pSimulacion;
    indiceCarrito = 0;

    QString etiquetaContador = "";
    etiquetaContador += "Carrito " + QString::number(indiceCarrito + 1) + " de " + QString::number(simulacion->listaGalletas->largoListaGalletas());
    ui->contador->setText(etiquetaContador);

    if(simulacion->listaGalletas->largoListaGalletas() == 1){
        ui->flechaDerecha->setEnabled(false);
    }

    ui->valorTipo->setText(carritosSalida[0]->nombrePaquete);
}

VentanaCarritos::~VentanaCarritos()
{
    delete ui;
}

void VentanaCarritos::on_flechaIzquierda_clicked()
{
    QString tiempo = ui->editorTiempo->text();
    QString capacidad = ui->editorCapacidad->text();
    carritosSalida[indiceCarrito]->tiempoViaje = tiempo.toFloat();
    carritosSalida[indiceCarrito]->capacidadMaxima = capacidad.toFloat();

    indiceCarrito--;

    ui->editorTiempo->clear();
    ui->editorCapacidad->clear();

    ui->editorTiempo->setText(QString::number(carritosSalida[indiceCarrito]->tiempoViaje));
    ui->editorCapacidad->setText(QString::number(carritosSalida[indiceCarrito]->capacidadMaxima));

    ui->valorTipo->setText(carritosSalida[indiceCarrito]->nombrePaquete);

    QString etiquetaContador = "";
    etiquetaContador += "Carrito " + QString::number(indiceCarrito + 1) + " de " + QString::number(simulacion->listaGalletas->largoListaGalletas());
    ui->contador->setText(etiquetaContador);

    if(indiceCarrito == 0){
        ui->flechaIzquierda->setEnabled(false);
        ui->flechaDerecha->setEnabled(true);
    } else {
        ui->flechaDerecha->setEnabled(true);
    }
}

void VentanaCarritos::on_flechaDerecha_clicked()
{
    QString tiempo = ui->editorTiempo->text();
    QString capacidad = ui->editorCapacidad->text();
    carritosSalida[indiceCarrito]->tiempoViaje = tiempo.toFloat();
    carritosSalida[indiceCarrito]->capacidadMaxima = capacidad.toFloat();

    indiceCarrito++;

    ui->editorTiempo->clear();
    ui->editorCapacidad->clear();

    ui->editorTiempo->setText(QString::number(carritosSalida[indiceCarrito]->tiempoViaje));
    ui->editorCapacidad->setText(QString::number(carritosSalida[indiceCarrito]->capacidadMaxima));

    ui->valorTipo->setText(carritosSalida[indiceCarrito]->nombrePaquete);

    QString etiquetaContador = "";
    etiquetaContador += "Carrito " + QString::number(indiceCarrito + 1) + " de " + QString::number(simulacion->listaGalletas->largoListaGalletas());
    ui->contador->setText(etiquetaContador);

    if(indiceCarrito == (simulacion->listaGalletas->largoListaGalletas()) - 1){
        ui->flechaDerecha->setEnabled(false);
        ui->flechaIzquierda->setEnabled(true);
    } else {
        ui->flechaIzquierda->setEnabled(true);

    }
}

void VentanaCarritos::actualizarVentana(){
    ui->valorCantidad->setText(QString::number(carritosSalida[indiceCarrito]->cantidadTransportada));
}
