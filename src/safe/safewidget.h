#ifndef SAFEWIDGET_H
#define SAFEWIDGET_H

#include <QWidget>
class SafeScanBottom;
class WenliBackWidget;
class StackStatusWidget;

class SafeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SafeWidget(QWidget *parent = 0);

signals:
    void goToMain();
private:
    void initUI();
private:
    WenliBackWidget *m_topBackWidget;
    StackStatusWidget   *m_stackStatusWidget;
    SafeScanBottom  *m_scanBottomWidget;
};

#endif // SAFEWIDGET_H
