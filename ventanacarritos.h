#ifndef VENTANACARRITOS_H
#define VENTANACARRITOS_H

#include <QWidget>

namespace Ui {
class VentanaCarritos;
}

class VentanaCarritos : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaCarritos(QWidget *parent = 0);
    ~VentanaCarritos();

private:
    Ui::VentanaCarritos *ui;
};

#endif // VENTANACARRITOS_H
