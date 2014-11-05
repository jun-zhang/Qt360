/*
 * 纹理背景，在主界面和分页面中，用于有分数需求需要动态改变背景的情况。
 *
 * */

#ifndef WENLIWIDGET_H
#define WENLIWIDGET_H

#include <QWidget>
#include "basestylewidget.h"
class QPropertyAnimation;

class WenliWidget : public BaseStyleWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor)
    //注册属性为样式表提供自定义值
    Q_PROPERTY(QString backPix READ backPix WRITE setBackPix DESIGNABLE true SCRIPTABLE true)
public:
    explicit WenliWidget(QWidget *parent = 0);
    void setColor(const QColor &color);
    const QColor &color()
    {
        return m_backgroundColor;
    }
    const QString &backPix()
    {
        return m_backgroundPix;
    }

    void setBackPix(const QString &backPix);

public slots:
    void setNums(int num);
protected:
    void paintEvent(QPaintEvent *);
private:
    void initAnimations();
private:
    int m_num;
    qreal m_opacity;
    QPixmap m_guangYPix;
    QPixmap m_wenliPix;
    QColor m_backgroundColor;
    QPropertyAnimation *m_toOrange;
    QPropertyAnimation *m_toYellow;
    QString m_backgroundPix;
};

#endif // WENLIWIDGET_H
