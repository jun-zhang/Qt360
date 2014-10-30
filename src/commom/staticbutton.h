#ifndef STATICBUTTON_H
#define STATICBUTTON_H

#include <QPushButton>
#include "common.h"

class StaticButton : public QWidget
{
    Q_OBJECT
public:
    explicit StaticButton(QWidget *parent = 0);
    explicit StaticButton(const QString &icon,int num = 4, QWidget *parent = 0); //默认为一张图片的icon
    explicit StaticButton(const QString &icon,bool isDivision, int num = 3, QWidget *parent = 0);
    void setOneButtonInfo(const QString &icon,int num = 4);
    void setDivisionButtonInfo(const QString &icon,int num = 3);
    void setCursorEnabled(bool enalbed);
    void setButtonStatus(BUTTONSTATUS status);
signals:
    void buttonClicked();
    void enterSignal();
    void leaveSignal();
protected:
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void changeEvent(QEvent *e);
private:
    QPixmap m_currentPix;
    QList<QPixmap> m_pixList;
    int m_num;
    QCursor m_preCursor;
    bool m_isCursor;
};

#endif // STATICBUTTON_H
