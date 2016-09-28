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
};

#endif // VENTANAPRINCIPAL_H
