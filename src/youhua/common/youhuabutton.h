#ifndef YOUHUABUTTON_H
#define YOUHUABUTTON_H

#include <QWidget>
class QLabel;
class SpeedOutButton;

class YouhuaButton : public QWidget
{
    Q_OBJECT
    //自定义属性，用于样式表
    Q_PROPERTY(QString iconInfo READ iconInfo \
               WRITE setIconInfo DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QString title READ title \
               WRITE setTitle DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QString description READ description \
               WRITE setDescription DESIGNABLE true SCRIPTABLE true)
public:
    explicit YouhuaButton(QWidget *parent = 0);
    void setIconInfo(const QString &icon);
    QString iconInfo() const
    {
        return m_icon;
    }

    void setTextInfo(const QString &title, const QString &desc);
    void setTitle(const QString &title);
    QString title()
    {
        return m_title;
    }

    void setDescription(const QString &desc);
    QString description()
    {
        return m_description;
    }
    void setCheckedState(bool state);
    bool isCheckd()
    {
        return m_isChecked;
    }
signals:
    void checkedChanged(bool);
protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    void initUI();
private:
    QString m_title;
    QString m_description;
    QString m_icon;
    SpeedOutButton  *m_speed;
    QLabel *m_titleLabel;
    QLabel *m_descriptionLabel;
    bool    m_isChecked;
};

#endif // YOUHUABUTTON_H
