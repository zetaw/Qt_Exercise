/********************************************************************************
** Form generated from reading UI file 'body3.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BODY3_H
#define UI_BODY3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_body3
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;

    void setupUi(QWidget *body3)
    {
        if (body3->objectName().isEmpty())
            body3->setObjectName(QStringLiteral("body3"));
        body3->resize(400, 300);
        pushButton = new QPushButton(body3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 30, 81, 81));
        pushButton->setStyleSheet(QStringLiteral("font: 24pt \"Sans Serif\";"));
        pushButton_2 = new QPushButton(body3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 30, 81, 81));
        pushButton_2->setStyleSheet(QStringLiteral("font: 24pt \"Sans Serif\";"));
        pushButton_3 = new QPushButton(body3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(230, 30, 81, 81));
        pushButton_3->setStyleSheet(QStringLiteral("font: 24pt \"Sans Serif\";"));
        pushButton_4 = new QPushButton(body3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(70, 110, 81, 81));
        pushButton_4->setStyleSheet(QStringLiteral("font: 24pt \"Sans Serif\";"));
        pushButton_5 = new QPushButton(body3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(150, 110, 81, 81));
        pushButton_5->setStyleSheet(QStringLiteral("font: 24pt \"Sans Serif\";"));
        pushButton_6 = new QPushButton(body3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(230, 110, 81, 81));
        pushButton_6->setStyleSheet(QStringLiteral("font: 24pt \"Sans Serif\";"));
        pushButton_7 = new QPushButton(body3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(70, 190, 81, 81));
        pushButton_7->setStyleSheet(QStringLiteral("font: 24pt \"Sans Serif\";"));
        pushButton_8 = new QPushButton(body3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(150, 190, 81, 81));
        pushButton_8->setStyleSheet(QStringLiteral("font: 24pt \"Sans Serif\";"));
        pushButton_9 = new QPushButton(body3);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(230, 190, 81, 81));
        pushButton_9->setStyleSheet(QStringLiteral("font: 24pt \"Sans Serif\";"));

        retranslateUi(body3);

        QMetaObject::connectSlotsByName(body3);
    } // setupUi

    void retranslateUi(QWidget *body3)
    {
        body3->setWindowTitle(QApplication::translate("body3", "gaming", 0));
        pushButton->setText(QApplication::translate("body3", "0", 0));
        pushButton_2->setText(QApplication::translate("body3", "8", 0));
        pushButton_3->setText(QApplication::translate("body3", "4", 0));
        pushButton_4->setText(QApplication::translate("body3", "3", 0));
        pushButton_5->setText(QApplication::translate("body3", "6", 0));
        pushButton_6->setText(QApplication::translate("body3", "7", 0));
        pushButton_7->setText(QApplication::translate("body3", "1", 0));
        pushButton_8->setText(QApplication::translate("body3", "2", 0));
        pushButton_9->setText(QApplication::translate("body3", "5", 0));
    } // retranslateUi

};

namespace Ui {
    class body3: public Ui_body3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BODY3_H
