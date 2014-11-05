#include "mainexaminewidget.h"
#include "../../commom/wenliwidget.h"
#include <QVBoxLayout>

MainExamineWidget::MainExamineWidget(QWidget *parent) :
    BaseStyleWidget(parent)
{
//    this->setObjectName("examineWidget");
//    this->setStyleSheet("#examineWidget{background: #2abf1d;}");
    QVBoxLayout *vLayout = new QVBoxLayout;
    WenliWidget *wenliWidget = new WenliWidget;
    vLayout->addWidget(wenliWidget);
    vLayout->setContentsMargins(0,0,0,0);
    this->setLayout(vLayout);
}
