#include "scanbuttonwidget.h"
#include <QLabel>
#include <QVBoxLayout>
#include "../../commom/safebuttonwidget.h"

ScanButtonWidget::ScanButtonWidget(QWidget *parent) :
    QWidget(parent)
{
    m_animNum = 8;
    m_normalNum = 4;
    m_button = new SafeButtonWidget;
    m_textLabel = new QLabel;
    m_textLabel->setObjectName("scanButtonText");

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(m_button, 0, Qt::AlignCenter);
    vLayout->addSpacing(5);
    vLayout->addWidget(m_textLabel, 0, Qt::AlignHCenter);
    vLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(vLayout);

    connect(m_button, SIGNAL(buttonClicked()), this, SIGNAL(buttonClicked()));
}

void ScanButtonWidget::setAnimNum(int num)
{
    m_animNum = num;
}

void ScanButtonWidget::setAnimPix(const QString &pix)
{
    m_button->setAnimInfo(pix, m_animNum);
}

void ScanButtonWidget::setNormalNum(int num)
{
    m_normalNum = num;
}

void ScanButtonWidget::setNormalPix(const QString &pix)
{
    m_button->setNormalInfo(pix, m_normalNum);
}

void ScanButtonWidget::setText(const QString &text)
{
    m_text = text;
    m_textLabel->setText(text);
}
