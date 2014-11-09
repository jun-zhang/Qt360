#include "shadowwidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <qmath.h>

ShadowWidget::ShadowWidget(QWidget *parent) :
    QDialog(parent), m_mousePress(false)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    this->setObjectName("basewidget");
    //setAttribute(Qt::WA_TranslucentBackground);
}

void ShadowWidget::paintEvent(QPaintEvent *)
{
    //加阴影，因为扁平化去掉
//    QPainterPath path;
//    path.setFillRule(Qt::WindingFill);
//    path.addRect(10, 10, this->width()-20, this->height()-20);

//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing, true);
//    painter.fillPath(path, QBrush(Qt::white));

//    QColor color(0, 0, 0, 50);
//    for(int i=0; i<10; i++)
//    {
//        QPainterPath path;
//        path.setFillRule(Qt::WindingFill);
//        path.addRect(10-i, 10-i, this->width()-(10-i)*2, this->height()-(10-i)*2);
//        color.setAlpha(150 - qSqrt(i)*50);
//        painter.setPen(color);
//        painter.drawPath(path);
//    }

}

void ShadowWidget::mousePressEvent(QMouseEvent *event)
{
    //只能是鼠标左键移动和改变大小
    if(event->button() == Qt::LeftButton)
    {
        m_mousePress = true;
    }
    //窗口移动距离
    m_movePoint = event->globalPos() - pos();
}

void ShadowWidget::mouseReleaseEvent(QMouseEvent *)
{
    m_mousePress = false;
}

void ShadowWidget::mouseMoveEvent(QMouseEvent *event)
{
    //移动窗口
    if(m_mousePress)
    {
        QPoint movePpos = event->globalPos();
        move(movePpos - m_movePoint);
    }
}

