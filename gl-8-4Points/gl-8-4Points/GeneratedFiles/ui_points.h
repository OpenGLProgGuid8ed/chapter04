/********************************************************************************
** Form generated from reading UI file 'points.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTS_H
#define UI_POINTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PointsClass
{
public:

    void setupUi(QWidget *PointsClass)
    {
        if (PointsClass->objectName().isEmpty())
            PointsClass->setObjectName(QStringLiteral("PointsClass"));
        PointsClass->resize(600, 400);

        retranslateUi(PointsClass);

        QMetaObject::connectSlotsByName(PointsClass);
    } // setupUi

    void retranslateUi(QWidget *PointsClass)
    {
        PointsClass->setWindowTitle(QApplication::translate("PointsClass", "Points", 0));
    } // retranslateUi

};

namespace Ui {
    class PointsClass: public Ui_PointsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTS_H
