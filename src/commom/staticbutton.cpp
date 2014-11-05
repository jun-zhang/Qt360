#include "staticbutton.h"
#include <QPainter>
#include <QEvent>
#include <QMouseEvent>

StaticButton::StaticButton(QWidget *parent) :
    QWidget(parent), m_isCursor(false)
{
    this->setAttribute(Qt::WA_TranslucentBackground);
}

StaticButton::StaticButton(const QString &icon, int num, QWidget *parent) :
    QWidget(parent), m_num(num), m_isCursor(false)
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

StaticButton::StaticButton(const QString &icon, bool isDivision, int num, QWidget *parent) :
    QWidget(parent), m_num(num), m_isCursor(false)
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    if(isDivision)
    {
        setDivisionButtonInfo(icon, num);
    }else
    {
        setOneButtonInfo(icon, num);
    }
}

void StaticButton::setOneButtonInfo(const QString &icon, int num)
{
    m_num = num;
    QPixmap pixmap(icon);
    if(m_pixList.size() != 0)
    {
        m_pixList.clear();
    }
    for(int i=0; i != m_num; i++)
    {
        m_pixList.append(pixmap.copy(i*(pixmap.width()/m_num), 0, pixmap.width()/m_num, pixmap.height()));
    }
    m_currentPix = m_pixList.at(0);
    this->setFixedSize(m_pixList.at(0).size());
}

void StaticButton::setDivisionButtonInfo(const QString &icon, int num)
{
    m_pixList.append(QPixmap(icon + "_normal"));
    m_pixList.append(QPixmap(icon + "_hover"));
    m_pixList.append(QPixmap(icon + "_press"));
    if(num == 4)
        m_pixList.append(QPixmap(icon + "_disable"));
    m_num = num;
    m_currentPix = m_pixList.at(0);
    this->setFixedSize(QPixmap(icon + "_normal").size());
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

void StaticButton::setCursorEnabled(bool enalbed)
{
    m_isCursor = enalbed;
}

void StaticButton::enterEvent(QEvent *)
{
    setButtonStatus(BUTTON_ENTER);
    if(m_isCursor)
    {
        m_preCursor = cursor();
        setCursor(Qt::OpenHandCursor);
    }
    emit enterSignal();
}

void StaticButton::leaveEvent(QEvent *)
{
    setButtonStatus(BUTTON_LEAVE);
    if(m_isCursor)
    {
        setCursor(m_preCursor);
    }
    emit leaveSignal();
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
        if(this->isEnabled())
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
