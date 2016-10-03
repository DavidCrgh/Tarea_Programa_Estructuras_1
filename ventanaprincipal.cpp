#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include <QDebug>
#include <QRegion>
#include <QRect>


VentanaPrincipal::VentanaPrincipal(QWidget *parent, Simulacion* pSimulacion) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    //qDebug("A");
    simulacion = pSimulacion;
    //qDebug("B");
    ui->setupUi(this);
    //qDebug("C");
    ventanaAlmacen = new VentanaAlmacenPrima(NULL, simulacion->almacenPrima);
    //qDebug("D");
    ventanaCarrito = new VentanaCarritoEntrega(NULL, simulacion->carritoEntrega);
    //qDebug("E");
    ventanaMezcladora1 = new VentanaMezcladoras(NULL, simulacion->mezcladorasMasa[0]);
    //qDebug("F");
    ventanaMezcladora2 = new VentanaMezcladoras(NULL, simulacion->mezcladorasMasa[1]);
    //qDebug("G");
    ventanaMezcladoraChocolate = new VentanaMezcladoras(NULL, simulacion->mezcladoraChocolate);
    //qDebug("H");
    ventanaBandaMasa = new VentanaBanda(NULL, simulacion->bandaMasa);
    //qDebug("I");
    ventanaBandaChocolate = new VentanaBanda(NULL, simulacion->bandaChocolate);
    //qDebug("J");
    ventanaEnsambladoraSimulador = new ventanaEnsambladora(NULL, simulacion->ensambladora);
    //qDebug("K");
    ventanaBandaCrudas = new VentanaBanda(NULL, simulacion->bandaGalletasCrudas);
    //qDebug("L");
    ventanaHorno = new VentanaHorno(NULL, simulacion->horno);
    //qDebug("Completado");
    ventanaBandaInspectores= new VentanaBanda(NULL,simulacion->bandaInspectores);
    ventanaInspector1 = new ventanaInspectores(NULL,simulacion->inspector1);
    ventanaInspector2 = new ventanaInspectores(NULL,simulacion->inspector2);
    ventanaPlanificador = new VentanaPlanificador(NULL, simulacion->listaGalletas, simulacion->empacadora);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_botonCarritoEntrega_clicked()
{
    ventanaCarrito->show();
}


void VentanaPrincipal::on_botonMezcladora1_clicked()
{
    ventanaMezcladora1->setWindowIcon(QIcon(":/imagenes/Imagenes/iconoMezcladoraC.png"));
    ventanaMezcladora1->show();
}

void VentanaPrincipal::on_botonMezcladora2_clicked()
{
    ventanaMezcladora2->setWindowIcon(QIcon(":/imagenes/Imagenes/iconoMezcladoraC.png"));
    ventanaMezcladora2->show();
}

void VentanaPrincipal::on_botonMezcladoraChocolate_clicked()
{
    ventanaMezcladoraChocolate->setWindowIcon(QIcon(":/imagenes/Imagenes/Imagen1.png"));
    ventanaMezcladoraChocolate->show();

}

void VentanaPrincipal::on_botonEnsambladora_clicked()
{
    ventanaEnsambladoraSimulador->setWindowIcon(QIcon(":/imagenes/Imagenes/iconoEnsambladora.png"));
    ventanaEnsambladoraSimulador->show();
}

void VentanaPrincipal::on_botonAlmacenPrima_clicked()
{
    ventanaAlmacen->show();
}

void VentanaPrincipal::on_botonHorno_clicked()
{
    ventanaHorno->show();
}

void VentanaPrincipal::on_botonPlay_clicked()
{
    simulacion->iniciarHilos();
}

void VentanaPrincipal::on_botonPausa_clicked()
{
    simulacion->pausarHilos();
}

void VentanaPrincipal::on_botonBandaMasa_clicked()
{
    ventanaBandaMasa->show();
}

void VentanaPrincipal::on_botonBandaChocolate_clicked()
{
    ventanaBandaChocolate->show();
}

void VentanaPrincipal::on_botonBandaCrudas_clicked()
{
    ventanaBandaCrudas->show();
}

void VentanaPrincipal::on_bandaInspectores_clicked()
{
    ventanaBandaInspectores->show();
}

void VentanaPrincipal::on_botonInspector1_clicked()
{
    ventanaInspector1->show();
}


void VentanaPrincipal::on_botonInspector2_clicked()
{
    ventanaInspector2->show();
}

void VentanaPrincipal::on_botonPlanificador_clicked()
{
    ventanaPlanificador->show();
}
