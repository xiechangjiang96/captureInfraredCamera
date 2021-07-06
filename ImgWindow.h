/********************************************************************************
** Form generated from reading UI file 'ImgWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef IMGWINDOW_H
#define IMGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ImgLabel.h"

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    ImgLabel *label;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditPos;
    QLineEdit *lineEdiTemperature;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(784, 498);
        Form->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new ImgLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(640, 480));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(36, 23));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(36, 23));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEditPos = new QLineEdit(Form);
        lineEditPos->setObjectName(QString::fromUtf8("lineEditPos"));
        lineEditPos->setMinimumSize(QSize(70, 23));
        lineEditPos->setEchoMode(QLineEdit::Normal);
        lineEditPos->setAlignment(Qt::AlignCenter);
        lineEditPos->setReadOnly(true);

        verticalLayout_2->addWidget(lineEditPos);

        lineEdiTemperature = new QLineEdit(Form);
        lineEdiTemperature->setObjectName(QString::fromUtf8("lineEdiTemperature"));
        lineEdiTemperature->setMinimumSize(QSize(70, 0));
        lineEdiTemperature->setAlignment(Qt::AlignCenter);
        lineEdiTemperature->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdiTemperature);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "New Window", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("Form", "(x,y):", nullptr));
        label_3->setText(QApplication::translate("Form", "\346\270\251\345\272\246\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // IMGWINDOW_H
