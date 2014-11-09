#include "youhuabutton.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QMouseEvent>
#include "../../commom/speedoutbutton.h"

YouhuaButton::YouhuaButton(QWidget *parent) :
    QWidget(parent), m_isChecked(true)
{
    this->initUI();
}

void YouhuaButton::initUI()
{
    this->setAttribute(Qt::WA_TranslucentBackground);

    m_speed = new SpeedOutButton;
    m_speed->setAttribute(Qt::WA_TransparentForMouseEvents);

    m_titleLabel = new QLabel;
    m_titleLabel->setObjectName("youhuaTitle");
    m_descriptionLabel = new QLabel;
    m_descriptionLabel->setObjectName("youhuaDesc");

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(m_speed, 0, Qt::AlignHCenter);
    vLayout->addWidget(m_titleLabel, 0, Qt::AlignHCenter);
    vLayout->addWidget(m_descriptionLabel, 0, Qt::AlignHCenter);
    vLayout->setSpacing(5);
    vLayout->setContentsMargins(5, 0, 5, 5);

    this->setLayout(vLayout);
}

void YouhuaButton::setIconInfo(const QString &icon)
{
    m_icon = icon;
    m_speed->setIconsInfo(icon);
}

void YouhuaButton::setTitle(const QString &title)
{
    m_title = title;
    m_titleLabel->setText(title);
}

void YouhuaButton::setDescription(const QString &desc)
{
    m_description = desc;
    m_descriptionLabel->setText(m_description);
}

void YouhuaButton::setCheckedState(bool state)
{
    m_isChecked = state;
    m_speed->setCheckdStatus(m_isChecked);
}

void YouhuaButton::enterEvent(QEvent *)
{
    m_speed->setButtonStatus(BUTTON_ENTER);
}

void YouhuaButton::leaveEvent(QEvent *)
{
    m_speed->setButtonStatus(BUTTON_LEAVE);
}

void YouhuaButton::mousePressEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }
    m_speed->setButtonStatus(BUTTON_PRESSED);
}

void YouhuaButton::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }

    if(rect().contains(e->pos()))
    {
        this->setCheckedState((!m_isChecked));
        m_speed->setButtonStatus(BUTTON_ENTER);
        emit checkedChanged(m_isChecked);
        e->accept();
    }else{
        m_speed->setButtonStatus(BUTTON_LEAVE);
        e->ignore();
    }
}
