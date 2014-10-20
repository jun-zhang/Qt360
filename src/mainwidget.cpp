#include "mainwidget.h"
#include <QPushButton>
#include "commom/staticbutton.h"
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    StaticButton *button = new StaticButton(":/default/clean", this);
    button->setEnabled(true);
}

MainWidget::~MainWidget()
{

}
