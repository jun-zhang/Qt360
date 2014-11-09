#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "common/shadowwidget.h"
class QParallelAnimationGroup;
class QStackedWidget;
class MainTopWidget;
class MainBottomWidget;
class SafeWidget;
class CleanWidget;
class YouhuaWidget;
class BaseStyleWidget;
class OpacityWidget;
class VideoWidget;

class MainWindow : public ShadowWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
private:
    void initUI();
    void initConnect();
    void initAnim();
private slots:
    void playVideo();
    void showSkin();
    void showMenu();
    void showMin();
    void closeWidget();
    void goToMain();
    void goToSafe();
    void goToClean();
    void goToYouhua();
    void upAnimFinished();
private:
    MainTopWidget   *m_topWidget;
    MainBottomWidget    *m_bottomWidget;
    QParallelAnimationGroup *m_upGroup;
    QParallelAnimationGroup *m_downGroup;
    QStackedWidget  *m_stackWidget;
    SafeWidget  *m_safeWidget;
    CleanWidget *m_cleanWidget;
    YouhuaWidget    *m_youhuaWidget;
    OpacityWidget *m_grayWidget;
    VideoWidget *m_video;
};

#endif // MAINWINDOW_H
