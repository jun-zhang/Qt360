#include "sysbuttongroup.h"
#include <QHBoxLayout>
#include "staticbutton.h"
SysButtonGroup::SysButtonGroup(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *hLayout = new QHBoxLayout;
    StaticButton *playButton = new StaticButton(":/main/playvideo");
    connect(playButton, SIGNAL(buttonClicked()), this, SIGNAL(playVideo()));

    StaticButton *skinButton = new StaticButton(":/main/skin");
    connect(skinButton, SIGNAL(buttonClicked()), this, SIGNAL(showSkin()));

    StaticButton *menuButton = new StaticButton(":/main/menu");
    connect(menuButton, SIGNAL(buttonClicked()), this, SIGNAL(showMenu()));

    StaticButton *minButton = new StaticButton(":/main/sys_min");
    connect(minButton, SIGNAL(buttonClicked()), this, SIGNAL(showMin()));

    StaticButton *closeButton = new StaticButton(":/main/sys_close");
    connect(closeButton, SIGNAL(buttonClicked()), this, SIGNAL(closeWidget()));

    hLayout->addWidget(playButton);
    hLayout->addWidget(skinButton);
    hLayout->addWidget(menuButton);
    hLayout->addWidget(minButton);
    hLayout->addWidget(closeButton);
    hLayout->setContentsMargins(5, 0, 5, 0);
    hLayout->setSpacing(0);

    this->setLayout(hLayout);
}
