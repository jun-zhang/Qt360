#ifndef WENLIWIDGET_H
#define WENLIWIDGET_H

#include <QWidget>
#include "basestylewidget.h"
class QPropertyAnimation;

class WenliWidget : public BaseStyleWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor)
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
    void initUI();
    void initData();
    void initConnect();
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
