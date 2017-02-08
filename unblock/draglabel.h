#ifndef DRAGLABEL_H
#define DRAGLABEL_H
#define SPACE 20

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QPoint>
#include <QSize>
#include <QList>
#include <QRect>

class DragLabel : public QLabel
{
public:
    DragLabel(QWidget *parent=nullptr);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void move(int x, int y);
    void adjust(int x,int y);
    void AutoAdjust();
    bool LRActivated,UDActivated;
    bool AutoAbsorb;
    int m_x,m_y;
    int ix,iy;
    int tx,ty;
    int UnitLength;
};

#endif // DRAGLABEL_H
