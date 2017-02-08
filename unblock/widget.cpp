#include "widget.h"
#include "ui_widget.h"
#include <QGridLayout>
#include <QLabel>
#include <QMessageBox>
#include <QFile>
#include <QDir>

FILE *read;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QDir d;
    standardItemModel = new QStandardItemModel(this);
    d.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks | QDir::AllDirs);
    d.setSorting(QDir::Size | QDir::Reversed);
    const QFileInfoList flist = d.entryInfoList();
    QFileInfoList::const_iterator iterator = flist.begin();
    QStringList list;
    while (iterator!=flist.end()){
        if (iterator->fileName().endsWith(".dat")) list.push_back(iterator->fileName());
        iterator++;
    }
    for (int i=0;i<list.size();i++){
        QString string=static_cast<QString>(list.at(i));
        QStandardItem *item=new QStandardItem(string);
        standardItemModel->appendRow(item);
        ui->listView->setModel(standardItemModel);
        ui->listView->setFixedSize(200,300);
        connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(itemClicked(QModelIndex)));
    }
    /*
    if (NULL==(read=fopen("map.dat","r"))) {QMessageBox::warning(parent,"请检查文件是否存在!","找不到map.dat!");exit(-1);}
    int i,x,y,w,h,ul;
    fscanf(read,"%d%d%d",&ul,&w,&h);
    ui->frame->setGeometry(10,10,w,h);
    fscanf(read,"%d",&N);
    for (i=0;i<N;i++) {
        label[i]=new DragLabel(ui->frame);
        label[i]->UDActivated=false;
        label[i]->LRActivated=true;
        fscanf(read,"%d%d%d%d",&x,&y,&w,&h);
        label[i]->setGeometry(x*ul,y*ul,w*ul,h*ul);
        label[i]->move(x*ul,y*ul);
        label[i]->setObjectName("label_"+QString::number(i));
        label[i]->UnitLength=ul;
    }*/
}

Widget::~Widget()
{
    fclose(read);
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    int row=ui->listView->currentIndex().row();
    int column=ui->listView->currentIndex().column();
    if(row!=-1){
        QModelIndex index=standardItemModel->index(row,column);
        char str[1000];
        strcpy(str,standardItemModel->data(index,Qt::DisplayRole).toString().toStdString().data());
        read=fopen(str,"r");
    }
    else QMessageBox::information(NULL,tr("information"),tr("please select a item!"));
    rewind(read);
    int i,x,y,w,h,ul;
    fscanf(read,"%d%d%d",&ul,&w,&h);
    ui->frame->setGeometry(10,10,w,h);
    fscanf(read,"%d",&N);
    for (i=0;i<N;i++) {
        label[i]=new DragLabel(ui->frame);
        label[i]->UDActivated=false;
        label[i]->LRActivated=true;
        fscanf(read,"%d%d%d%d",&x,&y,&w,&h);
        label[i]->setGeometry(x*ul,y*ul,w*ul,h*ul);
        label[i]->move(x*ul,y*ul);
        label[i]->setObjectName("label_"+QString::number(i));
        label[i]->UnitLength=ul;
        label[i]->show();
    }
    /*
    for (i=0;i<N;i++) {
        fscanf(read,"%d%d%d%d",&x,&y,&w,&h);
        label[i]->setGeometry(x*ul,y*ul,w*ul,h*ul);
        label[i]->move(x*ul,y*ul);
        label[i]->AutoAbsorb=true;
    }*/
}
