#include "mainwindow.h"
#include "mainbottomwidget.h"
#include "maintopwidget.h"
#include "../safe/safewidget.h"
#include "../clean/cleanwidget.h"
#include "../youhua/youhuawidget.h"
#include <QApplication>
#include <QFile>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

MainWindow::MainWindow(QWidget *parent) :
    ShadowWidget(parent)
{
    this->initUI();
    this->initConnect();
    this->initAnim();
}

void MainWindow::initUI()
{
    this->setFixedSize(900, 600);
    m_topWidget = new MainTopWidget(this);
    m_bottomWidget = new MainBottomWidget(this);
    m_stackWidget = new QStackedWidget(this);
    m_stackWidget->setGeometry(rect());
    m_stackWidget->lower();

    m_safeWidget = new SafeWidget;
    m_stackWidget->addWidget(m_safeWidget);
    m_cleanWidget = new CleanWidget;
    m_stackWidget->addWidget(m_cleanWidget);
    m_youhuaWidget = new YouhuaWidget;
    m_stackWidget->addWidget(m_youhuaWidget);
}

void MainWindow::initConnect()
{
    connect(m_topWidget, SIGNAL(goExamine()), m_bottomWidget, SLOT(goExamine()));
    connect(m_topWidget, SIGNAL(goMain()), m_bottomWidget, SLOT(goMain()));
    connect(m_topWidget, SIGNAL(showMin()), this, SLOT(showMinimized()));
    connect(m_topWidget, SIGNAL(closeWidget()), this, SLOT(closeWidget()));
    connect(m_topWidget, SIGNAL(showSkin()), this, SLOT(showSkin()));
    connect(m_safeWidget, SIGNAL(goToMain()), this, SLOT(goToMain()));
    connect(m_cleanWidget, SIGNAL(goToMain()), this, SLOT(goToMain()));
    connect(m_youhuaWidget, SIGNAL(goToMain()), this, SLOT(goToMain()));
    connect(m_bottomWidget, SIGNAL(safeClicked()), this, SLOT(goToSafe()));
    connect(m_bottomWidget, SIGNAL(cleanClicked()), this, SLOT(goToClean()));
    connect(m_bottomWidget, SIGNAL(youhuaClicked()), this, SLOT(goToYouhua()));
}

void MainWindow::initAnim()
{
    QPropertyAnimation *m_upMainAnimation = new QPropertyAnimation(m_topWidget, "pos");
    m_upMainAnimation->setDuration(200);
    m_upMainAnimation->setStartValue(QPoint(0, 0));
    m_upMainAnimation->setEndValue(QPoint(0, -440));

    QPropertyAnimation *m_downMainAnimation = new QPropertyAnimation(m_bottomWidget, "pos");
    m_downMainAnimation->setDuration(200);
    m_downMainAnimation->setStartValue(QPoint(0, 440));
    m_downMainAnimation->setEndValue(QPoint(0, 600));

    m_upGroup = new QParallelAnimationGroup;
    m_upGroup->addAnimation(m_upMainAnimation);
    m_upGroup->addAnimation(m_downMainAnimation);

    QPropertyAnimation *m_upGarAnimation = new QPropertyAnimation(m_topWidget, "pos");
    m_upGarAnimation->setDuration(200);
    m_upGarAnimation->setStartValue(QPoint(0, -440));
    m_upGarAnimation->setEndValue(QPoint(0, 0));

    QPropertyAnimation *m_downGarAnimation = new QPropertyAnimation(m_bottomWidget, "pos");
    m_downGarAnimation->setDuration(200);
    m_downGarAnimation->setStartValue(QPoint(0, 600));
    m_downGarAnimation->setEndValue(QPoint(0, 440));

    m_downGroup = new QParallelAnimationGroup;
    m_downGroup->addAnimation(m_upGarAnimation);
    m_downGroup->addAnimation(m_downGarAnimation);
}

void MainWindow::playVideo()
{

}

void MainWindow::showMenu()
{

}

void MainWindow::goToMain()
{
    m_downGroup->start();
}

void MainWindow::goToSafe()
{
    m_stackWidget->setCurrentIndex(0);
    m_upGroup->start();
}

void MainWindow::goToClean()
{
    m_stackWidget->setCurrentIndex(1);
    m_upGroup->start();
    m_cleanWidget->startFirst();
}

void MainWindow::goToYouhua()
{
    m_stackWidget->setCurrentIndex(2);
    m_upGroup->start();
}

void MainWindow::showSkin()
{
    QFile qss(":/qss/skin");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
    update();
}

void MainWindow::closeWidget()
{
    qApp->quit();
}

void MainWindow::showMin()
{

}
