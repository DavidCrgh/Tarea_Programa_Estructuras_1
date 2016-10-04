#include "ventanamezcladoras.h"
#include "ui_ventanamezcladoras.h"

VentanaMezcladoras::VentanaMezcladoras(QWidget *parent, MezcladoraMasa* pMezcladora, Simulacion* pSimulacion) :
    QMainWindow(parent),
    ui(new Ui::VentanaMezcladoras)
{
    ui->setupUi(this);
    simulacion = pSimulacion;
    mezcladoraMasa = pMezcladora;
    mezcladoraChocolate = NULL;
}

VentanaMezcladoras::VentanaMezcladoras(QWidget *parent, MezcladoraChocolate* pMezcladora, Simulacion* pSimulacion) :
    QMainWindow(parent),
    ui(new Ui::VentanaMezcladoras)
{
    ui->setupUi(this);
    simulacion = pSimulacion;
    mezcladoraMasa = NULL;
    mezcladoraChocolate = pMezcladora;
}

VentanaMezcladoras::~VentanaMezcladoras()
{
    delete ui;
}

void VentanaMezcladoras::on_configurar_clicked()
{
    ui->editorMinimo->setEnabled(true);
    ui->editorMaximo->setEnabled(true);
    ui->editorCantidad->setEnabled(true);
    ui->editorTiempo->setEnabled(true);
    ui->configurar->setEnabled(false);
    ui->aceptar->setEnabled(true);
}

void VentanaMezcladoras::on_aceptar_clicked()
{
    QString minimo = ui->editorMinimo->text();
    QString maximo = ui->editorMaximo->text();
    QString cantidad = ui->editorCantidad->text();
    QString tiempo = ui->editorTiempo->text();

    if(mezcladoraMasa != NULL){
        mezcladoraMasa->masaMinima = minimo.toFloat();
        mezcladoraMasa->masaMaxima = maximo.toFloat();
        mezcladoraMasa->cantidadxTanda = cantidad.toFloat();
        mezcladoraMasa->tiempo = tiempo.toFloat();
    } else {
        mezcladoraChocolate->mezclaMinima = minimo.toFloat();
        mezcladoraChocolate->mezclaMaxima = maximo.toFloat();
        mezcladoraChocolate->cantidadxTanda = cantidad.toFloat();
        mezcladoraChocolate->tiempo = tiempo.toFloat();
    }
    ui->editorMinimo->setEnabled(false);
    ui->editorMaximo->setEnabled(false);
    ui->editorCantidad->setEnabled(false);
    ui->editorTiempo->setEnabled(false);
    ui->configurar->setEnabled(true);
    ui->aceptar->setEnabled(false);
}

void VentanaMezcladoras::actualizarVentana(){
    QStringList informacion;
    if(mezcladoraMasa != NULL){
        informacion = mezcladoraMasa->imprimirMezcladora();
    } else {
        informacion = mezcladoraChocolate->imprimirMezcladora();
    }
    ui->procesandoValor->setText(informacion[0]);
    ui->procesadoValor->setText(informacion[1]);

    if(mezcladoraMasa == simulacion->mezcladorasMasa[0]){
        ui->encendido->setChecked(!(simulacion->hilosMezcladorasMasa[0]->pause));
        ui->apagado->setChecked(simulacion->hilosMezcladorasMasa[0]->pause);
    } else if(mezcladoraMasa == simulacion->mezcladorasMasa[1]){
        ui->encendido->setChecked(!(simulacion->hilosMezcladorasMasa[1]->pause));
        ui->apagado->setChecked(simulacion->hilosMezcladorasMasa[1]->pause);
    } else {
        ui->encendido->setChecked(!(simulacion->hiloMezcladoraChocolate->pause));
        ui->apagado->setChecked(simulacion->hiloMezcladoraChocolate->pause);
    }

}
