#include "mainwidget.h"
#include <QPushButton>
#include "commom/staticbutton.h"
#include <QHBoxLayout>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    StaticButton *button = new StaticButton(":/default/clean", this);
    connect(button, SIGNAL(buttonClicked()), this, SLOT(buttonClicked()));
    m_dyButton = new DynamicButton;
    m_dyButton->setFirstAnim(":/default/enter_anim", 11);
    m_dyButton->setNormalAnimInfo(":/default/soft_anim", 17);
    m_dyButton->setNormalIconsInfo(":/default/select_normal", ":/default/select_hover");
    m_dyButton->setNoSelectedAnimInfo(":/default/soft_anim_gray", 17);
    m_dyButton->setNoSelectedIconsInfo(":/default/notselect_normal", ":/default/notselect_hover");
    m_dyButton->setCheckedState(true);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(button);
    hLayout->addWidget(m_dyButton);

    this->setLayout(hLayout);
}

void MainWidget::buttonClicked()
{
    m_dyButton->startFirstAnim();
}

MainWidget::~MainWidget()
{

}
