#ifndef ANIMBUTTONGROUPWIDGET_H
#define ANIMBUTTONGROUPWIDGET_H

#include <QWidget>
#include "staticbutton.h"
class AnimButtonGroupWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AnimButtonGroupWidget(QWidget *parent = 0);
    void setButtonList(const QList<QString> &list);
signals:
    void turnPage(int);
private:
    QList<StaticButton*> m_buttonList;

};

#endif // ANIMBUTTONGROUPWIDGET_H
