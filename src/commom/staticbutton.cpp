#include "staticbutton.h"
#include <QPainter>
#include <QEvent>

StaticButton::StaticButton(const QString &icon, QWidget *parent) :
    QWidget(parent)
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    QPixmap pixmap(icon);
    for(int i=0; i != 4; i++)
    {
        m_pixList.append(pixmap.copy(i*(pixmap.width()/4), 0, pixmap.width()/4, pixmap.height()));
    }
    m_currentPix = m_pixList.at(0);
    this->setFixedSize(m_currentPix.size());
}

void StaticButton::enterEvent(QEvent *)
{
    if(this->isEnabled())
    {
        m_currentPix = m_pixList.at(1);
        update();
    }
}

void StaticButton::leaveEvent(QEvent *)
{
    m_currentPix = m_pixList.at(0);
    update();
}

void StaticButton::mousePressEvent(QMouseEvent *)
{
    m_currentPix = m_pixList.at(2);
    emit buttonClicked();
    update();
}

void StaticButton::changeEvent(QEvent *e)
{
    if(e->type() == QEvent::EnabledChange)
    {
        if(!this->isEnabled())
        {
            m_currentPix = m_pixList.at(3);
            update();
        }
    }
}

void StaticButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), m_currentPix);
}
