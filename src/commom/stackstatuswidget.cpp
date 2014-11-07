#include "stackstatuswidget.h"
#include "staticbutton.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

StackStatusWidget::StackStatusWidget(QWidget *parent) :
    QWidget(parent)
{
    this->initUI();
}

void StackStatusWidget::initUI()
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    m_logo = new QLabel;
    m_topText = new QLabel;
    m_topText->setObjectName("stacktopLabel");
    m_bottomText = new QLabel;
    m_bottomText->setObjectName("stackbottomLabel");
    m_normalButton = new StaticButton;
    connect(m_normalButton, SIGNAL(buttonClicked()), this, SIGNAL(normalClicked()));

    QVBoxLayout *textLayout = new QVBoxLayout;
    textLayout->addWidget(m_topText, 0, Qt::AlignLeft | Qt::AlignVCenter);
    textLayout->addSpacing(5);
    textLayout->addWidget(m_bottomText, 0, Qt::AlignLeft | Qt::AlignVCenter);
    textLayout->setContentsMargins(5, 10, 5, 10);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(m_logo, 0, Qt::AlignVCenter);
    mainLayout->addLayout(textLayout);
    mainLayout->addStretch();
    mainLayout->addWidget(m_normalButton, 0, Qt::AlignCenter);
    mainLayout->setContentsMargins(20, 0, 20, 20);

    this->setLayout(mainLayout);

}

void StackStatusWidget::setTextInfo(const QString &top, const QString &bottom)
{
    m_topText->setText(top);
    m_bottomText->setText(bottom);
}

void StackStatusWidget::setNormalButton(const QString &icon, int num)
{
    m_normalButton->setOneButtonInfo(icon, num);
}

void StackStatusWidget::setStaticIcon(const QString &icon)
{
    QPixmap pix(icon);
    m_logo->setFixedSize(pix.size());
    m_logo->setPixmap(pix);
}
