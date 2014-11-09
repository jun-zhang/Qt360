#include "youhuawidget.h"
#include "common/youhuascanbottom.h"
#include "../commom/wenlibackwidget.h"
#include "../commom/stackstatuswidget.h"
#include <QVBoxLayout>

YouhuaWidget::YouhuaWidget(QWidget *parent) :
    QWidget(parent)
{
    this->initUI();
}

void YouhuaWidget::initUI()
{
    m_topBackWidget = new WenliBackWidget;
    m_stackStatusWidget = new StackStatusWidget;
    m_topBackWidget->insertWidget(m_stackStatusWidget);
    m_topBackWidget->setButtonInfo(":/safe/return");
    m_stackStatusWidget->setStaticIcon(":/youhua/logo");
    m_stackStatusWidget->setNormalButton(":/youhua/start");
    m_stackStatusWidget->setTextInfo("一键优化，让电脑快如闪电", \
                                         "全面提升电脑开机速度、系统速度、上网速度、硬盘速度");
    m_topBackWidget->setFixedHeight(150);
    connect(m_topBackWidget, SIGNAL(buttonClicked()), this, SIGNAL(goToMain()));
    m_scanBottomWidget = new YouhuaScanBottom;

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(m_topBackWidget);
    vLayout->addWidget(m_scanBottomWidget);
    vLayout->setSpacing(0);
    vLayout->setContentsMargins(0,0,0,0);

    this->setLayout(vLayout);
}
