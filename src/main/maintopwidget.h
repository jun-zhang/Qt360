#ifndef MAINTOPWIDGET_H
#define MAINTOPWIDGET_H

#include <QWidget>
#include <QPixmap>
#include "../commom/basestylewidget.h"
class QPropertyAnimation;
class QStackedWidget;
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
private slots:
    void examineClicked();
    void viewClicked();
    void returnMain();
private:
    void initUI();
    void initTopTitleWidget();
    void initData();
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
};

#endif // MAINTOPWIDGET_H
