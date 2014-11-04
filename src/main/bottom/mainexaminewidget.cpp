#include "mainexaminewidget.h"

MainExamineWidget::MainExamineWidget(QWidget *parent) :
    BaseStyleWidget(parent)
{
    this->setObjectName("examineWidget");
    this->setStyleSheet("#examineWidget{background: red;}");
}
