#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "common/shadowwidget.h"

class MainTopWidget;
class MainBottomWidget;

class MainWindow : public ShadowWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
private:
    void initUI();
    void initConnect();
private slots:
    void playVideo();
    void showSkin();
    void showMenu();
    void showMin();
    void closeWidget();
private:
    MainTopWidget   *m_topWidget;
    MainBottomWidget    *m_bottomWidget;
};

#endif // MAINWINDOW_H
