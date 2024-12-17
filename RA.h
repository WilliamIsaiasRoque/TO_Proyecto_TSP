#ifndef RA_H
#define RA_H

#include <QWidget>

namespace Ui {
class RA;
}

class RA : public QWidget
{
    Q_OBJECT

public:
    explicit RA(QWidget *parent = nullptr);
    ~RA();

private slots:
    void mostrarImagenC1(); // Mostrar imagen RA_C1
    void mostrarImagenC2(); // Mostrar imagen RA_C2

private:
    Ui::RA *ui;
};

#endif // RA_H


