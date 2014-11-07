#include "dynamicbutton.h"
#include <QPainter>
#include <QMouseEvent>

DynamicButton::DynamicButton(QWidget *parent) :
    QWidget(parent), m_isSelected(true), m_isFirsted(false)
{
    m_firstdyWidget = new DynamicWidget(this);
    m_firstdyWidget->hide();
    m_dyWidget = new DynamicWidget(this);
    m_dyWidget->hide();
    m_noSelectdDyWidget = new DynamicWidget(this);
    m_noSelectdDyWidget->hide();

    m_dyScaledWidget = new DynamicScaledWidget(this);
    m_dyScaledWidget->hide();
    this->setFixedSize(90, 90);
}

void DynamicButton::setFirstAnim(const QString &icon, int count)
{
    QPixmap pix(icon);
    m_firstdyWidget->setInfo(pix, count, 80);
    m_firstdyWidget->setGeometry((this->width()-m_firstdyWidget->width())/2, (this->height()-70)/2 - 1,\
                            m_firstdyWidget->width(), m_firstdyWidget->height());
    connect(m_firstdyWidget, SIGNAL(animFinished()), this, SLOT(firstAnimFinished()));
}

void DynamicButton::setNormalAnimInfo(const QString &icon, int count)
{
    QPixmap pix(icon);
    m_dyWidget->setInfo(pix, count, 50);
    m_dyWidget->setGeometry((this->width()-m_dyWidget->width())/2, (this->height()-m_dyWidget->height())/2,\
                            m_dyWidget->width(), m_dyWidget->height());

    m_dyScaledWidget->setAnimInfo(pix.copy(0, 0, pix.width()/count, pix.height()), 70, 9);
    m_dyScaledWidget->setGeometry((this->width()-m_dyScaledWidget->width())/2, (this->height()-m_dyScaledWidget->height())/2,\
                            m_dyScaledWidget->width(), m_dyScaledWidget->height());
    connect(m_dyScaledWidget, SIGNAL(animFinished()), this, SLOT(scaledAnimFinished()));
}

void DynamicButton::setNormalIconsInfo(const QString &normalIcon, const QString &hoverIcon)
{
    m_normalIcon = normalIcon;
    m_hoverIcon = hoverIcon;
}

void DynamicButton::setNoSelectedAnimInfo(const QString &icon, int count)
{
    QPixmap pix(icon);
    m_noSelectdDyWidget->setInfo(pix, count, 50);
    m_noSelectdDyWidget->setGeometry((this->width()-m_noSelectdDyWidget->width())/2, (this->height()-m_noSelectdDyWidget->height())/2,\
                            m_noSelectdDyWidget->width(), m_noSelectdDyWidget->height());
}

void DynamicButton::setNoSelectedIconsInfo(const QString &normalIcon, const QString &hoverIcon)
{
    m_noSelectedNormalIcon = normalIcon;
    m_noSelectedHoverIcon = hoverIcon;
}

void DynamicButton::startFirstAnim()
{
    if(m_firstdyWidget != NULL)
    {
        m_status = BUTTON_FIRST;
        m_firstdyWidget->show();
        m_firstdyWidget->raise();
        m_firstdyWidget->startClockwise();
    }
}

void DynamicButton::scaledAnimFinished()
{
    m_dyScaledWidget->hide();
    disconnect(m_dyScaledWidget, SIGNAL(animFinished()), this, SLOT(scaledAnimFinished()));
    delete m_dyScaledWidget;
    m_dyScaledWidget = NULL;
    m_status = BUTTON_LEAVE;
    if(m_isSelected)
    {
        m_dyWidget->raise();
        m_dyWidget->show();
    }else
    {
        m_noSelectdDyWidget->raise();
        m_noSelectdDyWidget->show();
    }
    update();
}

void DynamicButton::firstAnimFinished()
{
    m_firstdyWidget->hide();
    disconnect(m_firstdyWidget, SIGNAL(animFinished()), this, SLOT(firstAnimFinished()));
    delete m_firstdyWidget;
    emit firstFinished();
    m_firstdyWidget = NULL;
    m_status = BUTTON_SCALED;
    m_isFirsted = true;
    update();
    m_dyScaledWidget->show();
    m_dyScaledWidget->raise();
    m_dyScaledWidget->startAnim();

}

void DynamicButton::setCheckedState(bool state)
{
    m_isSelected = state;
}

void DynamicButton::setButtonStatus(BUTTONSTATUS status)
{
    if(!m_isFirsted)
        return;
    m_status = status;
    switch (status) {
    case BUTTON_ENTER:
        {
            if(m_isSelected)
            {
                m_dyWidget->startClockwise();
            }else{
                m_noSelectdDyWidget->startClockwise();
            }
        }
        break;
    case BUTTON_LEAVE:
        {
            if(m_isSelected)
            {
                m_dyWidget->startCounterclockwise();
            }else{
                m_noSelectdDyWidget->startCounterclockwise();
            }
        }
        break;
    case BUTTON_PRESSED:
        {
            m_isSelected = !m_isSelected;
            if(m_isSelected)
            {               
                m_noSelectdDyWidget->stopAnim();
                m_noSelectdDyWidget->hide();
                m_dyWidget->raise();
                m_dyWidget->show();
            }else
            {
                m_dyWidget->stopAnim();
                m_dyWidget->hide();
                m_noSelectdDyWidget->raise();
                m_noSelectdDyWidget->show();
            }
        }
        break;
    default:
        break;
    }
    update();
}

void DynamicButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    switch (m_status) {
    case BUTTON_FIRST:
        break;
    case BUTTON_SCALED:
    case BUTTON_LEAVE:
        {
            if(m_isSelected)
            {
                painter.drawPixmap(this->rect(), QPixmap(m_normalIcon));
            }else
            {
                painter.drawPixmap(this->rect(), QPixmap(m_noSelectedNormalIcon));
            }
        }
        break;
    case BUTTON_ENTER:
    case BUTTON_PRESSED:
        {
            if(m_isSelected)
            {
                painter.drawPixmap(this->rect(), QPixmap(m_hoverIcon));
            }else
            {
                painter.drawPixmap(this->rect(), QPixmap(m_noSelectedHoverIcon));
            }
        }
        break;
    default:
        break;
    }
}

void DynamicButton::enterEvent(QEvent *)
{
    setButtonStatus(BUTTON_ENTER);
}

void DynamicButton::leaveEvent(QEvent *)
{
    setButtonStatus(BUTTON_LEAVE);
}

void DynamicButton::mousePressEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }
    //setButtonStatus(BUTTON_PRESSED);
}

void DynamicButton::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }

    if(rect().contains(e->pos()))
    {
        emit buttonClicked();
        setButtonStatus(BUTTON_PRESSED);
        e->accept();
    }else{
        setButtonStatus(BUTTON_LEAVE);
        e->ignore();
    }
}
