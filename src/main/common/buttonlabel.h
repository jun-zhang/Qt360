#ifndef BUTTONLABEL_H
#define BUTTONLABEL_H

#include <QLabel>
class QCursor;
class ButtonLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ButtonLabel(QWidget *parent = 0);
    void setLabelText(const QString text);
    void setMouseClicked(bool isClicked);
signals:
    void labelClicked();
    void enterSignal();
    void leaveSignal();
protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    QCursor m_preCursor;
};

#endif // BUTTONLABEL_H
