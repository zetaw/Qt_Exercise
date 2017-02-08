#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <gaming.h>
#include <QFileDialog>
#include <QImage>
#include <QMessageBox>
#include <QPixmap>

QString tmp;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString s=ui->lineEdit->text();
    int t=s.toInt();
    if (QString::number(t)==s&&t>1&&t<10) {
        QMessageBox::information(this,"Warning!","程序还有一些小漏洞。调整窗口的大小以获得最佳的游戏体验。");
        gaming *body=new gaming(0,t);
        body->show();
        this->connect(this,SIGNAL(send(QString)),body,SLOT(receive(QString)));
        emit send(tmp);
    }
    else QMessageBox::warning(this,"Warning!","n必须在2~9之间！");
}

void Widget::on_pushButton_2_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("选择图像"),"",tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));
    if(filename.isEmpty()) return;
    else{
        QImage* img=new QImage;
        if(!(img->load(filename) ) )
        {
            QMessageBox::information(this,tr("打开图像失败"),tr("打开图像失败!"));
            delete img;
            return;
        }
        //ui->label_3->resize(img->size());
        //ui->label_3->setPixmap(QPixmap::fromImage(*img));
        tmp=filename;
        ui->lineEdit_2->setText(tmp);

    }
}

const QString help="这是一个使用QT编写的拼图小游戏。游戏中,你需要把n*n-1个格子按照图片的顺序摆放，总有一个空格没有图片，其他与之相邻的格子可以与其交换。要开始游戏，请先选择一张图片进行加载。游戏的魅力在于这张图片是你不知道顺序的。所以不要对着原图玩哦~";

void Widget::on_pushButton_3_clicked()
{
    QMessageBox::information(this,"Help",help);
}
