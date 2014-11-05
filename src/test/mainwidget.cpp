#include "mainwidget.h"
#include <QPushButton>
#include "../commom/staticbutton.h"
#include "../commom/safebuttonwidget.h"
#include "../commom/speedoutbutton.h"
#include "../commom/toptabwidget.h"
#include "../commom/numbersanimwidget.h"
#include "../safe/common/safescanbottom.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    StaticButton *button = new StaticButton(":/default/clean", 4, this);
    //button->setEnabled(false);
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

    SpeedOutButton *speedButton = new SpeedOutButton(this);
    speedButton->setIconsInfo(":/default/disk");
    speedButton->setCheckdStatus(true);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(button);
    hLayout->addWidget(m_dyButton);
    hLayout->addWidget(safebutton);
    hLayout->addWidget(speedButton);

    TopTabWidget *topWidget = new TopTabWidget;

    m_numsWidget = new NumbersAnimWidget;
    m_numsWidget->setInitInfo(100, 4, ":/numbers/main/");
    QHBoxLayout *numLayout = new QHBoxLayout;
    numLayout->addWidget(m_numsWidget);

    numLayout->addStretch();
    numLayout->setSpacing(0);

    QTimer::singleShot(2000, this, SLOT(updateNum()));
    QVBoxLayout *vLayout = new QVBoxLayout;

    SafeScanBottom *scanButton = new SafeScanBottom;
    vLayout->addLayout(hLayout);
    vLayout->addWidget(topWidget);
    vLayout->addLayout(numLayout);
    vLayout->addWidget(scanButton);

    this->setLayout(vLayout);
}

void MainWidget::updateNum()
{
    m_numsWidget->setNums(1000);
}

void MainWidget::buttonClicked()
{
    m_dyButton->startFirstAnim();
}

MainWidget::~MainWidget()
{

}
