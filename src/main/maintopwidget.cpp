#include "maintopwidget.h"
#include <QPainter>
MainTopWidget::MainTopWidget(QWidget *parent) :
    BaseStyleWidget(parent)
{

}

void MainTopWidget::setSkinType(int type)
{

}

void MainTopWidget::examineClicked()
{

}

void MainTopWidget::viewClicked()
{

}

void MainTopWidget::setNums(int num)
{

}

void MainTopWidget::paintEvent(QPaintEvent *)
{
    if(m_type != 0)
    {
        QPainter painter(this);
        painter.drawPixmap();
    }
}
