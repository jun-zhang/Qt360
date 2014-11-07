#include "dynamicscaledwidget.h"
#include <QTimer>
#include <QPainter>

DynamicScaledWidget::DynamicScaledWidget(QWidget *parent) :
    QWidget(parent)
{
    m_currentNum = 0;
}

void DynamicScaledWidget::setAnimInfo(const QPixmap &pix, int milliseconds, int number, qreal maxScaledRate)
{
    m_currentPix = pix.scaled(pix.width(), pix.height());
    m_originPix = pix;
    m_number = number;
    m_rate = maxScaledRate;
    m_originWidth = pix.width();
    m_originHeight = pix.height();
    this->setFixedSize(pix.size());



    if(m_rateList.size() > 0)
    {
        m_rateList.clear();
    }else
    {
        m_timer = new QTimer(this);
        m_timer->setInterval(milliseconds);
        connect(m_timer, SIGNAL(timeout()), this, SLOT(updateAnim()));
    }

    for(int i=0; i < number; i++)
    {
        m_rateList.append(0.0);
    }

    for(int i=0; i <= (number/2); i++)
    {
        if(i == (number/2))
        {
            m_rateList[number/2] = maxScaledRate;
        }else
        {
            m_rateList[i] = (1 + ((maxScaledRate - 1)/((number/2)*1.0))*i);
            m_rateList[number -1 - i] = (1 + ((maxScaledRate - 1)/((number/2)*1.0))*i);
        }
    }
}

void DynamicScaledWidget::startAnim()
{
    m_timer->start();
}

void DynamicScaledWidget::updateAnim()
{
    if(m_currentNum != m_number)
    {
        m_currentPix = m_originPix.scaled(int(m_originWidth*m_rateList.at(m_currentNum)), \
                                          int(m_originHeight*m_rateList.at(m_currentNum)),\
                                          Qt::KeepAspectRatio,Qt::SmoothTransformation);
        m_currentNum++;
        update();
        if(m_currentNum == (m_number - 1))
        {
            m_timer->stop();
            m_currentNum = 0;
            emit animFinished();
        }
    }
}

void DynamicScaledWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(QRect(-((m_currentPix.width()-this->width())/2), -((m_currentPix.height()-this->height())/2),\
                       m_currentPix.width(), m_currentPix.height()), m_currentPix);
}
