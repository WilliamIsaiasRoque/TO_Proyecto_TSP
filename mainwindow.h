#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ra.h"
#include "rb.h"
#include "rc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget *currentWidget; // Widget dinámico actualmente cargado

    void clearLayout(QLayout *layout); // Función para limpiar el layout

private slots:
    void loadRA();
    void loadRB();
    void loadRC();
};

#endif // MAINWINDOW_H
