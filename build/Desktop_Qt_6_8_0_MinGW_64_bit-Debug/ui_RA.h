/********************************************************************************
** Form generated from reading UI file 'RA.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RA_H
#define UI_RA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RA
{
public:
    QPushButton *pb1;
    QPushButton *pb2;
    QLabel *label;

    void setupUi(QWidget *RA)
    {
        if (RA->objectName().isEmpty())
            RA->setObjectName("RA");
        RA->resize(542, 639);
        pb1 = new QPushButton(RA);
        pb1->setObjectName("pb1");
        pb1->setGeometry(QRect(100, 70, 75, 24));
        pb2 = new QPushButton(RA);
        pb2->setObjectName("pb2");
        pb2->setGeometry(QRect(330, 70, 75, 24));
        label = new QLabel(RA);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 120, 521, 491));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/images/RA_C1.jpg")));
        label->setScaledContents(true);

        retranslateUi(RA);

        QMetaObject::connectSlotsByName(RA);
    } // setupUi

    void retranslateUi(QWidget *RA)
    {
        RA->setWindowTitle(QCoreApplication::translate("RA", "Form", nullptr));
        pb1->setText(QCoreApplication::translate("RA", "RA_C1", nullptr));
        pb2->setText(QCoreApplication::translate("RA", "RA_C2", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RA: public Ui_RA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RA_H
