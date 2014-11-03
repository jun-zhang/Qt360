#include "userwidget.h"
#include <QHBoxLayout>
#include "../common/buttonlabel.h"
#include "../common/backgroundbutton.h"

UserWidget::UserWidget(QWidget *parent) :
    QWidget(parent)
{
    m_loginButton = new ButtonLabel;
    m_loginButton->setText(tr("登录360帐号"));

    m_userButton = new BackgroundButton;
    m_userButton->setIconsInfo(":/main/def_head", ":/main/head_bkg");

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addStretch();
    hLayout->addWidget(m_loginButton);
    hLayout->addWidget(m_userButton);
    hLayout->setSpacing(5);
    //hLayout->setContentsMargins();

    this->setLayout(hLayout);
}
