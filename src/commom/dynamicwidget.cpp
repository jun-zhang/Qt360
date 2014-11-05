#include "dynamicwidget.h"
#include <QPainter>

DynamicWidget::DynamicWidget(QWidget *parent) :
    QWidget(parent)
{
    m_currentIndex = 0;
}

void DynamicWidget::setInfo(const QPixmap &pix, int count, int milliseconds)
{
    m_currentIndex = 0;
    m_count = count;

    if(m_pixList.count() != 0)
    {
        m_pixList.clear();
    }else
    {
        m_clockTimer = new QTimer(this);
        m_clockTimer->setInterval(milliseconds);
        connect(m_clockTimer, SIGNAL(timeout()), this, SLOT(updateClockwise()));

        m_counterclockTimer = new QTimer(this);
        m_counterclockTimer->setInterval(milliseconds);
        connect(m_counterclockTimer, SIGNAL(timeout()), this, SLOT(updateCounterclockwise()));
    }

    for(int i=0; i != count; i++)
    {
        m_pixList.append(pix.copy(i*(pix.width()/count), 0, pix.width()/count, pix.height()));
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
    m_currentIndex = 0;
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

void DynamicWidget::stopAnim()
{
    if(m_clockTimer->isActive())
        m_clockTimer->stop();
    if(m_counterclockTimer->isActive())
        m_counterclockTimer->stop();
    m_currentIndex = 0;
    m_currentPix = m_pixList.at(0);
    update();
}

void DynamicWidget::updateClockwise()
{
    if(m_currentIndex != m_count)
    {
        m_currentPix = m_pixList.at(m_currentIndex);
        update();
        if(m_currentIndex == (m_count - 1))
        {
            m_clockTimer->stop();
            m_currentIndex = 0;
            emit animFinished();
        }
        m_currentIndex++;
    }
}

void DynamicWidget::updateCounterclockwise()
{
    if(m_currentIndex >= 0)
    {
        m_currentPix = m_pixList.at(m_currentIndex);
        update();
        if(m_currentIndex == 0)
        {
            m_counterclockTimer->stop();
        }
        m_currentIndex--;
    }
}

void DynamicWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), m_currentPix);
}
