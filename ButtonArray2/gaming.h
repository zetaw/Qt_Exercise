#ifndef GAMING_H
#define GAMING_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <dialog.h>
#include <QString>
#include <QDebug>
#include <QMouseEvent>


namespace Ui {
class gaming;
}

class gaming : public QWidget
{
    Q_OBJECT

public:
    explicit gaming(QWidget *parent = 0,int n=3);
    QLabel *sum,*im;
    QPushButton *pb[81];
    //QString file;
    //static int n;
    ~gaming();
signals:
    void sendData(int);
public slots:
    void receive(QString data);
    void movestate(int m);
    void spinstate(int m);
private:
    Ui::gaming *ui;
    Dialog dialog;
};


#endif // GAMING_H
