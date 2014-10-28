#include "numanimwidget.h"
#include <QTimer>
#include <QPainter>

NumAnimWidget::NumAnimWidget(QWidget *parent) :
    QWidget(parent), m_isInit(true), m_isStart(false), m_isEnd(false)
{
    m_timer = new QTimer(this);
    m_timer->setInterval(50);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updatePix()));
    this->setAttribute(Qt::WA_TranslucentBackground);
}

void NumAnimWidget::setInitNum(int num)
{
    m_currentPix = QPixmap(NUM_ICONS_BEGIN + QString::number(num));
    this->setFixedSize(m_currentPix.width(), m_currentPix.height() + 30);
    m_endY = 15;
    m_pixY = m_endY;
}

void NumAnimWidget::setNum(int num)
{
    m_prePix = QPixmap(NUM_ICONS_BEGIN + QString::number(num));
    m_pixY = m_endY;
    m_isStart = true;
    m_timer->start();
}

void NumAnimWidget::updatePix()
{
    if((m_pixY - m_currentPix.height()) >= m_endY)
    {
        m_timer->stop();
        m_pixY = m_endY;
        m_currentPix = m_prePix;
        m_isStart = false;
    }else
    {
        m_pixY += 1;
    }
    update();
}

void NumAnimWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(m_isInit)
    {
        painter.drawPixmap(0, m_endY, m_currentPix.width(), m_currentPix.height(), m_currentPix);
        m_isInit = false;
    }else
    {
        if(m_isStart)
        {
            painter.drawPixmap(0, m_pixY - m_prePix.height(), \
                               m_prePix.width(), m_prePix.height(), m_prePix);
            painter.drawPixmap(0, m_pixY, m_currentPix.width(), m_currentPix.height(), m_currentPix);
        }else
        {
            painter.drawPixmap(0, m_pixY, m_currentPix.width(), m_currentPix.height(), m_currentPix);
        }
    }
}

