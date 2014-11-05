#ifndef MAINTOPWIDGET_H
#define MAINTOPWIDGET_H

#include <QWidget>
#include <QPixmap>
#include "../commom/basestylewidget.h"

#define MAIN_TOP_WIDTH      900
#define MAIN_TOP_HEIGHT     440

class QPropertyAnimation;
class QStackedWidget;
class QParallelAnimationGroup;
class UserWidget;
class TopBottomWidget;
class MainScoreWidget;
class WenliWidget;

class MainTopWidget : public BaseStyleWidget
{
    Q_OBJECT
public:
    explicit MainTopWidget(QWidget *parent = 0);

public slots:
    void setNums(int num);
signals:
    void playVideo();
    void showSkin();
    void showMenu();
    void showMin();
    void closeWidget();
    void goExamine();
    void goMain();
protected:
    void resizeEvent(QResizeEvent *);
private slots:
    void examineClicked();
    void viewClicked();
    void returnMain();
    void returnAnimationFinished();
private:
    void initUI();
    void initTopTitleWidget();
    void initConnect();
    void initAnimations();
    void updateSizeAndPos();
private:
    QWidget *m_titleWidget;
    QStackedWidget *m_titleStacked;
    UserWidget *m_userWidget;
    MainScoreWidget *m_scoreWidget;
    TopBottomWidget *m_bottomWidget;
    QParallelAnimationGroup *m_examineGroupAnimation;
    QParallelAnimationGroup *m_returnGroupAnimation;
    WenliWidget *m_backgroundWidget;
};

#endif // MAINTOPWIDGET_H
