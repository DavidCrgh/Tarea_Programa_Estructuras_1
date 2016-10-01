#ifndef VENTANABANDEJA_H
#define VENTANABANDEJA_H

#include <QWidget>

namespace Ui {
class VentanaBandeja;
}

class VentanaBandeja : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaBandeja(QWidget *parent = 0);
    ~VentanaBandeja();

private:
    Ui::VentanaBandeja *ui;
};

#endif // VENTANABANDEJA_H
