#ifndef BODY3_H
#define BODY3_H

#include <QWidget>
#include "dialog.h"

namespace Ui {
class body3;
}

class body3 : public QWidget
{
    Q_OBJECT

public:
    explicit body3(QWidget *parent = 0);
    bool check();
    void init();
    ~body3();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::body3 *ui;
    Dialog dialog;
};

#endif // BODY3_H
