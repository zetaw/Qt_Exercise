#include "draglabel.h"
#include <QDebug>

DragLabel::DragLabel(QWidget *parent):QLabel(parent)
{
    move(x(),y());
    ix=0;iy=0;
    this->setFrameShape(QFrame::Box);
    this->LRActivated=true;
    this->UDActivated=true;
    this->AutoAbsorb=true;
}

void DragLabel::adjust(int x, int y){
    m_x+=x;
    m_y+=y;
    QLabel::move(m_x,m_y);
}

void DragLabel::move(int x, int y){
    m_x=x;
    m_y=y;
    QLabel::move(x,y);
}

void DragLabel::mouseDoubleClickEvent(QMouseEvent *e){
    qSwap(LRActivated,UDActivated);
    QLabel::mouseDoubleClickEvent(e);
}

void DragLabel::mousePressEvent(QMouseEvent *e){
    if (e->buttons()==Qt::LeftButton){
        ix=e->pos().x();
        iy=e->pos().y();
        tx=m_x;
        ty=m_y;
    }
    QLabel::mousePressEvent(e);
}

void DragLabel::AutoAdjust(){
    int X=x(),Y=y(),ul=UnitLength;
    if (X%ul<15) X=ul*(X/ul);
    if (X%ul>ul-15) X=ul*(X/ul+1);
    if (Y%ul>ul-15) Y=ul*(Y/ul+1);
    if (Y%ul<15) Y=ul*(Y/ul);
    qDebug()<<X<<Y;
    move(X,Y);
}

void DragLabel::mouseMoveEvent(QMouseEvent *e){
    if(e->buttons() & Qt::LeftButton){
        adjust(LRActivated*(e->pos().x()-ix),UDActivated*(e->pos().y()-iy));
        this->setText(QString::number(x())+","+QString::number(y()));
    }
    QLabel::mouseMoveEvent(e);
}

void DragLabel::mouseReleaseEvent(QMouseEvent *e){
    //Stage 1 Whether the Rect intersects other.
    QList<DragLabel *> dlList=this->parentWidget()->findChildren<DragLabel *>();
    QRect rc[1000];
    int i,movable=1,k1=0,k2=0,t=0;
    for (i=0;i<dlList.size();i++){
        rc[i].setRect(dlList[i]->x(),dlList[i]->y(),dlList[i]->width(),dlList[i]->height());
        if (dlList[i]->objectName()==this->objectName()) t=i;
    }
    for (i=0;i<dlList.size();i++) if (i!=t) movable&=!rc[t].intersects(rc[i]);
    if (!movable) {
        move(tx,ty);
        qDebug()<<"1";
        return;
    }
    //Stage 2 Whether the Rect fly out of the boundary line.
    if (x()<0||y()<0||x()+width()>parentWidget()->width()||y()+height()>parentWidget()->height()) {
        move(tx,ty);
        qDebug()<<"2";
        return;
    }
    //Stage 3 If it can only L&R moves ,it can't Cross!
    QRect temp;
    if (!LRActivated){
        for (i=0;i<dlList.size();i++) {
            if (t==i) continue;
            temp.setX(tx);
            temp.setY(rc[i].y());
            temp.setWidth(rc[t].width());
            temp.setHeight(rc[t].height());
            if (temp.intersects(rc[i])){
                if (rc[i].y()<rc[t].y()) k1++;
                if (rc[i].y()<ty) k2++;
            }
        }
        if (k1!=k2) {
            move(tx,ty);
            qDebug()<<"3";
            return;
        }
    }
    //Stage 4 If it can only U&D moves ,it can't Cross!
    if (!UDActivated){
        for (i=0;i<dlList.size();i++) {
            if (t==i) continue;
            temp.setX(rc[i].x());
            temp.setY(ty);
            temp.setWidth(rc[t].width());
            temp.setHeight(rc[t].height());
            if (temp.intersects(rc[i])){
                if (rc[i].x()<rc[t].x()) k1++;
                if (rc[i].x()<tx) k2++;
            }
        }
        if (k1!=k2) {
            move(tx,ty);
            qDebug()<<"4"<<" "<<k1<<" "<<k2;
            return;
        }
    }
    if (AutoAbsorb) AutoAdjust();
    QLabel::mouseReleaseEvent(e);
}
