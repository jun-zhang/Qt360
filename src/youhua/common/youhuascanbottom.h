#ifndef YOUHUASCANBOTTOM_H
#define YOUHUASCANBOTTOM_H

#include "../../commom/basestylewidget.h"
class YouhuaButton;

class YouhuaScanBottom : public BaseStyleWidget
{
    Q_OBJECT
public:
    explicit YouhuaScanBottom(QWidget *parent = 0);
private:
    void initUI();
private:
    YouhuaButton    *m_startButton;
    YouhuaButton    *m_sysButton;
    YouhuaButton    *m_netButton;
    YouhuaButton    *m_diskButton;
};

#endif // YOUHUASCANBOTTOM_H
