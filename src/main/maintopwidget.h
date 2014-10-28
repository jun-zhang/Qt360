#ifndef MAINTOPWIDGET_H
#define MAINTOPWIDGET_H

#include <QWidget>
#include "../commom/basestylewidget.h"
class MainTopWidget : public BaseStyleWidget
{
    Q_OBJECT
public:
    explicit MainTopWidget(QWidget *parent = 0);
    void setSkinType(int type);
protected:
    void paintEvent(QPaintEvent *);
private:
    void initUI();
private:
    int m_type;
};

#endif // MAINTOPWIDGET_H
