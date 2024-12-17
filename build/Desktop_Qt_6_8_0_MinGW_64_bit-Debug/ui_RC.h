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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RC
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *rc1;
    QPushButton *rc2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *rutaC;

    void setupUi(QWidget *RC)
    {
        if (RC->objectName().isEmpty())
            RC->setObjectName("RC");
        RC->resize(745, 652);
        horizontalLayoutWidget = new QWidget(RC);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(230, 10, 301, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rc1 = new QPushButton(horizontalLayoutWidget);
        rc1->setObjectName("rc1");

        horizontalLayout->addWidget(rc1);

        rc2 = new QPushButton(horizontalLayoutWidget);
        rc2->setObjectName("rc2");

        horizontalLayout->addWidget(rc2);

        verticalLayoutWidget = new QWidget(RC);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 100, 741, 551));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setScaledContents(true);

        verticalLayout->addWidget(label);

        rutaC = new QLabel(verticalLayoutWidget);
        rutaC->setObjectName("rutaC");
        rutaC->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(rutaC);


        retranslateUi(RC);

        QMetaObject::connectSlotsByName(RC);
    } // setupUi

    void retranslateUi(QWidget *RC)
    {
        RC->setWindowTitle(QCoreApplication::translate("RC", "Form", nullptr));
        rc1->setText(QCoreApplication::translate("RC", "RC_C1", nullptr));
        rc2->setText(QCoreApplication::translate("RC", "RC_C2", nullptr));
        label->setText(QString());
        rutaC->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RC: public Ui_RC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RC_H
