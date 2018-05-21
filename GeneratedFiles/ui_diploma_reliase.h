/********************************************************************************
** Form generated from reading UI file 'diploma_reliase.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIPLOMA_RELIASE_H
#define UI_DIPLOMA_RELIASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Diploma_ReliaseClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Diploma_ReliaseClass)
    {
        if (Diploma_ReliaseClass->objectName().isEmpty())
            Diploma_ReliaseClass->setObjectName(QStringLiteral("Diploma_ReliaseClass"));
        Diploma_ReliaseClass->resize(600, 400);
        menuBar = new QMenuBar(Diploma_ReliaseClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Diploma_ReliaseClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Diploma_ReliaseClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Diploma_ReliaseClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Diploma_ReliaseClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Diploma_ReliaseClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Diploma_ReliaseClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Diploma_ReliaseClass->setStatusBar(statusBar);

        retranslateUi(Diploma_ReliaseClass);

        QMetaObject::connectSlotsByName(Diploma_ReliaseClass);
    } // setupUi

    void retranslateUi(QMainWindow *Diploma_ReliaseClass)
    {
        Diploma_ReliaseClass->setWindowTitle(QApplication::translate("Diploma_ReliaseClass", "Diploma_Reliase", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Diploma_ReliaseClass: public Ui_Diploma_ReliaseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIPLOMA_RELIASE_H
