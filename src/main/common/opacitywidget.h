#ifndef OPACITYWIDGET_H
#define OPACITYWIDGET_H

#include <QWidget>

class OpacityWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)
public:
    explicit OpacityWidget(QWidget *parent = 0);
    void setOpacity(qreal opacity);
    qreal opacity()
    {
        return m_opacity;
    }
    void setColor(QColor color)
    {
        m_color = color;
    }

protected:
    void paintEvent(QPaintEvent *);
private:
    qreal m_opacity;
    QColor  m_color;
};

#endif // OPACITYWIDGET_H
