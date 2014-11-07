#ifndef CLEANSCANBOTTOM_H
#define CLEANSCANBOTTOM_H

#include "../../commom/basestylewidget.h"
class CleanDynamicButtonWidget;

class CleanScanBottom : public BaseStyleWidget
{
    Q_OBJECT
public:
    explicit CleanScanBottom(QWidget *parent = 0);
    void startFirstAnim();
signals:
private:
    void initUI();
private:
    CleanDynamicButtonWidget    *m_trashButton;
    CleanDynamicButtonWidget    *m_traceButton;
    CleanDynamicButtonWidget    *m_regButton;
    CleanDynamicButtonWidget    *m_pluginButton;
    CleanDynamicButtonWidget    *m_softButton;
    CleanDynamicButtonWidget    *m_cookiesButton;
    QList<CleanDynamicButtonWidget*>    m_buttonList;
};

#endif // CLEANSCANBOTTOM_H
