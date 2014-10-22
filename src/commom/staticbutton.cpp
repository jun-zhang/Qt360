#include "staticbutton.h"
#include <QPainter>
#include <QEvent>
#include <QMouseEvent>

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
    if(this->isEnabled())
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
        default:
            break;
        }
    }else
    {
        if(m_num == 4)
            m_currentPix = m_pixList.at(3);
    }
    update();
}

void StaticButton::enterEvent(QEvent *)
{
    setButtonStatus(BUTTON_ENTER);
}

void StaticButton::leaveEvent(QEvent *)
{
    setButtonStatus(BUTTON_LEAVE);
}

void StaticButton::mousePressEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }
    setButtonStatus(BUTTON_PRESSED);
}

void StaticButton::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }

    if(rect().contains(e->pos()))
    {
        emit buttonClicked();
        setButtonStatus(BUTTON_ENTER);
        e->accept();
    }else{
        setButtonStatus(BUTTON_LEAVE);
        e->ignore();
    }
}

void StaticButton::changeEvent(QEvent *e)
{
    if(e->type() == QEvent::EnabledChange)
    {
        if(!this->isEnabled() && (m_num == 4))
        {
            setButtonStatus(BUTTON_DISABLE);
        }
    }
}

void StaticButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), m_currentPix);
}
