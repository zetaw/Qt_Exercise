#include "widget.h"
#include "ui_widget.h"
#define PI (3.1415926535)

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    srand((unsigned int)time(0));
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if (ui->lineEdit->text().isEmpty()) {
        QMessageBox::warning(this,"Empty","The lineEdit is Empty!");
        return;
    }
    int n=ui->lineEdit_2->text().toInt();
    if (QString::number(n)!=ui->lineEdit_2->text()){
        QMessageBox::warning(this,"Error","The lineEdit's filling is ERROR!");
        return;
    }
    QString filename=ui->lineEdit->text()+".jpg";
    QImageWriter qiw;
    qiw.setFileName(filename);
    qiw.setFormat("jpg");
    qiw.setQuality(100);
    QImage qi(n,n,QImage::Format_RGB32);
    int i,j;QRgb value;int r,g,b;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            r=(int)(i*cos(i)/(n/256))%256;
            g=(int)(j*sin(j)/(n/256))%256;
            b=(int)(atan(i+j))%256;
            value=qRgb(r,g,b);
            qi.setPixel(i,j,value);
        }
    }
    qiw.write(qi);
}
