#ifndef TOPTABWIDGET_H
#define TOPTABWIDGET_H

#include <QWidget>
class AnimButtonWidget;
class AnimButtonGroupWidget;
class TopTabWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TopTabWidget(QWidget *parent = 0);

private:
    AnimButtonGroupWidget *m_buttonGroup;
    AnimButtonWidget *m_animButton;
};

#endif // TOPTABWIDGET_H
