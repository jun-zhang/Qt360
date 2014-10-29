#ifndef NUMANIMWIDGET_H
#define NUMANIMWIDGET_H

#define NUM_ICONS_BEGIN ":/numbers/main/"

#include <QWidget>
class QTimer;
class NumAnimWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NumAnimWidget(QWidget *parent = 0);
    void setInitInfo(const QString &iconPath, int num);
    void setNum(int num);
private slots:
    void updatePix();
protected:
    void paintEvent(QPaintEvent *);
private:
    int m_preNum;
    QPixmap m_currentPix;
    QPixmap m_prePix;
    QTimer *m_timer;
    QString m_iconPath;
    int m_pixY;
    int m_endY;
    bool m_isInit;
    bool m_isStart;
    bool m_isEnd;
};

#endif // NUMANIMWIDGET_H
