/********************************************************************************
** Form generated from reading UI file 'cube.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUBE_H
#define UI_CUBE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CubeClass
{
public:

    void setupUi(QWidget *CubeClass)
    {
        if (CubeClass->objectName().isEmpty())
            CubeClass->setObjectName(QStringLiteral("CubeClass"));
        CubeClass->resize(600, 400);

        retranslateUi(CubeClass);

        QMetaObject::connectSlotsByName(CubeClass);
    } // setupUi

    void retranslateUi(QWidget *CubeClass)
    {
        CubeClass->setWindowTitle(QApplication::translate("CubeClass", "Cube", 0));
    } // retranslateUi

};

namespace Ui {
    class CubeClass: public Ui_CubeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUBE_H
