//解决直接继承QWidget的窗口不能使用qss样式表

#ifndef BASESTYLEWIDGET_H
#define BASESTYLEWIDGET_H

#include <QWidget>

class BaseStyleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BaseStyleWidget(QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *);
};

#endif // BASESTYLEWIDGET_H
