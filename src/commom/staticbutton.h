#ifndef STATICBUTTON_H
#define STATICBUTTON_H

#include <QPushButton>

class StaticButton : public QWidget
{
    Q_OBJECT
public:
    explicit StaticButton(const QString &icon, QWidget *parent = 0);
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
};

#endif // STATICBUTTON_H
