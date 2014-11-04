#include "mainwindow.h"
#include "mainbottomwidget.h"
#include "maintopwidget.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    ShadowWidget(parent)
{
    this->initUI();
    this->initConnect();
}

void MainWindow::initUI()
{
    this->setFixedSize(900, 600);
    m_topWidget = new MainTopWidget(this);
    m_bottomWidget = new MainBottomWidget(this);

}

void MainWindow::initConnect()
{
    connect(m_topWidget, SIGNAL(goExamine()), m_bottomWidget, SLOT(goExamine()));
    connect(m_topWidget, SIGNAL(goMain()), m_bottomWidget, SLOT(goMain()));
    connect(m_topWidget, SIGNAL(showMin()), this, SLOT(showMinimized()));
    connect(m_topWidget, SIGNAL(closeWidget()), this, SLOT(closeWidget()));

}

void MainWindow::playVideo()
{

}

void MainWindow::showMenu()
{

}

void MainWindow::showSkin()
{

}

void MainWindow::closeWidget()
{
    qApp->quit();
}

void MainWindow::showMin()
{

}
