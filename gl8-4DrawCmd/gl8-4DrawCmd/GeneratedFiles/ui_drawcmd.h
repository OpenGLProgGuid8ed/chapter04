/********************************************************************************
** Form generated from reading UI file 'drawcmd.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWCMD_H
#define UI_DRAWCMD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrawCmdClass
{
public:

    void setupUi(QWidget *DrawCmdClass)
    {
        if (DrawCmdClass->objectName().isEmpty())
            DrawCmdClass->setObjectName(QStringLiteral("DrawCmdClass"));
        DrawCmdClass->resize(600, 400);

        retranslateUi(DrawCmdClass);

        QMetaObject::connectSlotsByName(DrawCmdClass);
    } // setupUi

    void retranslateUi(QWidget *DrawCmdClass)
    {
        DrawCmdClass->setWindowTitle(QApplication::translate("DrawCmdClass", "DrawCmd", 0));
    } // retranslateUi

};

namespace Ui {
    class DrawCmdClass: public Ui_DrawCmdClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWCMD_H
