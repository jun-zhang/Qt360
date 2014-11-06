#ifndef WENLIBACKWIDGET_H
#define WENLIBACKWIDGET_H

#include <QWidget>
class WenliWidget;
class StaticButton;
class SysButtonGroup;
class QVBoxLayout;

class WenliBackWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WenliBackWidget(QWidget *parent = 0);
    void setButtonInfo(const QString &icon, int num = 4);
    void insertWidget(QWidget *widget);
    void insertLayout(QLayout *layout);
signals:
    void buttonClicked();
    void playVideo();
    void showSkin();
    void showMenu();
    void showMin();
    void closeWidget();
protected:
    void resizeEvent(QResizeEvent *);
private:
    void initUI();
    void initConnect();
private:
    WenliWidget *m_back;
    StaticButton *m_button;
    QVBoxLayout *m_vLayout;
    SysButtonGroup *m_groupButton;
};

#endif // WENLIBACKWIDGET_H
