#ifndef ANIMBUTTONWIDGET_H
#define ANIMBUTTONWIDGET_H


#include <QWidget>
class QTimer;

class AnimButtonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AnimButtonWidget(QWidget *parent = 0);
    void setAnimInfo(int perLength = 4, int milliseconds = 50);
    void setLineInfo(int linelength, const QColor &color);//如果设置以drawline形式
    void setPixInfo(const QString &pix);

public slots:
    void setOriginX(int x);
    void setEndX(int x);
    void leaveButton();
private slots:
    void updateAnim();
protected:
    void paintEvent(QPaintEvent *);
private:
    QTimer *m_timer;
    int m_perLength;//每次移动的距离
    int m_lineLength;
    bool m_isRightOri;
    bool m_isPix;
    QPixmap m_pix;
    int m_currentX;
    int m_originX;
    int m_endX;
    QColor m_lineColor;
};

#endif // ANIMBUTTONWIDGET_H
