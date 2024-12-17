#include "RC.h"
#include "ui_RC.h"

RC::RC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RC)
{
    ui->setupUi(this);

    // Conectar los botones rc1 y rc2 para cambiar la imagen en el QLabel
    connect(ui->rc1, &QPushButton::clicked, this, &RC::mostrarImagenC1);
    connect(ui->rc2, &QPushButton::clicked, this, &RC::mostrarImagenC2);
}

RC::~RC()
{
    delete ui;
}

void RC::mostrarImagenC1()
{
    // Cambiar la imagen del QLabel a RC_C1.jpg
    QPixmap imageC1(":/images/images/RC_C1.jpg");
    ui->label->setPixmap(imageC1);
    ui->label->setScaledContents(true);
}

void RC::mostrarImagenC2()
{
    // Cambiar la imagen del QLabel a RC_C2.jpg
    QPixmap imageC2(":/images/images/RC_C2.jpg");
    ui->label->setPixmap(imageC2);
    ui->label->setScaledContents(true);
}
