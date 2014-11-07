#include "cleanscanbottom.h"
#include "cleandynamicbuttonwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

CleanScanBottom::CleanScanBottom(QWidget *parent) :
    BaseStyleWidget(parent)
{
    this->setObjectName("bottomWidget");
    this->initUI();
}

void CleanScanBottom::initUI()
{
    m_trashButton = new CleanDynamicButtonWidget;
    m_trashButton->setObjectName("trashButton");
    m_buttonList.append(m_trashButton);

    m_traceButton = new CleanDynamicButtonWidget;
    m_traceButton->setObjectName("traceButton");
    m_buttonList.append(m_traceButton);

    m_regButton = new CleanDynamicButtonWidget;
    m_regButton->setObjectName("regButton");
    m_buttonList.append(m_regButton);

    QHBoxLayout *firstLayout = new QHBoxLayout;
    firstLayout->addWidget(m_trashButton, 0, Qt::AlignVCenter);
    firstLayout->addWidget(m_traceButton, 0, Qt::AlignVCenter);
    firstLayout->addWidget(m_regButton, 0, Qt::AlignVCenter);

    m_pluginButton = new CleanDynamicButtonWidget;
    m_pluginButton->setObjectName("pluginButton");
    m_buttonList.append(m_pluginButton);

    m_softButton = new CleanDynamicButtonWidget;
    m_softButton->setObjectName("softButton");
    m_buttonList.append(m_softButton);

    m_cookiesButton = new CleanDynamicButtonWidget;
    m_cookiesButton->setObjectName("cookiesButton");
    m_buttonList.append(m_cookiesButton);

    QHBoxLayout *secondLayout = new QHBoxLayout;
    secondLayout->addWidget(m_pluginButton, 0, Qt::AlignVCenter);
    secondLayout->addWidget(m_softButton, 0, Qt::AlignVCenter);
    secondLayout->addWidget(m_cookiesButton, 0, Qt::AlignVCenter);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(secondLayout);

    this->setLayout(mainLayout);
}

void CleanScanBottom::startFirstAnim()
{
    for(int i=0; i< m_buttonList.size(); i++)
    {
        m_buttonList.at(i)->startFirstAnim();
    }
}
