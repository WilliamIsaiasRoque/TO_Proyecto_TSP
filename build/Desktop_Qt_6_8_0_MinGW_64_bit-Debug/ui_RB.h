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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RB
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *RB)
    {
        if (RB->objectName().isEmpty())
            RB->setObjectName("RB");
        RB->resize(549, 655);
        pushButton = new QPushButton(RB);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(220, 60, 75, 24));
        label = new QLabel(RB);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 100, 531, 491));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/images/RB_C1.jpg")));
        label->setScaledContents(true);

        retranslateUi(RB);

        QMetaObject::connectSlotsByName(RB);
    } // setupUi

    void retranslateUi(QWidget *RB)
    {
        RB->setWindowTitle(QCoreApplication::translate("RB", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("RB", "RB_C1", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RB: public Ui_RB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RB_H
