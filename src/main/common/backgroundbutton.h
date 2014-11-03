#ifndef BACKGROUNDBUTTON_H
#define BACKGROUNDBUTTON_H

#include <QWidget>
#include "../../commom/common.h"

class BackgroundButton : public QWidget
{
    Q_OBJECT
public:
    explicit BackgroundButton(QWidget *parent = 0);
    void setIconsInfo(const QString &fore, const QString &back, int start = 0, int num = 2);
    void setButtonStatus(BUTTONSTATUS status);
    void setCursorEnabled(bool enalbed);
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
private:
    int m_start;
    int m_num;
    QPixmap m_forePix;
    QPixmap m_backPix;
    QCursor m_preCursor;
    QList<QPixmap> m_pixList;
    bool m_isCursor;
};

#endif // BACKGROUNDBUTTON_H
