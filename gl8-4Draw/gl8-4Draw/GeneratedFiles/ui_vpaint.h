/********************************************************************************
** Form generated from reading UI file 'vpaint.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VPAINT_H
#define UI_VPAINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VPaintClass
{
public:

    void setupUi(QWidget *VPaintClass)
    {
        if (VPaintClass->objectName().isEmpty())
            VPaintClass->setObjectName(QStringLiteral("VPaintClass"));
        VPaintClass->resize(600, 400);

        retranslateUi(VPaintClass);

        QMetaObject::connectSlotsByName(VPaintClass);
    } // setupUi

    void retranslateUi(QWidget *VPaintClass)
    {
        VPaintClass->setWindowTitle(QApplication::translate("VPaintClass", "VPaint", 0));
    } // retranslateUi

};

namespace Ui {
    class VPaintClass: public Ui_VPaintClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VPAINT_H
