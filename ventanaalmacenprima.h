#ifndef VENTANAALMACENPRIMA_H
#define VENTANAALMACENPRIMA_H

#include <QMainWindow>

namespace Ui {
class VentanaAlmacenPrima;
}

class VentanaAlmacenPrima : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaAlmacenPrima(QWidget *parent = 0);
    ~VentanaAlmacenPrima();

private:
    Ui::VentanaAlmacenPrima *ui;
};

#endif // VENTANAALMACENPRIMA_H
