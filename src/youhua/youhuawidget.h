#ifndef YOUHUAWIDGET_H
#define YOUHUAWIDGET_H

#include <QWidget>
class YouhuaScanBottom;
class WenliBackWidget;
class StackStatusWidget;

class YouhuaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit YouhuaWidget(QWidget *parent = 0);

signals:
    void goToMain();
private:
    void initUI();
private:
    WenliBackWidget *m_topBackWidget;
    StackStatusWidget   *m_stackStatusWidget;
    YouhuaScanBottom  *m_scanBottomWidget;
};

#endif // YOUHUAWIDGET_H
