#include "RB.h"

#include "ui_RA.h" // En RA.cpp
#include "ui_RB.h" // En RB.cpp
#include "ui_RC.h" // En RC.cpp

RB::RB(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RB)
{
    ui->setupUi(this);
}

RB::~RB()
{
    delete ui;
}
