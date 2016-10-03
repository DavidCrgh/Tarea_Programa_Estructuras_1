#include "ventanaplanificador.h"
#include "ui_ventanaplanificador.h"

VentanaPlanificador::VentanaPlanificador(QWidget *parent, ListaGalletas* pLista, Empacadora* pEmpacadora,
                                         AlmacenTerminal* pAlmacen) :
    QWidget(parent),
    ui(new Ui::VentanaPlanificador)
{
    ui->setupUi(this);
    listaGalletas = pLista;
    empacadora = pEmpacadora;
    almacen = pAlmacen;
    actualizarVentana();
}

VentanaPlanificador::~VentanaPlanificador()
{
    delete ui;
}

void VentanaPlanificador::on_agregar_clicked()
{
    ventanaPaquete = new VentanaPaquete(NULL, listaGalletas);
    connect(ventanaPaquete, SIGNAL(actualizarPlanificador()), this, SLOT(actualizarVentana()));
    ventanaPaquete->show();
}

void VentanaPlanificador::actualizarVentana(){
    ui->barraProbabilidades->setValue(listaGalletas->contarProbabilidades());
    ui->cuadroLista->setText(listaGalletas->imprimirLista());
    ui->valorTotal->setText(QString::number(listaGalletas->contarTotalRequerido()));
}

void VentanaPlanificador::on_cancelar_clicked()
{
    on_limpiar_clicked();
    this->close();
}

void VentanaPlanificador::on_barraProbabilidades_valueChanged(int value)
{
    if(value == 100){
        ui->aceptar->setEnabled(true);
        ui->agregar->setEnabled(false);
    }
}

void VentanaPlanificador::on_limpiar_clicked()
{
    listaGalletas->primerEmpaque = NULL;
    ui->aceptar->setEnabled(false);
    ui->agregar->setEnabled(true);
    actualizarVentana();
}

void VentanaPlanificador::on_aceptar_clicked()
{
    empacadora->listaRangos = listaGalletas->construirRangos();
    empacadora->monticulosEmpacadora = listaGalletas->generarMonticulos();
    almacen->depositos = listaGalletas->generarMonticulos();
    emit inicializarCarritos();
    this->close();
}
