#include "ra.h"
#include "ui_RA.h"

RA::RA(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RA)
{
    ui->setupUi(this);

    // Conectar los botones pb1 y pb2 para cambiar la imagen en el QLabel
    connect(ui->pb1, &QPushButton::clicked, this, &RA::mostrarImagenC1);
    connect(ui->pb2, &QPushButton::clicked, this, &RA::mostrarImagenC2);
}

RA::~RA()
{
    delete ui;
}

void RA::mostrarImagenC1()
{
    // Cambiar la imagen del QLabel a RA_C1.jpg
    QPixmap imageC1(":/images/images/RA_C1.jpg");
    ui->label->setPixmap(imageC1);
    ui->label->setScaledContents(true);
}

void RA::mostrarImagenC2()
{
    // Cambiar la imagen del QLabel a RA_C2.jpg
    QPixmap imageC2(":/images/images/RA_C2.jpg");
    ui->label->setPixmap(imageC2);
    ui->label->setScaledContents(true);
}
