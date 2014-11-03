#include "topbottomwidget.h"
#include "../../commom/staticbutton.h"
#include <QStackedWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

TopBottomWidget::TopBottomWidget(QWidget *parent) :
    QWidget(parent)
{
    this->initUI();
    this->initConnect();
}

void TopBottomWidget::initUI()
{
    m_stacked = new QStackedWidget;
    m_examineButton = new StaticButton(":/main/btn_examine_now");
    m_stacked->addWidget(m_examineButton);
    m_viewButton = new StaticButton(":/main/btn_view_detail");
    m_stacked->addWidget(m_viewButton);

    m_payinsureButton = new StaticButton(":/main/payinsure_safe", true);
    m_securityButton = new StaticButton(":/main/security_safe", true);
    QLabel *line = new QLabel;
    QPixmap pix(":/main/guardline");
    line->setPixmap(pix);
    line->setFixedSize(pix.size());

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(m_payinsureButton);
    hLayout->addWidget(line);
    hLayout->addSpacing(15);
    hLayout->addWidget(m_securityButton);
    hLayout->addStretch();
    hLayout->setSpacing(5);
    hLayout->setContentsMargins(15, 10, 10, 30);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_stacked, 0, Qt::AlignCenter);
    mainLayout->addLayout(hLayout);

    this->setLayout(mainLayout);
}

void TopBottomWidget::initConnect()
{
    connect(m_examineButton, SIGNAL(buttonClicked()), this, SIGNAL(examineClicked()));
    connect(m_viewButton, SIGNAL(buttonClicked()), this, SIGNAL(viewClicked()));
    connect(m_payinsureButton, SIGNAL(buttonClicked()), this, SIGNAL(payinsureClicked()));
    connect(m_securityButton, SIGNAL(buttonClicked()), this, SIGNAL(securityClicked()));
}

void TopBottomWidget::setStackedButton(int index)
{
    m_stacked->setCurrentIndex(index);
}
