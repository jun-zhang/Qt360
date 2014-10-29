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
public slots:
    void setNums(int num);
signals:

protected:
    void paintEvent(QPaintEvent *);
private slots:
    void examineClicked();
    void viewClicked();
private:
    void initUI();
private:
    int m_type;
    QPixmap m_guangYPix;
    QColor m_backgroundColor;
};

#endif // MAINTOPWIDGET_H
