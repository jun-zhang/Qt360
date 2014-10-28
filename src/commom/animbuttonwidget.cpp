#include "animbuttonwidget.h"
#include "common.h"
#include <QTimer>
#include <QPainter>

AnimButtonWidget::AnimButtonWidget(QWidget *parent) :
    QWidget(parent), m_isPix(false)
{
    this->setAttribute(Qt::WA_TranslucentBackground);
}

void AnimButtonWidget::setAnimInfo(int perLength, int milliseconds)
{
    m_perLength = perLength;
    m_timer = new QTimer(this);
    m_timer->setInterval(milliseconds);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateAnim()));
}

void AnimButtonWidget::setLineInfo(int linelength, const QColor &color)
{
    m_lineLength = linelength;
    m_lineColor = color;
    this->setFixedHeight(ANIM_LINE_WIDTH);
}

void AnimButtonWidget::setPixInfo(const QString &pix)
{
    m_isPix = true;
    m_pix.load(pix);
    this->setFixedHeight(m_pix.height());
}

void AnimButtonWidget::setOriginX(int x)
{
    m_originX = x;
    m_currentX = x;
}

void AnimButtonWidget::setEndX(int x)
{
    m_endX = x;
    if(!m_timer->isActive())
        m_timer->start();
}


void AnimButtonWidget::leaveButton()
{
    if(m_currentX != m_originX)
    {
        m_endX = m_originX;
        if(m_currentX > m_originX)
            m_isRightOri = true;
        else
            m_isRightOri = false;
        if(!m_timer->isActive())
            m_timer->start();
    }
}

void AnimButtonWidget::updateAnim()
{
    if(m_endX > m_originX) //结束点在原点右边
    {
        if(m_currentX >= m_endX)
        {
            m_currentX = m_endX;
            m_timer->stop();
        }else
        {
            m_currentX += m_perLength;
        }
    }else if(m_endX < m_originX)
    {
        if(m_currentX <= m_endX)
        {
            m_currentX = m_endX;
            m_timer->stop();
        }else
        {
            m_currentX -= m_perLength;
        }
    }else if(m_endX == m_originX) //回到原点
    {
        if(m_isRightOri)
        {
            if(m_currentX <= m_endX)
            {
                m_currentX = m_endX;
                m_timer->stop();
            }else
            {
                m_currentX -= m_perLength;
            }
        }else{
            if(m_currentX >= m_endX)
            {
                m_currentX = m_endX;
                m_timer->stop();
            }else
            {
                m_currentX += m_perLength;
            }
        }
    }
    update();
}

void AnimButtonWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    if(m_isPix)
    {
        painter.drawPixmap(m_currentX, 0, m_pix);
    }else
    {
        painter.setPen(QPen(m_lineColor, ANIM_LINE_WIDTH));
        painter.drawLine(m_currentX, 0, m_currentX + m_lineLength, 0);
    }
}
