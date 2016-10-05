#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include <QDebug>
#include <QRegion>
#include <QRect>


VentanaPrincipal::VentanaPrincipal(QWidget *parent, Simulacion* pSimulacion) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    simulacion = pSimulacion;
    ui->setupUi(this);
    ventanaAlmacen = new VentanaAlmacenPrima(NULL, simulacion->almacenPrima);
    ventanaCarrito = new VentanaCarritoEntrega(NULL, simulacion);
    ventanaMezcladora1 = new VentanaMezcladoras(NULL, simulacion->mezcladorasMasa[0], simulacion);
    ventanaMezcladora2 = new VentanaMezcladoras(NULL, simulacion->mezcladorasMasa[1], simulacion);
    ventanaMezcladoraChocolate = new VentanaMezcladoras(NULL, simulacion->mezcladoraChocolate, simulacion);
    ventanaBandaMasa = new VentanaBanda(NULL, simulacion->bandaMasa);
    ventanaBandaChocolate = new VentanaBanda(NULL, simulacion->bandaChocolate);
    ventanaEnsambladoraSimulador = new ventanaEnsambladora(NULL, simulacion);
    ventanaBandaCrudas = new VentanaBanda(NULL, simulacion->bandaGalletasCrudas);
    ventanaHorno = new VentanaHorno(NULL, simulacion);
    ventanaBandaInspectores = new VentanaBanda(NULL,simulacion->bandaInspectores);
    ventanaInspector1 = new ventanaInspectores(NULL,simulacion->inspector1, simulacion);
    ventanaInspector2 = new ventanaInspectores(NULL,simulacion->inspector2, simulacion);
    ventanaPlanificador = new VentanaPlanificador(NULL, simulacion->listaGalletas, simulacion->empacadora,
                                                  simulacion->almacenTerminal);
    ventanaEmpacadora = new VentanaEmpacadora(NULL, simulacion);
    connect(ventanaPlanificador, SIGNAL(inicializarCarritos()), this, SLOT(crearCarritos()));
    ventanaCarritosSalida = NULL;
    ventanaAlmacenTerminal = new VentanaAlmacenTerminal(NULL, simulacion);
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
    ventanaMezcladora1->show();
}

void VentanaPrincipal::on_botonMezcladora2_clicked()
{
    ventanaMezcladora2->show();
}

void VentanaPrincipal::on_botonMezcladoraChocolate_clicked()
{
    ventanaMezcladoraChocolate->setWindowIcon(QIcon(":/imagenes/Imagenes/Imagen1.png"));
    ventanaMezcladoraChocolate->show();

}

void VentanaPrincipal::on_botonEnsambladora_clicked()
{
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
    ventanaHorno->toggleVentana(true);
}

void VentanaPrincipal::on_botonPausa_clicked()
{
    simulacion->pausarHilos();
    ventanaHorno->toggleVentana(false);
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

void VentanaPrincipal::on_botonEmpacadora_clicked()
{
    ventanaEmpacadora->show();
}

void VentanaPrincipal::crearCarritos(){
    simulacion->crearHilosCarritoSalida();
    ventanaCarritosSalida = new VentanaCarritos(NULL, simulacion);
    ui->botonCarritoSalida->setEnabled(true);
}

void VentanaPrincipal::on_botonCarritoSalida_clicked()
{
    ventanaCarritosSalida->show();
}

void VentanaPrincipal::on_botonAlmacenTerminal_clicked()
{
    ventanaAlmacenTerminal->show();
}

void VentanaPrincipal::on_botonStop_clicked()
{
    simulacion->resetearSimulacion();
    ui->botonCarritoSalida->setEnabled(false);
    ventanaPlanificador->resetearVentana();
     ventanaEnsambladoraSimulador->resetearVentana();
     ventanaHorno->resetearVentana();
     ventanaInspector1->resetearVentana();
     ventanaInspector2->resetearVentana();
    ventanaMezcladora1->resetearVentana();
    ventanaMezcladora2->resetearVentana();
    ventanaMezcladoraChocolate->resetearVentana();
 }
  }
