#include "statictextbutton.h"
#include <QLabel>
#include <QVBoxLayout>
#include "staticbutton.h"

StaticTextButton::StaticTextButton(QWidget *parent) :
    QWidget(parent)
{
    m_num = 4;
    m_button = new StaticButton;
    m_textLabel = new QLabel;
    m_textLabel->setObjectName("staticText");

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(m_button, 0, Qt::AlignCenter);
    vLayout->addSpacing(5);
    vLayout->addWidget(m_textLabel, 0, Qt::AlignHCenter);
    vLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(vLayout);

    connect(m_button, SIGNAL(buttonClicked()), this, SIGNAL(buttonClicked()));
}

void StaticTextButton::setButtonPix(const QString &pix)
{
    m_button->setOneButtonInfo(pix, m_num);
}

void StaticTextButton::setText(const QString &text)
{
    m_text = text;
    m_textLabel->setText(m_text);
}
