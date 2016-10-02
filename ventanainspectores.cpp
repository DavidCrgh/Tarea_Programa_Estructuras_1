#include "ventanainspectores.h"
#include "ui_ventanainspectores.h"

ventanaInspectores::ventanaInspectores(QWidget *parent,Inspector* pInspector) :
    QMainWindow(parent),
    ui(new Ui::ventanaInspectores)
{
    ui->setupUi(this);
    inspector=pInspector;
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

}
