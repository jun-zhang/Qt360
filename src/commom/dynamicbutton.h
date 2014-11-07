#ifndef DYNAMICBUTTON_H
#define DYNAMICBUTTON_H

#include <QWidget>
#include "dynamicwidget.h"
#include "dynamicscaledwidget.h"
#include "common.h"
#define INIT_ANIM_COUNT 11



class DynamicButton : public QWidget
{
    Q_OBJECT
public:
    explicit DynamicButton(QWidget *parent = 0);
    void setFirstAnim(const QString &icon, int count);
    void setNormalAnimInfo(const QString &icon, int count);
    void setNormalIconsInfo(const QString &normalIcon, const QString &hoverIcon);
    void setNoSelectedAnimInfo(const QString &icon, int count);
    void setNoSelectedIconsInfo(const QString &normalIcon, const QString &hoverIcon);

    void startFirstAnim();
    void setCheckedState(bool state);
    void setButtonStatus(BUTTONSTATUS status);
signals:
    void buttonClicked();
    void firstFinished();
protected:
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    //void changeEvent(QEvent *e);
private slots:
    void firstAnimFinished();
    void scaledAnimFinished();
private:
    BUTTONSTATUS m_status;
    QPixmap m_backgroundPix;
    QPixmap m_foregroundPix;
    DynamicWidget *m_firstdyWidget;
    DynamicWidget *m_dyWidget;
    DynamicWidget *m_noSelectdDyWidget;
    DynamicScaledWidget *m_dyScaledWidget;
    bool m_isSelected;
    QString m_normalIcon;
    QString m_hoverIcon;
    QString m_noSelectedNormalIcon;
    QString m_noSelectedHoverIcon;
    bool m_isFirsted;

//    QString m_normalAnimIcon;
//    QString m_noSelectedAnimIcon;
//    QString m_animCount;
};

#endif // DYNAMICBUTTON_H
