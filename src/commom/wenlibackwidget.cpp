#include "wenlibackwidget.h"
#include "staticbutton.h"
#include "wenliwidget.h"
#include "sysbuttongroup.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

WenliBackWidget::WenliBackWidget(QWidget *parent) :
    QWidget(parent)
{
    this->initUI();
    this->initConnect();
}

void WenliBackWidget::initUI()
{
    m_back = new WenliWidget(this);
    m_button = new StaticButton;
    m_groupButton = new SysButtonGroup;
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(m_button, 0, Qt::AlignLeft | Qt::AlignTop);
    hLayout->addStretch();
    hLayout->addWidget(m_groupButton, 0, Qt::AlignRight | Qt::AlignTop);
    hLayout->setContentsMargins(0, 0, 2, 0);

    m_vLayout = new QVBoxLayout;
    m_vLayout->addLayout(hLayout);

}

void WenliBackWidget::initConnect()
{
    connect(m_groupButton, SIGNAL(playVideo()), this, SIGNAL(playVideo()));
    connect(m_groupButton, SIGNAL(showSkin()), this, SIGNAL(showSkin()));
    connect(m_groupButton, SIGNAL(showMenu()), this, SIGNAL(showMenu()));
    connect(m_groupButton, SIGNAL(showMin()), this, SIGNAL(showMin()));
    connect(m_groupButton, SIGNAL(closeWidget()), this, SIGNAL(closeWidget()));
    connect(m_button, SIGNAL(buttonClicked()), this, SIGNAL(buttonClicked()));
}

void WenliBackWidget::resizeEvent(QResizeEvent *)
{
    m_back->setGeometry(rect());
}

void WenliBackWidget::setButtonInfo(const QString &icon, int num)
{
    m_button->setOneButtonInfo(icon, num);
}

void WenliBackWidget::insertWidget(QWidget *widget)
{
    m_vLayout->addWidget(widget);
    m_vLayout->setContentsMargins(0, 0, 0, 0);
    m_vLayout->setSpacing(0);

    this->setLayout(m_vLayout);
}

void WenliBackWidget::insertLayout(QLayout *layout)
{
    m_vLayout->addLayout(layout);
    m_vLayout->setContentsMargins(0, 0, 0, 0);
    m_vLayout->setSpacing(0);

    this->setLayout(m_vLayout);
}
