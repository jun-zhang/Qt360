#ifndef SAFESCANBOTTOM_H
#define SAFESCANBOTTOM_H
#include "../../commom/basestylewidget.h"
class ScanButtonWidget;
class StaticTextButton;

class SafeScanBottom : public BaseStyleWidget
{
    Q_OBJECT
public:
    explicit SafeScanBottom(QWidget *parent = 0);

signals:
    void quickClicked();
    void fullClicked();
    void customClicked();
    void fixClicked();
    void patchClicked();
private:
    void initUI();
    void initConnect();
private:
    ScanButtonWidget    *m_quick;
    ScanButtonWidget    *m_full;
    ScanButtonWidget    *m_custom;
    StaticTextButton    *m_fix;
    StaticTextButton    *m_patch;
};

#endif // SAFESCANBOTTOM_H
