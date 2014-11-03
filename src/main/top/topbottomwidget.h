#ifndef TOPBOTTOMWIDGET_H
#define TOPBOTTOMWIDGET_H

#include <QWidget>
class StaticButton;
class QStackedWidget;

class TopBottomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TopBottomWidget(QWidget *parent = 0);
public slots:
    void setStackedButton(int index);
signals:
    void payinsureClicked();
    void securityClicked();
    void examineClicked();
    void viewClicked();
private:
    void initUI();
    void initConnect();
private:
    QStackedWidget *m_stacked;
    StaticButton *m_payinsureButton;
    StaticButton *m_securityButton;
    StaticButton *m_examineButton;
    StaticButton *m_viewButton;
};

#endif // TOPBOTTOMWIDGET_H
