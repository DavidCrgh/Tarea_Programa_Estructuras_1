#include "ventanahorno.h"
#include "ui_ventanahorno.h"

VentanaHorno::VentanaHorno(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaHorno)
{
    ui->setupUi(this);
}

VentanaHorno::~VentanaHorno()
{
    delete ui;
}

void VentanaHorno::on_encendido_clicked()
{
    ui->checkBandeja3->setEnabled(true);
    ui->checkBandeja4->setEnabled(true);
    ui->checkBandeja5->setEnabled(true);
    ui->checkBandeja6->setEnabled(true);
    ui->checkBandeja1->setChecked(true);
    ui->checkBandeja2->setChecked(true);
}

void VentanaHorno::on_apagado_clicked()
{
    ui->checkBandeja3->setEnabled(false);
    ui->checkBandeja4->setEnabled(false);
    ui->checkBandeja5->setEnabled(false);
    ui->checkBandeja6->setEnabled(false);
    ui->checkBandeja1->setChecked(false);
    ui->checkBandeja2->setChecked(false);
}
