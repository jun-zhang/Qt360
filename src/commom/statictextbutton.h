/*
 * 按钮加文字
 *
 * */

#ifndef STATICTEXTBUTTON_H
#define STATICTEXTBUTTON_H

#include <QWidget>
class QLabel;
class StaticButton;

class StaticTextButton : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(QString buttonPix READ buttonPix WRITE setButtonPix DESIGNABLE true SCRIPTABLE true)
    Q_PROPERTY(int buttonNum READ buttonNum WRITE setButtonNum DESIGNABLE true SCRIPTABLE true)
public:
    explicit StaticTextButton(QWidget *parent = 0);
    void setButtonPix(const QString &pix);
    const QString &buttonPix()
    {
        return m_pix;
    }

    void setButtonNum(int num)
    {
        m_num = num;
    }

    int buttonNum()
    {
        return m_num;
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
    StaticButton *m_button;
    QString m_text;
    QString m_pix;
    int m_num;
};

#endif // STATICTEXTBUTTON_H
