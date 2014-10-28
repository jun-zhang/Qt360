#include "animbuttongroupwidget.h"
#include <QHBoxLayout>
#include <QSignalMapper>
#include "staticbutton.h"
AnimButtonGroupWidget::AnimButtonGroupWidget(QWidget *parent) :
    QWidget(parent), m_isFirstPaint(true)
{
}

void AnimButtonGroupWidget::setButtonList(const QList<QString> &list)
{
    QHBoxLayout *hLayout = new QHBoxLayout;
    QSignalMapper *clickMapper = new QSignalMapper(this);
    QSignalMapper *enterMapper = new QSignalMapper(this);
    QSignalMapper *leaveMapper = new QSignalMapper(this);
    for(int i=0; i< list.size(); i++)
    {
        StaticButton *button = new StaticButton(list.at(i));
        m_perButtonWidth = button->width();
        hLayout->addWidget(button);
        m_buttonList.append(button);
        connect(button, SIGNAL(buttonClicked()), clickMapper, SLOT(map()));
        clickMapper->setMapping(button, i);

        connect(button, SIGNAL(enterSignal()), enterMapper, SLOT(map()));
        enterMapper->setMapping(button, i);

        connect(button, SIGNAL(leaveSignal()), leaveMapper, SLOT(map()));
        leaveMapper->setMapping(button, i);
    }
    connect(clickMapper, SIGNAL(mapped(int)), this, SLOT(clickButton(int)));
    connect(enterMapper, SIGNAL(mapped(int)), this, SLOT(enterButton(int)));
    connect(leaveMapper, SIGNAL(mapped(int)), this, SLOT(leaveButton(int)));

    hLayout->setContentsMargins(5, 2, 5, 2);
    hLayout->setSpacing(4);
    this->setLayout(hLayout);
}

void AnimButtonGroupWidget::clickButton(int index)
{
    emit setOriginSignal(int(m_buttonList.at(index)->x()));
    emit turnPage(index);
}

void AnimButtonGroupWidget::enterButton(int index)
{
    emit setEndSignal(int(m_buttonList.at(index)->x()));
}

void AnimButtonGroupWidget::leaveButton(int index)
{
    emit leaveButtonSignal();
}

void AnimButtonGroupWidget::paintEvent(QPaintEvent *)
{
    if(m_isFirstPaint)
    {
        emit setOriginSignal(int(m_buttonList.at(0)->x()));
        m_isFirstPaint = false;
    }
}
