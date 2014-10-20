#include "dynamicwidget.h"
#include <QPainter>

DynamicWidget::DynamicWidget(QWidget *parent) :
    QWidget(parent)
{
    m_currentIndex = 0;
}

void DynamicWidget::setInfo(int count, const QString &icon, int milliseconds)
{
    m_count = count;
    m_clockTimer = new QTimer(this);
    m_clockTimer->setInterval(milliseconds);
    connect(m_clockTimer, SIGNAL(timeout()), this, SLOT(updateClockwise()));

    m_counterclockTimer = new QTimer(this);
    m_counterclockTimer->setInterval(milliseconds);
    connect(m_counterclockTimer, SIGNAL(timeout()), this, SLOT(updateCounterclockwise()));

    QPixmap pixmap(icon);
    for(int i=0; i != count; i++)
    {
        m_pixList.append(pixmap.copy(i*(pixmap.width()/count), 0, pixmap.width()/count, pixmap.height()));
    }
    m_currentPix = m_pixList.at(0);
    this->setFixedSize(m_currentPix.size());
    update();
}

void DynamicWidget::startClockwise()
{
    if(m_counterclockTimer->isActive())
    {
        m_counterclockTimer->stop();
    }
    m_clockTimer->start();
}

void DynamicWidget::startCounterclockwise()
{
    if(m_clockTimer->isActive())
    {
        m_clockTimer->stop();
    }
    if(m_currentIndex != 0)
        m_counterclockTimer->start();
}

void DynamicWidget::updateClockwise()
{
    for(; m_currentIndex != m_count; m_currentIndex++)
    {
        m_currentPix = m_pixList.at(m_currentIndex);
        update();
        if(m_currentIndex == (m_count - 1))
        {
            m_clockTimer->stop();
            m_currentIndex = 0;
            emit animFinished();
        }
    }
}

void DynamicWidget::updateCounterclockwise()
{
    for(; m_currentIndex >= 0; m_currentIndex--)
    {
        m_currentPix = m_pixList.at(m_currentIndex);
        update();
        if(m_currentIndex == 0)
        {
            m_counterclockTimer->stop();
        }
    }
}

void DynamicWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), m_currentPix);
}
