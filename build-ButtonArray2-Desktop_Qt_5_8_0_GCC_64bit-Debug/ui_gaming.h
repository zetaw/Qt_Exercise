/********************************************************************************
** Form generated from reading UI file 'gaming.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMING_H
#define UI_GAMING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gaming
{
public:

    void setupUi(QWidget *gaming)
    {
        if (gaming->objectName().isEmpty())
            gaming->setObjectName(QStringLiteral("gaming"));
        gaming->resize(400, 300);

        retranslateUi(gaming);

        QMetaObject::connectSlotsByName(gaming);
    } // setupUi

    void retranslateUi(QWidget *gaming)
    {
        gaming->setWindowTitle(QApplication::translate("gaming", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gaming: public Ui_gaming {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMING_H
