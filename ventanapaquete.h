#ifndef VENTANAPAQUETE_H
#define VENTANAPAQUETE_H

#include <QWidget>
#include "listagalletas.h"

namespace Ui {
class VentanaPaquete;
}

class VentanaPaquete : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaPaquete(QWidget *parent = 0, ListaGalletas* pLista = 0);
    ~VentanaPaquete();


signals:
    void actualizarPlanificador();

private slots:
    void on_aceptar_clicked();

    void on_cancelar_clicked();

private:
    Ui::VentanaPaquete *ui;
    ListaGalletas* listaGalletas;
};

#endif // VENTANAPAQUETE_H
