#include "ventanabandeja.h"
#include "ui_ventanabandeja.h"

VentanaBandeja::VentanaBandeja(QWidget *parent, Bandeja* pBandeja) :
    QWidget(parent),
    ui(new Ui::VentanaBandeja)
{
    ui->setupUi(this);
    bandeja = pBandeja;
}

VentanaBandeja::~VentanaBandeja()
{
    delete ui;
}

void VentanaBandeja::resetearVentana(){
    ui->editorTiempo->setText("");
    ui->editorCapacidad->setText("");
}

void VentanaBandeja::on_configurar_clicked()
{
    ui->configurar->setEnabled(false);
    ui->aceptar->setEnabled(true);
    ui->editorCapacidad->setEnabled(true);
    ui->editorTiempo->setEnabled(true);
}

void VentanaBandeja::on_aceptar_clicked()
{
    QString capacidad = ui->editorCapacidad->text();
    QString tiempo = ui->editorTiempo->text();
    bandeja->capacidad = capacidad.toFloat();
    bandeja->tiempo = tiempo.toFloat();
    ui->configurar->setEnabled(true);
    ui->aceptar->setEnabled(false);
    ui->editorCapacidad->setEnabled(false);
    ui->editorTiempo->setEnabled(false);
}

void VentanaBandeja::actualizarVentana(){
    ui->cargadasValor->setText(QString::number(bandeja->contenidoActual));
    ui->horneadasValor->setText(QString::number(bandeja->cantidadProcesada));
}
