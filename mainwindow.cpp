#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap> // Necesario para manejar imágenes

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentWidget(nullptr) // Inicializa currentWidget como nullptr
{
    ui->setupUi(this);

    // Imagen inicial opcional
    QPixmap initialImage(":/images/images/logo.jpg");
    ui->label->setPixmap(initialImage);
    ui->label->setScaledContents(true);

    // Conexión del botón RA
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::loadRA);

    // Conexión del botón RB
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::loadRB);

    // Conexión del botón RC
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::loadRC);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Función para limpiar el layout antes de cargar un nuevo widget
void MainWindow::clearLayout(QLayout *layout)
{
    if (currentWidget) {
        layout->removeWidget(currentWidget);
        delete currentWidget; // Elimina el widget actual
        currentWidget = nullptr;
    }
}

// Cargar el widget RA en el layout y cambiar la imagen
void MainWindow::loadRA()
{
    clearLayout(ui->verticalLayout_2);
    currentWidget = new RA(this); // Crea el widget RA
    ui->verticalLayout_2->addWidget(currentWidget);

    // Cambia la imagen en el QLabel
    QPixmap imageRA(":/images/images/RA.jpg");
    ui->label->setPixmap(imageRA);
    ui->label->setScaledContents(true);
}

// Cargar el widget RB en el layout y cambiar la imagen
void MainWindow::loadRB()
{
    clearLayout(ui->verticalLayout_2);
    currentWidget = new RB(this); // Crea el widget RB
    ui->verticalLayout_2->addWidget(currentWidget);

    // Cambia la imagen en el QLabel
    QPixmap imageRB(":/images/images/RB.jpg");
    ui->label->setPixmap(imageRB);
    ui->label->setScaledContents(true);
}

// Cargar el widget RC en el layout y cambiar la imagen
void MainWindow::loadRC()
{
    clearLayout(ui->verticalLayout_2);
    currentWidget = new RC(this); // Crea el widget RC
    ui->verticalLayout_2->addWidget(currentWidget);

    // Cambia la imagen en el QLabel
    QPixmap imageRC(":/images/images/RC.jpg");
    ui->label->setPixmap(imageRC);
    ui->label->setScaledContents(true);
}
