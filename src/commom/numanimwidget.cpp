#include "numanimwidget.h"
#include <QTimer>
#include <QPainter>

NumAnimWidget::NumAnimWidget(QWidget *parent) :
    QWidget(parent), m_isInit(true), m_isStart(false), m_isEnd(false)
{
    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updatePix()));
    this->setAttribute(Qt::WA_TranslucentBackground);
}

void NumAnimWidget::setInitInfo(const QString &iconPath, int num)
{
    m_preNum = num;
    m_iconPath = iconPath;
    if(m_preNum != -1)
        m_currentPix = QPixmap(iconPath + QString::number(num));
    QPixmap tmpPix(iconPath + "1");
    this->setFixedSize(tmpPix.width(), tmpPix.height() + 30);
    m_endY = 15;
    m_pixY = m_endY;
}

void NumAnimWidget::setNum(int num)
{
    if(num == m_preNum)
        return;
    if(num == -1)
    {
        m_isEnd = true;
    }else
    {
        m_prePix = QPixmap(m_iconPath + QString::number(num));
    }
    m_pixY = m_endY;
    m_preNum = num;
    m_isStart = true;
    if(m_timer->isActive())
        m_timer->stop();
    m_timer->start();
}

void NumAnimWidget::updatePix()
{
    if((m_pixY - m_currentPix.height()) >= m_endY)
    {
        m_timer->stop();
        m_pixY = m_endY;
        if(!m_isEnd)
            m_currentPix = m_prePix;
        m_isStart = false;
    }else
    {
        m_pixY += 4;
    }
    update();
}

void NumAnimWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(m_isInit)
    {
        if(m_preNum != -1)
            painter.drawPixmap(0, m_endY, m_currentPix.width(), m_currentPix.height(), m_currentPix);
        m_isInit = false;
    }else
    {
        if(m_isEnd)
        {
            if(m_isStart)
            {
                painter.drawPixmap(0, m_pixY, m_currentPix.width(), m_currentPix.height(), m_currentPix);
            }
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
}

