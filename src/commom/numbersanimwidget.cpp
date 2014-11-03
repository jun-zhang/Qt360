#include "numbersanimwidget.h"
#include "numanimwidget.h"
#include <QHBoxLayout>

NumbersAnimWidget::NumbersAnimWidget(QWidget *parent) :
    QWidget(parent)
{
}

void NumbersAnimWidget::setInitInfo(int num, int digits, const QString &iconPath)
{
    m_digits = digits;
    QList<int> numsList = getNumsList(num, digits);
    QHBoxLayout *hLayout = new QHBoxLayout;
    for(int i=0; i != digits; i++)
    {
        NumAnimWidget *numWidget = new NumAnimWidget;
        numWidget->setInitInfo(iconPath, numsList.at(i));
        m_numsList.append(numWidget);
        hLayout->addWidget(numWidget);
    }
    //hLayout->addStretch();
    hLayout->setSpacing(0);
    hLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(hLayout);

    this->setFixedSize((m_numsList.at(0)->width())*digits, m_numsList.at(0)->height());
}

void NumbersAnimWidget::setNums(int num)
{
    QList<int> numsList = getNumsList(num, m_digits);
    for(int i=0; i != m_numsList.size(); i++)
    {
        m_numsList.at(i)->setNum(numsList.at(i));
    }
}

QList<int> NumbersAnimWidget::getNumsList(int num, int digits)
{
    int realDigits = getNumsDigits(num);
    QList<int> numsList;
    if(realDigits > digits)
    {
        return getNumsList((num%powNum(digits)), digits);
    }else if(realDigits < digits)
    {
        for(int i=digits; i != 0; i--)
        {
            if(i > realDigits)
            {
                numsList.append(-1);
            }else
            {
                numsList.append(num/powNum(i));
                num %= powNum(i);
            }
        }
    }else if(realDigits == digits)
    {
        for(int i=digits; i != 0; i--)
        {
            numsList.append(num/powNum(i));
            num %= powNum(i);
        }
    }
    return numsList;
}

int NumbersAnimWidget::powNum(int dig, int y)
{
    int num = 1;
    for(int i=1; i < dig; i++)
    {
        num *= y;
    }
    return num;
}

int NumbersAnimWidget::getNumsDigits(int num)
{
    int len = 1;
    while(num /= 10)
    {
        len++;
    }
    return len;
}
