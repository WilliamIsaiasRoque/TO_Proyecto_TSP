/********************************************************************************
** Form generated from reading UI file 'RC.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RC_H
#define UI_RC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RC
{
public:
    QPushButton *rc1;
    QPushButton *rc2;
    QLabel *label;

    void setupUi(QWidget *RC)
    {
        if (RC->objectName().isEmpty())
            RC->setObjectName("RC");
        RC->resize(586, 689);
        rc1 = new QPushButton(RC);
        rc1->setObjectName("rc1");
        rc1->setGeometry(QRect(120, 60, 75, 24));
        rc2 = new QPushButton(RC);
        rc2->setObjectName("rc2");
        rc2->setGeometry(QRect(360, 60, 75, 24));
        label = new QLabel(RC);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 110, 561, 491));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/images/RC_C1.jpg")));
        label->setScaledContents(true);

        retranslateUi(RC);

        QMetaObject::connectSlotsByName(RC);
    } // setupUi

    void retranslateUi(QWidget *RC)
    {
        RC->setWindowTitle(QCoreApplication::translate("RC", "Form", nullptr));
        rc1->setText(QCoreApplication::translate("RC", "RC_C1", nullptr));
        rc2->setText(QCoreApplication::translate("RC", "RC_C2", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RC: public Ui_RC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RC_H
