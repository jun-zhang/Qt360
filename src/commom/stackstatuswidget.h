#ifndef STACKSTATUSWIDGET_H
#define STACKSTATUSWIDGET_H

#include <QWidget>
class QLabel;
class StaticButton;

class StackStatusWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StackStatusWidget(QWidget *parent = 0);
    void setNormalButton(const QString &icon, int num = 4);
    void setTextInfo(const QString &top, const QString &bottom);
    void setStaticIcon(const QString &icon);
signals:
    void normalClicked();
private:
    void initUI();
private:
    QLabel *m_logo;
    QLabel *m_topText;
    QLabel *m_bottomText;
    StaticButton *m_normalButton;
};

#endif // STACKSTATUSWIDGET_H
