/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *labelMat;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnConnect;
    QPushButton *btnSnapshot;
    QPushButton *btnStartRecord;
    QPushButton *btnStopRecord;
    QComboBox *comboBoxPos;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditPos0;
    QLineEdit *lineEditTemperature0;
    QLineEdit *lineEditPos1;
    QLineEdit *lineEditTemperature1;
    QLineEdit *lineEditPos2;
    QLineEdit *lineEditTemperature2;
    QLineEdit *lineEditPos3;
    QLineEdit *lineEditTemperature3;
    QLineEdit *lineEditPos4;
    QLineEdit *lineEditTemperature4;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(842, 799);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, -1, -1);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(640, 480));
        label->setMaximumSize(QSize(516, 535));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        labelMat = new QLabel(centralwidget);
        labelMat->setObjectName(QString::fromUtf8("labelMat"));
        labelMat->setMinimumSize(QSize(640, 480));
        labelMat->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(labelMat, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        btnConnect = new QPushButton(centralwidget);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));

        verticalLayout_3->addWidget(btnConnect);

        btnSnapshot = new QPushButton(centralwidget);
        btnSnapshot->setObjectName(QString::fromUtf8("btnSnapshot"));

        verticalLayout_3->addWidget(btnSnapshot);

        btnStartRecord = new QPushButton(centralwidget);
        btnStartRecord->setObjectName(QString::fromUtf8("btnStartRecord"));

        verticalLayout_3->addWidget(btnStartRecord);

        btnStopRecord = new QPushButton(centralwidget);
        btnStopRecord->setObjectName(QString::fromUtf8("btnStopRecord"));

        verticalLayout_3->addWidget(btnStopRecord);

        comboBoxPos = new QComboBox(centralwidget);
        comboBoxPos->addItem(QString());
        comboBoxPos->addItem(QString());
        comboBoxPos->addItem(QString());
        comboBoxPos->addItem(QString());
        comboBoxPos->addItem(QString());
        comboBoxPos->setObjectName(QString::fromUtf8("comboBoxPos"));

        verticalLayout_3->addWidget(comboBoxPos);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(36, 23));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(36, 23));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(36, 23));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(36, 23));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_8);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(36, 23));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(36, 23));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_9);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(36, 23));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(36, 23));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_10);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(36, 23));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_7);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(36, 23));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_11);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEditPos0 = new QLineEdit(centralwidget);
        lineEditPos0->setObjectName(QString::fromUtf8("lineEditPos0"));
        lineEditPos0->setMinimumSize(QSize(70, 23));
        lineEditPos0->setReadOnly(true);

        verticalLayout_2->addWidget(lineEditPos0);

        lineEditTemperature0 = new QLineEdit(centralwidget);
        lineEditTemperature0->setObjectName(QString::fromUtf8("lineEditTemperature0"));
        lineEditTemperature0->setMinimumSize(QSize(70, 23));
        lineEditTemperature0->setReadOnly(true);

        verticalLayout_2->addWidget(lineEditTemperature0);

        lineEditPos1 = new QLineEdit(centralwidget);
        lineEditPos1->setObjectName(QString::fromUtf8("lineEditPos1"));
        lineEditPos1->setMinimumSize(QSize(70, 23));
        lineEditPos1->setReadOnly(true);

        verticalLayout_2->addWidget(lineEditPos1);

        lineEditTemperature1 = new QLineEdit(centralwidget);
        lineEditTemperature1->setObjectName(QString::fromUtf8("lineEditTemperature1"));
        lineEditTemperature1->setMinimumSize(QSize(70, 23));
        lineEditTemperature1->setReadOnly(true);

        verticalLayout_2->addWidget(lineEditTemperature1);

        lineEditPos2 = new QLineEdit(centralwidget);
        lineEditPos2->setObjectName(QString::fromUtf8("lineEditPos2"));
        lineEditPos2->setMinimumSize(QSize(70, 23));
        lineEditPos2->setReadOnly(true);

        verticalLayout_2->addWidget(lineEditPos2);

        lineEditTemperature2 = new QLineEdit(centralwidget);
        lineEditTemperature2->setObjectName(QString::fromUtf8("lineEditTemperature2"));
        lineEditTemperature2->setMinimumSize(QSize(70, 23));
        lineEditTemperature2->setReadOnly(true);

        verticalLayout_2->addWidget(lineEditTemperature2);

        lineEditPos3 = new QLineEdit(centralwidget);
        lineEditPos3->setObjectName(QString::fromUtf8("lineEditPos3"));
        lineEditPos3->setMinimumSize(QSize(70, 23));
        lineEditPos3->setReadOnly(true);

        verticalLayout_2->addWidget(lineEditPos3);

        lineEditTemperature3 = new QLineEdit(centralwidget);
        lineEditTemperature3->setObjectName(QString::fromUtf8("lineEditTemperature3"));
        lineEditTemperature3->setMinimumSize(QSize(70, 23));
        lineEditTemperature3->setReadOnly(true);

        verticalLayout_2->addWidget(lineEditTemperature3);

        lineEditPos4 = new QLineEdit(centralwidget);
        lineEditPos4->setObjectName(QString::fromUtf8("lineEditPos4"));
        lineEditPos4->setMinimumSize(QSize(70, 23));
        lineEditPos4->setReadOnly(true);

        verticalLayout_2->addWidget(lineEditPos4);

        lineEditTemperature4 = new QLineEdit(centralwidget);
        lineEditTemperature4->setObjectName(QString::fromUtf8("lineEditTemperature4"));
        lineEditTemperature4->setMinimumSize(QSize(70, 23));
        lineEditTemperature4->setReadOnly(true);

        verticalLayout_2->addWidget(lineEditTemperature4);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        gridLayout_2->addLayout(verticalLayout_3, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 842, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        labelMat->setText(QString());
        btnConnect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        btnSnapshot->setText(QApplication::translate("MainWindow", "\345\277\253\347\205\247", nullptr));
        btnStartRecord->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\275\225\345\210\266", nullptr));
        btnStopRecord->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237\345\275\225\345\210\266", nullptr));
        comboBoxPos->setItemText(0, QApplication::translate("MainWindow", "0", nullptr));
        comboBoxPos->setItemText(1, QApplication::translate("MainWindow", "1", nullptr));
        comboBoxPos->setItemText(2, QApplication::translate("MainWindow", "2", nullptr));
        comboBoxPos->setItemText(3, QApplication::translate("MainWindow", "3", nullptr));
        comboBoxPos->setItemText(4, QApplication::translate("MainWindow", "4", nullptr));

        label_2->setText(QApplication::translate("MainWindow", "\347\202\2710\357\274\232", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\357\274\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\347\202\2711\357\274\232", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\357\274\232", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\347\202\2712\357\274\232", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\357\274\232", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\347\202\2713\357\274\232", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\357\274\232", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\347\202\2714\357\274\232", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
