#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include <QDebug>
#include <QRegion>
#include <QRect>


VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
    /*ui->pushButton_2->setText("Test Text");
    ui->pushButton_2->setFixedHeight(200);
    ui->pushButton_2->setFixedWidth(200);
    QRect *rect = new QRect(0,0,100,100);
    qDebug() << rect->size();
    qDebug() << ui->pushButton_2->size();
    QRegion* region = new QRegion(*rect,QRegion::Ellipse);
    qDebug() << region->boundingRect().size();
    ui->pushButton_2->setMask(*region);*/
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}
