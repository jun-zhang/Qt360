#ifndef MAINSCOREWIDGET_H
#define MAINSCOREWIDGET_H

#include <QWidget>

class QLabel;
class ScoreWidget;
class QStackedWidget;

class MainScoreWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainScoreWidget(QWidget *parent = 0);
    void setScoreStatus(int status);
    void setNums(int num);
    void setTextInfo(const QString &topText, const QString &bottomText);
    void setButtonStatus(int status);
signals:
    void cancleExamine();
    void oneFix();
    void reExamine();
private:
    void initUI();
    void initButtonLayout();
private:
    QLabel *m_topLabel;
    QLabel *m_bottomLabel;
    ScoreWidget *m_scoreWidget;
    QStackedWidget *m_stackedWidget;
};

#endif // MAINSCOREWIDGET_H
