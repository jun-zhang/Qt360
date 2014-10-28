#include "toptabwidget.h"
#include <QVBoxLayout>
#include "animbuttongroupwidget.h"
#include "animbuttonwidget.h"

TopTabWidget::TopTabWidget(QWidget *parent) :
    QWidget(parent)
{
    m_buttonGroup = new AnimButtonGroupWidget;
    m_animButton = new AnimButtonWidget;

    QList<QString> iconList;
    iconList << ":/default/tab_start" << ":/default/tab_ignore" << ":/default/tab_opt";
    m_buttonGroup->setButtonList(iconList);

    m_animButton->setAnimInfo(10, 15);
    m_animButton->setLineInfo(m_buttonGroup->perButtonWidth(), QColor(Qt::white));

    connect(m_buttonGroup, SIGNAL(leaveButtonSignal()), m_animButton, SLOT(leaveButton()));
    connect(m_buttonGroup, SIGNAL(setOriginSignal(int)), m_animButton, SLOT(setOriginX(int)));
    connect(m_buttonGroup, SIGNAL(setEndSignal(int)), m_animButton, SLOT(setEndX(int)));

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(m_buttonGroup);
    vLayout->addWidget(m_animButton);

    this->setLayout(vLayout);
}
