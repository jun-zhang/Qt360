#include "speedoutbutton.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

SpeedOutButton::SpeedOutButton(QWidget *parent) :
    QWidget(parent)
{
    m_normalHover.load(":/default/cat_hover");
    m_grayHover.load(":/default/cat_gray_hover");
    this->setFixedSize(m_normalHover.size());
    QPixmap checkBoxPix(":/default/cat_checkbox");
    int pixWidth = checkBoxPix.width();
    int pixHeight = checkBoxPix.height();
    int num = 12;
    for(int i=0; i != num; i++)
    {
        m_checkList.append(checkBoxPix.copy(i*(pixWidth/num), 0, pixWidth/num, pixHeight));
    }

    m_checkRect.setX(100);
    m_checkRect.setY(100);
    m_checkRect.setSize(m_checkList.at(0).size());
}

void SpeedOutButton::setIconsInfo(const QString &icon)
{
    m_checkPix.load(icon + "_check");
    m_uncheckPix.load(icon + "_uncheck");

}

void SpeedOutButton::setButtonStatus(BUTTONSTATUS status)
{
    m_status = status;
    update();
}

void SpeedOutButton::setCheckdStatus(bool checked)
{
    m_isChecked = checked;
    setButtonStatus(BUTTON_LEAVE);
}

void SpeedOutButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    switch (m_status) {
    case BUTTON_LEAVE:
        if(m_isChecked)
        {
            painter.drawPixmap(rect(), m_checkPix);
            painter.drawPixmap(m_checkRect, m_checkList.at(4));
        }else
        {
            painter.drawPixmap(rect(), m_uncheckPix);
            painter.drawPixmap(m_checkRect, m_checkList.at(0));
        }
        break;
    case BUTTON_ENTER:
        if(m_isChecked)
        {
            painter.drawPixmap(rect(), m_normalHover);
            painter.drawPixmap(rect(), m_checkPix);
            painter.drawPixmap(m_checkRect, m_checkList.at(5));
        }else
        {
            painter.drawPixmap(rect(), m_grayHover);
            painter.drawPixmap(rect(), m_uncheckPix);
            painter.drawPixmap(m_checkRect, m_checkList.at(1));
        }
        break;
    case BUTTON_PRESSED:
        if(m_isChecked)
        {
            painter.drawPixmap(rect(), m_normalHover);
            painter.drawPixmap(rect(), m_checkPix);
            painter.drawPixmap(m_checkRect, m_checkList.at(6));
        }else
        {
            painter.drawPixmap(rect(), m_grayHover);
            painter.drawPixmap(rect(), m_uncheckPix);
            painter.drawPixmap(m_checkRect, m_checkList.at(2));
        }
        break;
    default:
        break;
    }
}

void SpeedOutButton::enterEvent(QEvent *)
{
    setButtonStatus(BUTTON_ENTER);
}

void SpeedOutButton::leaveEvent(QEvent *)
{
    setButtonStatus(BUTTON_LEAVE);
}

void SpeedOutButton::mousePressEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }
    setButtonStatus(BUTTON_PRESSED);
}

void SpeedOutButton::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }

    if(rect().contains(e->pos()))
    {
        m_isChecked = !m_isChecked;
        setButtonStatus(BUTTON_ENTER);
        emit checkedChanged(m_isChecked);
    }else
    {
        setButtonStatus(BUTTON_LEAVE);
    }
}
