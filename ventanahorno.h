#ifndef VENTANAHORNO_H
#define VENTANAHORNO_H

#include <QMainWindow>

namespace Ui {
class VentanaHorno;
}

class VentanaHorno : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaHorno(QWidget *parent = 0);
    ~VentanaHorno();

private slots:
    void on_encendido_clicked();

    void on_apagado_clicked();

private:
    Ui::VentanaHorno *ui;
};

#endif // VENTANAHORNO_H
