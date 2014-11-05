#ifndef DYNAMICWIDGET_H
#define DYNAMICWIDGET_H

#include <QWidget>
#include <QTimer>

class DynamicWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DynamicWidget(QWidget *parent = 0);
    void setInfo(const QPixmap &pix, int count = 8, int milliseconds = 100);
    void startClockwise();
    void startCounterclockwise();
    void stopAnim();
signals:
    void animFinished();
private slots:
    void updateClockwise();
    void updateCounterclockwise();
protected:
    void paintEvent(QPaintEvent *);
private:
    int m_count;
    int m_currentIndex;
    QPixmap m_currentPix;
    QList<QPixmap> m_pixList;
    QTimer *m_clockTimer;
    QTimer *m_counterclockTimer;
};

#endif // DYNAMICWIDGET_H
