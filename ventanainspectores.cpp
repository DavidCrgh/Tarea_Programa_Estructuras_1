#include "ventanainspectores.h"
#include "ui_ventanainspectores.h"

ventanaInspectores::ventanaInspectores(QWidget *parent, Inspector* pInspector, Simulacion* pSimulacion) :
    QMainWindow(parent),
    ui(new Ui::ventanaInspectores)
{
    ui->setupUi(this);
    simulacion = pSimulacion;
    inspector = pInspector;
}

ventanaInspectores::~ventanaInspectores()
{
    delete ui;
}

void ventanaInspectores::on_Aceptar_clicked()
{
    QString probabilidad= ui->editorProbabilidad->text();

    inspector->probabilidadRechazo=probabilidad.toFloat();
    ui->configurar->setDisabled(false);
    ui->Aceptar->setDisabled(true);
    ui->editorProbabilidad->setDisabled(true);
}

void ventanaInspectores::on_configurar_clicked()
{
    ui->configurar->setDisabled(true);
    ui->Aceptar->setDisabled(false);
    ui->editorProbabilidad->setDisabled(false);
}

void ventanaInspectores::actualizarVentana(){
    ui->aprobadasValor->setText(QString ::number(inspector->aprobadas));
    ui->desechadasValor->setText(QString::number(inspector->desechadas));
    if(inspector == simulacion->inspector1){
        ui->encendido->setChecked(!(simulacion->hiloInspector1->pause));
        ui->apagado->setChecked(simulacion->hiloInspector1->pause);
    } else {
        ui->encendido->setChecked(!(simulacion->hiloInspector2->pause));
        ui->apagado->setChecked(simulacion->hiloInspector2->pause);
    }
}

void ventanaInspectores::on_encendido_clicked()
{
    if(inspector == simulacion->inspector1){
        simulacion->hiloInspector1->pause = false;
    } else {
        simulacion->hiloInspector2->pause = false;
    }
}

void ventanaInspectores::on_apagado_clicked()
{
    if(inspector == simulacion->inspector1){
        simulacion->hiloInspector1->pause = true;
    } else {
        simulacion->hiloInspector2->pause = true;
    }
}

void ventanaInspectores::resetearVentana(){

    ui->editorProbabilidad->setText("");
    ui->desechadasValor->setText("");
    ui->aprobadasValor->setText("");

}
