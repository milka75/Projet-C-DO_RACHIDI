/********************************************************************************
** Form generated from reading UI file 'resultwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTWINDOW_H
#define UI_RESULTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_ResultWindow
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *customPlot;

    void setupUi(QDialog *ResultWindow)
    {
        if (ResultWindow->objectName().isEmpty())
            ResultWindow->setObjectName(QStringLiteral("ResultWindow"));
        ResultWindow->resize(674, 511);
        gridLayout = new QGridLayout(ResultWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        customPlot = new QCustomPlot(ResultWindow);
        customPlot->setObjectName(QStringLiteral("customPlot"));

        gridLayout->addWidget(customPlot, 0, 0, 1, 1);


        retranslateUi(ResultWindow);

        QMetaObject::connectSlotsByName(ResultWindow);
    } // setupUi

    void retranslateUi(QDialog *ResultWindow)
    {
        ResultWindow->setWindowTitle(QApplication::translate("ResultWindow", "Results", 0));
    } // retranslateUi

};

namespace Ui {
    class ResultWindow: public Ui_ResultWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTWINDOW_H
