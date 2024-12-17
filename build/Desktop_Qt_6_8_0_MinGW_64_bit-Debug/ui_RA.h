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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RA
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb1;
    QPushButton *pb2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *rutaA;

    void setupUi(QWidget *RA)
    {
        if (RA->objectName().isEmpty())
            RA->setObjectName("RA");
        RA->resize(745, 652);
        horizontalLayoutWidget = new QWidget(RA);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(210, 0, 321, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pb1 = new QPushButton(horizontalLayoutWidget);
        pb1->setObjectName("pb1");

        horizontalLayout->addWidget(pb1);

        pb2 = new QPushButton(horizontalLayoutWidget);
        pb2->setObjectName("pb2");

        horizontalLayout->addWidget(pb2);

        verticalLayoutWidget = new QWidget(RA);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 60, 741, 591));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setScaledContents(true);

        verticalLayout_2->addWidget(label);

        rutaA = new QLabel(verticalLayoutWidget);
        rutaA->setObjectName("rutaA");
        rutaA->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(rutaA);


        retranslateUi(RA);

        QMetaObject::connectSlotsByName(RA);
    } // setupUi

    void retranslateUi(QWidget *RA)
    {
        RA->setWindowTitle(QCoreApplication::translate("RA", "Form", nullptr));
        pb1->setText(QCoreApplication::translate("RA", "RA_C1", nullptr));
        pb2->setText(QCoreApplication::translate("RA", "RA_C2", nullptr));
        label->setText(QString());
        rutaA->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RA: public Ui_RA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RA_H
