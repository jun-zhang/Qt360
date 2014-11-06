#include "safewidget.h"
#include "common/safescanbottom.h"
#include "../commom/wenlibackwidget.h"
#include "../commom/stackstatuswidget.h"
#include <QVBoxLayout>

SafeWidget::SafeWidget(QWidget *parent) :
    QWidget(parent)
{
    this->initUI();
}

void SafeWidget::initUI()
{
    m_topBackWidget = new WenliBackWidget;
    m_stackStatusWidget = new StackStatusWidget;
    m_topBackWidget->insertWidget(m_stackStatusWidget);
    m_topBackWidget->setButtonInfo(":/safe/return");
    m_stackStatusWidget->setStaticIcon(":/safe/logo_normal");
    m_stackStatusWidget->setNormalButton(":/safe/start");
    m_stackStatusWidget->setTextInfo("安全扫描", "谢谢使用");
    m_topBackWidget->setFixedHeight(150);
    connect(m_topBackWidget, SIGNAL(buttonClicked()), this, SIGNAL(goToMain()));
    m_scanBottomWidget = new SafeScanBottom;

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(m_topBackWidget);
    vLayout->addWidget(m_scanBottomWidget);
    vLayout->setSpacing(0);
    vLayout->setContentsMargins(0,0,0,0);

    this->setLayout(vLayout);

}
