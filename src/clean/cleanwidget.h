#ifndef CLEANWIDGET_H
#define CLEANWIDGET_H

#include <QWidget>
class CleanScanBottom;
class WenliBackWidget;
class StackStatusWidget;

class CleanWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CleanWidget(QWidget *parent = 0);
public slots:
    void startFirst();
signals:
    void goToMain();
private:
    void initUI();
private:
    WenliBackWidget *m_topBackWidget;
    StackStatusWidget   *m_stackStatusWidget;
    CleanScanBottom  *m_scanBottomWidget;
    bool m_isFirst;
};

#endif // CLEANWIDGET_H
