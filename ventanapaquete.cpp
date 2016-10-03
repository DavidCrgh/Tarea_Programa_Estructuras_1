#include "ventanapaquete.h"
#include "ui_ventanapaquete.h"

VentanaPaquete::VentanaPaquete(QWidget *parent, ListaGalletas* pLista) :
    QWidget(parent),
    ui(new Ui::VentanaPaquete)
{
    ui->setupUi(this);
    listaGalletas = pLista;
    ui->editorProbabilidad->setMaximum(100 - listaGalletas->contarProbabilidades());
}

VentanaPaquete::~VentanaPaquete()
{
    delete ui;
}

void VentanaPaquete::on_aceptar_clicked()
{
    QString nombre = ui->editorNombre->text();
    QString galletas = ui->editorGalletas->text();
    QString cantidad = ui->editorCantidad->text();
    QString tiempo = ui->editorTiempo->text();
    QString requerida = ui->editorRequerida->text();
    float probabilidad = ui->editorProbabilidad->value();
    listaGalletas->insertarTipoGalleta(nombre, galletas.toInt(),cantidad.toInt(), tiempo.toFloat(),probabilidad, requerida.toInt());
    emit actualizarPlanificador();
    this->close();
}

void VentanaPaquete::on_cancelar_clicked()
{
    this->close();
}
