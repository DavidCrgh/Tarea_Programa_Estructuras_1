#ifndef VENTANAMEZCLADORAS_H
#define VENTANAMEZCLADORAS_H

#include <QMainWindow>

#include "mezcladoramasa.h"
#include "mezcladorachocolate.h"

namespace Ui {
class VentanaMezcladoras;
}

class VentanaMezcladoras : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaMezcladoras(QWidget *parent = 0, MezcladoraMasa* pMezcladora = 0);
    explicit VentanaMezcladoras(QWidget *parent = 0, MezcladoraChocolate* pMezcladora = 0);
    ~VentanaMezcladoras();

private slots:
    void on_configurar_clicked();

    void on_aceptar_clicked();

private:
    Ui::VentanaMezcladoras *ui;
    MezcladoraMasa* mezcladoraMasa;
    MezcladoraChocolate* mezcladoraChocolate;
};

#endif // VENTANAMEZCLADORAS_H
