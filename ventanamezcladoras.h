#ifndef VENTANAMEZCLADORAS_H
#define VENTANAMEZCLADORAS_H

#include <QMainWindow>

namespace Ui {
class VentanaMezcladoras;
}

class VentanaMezcladoras : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaMezcladoras(QWidget *parent = 0);
    ~VentanaMezcladoras();

private slots:
    void on_configurar_clicked();

    void on_aceptar_clicked();

private:
    Ui::VentanaMezcladoras *ui;
};

#endif // VENTANAMEZCLADORAS_H
