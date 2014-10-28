#ifndef MAINBOTTOMWIDGET_H
#define MAINBOTTOMWIDGET_H

#include <QWidget>
#include <QPushButton>

class MainBottomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainBottomWidget(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
signals:
    void goGarbage();
private:
    QPushButton *m_button;

};

#endif // MAINBOTTOMWIDGET_H
