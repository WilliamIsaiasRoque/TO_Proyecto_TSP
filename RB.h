#ifndef RB_H
#define RB_H

#include <QWidget>

namespace Ui {
class RB;
}

class RB : public QWidget
{
    Q_OBJECT

public:
    explicit RB(QWidget *parent = nullptr);

    void mostrarImagenC1();
    ~RB();

private:
    Ui::RB *ui;
};

#endif // RB_H
