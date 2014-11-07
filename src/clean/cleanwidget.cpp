#include "cleanwidget.h"
#include <QVBoxLayout>
#include "common/cleanscanbottom.h"
#include "../commom/wenlibackwidget.h"
#include "../commom/stackstatuswidget.h"

CleanWidget::CleanWidget(QWidget *parent) :
    QWidget(parent), m_isFirst(true)
{
    this->initUI();
}

void CleanWidget::initUI()
{
    m_topBackWidget = new WenliBackWidget;
    m_stackStatusWidget = new StackStatusWidget;
    m_topBackWidget->insertWidget(m_stackStatusWidget);
    m_topBackWidget->setButtonInfo(":/safe/return");
    m_stackStatusWidget->setStaticIcon(":/clean/top_scan");
    m_stackStatusWidget->setNormalButton(":/clean/btn_top_scan");
    m_stackStatusWidget->setTextInfo("已选择6项清理类型", "经常清理，让电脑保持最佳状态");
    m_topBackWidget->setFixedHeight(150);
    connect(m_topBackWidget, SIGNAL(buttonClicked()), this, SIGNAL(goToMain()));
    m_scanBottomWidget = new CleanScanBottom;

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(m_topBackWidget);
    vLayout->addWidget(m_scanBottomWidget);
    vLayout->setSpacing(0);
    vLayout->setContentsMargins(0,0,0,0);

    this->setLayout(vLayout);
}

void CleanWidget::startFirst()
{
    if(m_isFirst)
    {
        m_scanBottomWidget->startFirstAnim();
        m_isFirst = !m_isFirst;
    }
}
