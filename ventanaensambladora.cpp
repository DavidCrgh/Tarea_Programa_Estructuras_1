#include "ventanaensambladora.h"
#include "ui_ventanaensambladora.h"

ventanaEnsambladora::ventanaEnsambladora(QWidget *parent, Simulacion* pSimulacion) :
    QMainWindow(parent),
    ui(new Ui::ventanaEnsambladora)
{
    ui->setupUi(this);
    simulacion = pSimulacion;
    ensambladora = simulacion->ensambladora;
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
    ui->apagado->setChecked(simulacion->hiloEnsambladora->pause);
    ui->encendido->setChecked(!(simulacion->hiloEnsambladora->pause));
}

void ventanaEnsambladora::on_apagado_clicked()
{
    simulacion->hiloEnsambladora->pause = true;
}

void ventanaEnsambladora::on_encendido_clicked()
{
    simulacion->hiloEnsambladora->pause = false;
}

void ventanaEnsambladora::resetearVentana(){

    ui->editorMasa->setText("");
    ui->editorCantidad->setText("");
    ui->editorChocolate->setText("");
    ui->editorTiempo->setText("");


}
