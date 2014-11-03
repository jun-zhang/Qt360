#include "mainscorewidget.h"
#include "../../commom/staticbutton.h"
#include "../common/scorewidget.h"
#include "../common/buttonlabel.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>

MainScoreWidget::MainScoreWidget(QWidget *parent) :
    QWidget(parent)
{
    this->initUI();
}

void MainScoreWidget::initUI()
{
    m_scoreWidget = new ScoreWidget;
    m_topLabel = new QLabel;
    m_topLabel->setObjectName("toplabel");
    m_bottomLabel = new QLabel;
    m_bottomLabel->setObjectName("bottomlabel");

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addStretch();
    vLayout->addWidget(m_topLabel, 0, Qt::AlignVCenter | Qt::AlignLeft);
    vLayout->addWidget(m_bottomLabel, 0, Qt::AlignVCenter | Qt::AlignLeft);
    vLayout->addStretch();
    vLayout->setSpacing(10);
    vLayout->setContentsMargins(0, 0, 0, 0);

    this->initButtonLayout();
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(m_scoreWidget);
    hLayout->addSpacing(10);
    hLayout->addLayout(vLayout);
    hLayout->addWidget(m_stackedWidget, 0, Qt::AlignRight | Qt::AlignVCenter);
    hLayout->setContentsMargins(10, 5, 10, 5);

    this->setLayout(hLayout);
    this->setFixedHeight(m_scoreWidget->height() + 10);
}

void MainScoreWidget::initButtonLayout()
{
    m_stackedWidget = new QStackedWidget;
    ButtonLabel *cancleButton = new ButtonLabel;
    cancleButton->setText("取消体检");
    connect(cancleButton, SIGNAL(labelClicked()), this, SIGNAL(cancleExamine()));

    QWidget *fixWidget = new QWidget;
    StaticButton *fixButton = new StaticButton(":/main/btn_fix_all");
    connect(fixButton, SIGNAL(buttonClicked()), this, SIGNAL(oneFix()));
    ButtonLabel *reExamineButton = new ButtonLabel;
    reExamineButton->setText("重新体检");
    connect(reExamineButton, SIGNAL(labelClicked()), this, SIGNAL(reExamine()));

    QVBoxLayout *fixVLayout = new QVBoxLayout;
    fixVLayout->addWidget(fixButton);
    fixVLayout->addWidget(reExamineButton);
    fixWidget->setLayout(fixVLayout);

    StaticButton *reStaticButton = new StaticButton(":/main/btn_reexamine");
    connect(reStaticButton, SIGNAL(buttonClicked()), this, SIGNAL(reExamine()));

    m_stackedWidget->addWidget(cancleButton);
    m_stackedWidget->addWidget(fixWidget);
    m_stackedWidget->addWidget(reStaticButton);
}

void MainScoreWidget::setButtonStatus(int status)
{
    switch (status) {
    case SCORE_NO_BUTTON:
        m_stackedWidget->hide();
        break;
    case SCORE_CANCLE_BUTTON:
    case SCORE_FIX_BUTTON:
    case SCORE_RE_BUTTON:
    {
        m_stackedWidget->show();
        m_stackedWidget->setCurrentIndex(status);
    }
        break;
    default:
        break;
    }
}

void MainScoreWidget::setScoreStatus(int status)
{
    m_scoreWidget->setScoreStatus(status);
}

void MainScoreWidget::setNums(int num)
{
    m_scoreWidget->setNums(num);
}

void MainScoreWidget::setTextInfo(const QString &topText, const QString &bottomText)
{
    m_topLabel->setText(topText);
    m_topLabel->adjustSize();
    m_bottomLabel->setText(bottomText);
    m_bottomLabel->adjustSize();
}
