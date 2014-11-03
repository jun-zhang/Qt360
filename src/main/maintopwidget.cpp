#include "maintopwidget.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QStackedWidget>
#include "top/mainscorewidget.h"
#include "../commom/staticbutton.h"
#include "../commom/sysbuttongroup.h"
#include "top/topbottomwidget.h"
#include "top/userwidget.h"

MainTopWidget::MainTopWidget(QWidget *parent) :
    BaseStyleWidget(parent)
{
    this->initData();
    this->initUI();
    this->initAnimations();
    this->initConnect();
}

void MainTopWidget::initAnimations()
{
    m_toOrange = new QPropertyAnimation(this, "color");
    m_toOrange->setDuration(5000);
    m_toOrange->setStartValue(QColor(Qt::green));
    m_toOrange->setEndValue(QColor("#FFA500"));

    m_toYellow = new QPropertyAnimation(this, "color");
    m_toYellow->setDuration(2000);
    m_toYellow->setStartValue(QColor("#FFA500"));
    m_toYellow->setEndValue(QColor(Qt::yellow));

    QRect mainRect(0, 0, width(), 240);
    QRect origRect = rect();
    QPoint origPoint = m_scoreWidget->pos();
    QPoint toPoint(0, m_titleWidget->height() + 10);

    QPropertyAnimation *mainExamineAnim = new QPropertyAnimation(this, "geometry");
    mainExamineAnim->setDuration(200);
    mainExamineAnim->setStartValue(origRect);
    mainExamineAnim->setEndValue(mainRect);

    QPropertyAnimation *scoreExamineAnim = new QPropertyAnimation(m_scoreWidget, "pos");
    scoreExamineAnim->setDuration(200);
    scoreExamineAnim->setStartValue(origPoint);
    scoreExamineAnim->setEndValue(toPoint);

    m_examineGroupAnimation = new QParallelAnimationGroup(this);
    m_examineGroupAnimation->addAnimation(mainExamineAnim);
    m_examineGroupAnimation->addAnimation(scoreExamineAnim);

    QPropertyAnimation *mainReturnAnim = new QPropertyAnimation(this, "geometry");
    mainReturnAnim->setDuration(200);
    mainReturnAnim->setStartValue(mainRect);
    mainReturnAnim->setEndValue(origRect);

    QPropertyAnimation *scoreReturnAnim = new QPropertyAnimation(m_scoreWidget, "pos");
    scoreReturnAnim->setDuration(200);
    scoreReturnAnim->setStartValue(toPoint);
    scoreReturnAnim->setEndValue(origPoint);

    m_returnGroupAnimation = new QParallelAnimationGroup(this);
    m_returnGroupAnimation->addAnimation(mainReturnAnim);
    m_returnGroupAnimation->addAnimation(scoreReturnAnim);
}

void MainTopWidget::initData()
{
    m_backgroundColor = QColor(Qt::green);
    m_opacity = 1.0;

    m_wenliPix = QPixmap(":/main/wenli");
    m_guangYPix = QPixmap(":/main/guangyun_green");
    m_type = 0;
}



void MainTopWidget::initUI()
{
    //this->setFixedSize(m_wenliPix.size());
    this->setGeometry(0, 0, m_wenliPix.width(), m_wenliPix.height());
    this->initTopTitleWidget();
    m_userWidget = new  UserWidget(this);
    m_userWidget->setFixedWidth(width());

    m_scoreWidget = new MainScoreWidget(this);
    m_scoreWidget->setButtonStatus(SCORE_NO_BUTTON);
    m_scoreWidget->setScoreStatus(SCORE_QUESTION);
    m_scoreWidget->setTextInfo(tr("建议体检"), tr("建议每天进行体检"));
    m_scoreWidget->setFixedWidth(width());

    m_bottomWidget = new TopBottomWidget(this);
    m_bottomWidget->setFixedWidth(width());
    updateSizeAndPos();
}

