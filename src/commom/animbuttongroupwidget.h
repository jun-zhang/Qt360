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
    int perButtonWidth()
    {
        return m_perButtonWidth;
    }
signals:
    void turnPage(int);
    void leaveButtonSignal();
    void setOriginSignal(int);
    void setEndSignal(int);
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void clickButton(int index);
    void enterButton(int index);
    void leaveButton(int index);
private:
    QList<StaticButton*> m_buttonList;
    int m_perButtonWidth;
    bool m_isFirstPaint;
};

#endif // ANIMBUTTONGROUPWIDGET_H
