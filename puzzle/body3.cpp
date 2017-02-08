#include "body3.h"
#include "ui_body3.h"
#include <QString>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <QPalette>

QPalette pal,pal2;

void body3::init(){
    int a[10],b[10];
    QString t;
    memset(b,0,sizeof(b));
    memset(a,0,sizeof(a));
    int k=rand()%9+1;
    for (int i=1;i<=9;i++) {
        do k=rand()%9;while (b[k]);
        b[k]=1;
        a[i]=k;
    }
    t=QString::number(a[1]);
    ui->pushButton->setText(t);
    t=QString::number(a[2]);
    ui->pushButton_2->setText(t);
    t=QString::number(a[3]);
    ui->pushButton_3->setText(t);
    t=QString::number(a[4]);
    ui->pushButton_4->setText(t);
    t=QString::number(a[5]);
    ui->pushButton_5->setText(t);
    t=QString::number(a[6]);
    ui->pushButton_6->setText(t);
    t=QString::number(a[7]);
    ui->pushButton_7->setText(t);
    t=QString::number(a[8]);
    ui->pushButton_8->setText(t);
    t=QString::number(a[9]);
    ui->pushButton_9->setText(t);
}

body3::body3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::body3)
{
    srand((unsigned)time(NULL));
    ui->setupUi(this);
    pal.setColor(QPalette::ButtonText,QColor(255,0,0));
    pal2.setColor(QPalette::ButtonText,QColor(0,0,0));
    init();
}

body3::~body3()
{
    init();
    delete ui;
}

bool body3::check(){
    if (ui->pushButton->text()=="1"&&ui->pushButton_2->text()=="2"&&
            ui->pushButton_3->text()=="3"&&ui->pushButton_4->text()=="4"&&
            ui->pushButton_5->text()=="5"&&ui->pushButton_6->text()=="6"&&
            ui->pushButton_7->text()=="7"&&ui->pushButton_8->text()=="8"&&
            ui->pushButton_9->text()=="0") return true;
    return false;
}



void body3::on_pushButton_clicked()
{
    QString r,d,t;
    t=ui->pushButton->text();
    d=ui->pushButton_4->text();
    r=ui->pushButton_2->text();
    if (r=="0") {
        ui->pushButton->setText("0");
        ui->pushButton->setPalette(pal);
        ui->pushButton_2->setText(t);
        ui->pushButton_2->setPalette(pal2);
    }
    else if (d=="0") {
        ui->pushButton->setText("0");
        ui->pushButton->setPalette(pal);
        ui->pushButton_4->setText(t);
        ui->pushButton_4->setPalette(pal2);
    }
    if (check()) {dialog.show();init();this->close();}
}

void body3::on_pushButton_2_clicked()
{
    QString l,r,d,t;
    t=ui->pushButton_2->text();
    l=ui->pushButton->text();
    r=ui->pushButton_3->text();
    d=ui->pushButton_5->text();
    if (l=="0") {
        ui->pushButton_2->setText("0");
        ui->pushButton_2->setPalette(pal);
        ui->pushButton->setText(t);
        ui->pushButton->setPalette(pal2);
    }
    else if (r=="0") {
        ui->pushButton_2->setText("0");
        ui->pushButton_2->setPalette(pal);
        ui->pushButton_3->setText(t);
        ui->pushButton_3->setPalette(pal2);
    }
    else if (d=="0") {
        ui->pushButton_2->setText("0");
        ui->pushButton_2->setPalette(pal);
        ui->pushButton_5->setText(t);
        ui->pushButton_5->setPalette(pal2);
    }
    if (check()) {dialog.show();init();this->close();}
}

void body3::on_pushButton_3_clicked()
{
    QString l,d,t;
    t=ui->pushButton_3->text();
    d=ui->pushButton_6->text();
    l=ui->pushButton_2->text();
    if (l=="0") {
        ui->pushButton_3->setText("0");
        ui->pushButton_3->setPalette(pal);
        ui->pushButton_2->setText(t);
        ui->pushButton_2->setPalette(pal2);
    }
    else if (d=="0") {
        ui->pushButton_3->setText("0");
        ui->pushButton_3->setPalette(pal);
        ui->pushButton_6->setText(t);
        ui->pushButton_6->setPalette(pal2);
    }
    if (check()) {dialog.show();init();this->close();}
}

void body3::on_pushButton_4_clicked()
{
    QString u,r,d,t;
    t=ui->pushButton_4->text();
    u=ui->pushButton->text();
    d=ui->pushButton_7->text();
    r=ui->pushButton_5->text();
    if (u=="0") {
        ui->pushButton_4->setText("0");
        ui->pushButton_4->setPalette(pal);
        ui->pushButton->setText(t);
        ui->pushButton->setPalette(pal2);
    }
    else if (r=="0") {
        ui->pushButton_4->setText("0");
        ui->pushButton_4->setPalette(pal);
        ui->pushButton_5->setText(t);
        ui->pushButton_5->setPalette(pal2);
    }
    else if (d=="0") {
        ui->pushButton_4->setText("0");
        ui->pushButton_4->setPalette(pal);
        ui->pushButton_7->setText(t);
        ui->pushButton_7->setPalette(pal2);
    }
    if (check()) {dialog.show();init();this->close();}
}

