#include "basestylewidget.h"
#include <QStyleOption>
#include <QPainter>

BaseStyleWidget::BaseStyleWidget(QWidget *parent) :
    QWidget(parent)
{
}

void BaseStyleWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
