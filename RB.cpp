#include "RB.h"
#include "ui_RB.h" // En RB.cpp
#include "rutas.h"

Ruta rutaBCamion1("Ruta B - Camion 1", {
                                           {0,   542, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 48},   // Nodo 1
                                           {542, 0,   540, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 600, INF}, // Nodo 2
                                           {INF, 540, 0,   143, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 3
                                           {INF, INF, 143, 0,   182, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 4
                                           {INF, INF, INF, 182, 0,   140, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 5
                                           {INF, INF, INF, INF, 140, 0,   275, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 6
                                           {INF, INF, INF, INF, INF, 275, 0,   66,  INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 7
                                           {INF, INF, INF, INF, INF, INF, 66,  0,   341, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 8
                                           {INF, INF, INF, INF, INF, INF, INF, 341, 0,   80,  INF, INF, INF, INF, INF, INF, INF, INF, INF}, // Nodo 9
                                           {INF, INF, INF, INF, INF, INF, INF, INF, 80,  0,   239, INF, INF, 422, INF, INF, INF, INF, INF}, // Nodo 10
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, 239, 0,   300, INF, INF, INF, INF, INF, INF, INF}, // Nodo 11
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 300, 0,   316, INF, INF, INF, INF, INF, INF}, // Nodo 12
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 316, 0,   324, INF, INF, INF, INF, INF}, // Nodo 13
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, 422, INF, INF, 324, 0,   112, INF, 370, INF, INF}, // Nodo 14
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 112, 0,   342, INF, INF, INF}, // Nodo 15
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 342, 0,   204, INF, INF}, // Nodo 16
                                           {INF, 600, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 370, INF, 204, 0,   508, INF}, // Nodo 17
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 508, 0,   400}, // Nodo 18
                                           {48,  INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 400, 0}    // Nodo 19
                                       });

RB::RB(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RB)
{
    ui->setupUi(this);
    connect(ui->pb1, &QPushButton::clicked, this, &RB::mostrarImagenC1);
}

RB::~RB()
{
    delete ui;
}

void RB::mostrarImagenC1()
{
    // Cambiar la imagen del QLabel a RB_C1.jpg
    QPixmap imageC1(":/images/images/RB_C1.jpg");
    ui->label->setPixmap(imageC1);
    ui->label->setScaledContents(true);

    // Mostrar resultados en QLabel
    QString textoRuta = resolverYmostrar(rutaBCamion1);
    ui->rutaB->setText(textoRuta);
    ui->rutaB->setWordWrap(true);
}
