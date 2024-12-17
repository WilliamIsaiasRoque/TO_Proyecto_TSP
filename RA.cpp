#include "ra.h"
#include "ui_RA.h"
#include "rutas.h"

Ruta rutaACamion2("Ruta A - Camion 2", {
                                           {0, 317, INF, INF, INF, INF, 244},
                                           {317, 0, 272, INF, INF, INF, INF},
                                           {INF, 272, 0, 853, INF, INF, INF},
                                           {INF, INF, 853, 0, 377, INF, INF},
                                           {INF, INF, INF, 377, 0, 286, INF},
                                           {INF, INF, INF, INF, 286, 0, 442},
                                           {244, INF, INF, INF, INF, 442, 0}
                                       });

Ruta rutaACamion1("Ruta A - Camion 1", {
                                           {0, 80, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 42},
                                           {80, 0, 276, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF},
                                           {INF, 276, 0, 314, INF, INF, INF, INF, INF, INF, INF, INF, INF},
                                           {INF, INF, 314, 0, 76, INF, 503, INF, INF, INF, INF, INF, INF},
                                           {INF, INF, INF, 76, 0, 522, INF, INF, INF, INF, INF, INF, INF},
                                           {INF, INF, INF, INF, 522, 0, 86, INF, INF, INF, INF, INF, INF},
                                           {INF, INF, INF, 503, INF, 86, 0, 555, INF, INF, INF, INF, INF},
                                           {INF, INF, INF, INF, INF, INF, 555, 0, 107, INF, INF, INF, INF},
                                           {INF, INF, INF, INF, INF, INF, INF, 107, 0, 152, INF, INF, INF},
                                           {INF, INF, INF, INF, INF, INF, INF, INF, 152, 0, 415, INF, INF},
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, 415, 0, 87, INF},
                                           {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 87, 0, 143},
                                           {42, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 143, 0}
                                       });

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
    // Mostrar resultados en QLabel
    QString textoRuta = resolverYmostrar(rutaACamion1);
    ui->rutaA->setText(textoRuta);
    ui->rutaA->setWordWrap(true);

}

void RA::mostrarImagenC2()
{
    // Cambiar la imagen del QLabel a RA_C2.jpg
    QPixmap imageC2(":/images/images/RA_C2.jpg");
    ui->label->setPixmap(imageC2);
    ui->label->setScaledContents(true);

    // Mostrar resultados en QLabel
    QString textoRuta = resolverYmostrar(rutaACamion2);
    ui->rutaA->setText(textoRuta);
    ui->rutaA->setWordWrap(true);
}
