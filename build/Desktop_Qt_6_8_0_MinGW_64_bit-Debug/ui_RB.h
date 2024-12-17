/********************************************************************************
** Form generated from reading UI file 'RB.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RB_H
#define UI_RB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RB
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *rutaB;
    QPushButton *pb1;

    void setupUi(QWidget *RB)
    {
        if (RB->objectName().isEmpty())
            RB->setObjectName("RB");
        RB->resize(745, 652);
        verticalLayoutWidget = new QWidget(RB);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 70, 741, 581));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setScaledContents(true);

        verticalLayout->addWidget(label);

        rutaB = new QLabel(verticalLayoutWidget);
        rutaB->setObjectName("rutaB");
        rutaB->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(rutaB);

        pb1 = new QPushButton(RB);
        pb1->setObjectName("pb1");
        pb1->setGeometry(QRect(290, 20, 201, 24));

        retranslateUi(RB);

        QMetaObject::connectSlotsByName(RB);
    } // setupUi

    void retranslateUi(QWidget *RB)
    {
        RB->setWindowTitle(QCoreApplication::translate("RB", "Form", nullptr));
        label->setText(QString());
        rutaB->setText(QString());
        pb1->setText(QCoreApplication::translate("RB", "RB_C1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RB: public Ui_RB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RB_H
