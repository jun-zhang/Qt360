#include "maintopwidget.h"
#include <QPainter>
MainTopWidget::MainTopWidget(QWidget *parent) :
    BaseStyleWidget(parent)
{

}

void MainTopWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/0_big.png"));
}
