#include "ventanabanda.h"
#include "ui_ventanabanda.h"

VentanaBanda::VentanaBanda(QWidget *parent, Banda* pBanda) :
    QWidget(parent),
    ui(new Ui::VentanaBanda)
{
    ui->setupUi(this);
    banda = pBanda;
}

VentanaBanda::~VentanaBanda()
{
    delete ui;
}

void VentanaBanda::on_configurar_clicked()
{
    ui->editorMaximo->setEnabled(true);
    ui->aceptar->setEnabled(true);
    ui->configurar->setEnabled(false);
}

void VentanaBanda::on_aceptar_clicked()
{
    QString maximoBanda= ui->editorMaximo->text();
    ui->editorMaximo->setEnabled(false);
    ui->aceptar->setEnabled(false);
    ui->configurar->setEnabled(true);
    banda->limite= maximoBanda.toFloat();
}

void VentanaBanda::actualizarBandas(){

ui->cantidadValor->setText(QString::number(banda->contenidoActual()));

}
