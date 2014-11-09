#include "youhuascanbottom.h"
#include <QHBoxLayout>
#include "youhuabutton.h"

YouhuaScanBottom::YouhuaScanBottom(QWidget *parent) :
    BaseStyleWidget(parent)
{
    this->setObjectName("bottomWidget");
    this->initUI();
}

void YouhuaScanBottom::initUI()
{
    m_startButton = new YouhuaButton;
    m_startButton->setCheckedState(true);
    m_startButton->setObjectName("startButton");

    m_sysButton = new YouhuaButton;
    m_sysButton->setCheckedState(true);
    m_sysButton->setObjectName("sysButton");

    m_netButton = new YouhuaButton;
    m_netButton->setCheckedState(true);
    m_netButton->setObjectName("netButton");

    m_diskButton = new YouhuaButton;
    m_diskButton->setCheckedState(true);
    m_diskButton->setObjectName("diskButton");

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(m_startButton, 0, Qt::AlignVCenter);
    hLayout->addWidget(m_sysButton, 0, Qt::AlignVCenter);
    hLayout->addWidget(m_netButton, 0, Qt::AlignVCenter);
    hLayout->addWidget(m_diskButton, 0, Qt::AlignVCenter);

    this->setLayout(hLayout);
}
