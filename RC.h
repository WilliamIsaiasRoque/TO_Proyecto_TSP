#ifndef RC_H
#define RC_H

#include <QWidget>

namespace Ui {
class RC;
}

class RC : public QWidget
{
    Q_OBJECT

public:
    explicit RC(QWidget *parent = nullptr);
    ~RC();

private slots:
    void mostrarImagenC1(); // Mostrar imagen RC_C1
    void mostrarImagenC2(); // Mostrar imagen RC_C2

private:
    Ui::RC *ui;
};

#endif // RC_H
