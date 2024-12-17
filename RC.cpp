#include "RC.h"
#include "ui_RC.h"
#include "rutas.h"

Ruta rutaCCamion1("Ruta C - Camion 1", {
                                           {0, 39,  INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 0
                                           {39, 0,  450, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 1
                                           {INF, 450, 0,  143, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 2
                                           {INF, INF, 143, 0,  1142, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 3
                                           {INF, INF, INF, 1142, 0, 401, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 449, INF, INF}, // Nodo 4
                                           {INF, INF, INF, INF, 401, 0, 394, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 5
                                           {INF, INF, INF, INF, INF, 394, 0, 182, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 6
                                           {INF, INF, INF, INF, INF, INF, 182, 0, 128, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 7
                                           {INF, INF, INF, INF, INF, INF, INF, 128, 0, 85, INF, INF, INF, INF, INF, INF, INF, INF, INF},   // Nodo 8
                                           {INF, INF, INF, INF, INF, INF, INF, INF, 85, 0, 209, INF, INF, INF, INF, INF, INF, INF, INF},   // Nodo 9
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, 209, 0, 111, INF, INF, INF, INF, INF, INF, INF},  // Nodo 10
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 111, 0, 289, INF, INF, INF, INF, INF, INF},  // Nodo 11
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 289, 0, 216, INF, INF, INF, INF, INF},  // Nodo 12
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 216, 0, 122, INF, INF, INF, INF},  // Nodo 13
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 122, 0, 250, INF, INF, INF},  // Nodo 14
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 250, 0, 356, INF, INF},  // Nodo 15
                                           {INF, INF, INF, INF, 449, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 356, 0, 481, INF},  // Nodo 16
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 263, INF, INF, 84, 0, INF},   // Nodo 17
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 481, 0}   // Nodo 18
                                       });

Ruta rutaCCamion2("Ruta C - Camion 2", {
                                           {0, 155, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 1
                                           {INF, 0, 413, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 2
                                           {INF, INF, 0, 1635, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 3
                                           {INF, INF, 1635, 0, 979, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 134}, // Nodo 4
                                           {INF, INF, INF, INF, 0, 341, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 5
                                           {INF, INF, INF, INF, INF, 0, 395, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 6
                                           {INF, INF, INF, INF, INF, INF, 0, 170, INF, INF, INF, INF, INF, INF, INF, INF, INF},  // Nodo 7
                                           {INF, INF, INF, INF, INF, INF, INF, 0, 308, INF, INF, 202, INF, INF, INF, INF, INF},  // Nodo 8
                                           {INF, INF, INF, INF, INF, INF, INF, INF, 0, 516, INF, INF, INF, INF, INF, INF, INF},  // Nodo 9
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 284, INF, INF, INF, INF, INF, INF},  // Nodo 10
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 153, INF, INF, INF, INF, INF},  // Nodo 11
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 294, INF, INF, INF, INF},  // Nodo 12
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 304, INF, INF, INF},  // Nodo 13
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 421, INF, INF},  // Nodo 14
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 446, INF},  // Nodo 15
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, 250},  // Nodo 16
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0}   // Nodo 17
                                       });

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
    // Mostrar resultados en QLabel
    QString textoRuta = resolverYmostrar(rutaCCamion1);
    ui->rutaC->setText(textoRuta);
    ui->rutaC->setWordWrap(true);
}

void RC::mostrarImagenC2()
{
    // Cambiar la imagen del QLabel a RC_C2.jpg
    QPixmap imageC2(":/images/images/RC_C2.jpg");
    ui->label->setPixmap(imageC2);
    ui->label->setScaledContents(true);
    // Mostrar resultados en QLabel
    QString textoRuta = resolverYmostrar(rutaCCamion2);
    ui->rutaC->setText(textoRuta);
    ui->rutaC->setWordWrap(true);
}
