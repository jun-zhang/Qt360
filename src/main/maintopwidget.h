#ifndef MAINTOPWIDGET_H
#define MAINTOPWIDGET_H

#include <QWidget>
#include <QPixmap>
#include "../commom/basestylewidget.h"
class QPropertyAnimation;
class QStackedWidget;
class QParallelAnimationGroup;
class UserWidget;
class TopBottomWidget;
class MainScoreWidget;

class MainTopWidget : public BaseStyleWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor)
public:
    explicit MainTopWidget(QWidget *parent = 0);
    void setSkinType(int type);
    void setColor(const QColor &color);
    const QColor &color()
    {
        return m_backgroundColor;
    }

public slots:
    void setNums(int num);
signals:
    void playVideo();
    void showSkin();
    void showMenu();
    void showMin();
    void closeWidget();
protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
private slots:
    void examineClicked();
    void viewClicked();
    void returnMain();
    void returnAnimationFinished();
private:
    void initUI();
    void initTopTitleWidget();
    void initData();
    void initConnect();
    void initAnimations();
    void updateSizeAndPos();
private:
    int m_type;
    int m_num;
    qreal m_opacity;
    QPixmap m_guangYPix;
    QPixmap m_wenliPix;
    QColor m_backgroundColor;
    QPropertyAnimation *m_toOrange;
    QPropertyAnimation *m_toYellow;
    QWidget *m_titleWidget;
    QStackedWidget *m_titleStacked;
    UserWidget *m_userWidget;
    MainScoreWidget *m_scoreWidget;
    TopBottomWidget *m_bottomWidget;
    QParallelAnimationGroup *m_examineGroupAnimation;
    QParallelAnimationGroup *m_returnGroupAnimation;
};

#endif // MAINTOPWIDGET_H
