#include "gaming.h"
#include "ui_gaming.h"
#include <QGridLayout>
#include <QString>
#include <QSignalMapper>
#include <stdlib.h>
#include <time.h>
#include <dialog.h>
#include <QColor>
#include <QRgb>
#include <QPalette>
#include <QImage>
#include <QMessageBox>
#include <QPixmap>
#include <QIcon>
#include <QDebug>
#include <QFileDialog>
#include <QSize>
#define MAX 10000

static int N,S,count;
const QColor red(255,0,0),black(0,0,0);
QSize qs;
int temp[MAX];
int state[81];
int spin_state[81];
QIcon qi[82];
QString filename;
bool Flag=false;


void gaming::movestate(int m){
    int x=m/N,y=m%N;
    int s;
    if (x-1>=0&&!state[N*(x-1)+y]){
        s=state[m];
        state[m]=0;
        state[N*(x-1)+y]=s;
        S++;
        sum->setText(QString::number(S));
    }
    if (x+1<N&&!state[N*(x+1)+y]){
        s=state[m];
        state[m]=0;
        state[N*(x+1)+y]=s;
        S++;
        sum->setText(QString::number(S));
    }
    if (y-1>=0&&!state[N*x+y-1]){
        s=state[m];
        state[m]=0;
        state[N*x+y-1]=s;
        S++;
        sum->setText(QString::number(S));
    }
    if (y+1<N&&!state[N*x+y+1]){
        s=state[m];
        state[m]=0;
        state[N*x+y+1]=s;
        S++;
        sum->setText(QString::number(S));
    }
    bool flag=true;
    for (int i=0;i<N*N;i++){
        if (state[i]!=(i+1)%(N*N)){
            flag=false;
            break;
        }
    }
    if (flag){
        emit sendData(S);
        connect(this,SIGNAL(sendData(int)),&dialog,SLOT(receiveData(int)));
        dialog.show();
        this->close();
    }

    //QPalette pal,pbl;
    //pal.setColor(QPalette::ButtonText,red);
    //pbl.setColor(QPalette::ButtonText,black);
    for (int i=0;i<N*N;i++){
        //if (!state[i]) pb[i]->setPalette(pal);else pb[i]->setPalette(pbl);
        pb[i]->setIcon(qi[state[i]]);
        pb[i]->setIconSize(qs);
    }
}

void merge(int *a, int start, int end) {
    int mid=(start+end)/2;
    int i = start,j = mid + 1,k = start;
    while(i <= mid&&j <= end)
        if(a[i] <= a[j])  temp[k++] = a[i++];
        else  {
            count += j - k;
            temp[k++] = a[j++];
        }
    while(i <= mid)   temp[k++] = a[i++];
    while(j <= end)   temp[k++] = a[j++];
    for(int i = start; i <= end; i++) a[i] = temp[i];
}

void mergesort(int *a,int start,int end){
    if (start<end){
        int mid=(start+end)/2;
        mergesort(a,start,mid);
        mergesort(a,mid+1,end);
        merge(a,start,end);
    }
}

int solveable(int *a){
    int i,j=0,t=0;
    count=0;
    int c[81];
    for (i=0;i<N*N;i++){
        if (!a[i]) {j=1;t=i;continue;}
        c[i-j]=a[i];
    }
    mergesort(c,0,N*N-2);
    if (N%2==0) return ((count%2==0)==((t/N+N)%2==1));else return (count%2==0);
}

void gaming::spinstate(int m){
    qDebug() << "success" << m;
}

void gaming::receive(QString data){
    filename=data;
    QImage *img=new QImage;
    if(filename.isEmpty()) return;
    else{

        if(!(img->load(filename) ) )
        {
            QMessageBox::information(this,tr("打开图像失败"),tr("打开图像失败!"));
            delete img;
            return;
        }
    }
    int W=img->width();int H=img->height();
    int w=W/N,h=H/N;
    QPixmap qp;
    for (int i=0;i<N*N-1;i++) {qp=QPixmap::fromImage(img->copy(i%N*w,i/N*h,w,h));qi[i+1].addPixmap(qp);}
    //QImage *p=new QImage("test.jpg");
    int a[81];
    memset(a,0,sizeof(a));
    int k;
    memset(spin_state,0,sizeof(spin_state));
    do{
        memset(a,0,sizeof(a));\
        memset(state,0,sizeof(state));
        for (int i=0;i<N*N;i++){
            while (a[k=rand()%(N*N)]);
            a[k]=1;
            state[i]=k;
        }
    }
    while (!solveable(state));
    if (Flag) for (int i=0;i<N*N;i++) if (state[i]) spin_state[i]=rand()%4+1;
    QSignalMapper *mapper=new QSignalMapper;
    QSignalMapper *spin_mapper=new QSignalMapper;
    QGridLayout *layout=new QGridLayout;
    const double p1=0.06,p2=0.095;
    W=W*(1+p1);
    H=H*(1+p2);

        resize(W,H);
        layout->setHorizontalSpacing(0);
        layout->setSpacing(0);
        sum=new QLabel(QString::number(S));
        //im=new QLabel;
        //im->setPixmap(QPixmap::fromImage(*img));
        layout->addWidget(sum,N,N);
        //layout->addWidget(im,n+1,n);
        QPalette pal,pbl;
        pal.setColor(QPalette::ButtonText,red);
        pbl.setColor(QPalette::ButtonText,black);

        for(int i=0;i<N;i++)
            for (int j=0;j<N;j++)
            {
                pb[N*i+j]=new QPushButton;
                pb[N*i+j]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                pb[N*i+j]->setMinimumSize(10,10);
                pb[N*i+j]->setGeometry(10*i+10,10*j+10,10,10);
                layout->addWidget(pb[N*i+j],i,j);
                //pb[n*i+j]->setText(QString::number(b[n*i+j]));
                connect(pb[N*i+j],SIGNAL(clicked()),mapper,SLOT(map()));
                mapper->setMapping(pb[N*i+j],N*i+j);
                connect(mapper,SIGNAL(mapped(int)),this,SLOT(movestate(int)));
                if (Flag){
                    spin_mapper->setMapping(pb[N*i+j],N*i+j);
                    connect(pb[N*i+j],SIGNAL(rightclicked()),mapper,SLOT(map()));
                    connect(spin_mapper,SIGNAL(mapped(int)),this,SLOT(spinstate(int)));
                }
                //if (!state) pb[n*i+j]->setPalette(pal);else pb[n*i+j]->setPalette(pbl);
                //pb[n*i+j]->setStyleSheet("font:0.5pt");
            }
        qs=QSize(w,h);
        for (int i=0;i<N*N;i++){
            if (state[i]){
                pb[i]->setIcon(qi[state[i]]);
                pb[i]->setIconSize(qs);
            }
        }
        this->setWindowTitle("gaming...");
        //QPalette bgp;
        //bgp.setBrush(QPalette::Window,QBrush(QPixmap::fromImage(*img)));
        //this->setPalette(bgp);
        setLayout(layout);
}

gaming::gaming(QWidget *parent,int n) :
    QWidget(parent),
    ui(new Ui::gaming)
{
    ui->setupUi(this);
    srand((unsigned)time(0));
    N=n;S=0;
}



gaming::~gaming()
{
    delete ui;
}
