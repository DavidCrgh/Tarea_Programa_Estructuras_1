#include "ventanahorno.h"
#include "ui_ventanahorno.h"

VentanaHorno::VentanaHorno(QWidget *parent, Horno* pHorno) :
    QMainWindow(parent),
    ui(new Ui::VentanaHorno)
{
    ui->setupUi(this);
    horno = pHorno;
    for(int i = 0; i < 6; i++){
        ventanasBandeja[i] = new VentanaBandeja(NULL, horno->bandejas[i]);
    }
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
    ui->checkBandeja3->setChecked(false);
    ui->checkBandeja4->setChecked(false);
    ui->checkBandeja5->setChecked(false);
    ui->checkBandeja6->setChecked(false);
}

void VentanaHorno::on_configurarBandeja1_clicked()
{
    ventanasBandeja[0]->show();
}

void VentanaHorno::on_configurarBandeja2_clicked()
{
    ventanasBandeja[1]->show();
}

void VentanaHorno::on_configurarBandeja3_clicked()
{
    ventanasBandeja[2]->show();
}

void VentanaHorno::on_configurarBandeja4_clicked()
{
    ventanasBandeja[3]->show();
}

void VentanaHorno::on_configurarBandeja5_clicked()
{
    ventanasBandeja[4]->show();
}

void VentanaHorno::on_configurarBandeja6_clicked()
{
    ventanasBandeja[5]->show();
}

void VentanaHorno::on_checkBandeja1_toggled(bool checked)
{
    if(checked){
        horno->bandejasPrendidas+=1;
        qDebug("Bandeja 1 prendida");
    }
   else{
        horno->bandejasPrendidas-=1;
        qDebug("Bandeja 1 apagada");
    }
}

void VentanaHorno::on_checkBandeja2_toggled(bool checked)
{
    if(checked){
        horno->bandejasPrendidas+=1;
        qDebug("Bandeja 2 prendida");
    }
   else{
        horno->bandejasPrendidas-=1;
        qDebug("Bandeja 2 apagada");
    }
}

void VentanaHorno::on_checkBandeja3_toggled(bool checked)
{
    if(checked){
        horno->bandejasPrendidas+=1;
        qDebug("Bandeja 3 prendida");
    }
   else{
        horno->bandejasPrendidas-=1;
        qDebug("Bandeja 3 apagada");
    }
}

void VentanaHorno::on_checkBandeja4_toggled(bool checked)
{
    if(checked){
        horno->bandejasPrendidas+=1;
        qDebug("Bandeja 4 prendida");
    }
   else{
        horno->bandejasPrendidas-=1;
        qDebug("Bandeja 4 apagada");
    }
}

void VentanaHorno::on_checkBandeja5_toggled(bool checked)
{
    if(checked){
        horno->bandejasPrendidas+=1;
        qDebug("Bandeja 5 prendida");
    }
   else{
        horno->bandejasPrendidas-=1;
        qDebug("Bandeja 5 apagada");
    }
}

void VentanaHorno::on_checkBandeja6_toggled(bool checked)
{
    if(checked){
        horno->bandejasPrendidas+=1;
        qDebug("Bandeja 6 prendida");
    }
   else{
        horno->bandejasPrendidas-=1;
        qDebug("Bandeja 6 apagada");
    }
}
