#ifndef SCANBUTTONWIDGET_H
#define SCANBUTTONWIDGET_H

#include <QWidget>
class SafeButtonWidget;
class QLabel;
class ScanButtonWidget : public QWidget
{
    Q_OBJECT
    //自定义属性，用于样式表
    Q_PROPERTY(QString animPix READ animPix WRITE setAnimPix DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(int animNum READ animNum WRITE setAnimNum DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QString normalPix READ normalPix WRITE setNormalPix DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(int normalNum READ normalNum WRITE setNormalNum DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QString text READ text WRITE setText DESIGNABLE true SCRIPTABLE true)

public:
    explicit ScanButtonWidget(QWidget *parent = 0);
    void setAnimPix(const QString &pix);
    const QString &animPix()
    {
        return m_animPix;
    }

    void setAnimNum(int num);
    int animNum()
    {
        return m_animNum;
    }

    void setNormalPix(const QString &pix);
    const QString &normalPix()
    {
        return m_normalPix;
    }

    void setNormalNum(int num);
    int normalNum()
    {
        return m_normalNum;
    }

    void setText(const QString &text);
    const QString &text()
    {
        return m_text;
    }

signals:
    void buttonClicked();
private:
    QLabel *m_textLabel;
    SafeButtonWidget *m_button;
    int m_animNum;
    QString m_animPix;
    QString m_normalPix;
    int m_normalNum;

    QString m_text;
};

#endif // SCANBUTTONWIDGET_H
