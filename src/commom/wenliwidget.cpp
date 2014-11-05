#include "wenliwidget.h"
#include <QPainter>
#include <QPropertyAnimation>

WenliWidget::WenliWidget(QWidget *parent) :
    BaseStyleWidget(parent)
{
    m_backgroundColor = QColor("#2abf1d");
    m_opacity = 1.0;

    m_wenliPix = QPixmap(":/main/wenli");
    m_guangYPix = QPixmap(":/main/guangyun_green");
    this->initAnimations();
}

void WenliWidget::initAnimations()
{
    m_toOrange = new QPropertyAnimation(this, "color");
    m_toOrange->setDuration(5000);
    m_toOrange->setStartValue(QColor("#2abf1d"));
    m_toOrange->setEndValue(QColor("#FFA500"));

    m_toYellow = new QPropertyAnimation(this, "color");
    m_toYellow->setDuration(2000);
    m_toYellow->setStartValue(QColor("#FFA500"));
    m_toYellow->setEndValue(QColor(Qt::yellow));

}

void WenliWidget::setColor(const QColor &color)
{
    m_backgroundColor = color;
    int count;
    int current;
    if(m_num > 70 && m_num < 90)
    {
        count = m_toOrange->duration();
        current = m_toOrange->currentLoopTime();
        if(current <= (count/2))
        {
            m_guangYPix = QPixmap(":/main/guangyun_green");
            m_opacity = 1 - current/(count/2.0);
        }else if(current > (count/2))
        {
            m_guangYPix = QPixmap(":/main/guangyun_orange");
            m_opacity = current/(count/2.0) - 1.0;
        }
    }else if(m_num > 0 && m_num <= 70)
    {
        count = m_toYellow->duration();
        current = m_toYellow->currentLoopTime();
        if(current <= (count/2))
        {
            m_guangYPix = QPixmap(":/main/guangyun_orange");
            m_opacity = 1 - current/(count/2.0);
        }else if(current > (count/2))
        {
            m_guangYPix = QPixmap(":/main/guangyun_yellow");
            m_opacity = current/(count/2.0) - 1.0;
        }

    }

    update();
}

void WenliWidget::setBackPix(const QString &backPix)
{
    m_backgroundPix = backPix;
    update();
}

void WenliWidget::setNums(int num)
{
    m_num = num;
    if(num >= 90)
    {

    }else if(num >= 70)
    {
        m_toOrange->start();
    }else{
        m_toYellow->start();
    }

}

void WenliWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    if(m_backgroundPix.isEmpty() || m_backgroundPix == "default")
    {
        painter.setBrush(m_backgroundColor);
        painter.drawRect(rect());
        painter.setOpacity(m_opacity);
        painter.drawPixmap(rect(), m_guangYPix, rect());
        painter.setOpacity(1.0);
        painter.drawPixmap(rect(), m_wenliPix, rect());
    }else
    {
        painter.drawPixmap(rect(), QPixmap(m_backgroundPix), rect());
    }

}
