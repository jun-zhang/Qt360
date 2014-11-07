#ifndef CLEANDYNAMICBUTTONWIDGET_H
#define CLEANDYNAMICBUTTONWIDGET_H

#include <QWidget>
class QLabel;
class DynamicButton;

class CleanDynamicButtonWidget : public QWidget
{
    Q_OBJECT
    //自定义属性，用于样式表
    Q_PROPERTY(QString normalAnimInfo READ normalAnimInfo \
               WRITE setNormalAnimInfo DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QString title READ title \
               WRITE setTitle DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QString description READ description \
               WRITE setDescription DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(int normalNum READ normalNum \
               WRITE setNormalNum DESIGNABLE true SCRIPTABLE true)
public:
    explicit CleanDynamicButtonWidget(QWidget *parent = 0);
    void setNormalAnimInfo(const QString &icon);
    QString normalAnimInfo()
    {
        return  m_normalIcon;
    }

    void setNormalNum(int num);
    int normalNum()
    {
        return m_num;
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

    void startFirstAnim();
    void setCheckedState(bool state);
    bool isCheckd()
    {
        return m_isChecked;
    }

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void resizeEvent(QResizeEvent *);
signals:
    void checkedChanged(bool);
private slots:
    void firstFinished();
private:
    void initUI();
private:
    QString m_title;
    QString m_description;
    QString m_icon;
    QString m_normalIcon;
    int m_num;
    QLabel *m_titleLabel;
    QLabel *m_descriptionLabel;
    DynamicButton *m_dynamic;
    QLabel  *m_checked;
    QLabel  *m_unChecked;
    bool    m_isChecked;
};

#endif // CLEANDYNAMICBUTTONWIDGET_H
