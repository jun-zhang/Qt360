#ifndef DYNAMICBUTTON_H
#define DYNAMICBUTTON_H

#include <QWidget>
#define INIT_ANIM_COUNT 11

class DynamicButton : public QWidget
{
    Q_OBJECT
public:
    explicit DynamicButton(QWidget *parent = 0);

signals:
    void buttonClicked();
protected:
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void changeEvent(QEvent *e);
private:


};

#endif // DYNAMICBUTTON_H
