#ifndef MAINBOTTOMFIRSTWIDGET_H
#define MAINBOTTOMFIRSTWIDGET_H

#include <QWidget>
#include "../../commom/basestylewidget.h"
class StaticButton;
//class BackgroundButton;
class MainBottomFirstWidget : public BaseStyleWidget
{
    Q_OBJECT
public:
    explicit MainBottomFirstWidget(QWidget *parent = 0);
signals:
    void safeClicked();
    void cleanClicked();
    void youhuaClicked();
    void advtoolMoreClicked();
private:
    void initUI();
    void initConnect();
private:
    StaticButton *m_safeButton;
    StaticButton *m_cleanButton;
    StaticButton *m_youhuaButton;
    StaticButton *m_advtoolMore;
};

#endif // MAINBOTTOMFIRSTWIDGET_H
