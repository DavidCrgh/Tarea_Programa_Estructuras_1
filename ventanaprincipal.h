#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>

#include "prototipos.h"

#include "simulacion.h"

#include "ventanacarritoentrega.h"
#include "ventanamezcladoras.h"
#include "ventanaensambladora.h"
#include "ventanaalmacenprima.h"
#include "ventanahorno.h"
#include "ventanabanda.h"

namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaPrincipal(QWidget *parent = 0, Simulacion* pSimulacion = 0);
    ~VentanaPrincipal();

public slots:
    void openNewWindow();

private slots:
    void on_botonCarritoEntrega_clicked();

    void on_botonMezcladora1_clicked();

    void on_botonMezcladora2_clicked();

    void on_botonMezcladoraChocolate_clicked();

    void on_botonEnsambladora_clicked();

    void on_botonAlmacenPrima_clicked();

    void on_botonHorno_clicked();

    void on_botonPlay_clicked();

    void on_botonPausa_clicked();

    void on_botonBandaMasa_clicked();

    void on_botonBandaChocolate_clicked();

public:
    Simulacion* simulacion;
    Ui::VentanaPrincipal *ui;
    VentanaCarritoEntrega* ventanaCarrito;
    VentanaMezcladoras* ventanaMezcladora1;
    VentanaMezcladoras* ventanaMezcladora2;
    VentanaMezcladoras* ventanaMezcladoraChocolate;
    ventanaEnsambladora* ventanaEnsambladoraSimulador;
    VentanaAlmacenPrima* ventanaAlmacen;
    VentanaHorno* ventanaHorno;
    VentanaBanda* ventanaBandaMasa;
    VentanaBanda* ventanaBandaChocolate;
    VentanaBanda* ventanaGalletasCrudas;
    VentanaBanda* ventanaGalletasCocinadas;
};

#endif // VENTANAPRINCIPAL_H
