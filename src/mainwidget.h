#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "commom/dynamicbutton.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
private slots:
    void buttonClicked();
private:
    DynamicButton *m_dyButton;
};

#endif // MAINWIDGET_H
