#include "scorewidget.h"
#include <QPainter>
#include "../../commom/numbersanimwidget.h"
#include "../../commom/common.h"

ScoreWidget::ScoreWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    m_backgroundPix.load(":/main/examine_score");
    this->setFixedSize(m_backgroundPix.size());
    m_fenPix.load(":/main/fen");

    m_numWidget = new NumbersAnimWidget(this);
    m_numWidget->setInitInfo(100, 3, ":/numbers/main/");
    m_numWidget->move((width()-m_numWidget->width())/2 - 30, (height() - m_numWidget->height())/2 + 5);
    m_numWidget->hide();
}

void ScoreWidget::setScoreStatus(int status)
{
    m_status = status;
    switch (status) {
    case SCORE_QUESTION:
        m_numWidget->hide();
        m_forePix.load(":/main/question");
        break;
    case SCORE_EXCLAMATION:
        m_numWidget->hide();
        m_forePix.load(":/main/exclamation");
        break;
    case SCORE_NUMBERS:
        m_numWidget->show();
        break;
    default:
        break;
    }
    update();
}

void ScoreWidget::setNums(int num)
{
    this->setScoreStatus(SCORE_NUMBERS);
    m_numWidget->setNums(num);
}

void ScoreWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), m_backgroundPix);
    if(m_status == SCORE_QUESTION || m_status == SCORE_EXCLAMATION)
    {
        painter.drawPixmap((width() - m_forePix.width())/2, (height() - m_forePix.height())/2, \
                           m_forePix.width(), m_forePix.height(), m_forePix);
    }else if(m_status == SCORE_NUMBERS)
    {
        painter.drawPixmap(m_numWidget->x() + m_numWidget->width(), \
                           m_numWidget->y() + m_numWidget->height() - m_fenPix.height() - 20, \
                           m_fenPix.width(), m_fenPix.height(), m_fenPix);
    }
}
