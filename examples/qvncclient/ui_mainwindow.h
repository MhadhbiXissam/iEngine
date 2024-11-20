/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "qvncclientwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *connect_btn;
    QPushButton *disconnect_btn;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *host_edit;
    QGridLayout *gridLayout_2;
    QVNCClientWidget *vncView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(794, 626);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        connect_btn = new QPushButton(centralWidget);
        connect_btn->setObjectName(QString::fromUtf8("connect_btn"));

        gridLayout->addWidget(connect_btn, 3, 0, 1, 1);

        disconnect_btn = new QPushButton(centralWidget);
        disconnect_btn->setObjectName(QString::fromUtf8("disconnect_btn"));

        gridLayout->addWidget(disconnect_btn, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        host_edit = new QLineEdit(centralWidget);
        host_edit->setObjectName(QString::fromUtf8("host_edit"));

        horizontalLayout->addWidget(host_edit);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        vncView = new QVNCClientWidget(centralWidget);
        vncView->setObjectName(QString::fromUtf8("vncView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(vncView->sizePolicy().hasHeightForWidth());
        vncView->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(vncView, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        connect_btn->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        disconnect_btn->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Host :", nullptr));
        host_edit->setText(QCoreApplication::translate("MainWindow", "192.168.56.101", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
