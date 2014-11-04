#ifndef MAINBOTTOMWIDGET_H
#define MAINBOTTOMWIDGET_H

#include <QWidget>
#include "../commom/basestylewidget.h"
class MainExamineWidget;
class MainBottomFirstWidget;
class QStackedLayout;
class QPropertyAnimation;

class MainBottomWidget : public BaseStyleWidget
{
    Q_OBJECT
public:
    explicit MainBottomWidget(QWidget *parent = 0);
public slots:
    void goExamine();
    void goMain();
private slots:
    void goExamineFinished();
    void goMainFinished();
signals:
    void safeClicked();
    void cleanClicked();
    void youhuaClicked();
    void advtoolMoreClicked();
private:
    void initUI();
    void initAnimation();
    void initConnect();
private:
    MainExamineWidget *m_examineWidget;
    MainBottomFirstWidget *m_firstWidget;
    QStackedLayout  *m_stackedWidget;
    QPropertyAnimation  *m_examineAnimation;
    QPropertyAnimation  *m_returnAnimation;
};

#endif // MAINBOTTOMWIDGET_H
