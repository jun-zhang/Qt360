#ifndef DYNAMICSCALEDWIDGET_H
#define DYNAMICSCALEDWIDGET_H

#include <QWidget>
class QTimer;
class DynamicScaledWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DynamicScaledWidget(QWidget *parent = 0);
    void setAnimInfo(const QPixmap &pix, int milliseconds = 400, int number = 5, qreal maxScaledRate = 1.25);
    void startAnim();
signals:
    void animFinished();
private slots:
    void updateAnim();
protected:
    void paintEvent(QPaintEvent *);
private:
    QTimer *m_timer;
    int m_number;
    int m_currentNum;
    QPixmap m_currentPix;
    QPixmap m_originPix;
    int m_originWidth;
    int m_originHeight;
    qreal m_rate;
    QList<qreal> m_rateList;
};

#endif // DYNAMICSCALEDWIDGET_H
