#ifndef NUMBERSANIMWIDGET_H
#define NUMBERSANIMWIDGET_H

#include <QWidget>
class NumAnimWidget;
class NumbersAnimWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NumbersAnimWidget(QWidget *parent = 0);
    void setInitInfo(int num, int digits, const QString &iconPath);
    void setNums(int num);
private:
    int getNumsDigits(int num);
    QList<int> getNumsList(int num, int digits);
    int powNum(int dig, int y = 10);
private:
    QList<NumAnimWidget*> m_numsList;
    int m_digits;
};

#endif // NUMBERSANIMWIDGET_H
