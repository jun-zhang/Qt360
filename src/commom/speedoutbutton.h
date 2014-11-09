#ifndef SPEEDOUTBUTTON_H
#define SPEEDOUTBUTTON_H

#include <QWidget>
#include "common.h"
class SpeedOutButton : public QWidget
{
    Q_OBJECT
public:
    explicit SpeedOutButton(QWidget *parent = 0);
    void setIconsInfo(const QString &icon);
    void setButtonStatus(BUTTONSTATUS status);
    void setCheckdStatus(bool checked);
signals:
    void checkedChanged(bool);
protected:
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    QPixmap m_normalHover;
    QPixmap m_grayHover;
    QPixmap m_checkPix;
    QPixmap m_uncheckPix;
    QList<QPixmap> m_checkList;
    bool m_isChecked;
    BUTTONSTATUS m_status;
    QRect m_checkRect;
};

#endif // SPEEDOUTBUTTON_H
