#ifndef VENTANAENSAMBLADORA_H
#define VENTANAENSAMBLADORA_H

#include <QMainWindow>

#include "ensambladora.h"

namespace Ui {
class ventanaEnsambladora;
}

class ventanaEnsambladora : public QMainWindow
{
    Q_OBJECT

public:
    explicit ventanaEnsambladora(QWidget *parent = 0, Ensambladora* pEnsambladora = 0);
    ~ventanaEnsambladora();

private slots:
    void on_configurar_clicked();

    void on_aceptar_clicked();

    void actualizarVentana();

private:
    Ui::ventanaEnsambladora *ui;
    Ensambladora* ensambladora;
};

#endif // VENTANAENSAMBLADORA_H
