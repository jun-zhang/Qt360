#include "maintopwidget.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QStackedWidget>
#include "common/mainscorewidget.h"
#include "../commom/staticbutton.h"
#include "../commom/sysbuttongroup.h"

MainTopWidget::MainTopWidget(QWidget *parent) :
    BaseStyleWidget(parent)
{
    this->initData();
    this->initUI();
}

void MainTopWidget::initData()
{
    m_backgroundColor = QColor(Qt::green);
    m_toOrange = new QPropertyAnimation(this, "color");
    m_toOrange->setDuration(5000);
    m_toOrange->setStartValue(QColor(Qt::green));
    m_toOrange->setEndValue(QColor("#FFA500"));

    m_toYellow = new QPropertyAnimation(this, "color");
    m_toYellow->setDuration(2000);
    m_toYellow->setStartValue(QColor("#FFA500"));
    m_toYellow->setEndValue(QColor(Qt::yellow));
    m_opacity = 1.0;

    m_wenliPix = QPixmap(":/main/wenli");
    m_guangYPix = QPixmap(":/main/guangyun_green");
    m_type = 0;
}



void MainTopWidget::initUI()
{
    this->setFixedSize(m_wenliPix.size());
    this->initTopTitleWidget();
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
    titleLayout->setContentsMargins(10, 5, 10, 5);

    m_titleWidget->setLayout(titleLayout);

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

void MainTopWidget::returnMain()
{
    m_titleStacked->setCurrentIndex(0);
}

void MainTopWidget::examineClicked()
{
    m_titleStacked->setCurrentIndex(1);
}

void MainTopWidget::viewClicked()
{
    m_titleStacked->setCurrentIndex(1);
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
