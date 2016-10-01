#include "ventanabandeja.h"
#include "ui_ventanabandeja.h"

VentanaBandeja::VentanaBandeja(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VentanaBandeja)
{
    ui->setupUi(this);
}

VentanaBandeja::~VentanaBandeja()
{
    delete ui;
}
