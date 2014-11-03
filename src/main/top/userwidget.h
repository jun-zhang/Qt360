#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
class BackgroundButton;
class ButtonLabel;

class UserWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UserWidget(QWidget *parent = 0);

private:
    BackgroundButton *m_userButton;
    ButtonLabel *m_loginButton;
};

#endif // USERWIDGET_H
