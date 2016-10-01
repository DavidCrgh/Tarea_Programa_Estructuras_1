#include "ventanaensambladora.h"
#include "ui_ventanaensambladora.h"

ventanaEnsambladora::ventanaEnsambladora(QWidget *parent, Ensambladora* pEnsambladora) :
    QMainWindow(parent),
    ui(new Ui::ventanaEnsambladora)
{
    ui->setupUi(this);
    ensambladora = pEnsambladora;
}

ventanaEnsambladora::~ventanaEnsambladora()
{
    delete ui;
}

void ventanaEnsambladora::on_configurar_clicked()
{
    ui->editorMasa->setEnabled(true);
    ui->editorChocolate->setEnabled(true);
    ui->editorTiempo->setEnabled(true);
    ui->editorCantidad->setEnabled(true);
    ui->aceptar->setEnabled(true);
    ui->configurar->setEnabled(false);
}

void ventanaEnsambladora::on_aceptar_clicked()
{
    QString masaRequerida = ui->editorMasa->text();
    QString chocolateRequerido = ui->editorChocolate->text();
    QString cantidadxTiempo = ui->editorCantidad->text();
    QString tiempo = ui->editorTiempo->text();
    ensambladora->masaRequerida = masaRequerida.toFloat();
    ensambladora->chocolateRequerido = chocolateRequerido.toFloat();
    ensambladora->producidoxTanda = cantidadxTiempo.toFloat();
    ensambladora->tiempo = tiempo.toFloat();
    ui->editorMasa->setEnabled(false);
    ui->editorChocolate->setEnabled(false);
    ui->editorTiempo->setEnabled(false);
    ui->editorCantidad->setEnabled(false);
    ui->aceptar->setEnabled(false);
    ui->configurar->setEnabled(true);
}

void ventanaEnsambladora::actualizarVentana(){
    ui->totalGalletasValor->setText(QString::number(ensambladora->cantidadProcesada));

}
