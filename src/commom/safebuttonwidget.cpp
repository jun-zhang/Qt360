#include "safebuttonwidget.h"
#include <QPainter>
#include <QMouseEvent>

SafeButtonWidget::SafeButtonWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setAttribute(Qt::WA_TranslucentBackground);
}

void SafeButtonWidget::setIconsInfo(const QString &animIcons, int animNum, const QString &normalIcons, int normalNum)
{
    m_staticButton = new StaticButton(normalIcons, normalNum, this);
    m_dynamicWidget = new DynamicWidget(this);
    m_dynamicWidget->setInfo(animNum, QPixmap(animIcons));
    this->setFixedSize(m_staticButton->size());

    m_staticButton->move(0, 0);
    m_dynamicWidget->move(0, 0);
    m_dynamicWidget->hide();
    m_staticButton->setButtonStatus(BUTTON_LEAVE);
}

void SafeButtonWidget::enterEvent(QEvent *)
{
    m_staticButton->setButtonStatus(BUTTON_ENTER);
    m_dynamicWidget->show();
    m_dynamicWidget->raise();
    m_dynamicWidget->startClockwise();
}

void SafeButtonWidget::leaveEvent(QEvent *)
{
    m_staticButton->setButtonStatus(BUTTON_LEAVE);
    m_dynamicWidget->stopAnim();
    m_dynamicWidget->hide();
}

void SafeButtonWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }
    m_dynamicWidget->stopAnim();
    m_dynamicWidget->hide();
    m_staticButton->setButtonStatus(BUTTON_PRESSED);
}

void SafeButtonWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }

    if(rect().contains(e->pos()))
    {
        m_staticButton->setButtonStatus(BUTTON_ENTER);
        m_staticButton->repaint();
        emit buttonClicked();
        e->accept();
    }else{
        m_staticButton->setButtonStatus(BUTTON_LEAVE);
        e->ignore();
    }
}