void body3::on_pushButton_5_clicked()
{
    QString u,r,d,l,t;
    t=ui->pushButton_5->text();
    u=ui->pushButton_2->text();
    d=ui->pushButton_8->text();
    l=ui->pushButton_4->text();
    r=ui->pushButton_6->text();
    if (u=="0") {
        ui->pushButton_5->setText("0");
        ui->pushButton_5->setPalette(pal);
        ui->pushButton_2->setText(t);
        ui->pushButton_2->setPalette(pal2);
    }
    else if (r=="0") {
        ui->pushButton_5->setText("0");
        ui->pushButton_5->setPalette(pal);
        ui->pushButton_6->setText(t);
        ui->pushButton_6->setPalette(pal2);
    }
    else if (d=="0") {
        ui->pushButton_5->setText("0");
        ui->pushButton_5->setPalette(pal);
        ui->pushButton_8->setText(t);
        ui->pushButton_8->setPalette(pal2);
    }
    else if (l=="0") {
        ui->pushButton_5->setText("0");
        ui->pushButton_5->setPalette(pal);
        ui->pushButton_4->setText(t);
        ui->pushButton_4->setPalette(pal2);
    }
    if (check()) {dialog.show();init();this->close();}
}

void body3::on_pushButton_6_clicked()
{
    QString u,l,d,t;
    t=ui->pushButton_6->text();
    u=ui->pushButton_3->text();
    d=ui->pushButton_9->text();
    l=ui->pushButton_5->text();
    if (u=="0") {
        ui->pushButton_6->setText("0");
        ui->pushButton_6->setPalette(pal);
        ui->pushButton_3->setText(t);
        ui->pushButton_3->setPalette(pal2);
    }
    else if (l=="0") {
        ui->pushButton_6->setText("0");
        ui->pushButton_6->setPalette(pal);
        ui->pushButton_5->setText(t);
        ui->pushButton_5->setPalette(pal2);
    }
    else if (d=="0") {
        ui->pushButton_6->setText("0");
        ui->pushButton_6->setPalette(pal);
        ui->pushButton_9->setText(t);
        ui->pushButton_9->setPalette(pal2);
    }
    if (check()) {dialog.show();init();this->close();}
}

void body3::on_pushButton_7_clicked()
{
    QString r,u,t;
    t=ui->pushButton_7->text();
    u=ui->pushButton_4->text();
    r=ui->pushButton_8->text();
    if (u=="0") {
        ui->pushButton_7->setText("0");
        ui->pushButton_7->setPalette(pal);
        ui->pushButton_4->setText(t);
        ui->pushButton_4->setPalette(pal2);
    }
    else if (r=="0") {
        ui->pushButton_7->setText("0");
        ui->pushButton_7->setPalette(pal);
        ui->pushButton_8->setText(t);
        ui->pushButton_8->setPalette(pal2);
    }
    if (check()) {dialog.show();init();this->close();}
}

void body3::on_pushButton_8_clicked()
{
    QString u,l,r,t;
    t=ui->pushButton_8->text();
    l=ui->pushButton_7->text();
    r=ui->pushButton_9->text();
    u=ui->pushButton_5->text();
    if (l=="0") {
        ui->pushButton_8->setText("0");
        ui->pushButton_8->setPalette(pal);
        ui->pushButton_7->setText(t);
        ui->pushButton_7->setPalette(pal2);
    }
    else if (u=="0") {
        ui->pushButton_8->setText("0");
        ui->pushButton_8->setPalette(pal);
        ui->pushButton_5->setText(t);
        ui->pushButton_5->setPalette(pal2);
    }
    else if (r=="0") {
        ui->pushButton_8->setText("0");
        ui->pushButton_8->setPalette(pal);
        ui->pushButton_9->setText(t);
        ui->pushButton_9->setPalette(pal2);
    }
    if (check()) {dialog.show();init();this->close();}
}

void body3::on_pushButton_9_clicked()
{
    QString l,u,t;
    t=ui->pushButton_9->text();
    u=ui->pushButton_6->text();
    l=ui->pushButton_8->text();
    if (u=="0") {
        ui->pushButton_9->setText("0");
        ui->pushButton_9->setPalette(pal);
        ui->pushButton_6->setText(t);
        ui->pushButton_6->setPalette(pal2);
    }
    else if (l=="0") {
        ui->pushButton_9->setText("0");
        ui->pushButton_9->setPalette(pal);
        ui->pushButton_8->setText(t);
        ui->pushButton_8->setPalette(pal2);
    }
    if (check()) {dialog.show();init();this->close();}
}
