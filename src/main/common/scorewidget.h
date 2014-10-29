#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>
typedef enum{
    SCORE_QUESTION,
    SCORE_EXCLAMATION,
    SCORE_NUMBERS
}SCORESTATUS;

class NumbersAnimWidget;
class ScoreWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScoreWidget(QWidget *parent = 0);
    void setScoreStatus(int status);
    void setNums(int num);
protected:
    void paintEvent(QPaintEvent *);
private:
    QPixmap m_backgroundPix;
    QPixmap m_forePix;
    QPixmap m_fenPix;
    NumbersAnimWidget *m_numWidget;
    int m_status;
};

#endif // SCOREWIDGET_H
