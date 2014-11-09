#include "opacitywidget.h"
#include <QPainter>

OpacityWidget::OpacityWidget(QWidget *parent) :
    QWidget(parent)
{
    m_opacity = 1;
}

void OpacityWidget::setOpacity(qreal opacity)
{
    m_opacity = opacity;
    update();
}

void OpacityWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setOpacity(m_opacity);
    painter.setBrush(m_color);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}
