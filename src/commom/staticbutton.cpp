#include "staticbutton.h"
#include <QPainter>
#include <QEvent>

StaticButton::StaticButton(const QString &icon, int num, QWidget *parent) :
    QWidget(parent), m_num(num)
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    QPixmap pixmap(icon);
    for(int i=0; i != m_num; i++)
    {
        m_pixList.append(pixmap.copy(i*(pixmap.width()/m_num), 0, pixmap.width()/m_num, pixmap.height()));
    }
    m_currentPix = m_pixList.at(0);
    this->setFixedSize(m_currentPix.size());
}

void StaticButton::setButtonStatus(BUTTONSTATUS status)
{
    switch (status) {
    case BUTTON_ENTER:
        m_currentPix = m_pixList.at(1);
        break;
    case BUTTON_LEAVE:
        m_currentPix = m_pixList.at(0);
        break;
    case BUTTON_PRESSED:
        m_currentPix = m_pixList.at(2);
        break;
    case BUTTON_DISABLE:
    {
        if(m_num == 4)
            m_currentPix = m_pixList.at(3);
    }
        break;
    default:
        break;
    }
    update();
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
        if(!this->isEnabled() && (m_num == 4))
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
