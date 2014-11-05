#ifndef SAFEBUTTONWIDGET_H
#define SAFEBUTTONWIDGET_H

#include <QWidget>
#include "staticbutton.h"
#include "dynamicwidget.h"

class SafeButtonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SafeButtonWidget(QWidget *parent = 0);
    void setIconsInfo(const QString &animIcons, int animNum,\
                      const QString &normalIcons,int normalNum = 4);
    void setAnimInfo(const QString &animIcons, int animNum = 8);
    void setNormalInfo(const QString &normalIcons,int normalNum = 4);

signals:
    void buttonClicked();
protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    StaticButton *m_staticButton;
    DynamicWidget *m_dynamicWidget;
};

#endif // SAFEBUTTONWIDGET_H
