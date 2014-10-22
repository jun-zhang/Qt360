#include "mainwidget.h"
#include <QPushButton>
#include "commom/staticbutton.h"
#include "commom/safebuttonwidget.h"
#include <QHBoxLayout>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    StaticButton *button = new StaticButton(":/default/clean", 4, this);
    connect(button, SIGNAL(buttonClicked()), this, SLOT(buttonClicked()));
    m_dyButton = new DynamicButton;
    m_dyButton->setFirstAnim(":/default/enter_anim", 11);
    m_dyButton->setNormalAnimInfo(":/default/soft_anim", 17);
    m_dyButton->setNormalIconsInfo(":/default/select_normal", ":/default/select_hover");
    m_dyButton->setNoSelectedAnimInfo(":/default/soft_anim_gray", 17);
    m_dyButton->setNoSelectedIconsInfo(":/default/notselect_normal", ":/default/notselect_hover");
    m_dyButton->setCheckedState(true);

    SafeButtonWidget *safebutton = new SafeButtonWidget(this);
    safebutton->setIconsInfo(":/default/scan_button_quick_hover", 8,
                             ":/default/scan_button_quick");

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(button);
    hLayout->addWidget(m_dyButton);
    hLayout->addWidget(safebutton);

    this->setLayout(hLayout);
}

void MainWidget::buttonClicked()
{
    m_dyButton->startFirstAnim();
}

MainWidget::~MainWidget()
{

}
