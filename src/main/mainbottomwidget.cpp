#include "mainbottomwidget.h"
#include <QPainter>
MainBottomWidget::MainBottomWidget(QWidget *parent) :
    QWidget(parent)
{
    //this->setStyleSheet("background:green;");
    m_button = new QPushButton(this);
    m_button->setText(tr("Go Garbage"));
    m_button->setGeometry(20, 40, 80, 20);
    connect(m_button, SIGNAL(clicked()), this, SIGNAL(goGarbage()));
}

void MainBottomWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(), this->height(), QPixmap(":/10_big.png"));
}
