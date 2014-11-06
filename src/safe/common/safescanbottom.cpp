#include "safescanbottom.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "scanbuttonwidget.h"
#include "../../commom/statictextbutton.h"

SafeScanBottom::SafeScanBottom(QWidget *parent) :
    BaseStyleWidget(parent)
{
    this->initUI();
    this->initConnect();
    this->setStyleSheet("QWidget{background:white;}");
}

void SafeScanBottom::initUI()
{
    m_quick = new ScanButtonWidget;
    m_quick->setObjectName("quickButton");

    m_full = new ScanButtonWidget;
    m_full->setObjectName("fullButton");

    m_custom = new ScanButtonWidget;
    m_custom->setObjectName("customButton");

    QHBoxLayout *scanLayout = new QHBoxLayout;
    scanLayout->addWidget(m_quick);
    scanLayout->addWidget(m_full);
    scanLayout->addWidget(m_custom);
    scanLayout->setContentsMargins(0, 40, 0, 20);

    m_fix = new StaticTextButton;
    m_fix->setObjectName("fixButton");

    m_patch = new StaticTextButton;
    m_patch->setObjectName("patchButton");

    QHBoxLayout *staticLayout = new QHBoxLayout;
    staticLayout->addStretch();
    staticLayout->addWidget(m_fix);
    staticLayout->addWidget(m_patch);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addStretch();
    mainLayout->addLayout(scanLayout);
    mainLayout->addLayout(staticLayout);
    mainLayout->addSpacing(20);

    this->setLayout(mainLayout);

}

void SafeScanBottom::initConnect()
{
    connect(m_quick, SIGNAL(buttonClicked()), this, SIGNAL(quickClicked()));
    connect(m_full, SIGNAL(buttonClicked()), this, SIGNAL(fullClicked()));
    connect(m_custom, SIGNAL(buttonClicked()), this, SIGNAL(customClicked()));
    connect(m_fix, SIGNAL(buttonClicked()), this, SIGNAL(fixClicked()));
    connect(m_patch, SIGNAL(buttonClicked()), this, SIGNAL(patchClicked()));
}

