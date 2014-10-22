#ifndef STATICBUTTON_H
#define STATICBUTTON_H

#include <QPushButton>
#include "common.h"

class StaticButton : public QWidget
{
    Q_OBJECT
public:
    explicit StaticButton(const QString &icon,int num = 4, QWidget *parent = 0);
    void setButtonStatus(BUTTONSTATUS status);
signals:
    void buttonClicked();
protected:
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void changeEvent(QEvent *e);
private:
    QPixmap m_currentPix;
    QList<QPixmap> m_pixList;
    int m_num;
};

#endif // STATICBUTTON_H
