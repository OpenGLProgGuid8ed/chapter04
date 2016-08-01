/********************************************************************************
** Form generated from reading UI file 'shadowmap.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHADOWMAP_H
#define UI_SHADOWMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shadowMapClass
{
public:

    void setupUi(QWidget *shadowMapClass)
    {
        if (shadowMapClass->objectName().isEmpty())
            shadowMapClass->setObjectName(QStringLiteral("shadowMapClass"));
        shadowMapClass->resize(600, 400);

        retranslateUi(shadowMapClass);

        QMetaObject::connectSlotsByName(shadowMapClass);
    } // setupUi

    void retranslateUi(QWidget *shadowMapClass)
    {
        shadowMapClass->setWindowTitle(QApplication::translate("shadowMapClass", "shadowMap", 0));
    } // retranslateUi

};

namespace Ui {
    class shadowMapClass: public Ui_shadowMapClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHADOWMAP_H
