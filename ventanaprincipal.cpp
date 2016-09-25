#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include <QDebug>
#include <QRegion>
#include <QRect>
#include <cstdlib>
#include <iostream>

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_toolButton_12_clicked()
{
    std::cout << "hola mundo" << endl;
}
