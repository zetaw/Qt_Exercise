#include "widget.h"
#include "ui_widget.h"
#include<QGridLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QGridLayout *layout=new QGridLayout;
        resize(300,200);
        layout->setHorizontalSpacing(0);
        layout->setSpacing(0);
        for(int i=0;i<3;i++)
            for (int j=0;j<3;j++)
            {
                pb[3*i+j]=new QPushButton(tr("Quit"));
                pb[3*i+j]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                pb[3*i+j]->setMinimumSize(10,10);
                pb[3*i+j]->setGeometry(10*i+10,10*j+10,10,10);
                layout->addWidget(pb[3*i+j],i,j);
                connect(pb[3*i+j],SIGNAL(clicked()),this,SLOT(close()));
            }
         setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
