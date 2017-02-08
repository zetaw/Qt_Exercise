#include "dialog.h"
#include "ui_dialog.h"
#include <stdio.h>
#include <QString>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    close();
}

void Dialog::receiveData(int Data){
    QString t,u;
    t="Your steps:";
    u=QString::number(Data);
    t+=u;
    ui->label_2->setText(t);
}