void MainTopWidget::initTopTitleWidget()
{
    m_titleWidget = new QWidget(this);
    m_titleWidget->setAttribute(Qt::WA_TranslucentBackground);
    m_titleWidget->setFixedWidth(width());
    m_titleWidget->move(0, 0);

    QLabel *logoLabel = new QLabel;
    logoLabel->setPixmap(QPixmap(":/main/logo"));
    QLabel *textLabel = new QLabel;
    textLabel->setText("360安全卫士 10.0 Beta");
    textLabel->adjustSize();
    StaticButton *updateButton = new StaticButton(":/main/update_btn");
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(logoLabel);
    hLayout->addWidget(textLabel);
    hLayout->addWidget(updateButton);

    QWidget *title = new QWidget;
    title->setAttribute(Qt::WA_TranslucentBackground);
    title->setLayout(hLayout);

    StaticButton *returnButton = new StaticButton(":/main/return");
    connect(returnButton, SIGNAL(buttonClicked()), this, SLOT(returnMain()));

    m_titleStacked = new QStackedWidget;
    m_titleStacked->addWidget(title);
    m_titleStacked->addWidget(returnButton);
    m_titleStacked->setFixedHeight(returnButton->height());

    SysButtonGroup *buttonGroup = new SysButtonGroup;
    connect(buttonGroup, SIGNAL(playVideo()), this, SIGNAL(playVideo()));
    connect(buttonGroup, SIGNAL(showSkin()), this, SIGNAL(showSkin()));
    connect(buttonGroup, SIGNAL(showMenu()), this, SIGNAL(showMenu()));
    connect(buttonGroup, SIGNAL(showMin()), this, SIGNAL(showMin()));
    connect(buttonGroup, SIGNAL(closeWidget()), this, SIGNAL(closeWidget()));

    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(m_titleStacked, 0, Qt::AlignLeft | Qt::AlignTop);
    titleLayout->addStretch();
    titleLayout->addWidget(buttonGroup, 0, Qt::AlignRight | Qt::AlignTop);
    titleLayout->setContentsMargins(0, 0, 0, 0);

    m_titleWidget->setLayout(titleLayout);

}

void MainTopWidget::initConnect()
{
    connect(m_bottomWidget, SIGNAL(examineClicked()), this, SLOT(examineClicked()));
    connect(m_bottomWidget, SIGNAL(viewClicked()), this, SLOT(viewClicked()));
    connect(m_returnGroupAnimation, SIGNAL(finished()), this, SLOT(returnAnimationFinished()));
}

void MainTopWidget::updateSizeAndPos()
{
    m_userWidget->move(0, m_titleWidget->y() + m_titleWidget->height() + 10);
    m_scoreWidget->move(0, m_userWidget->y() + m_userWidget->height() + 10);
    m_bottomWidget->move(0, m_scoreWidget->y() + m_scoreWidget->height() + 10);
}

void MainTopWidget::setColor(const QColor &color)
{
    m_backgroundColor = color;
    int count;
    int current;
    if(m_num > 70 && m_num < 90)
    {
        count = m_toOrange->duration();
        current = m_toOrange->currentLoopTime();
        if(current <= (count/2))
        {
            m_guangYPix = QPixmap(":/main/guangyun_green");
            m_opacity = 1 - current/(count/2.0);
        }else if(current > (count/2))
        {
            m_guangYPix = QPixmap(":/main/guangyun_orange");
            m_opacity = current/(count/2.0) - 1.0;
        }
    }else if(m_num > 0 && m_num <= 70)
    {
        count = m_toYellow->duration();
        current = m_toYellow->currentLoopTime();
        if(current <= (count/2))
        {
            m_guangYPix = QPixmap(":/main/guangyun_orange");
            m_opacity = 1 - current/(count/2.0);
        }else if(current > (count/2))
        {
            m_guangYPix = QPixmap(":/main/guangyun_yellow");
            m_opacity = current/(count/2.0) - 1.0;
        }

    }

    update();
}

void MainTopWidget::setSkinType(int type)
{
    m_type = type;
}

void MainTopWidget::returnAnimationFinished()
{
    m_userWidget->show();
    m_bottomWidget->show();
}

void MainTopWidget::returnMain()
{
    m_titleStacked->setCurrentIndex(0);
    m_bottomWidget->setStackedButton(0);
    m_scoreWidget->setButtonStatus(SCORE_NO_BUTTON);
    m_returnGroupAnimation->start();
}

void MainTopWidget::examineClicked()
{
    m_titleStacked->setCurrentIndex(1);
    m_userWidget->hide();
    m_bottomWidget->hide();
    m_scoreWidget->setButtonStatus(SCORE_FIX_BUTTON);
    m_scoreWidget->setNums(85);
    m_examineGroupAnimation->start();
}

void MainTopWidget::viewClicked()
{
    m_titleStacked->setCurrentIndex(1);
    m_userWidget->hide();
    m_bottomWidget->hide();
    m_examineGroupAnimation->start();
}

void MainTopWidget::setNums(int num)
{
    m_num = num;
    if(num >= 90)
    {

    }else if(num >= 70)
    {
        m_toOrange->start();
    }else{
        m_toYellow->start();
    }

}

void MainTopWidget::resizeEvent(QResizeEvent *)
{
    //updateSizeAndPos();
}

void MainTopWidget::paintEvent(QPaintEvent *)
{
    if(m_type == 0)
    {
        QPainter painter(this);
        painter.setPen(Qt::NoPen);
        painter.setBrush(m_backgroundColor);
        painter.drawRect(rect());
        painter.setOpacity(m_opacity);
        painter.drawPixmap(rect(), m_guangYPix);
        painter.setOpacity(1.0);
        painter.drawPixmap(rect(), m_wenliPix);
    }
}
