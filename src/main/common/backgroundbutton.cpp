#include "backgroundbutton.h"
#include <QPainter>
#include <QEvent>
#include <QMouseEvent>
#include <QLabel>
#include <QVBoxLayout>

BackgroundButton::BackgroundButton(QWidget *parent) :
    QWidget(parent), m_isCursor(false)
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    m_foreLabel = new QLabel;
    m_textLabel = new QLabel;
    m_textLabel->setObjectName("backButtonText");
    m_textLabel->hide();
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(m_foreLabel, 0, Qt::AlignCenter);
    vLayout->addWidget(m_textLabel, 0, Qt::AlignHCenter);
    vLayout->setContentsMargins(0, 5, 0, 5);
    this->setLayout(vLayout);
}

void BackgroundButton::setIconsInfo(const QString &fore, const QString &back, int start, int num)
{
    QPixmap tmpPix(back);
    QColor spaceColor(Qt::white);
    spaceColor.setAlpha(0);
    QPixmap spacePix(QSize(tmpPix.width()/num, tmpPix.height()));
    spacePix.fill(spaceColor);
    if(start == 0)
    {
        m_pixList.append(tmpPix.copy(0, 0, tmpPix.width()/num, tmpPix.height()));
        m_pixList.append(tmpPix.copy(tmpPix.width()/num, 0, tmpPix.width()/num, tmpPix.height()));
        m_pixList.append(tmpPix.copy(0, 0, tmpPix.width()/num, tmpPix.height()));
    }else if (start == 1) {
        m_pixList.append(spacePix);
        m_pixList.append(tmpPix.copy(0, 0, tmpPix.width()/num, tmpPix.height()));
        m_pixList.append(tmpPix.copy(tmpPix.width()/num, 0, tmpPix.width()/num, tmpPix.height()));
    }
    m_backPix = m_pixList.at(0);
    this->setFixedSize(tmpPix.width()/num, tmpPix.height());
    QPixmap forePix(fore);
    m_foreLabel->setPixmap(forePix);
    m_foreLabel->setFixedSize(forePix.size());
}

void BackgroundButton::setText(const QString &text)
{
    m_textLabel->setText(text);
    m_textLabel->adjustSize();
    m_textLabel->show();
}

void BackgroundButton::setButtonStatus(BUTTONSTATUS status)
{

    switch (status) {
    case BUTTON_ENTER:
        m_backPix = m_pixList.at(1);
        break;
    case BUTTON_LEAVE:
        m_backPix = m_pixList.at(0);
        break;
    case BUTTON_PRESSED:
        m_backPix = m_pixList.at(2);
        break;
    default:
        break;
    }
    update();
}

void BackgroundButton::setCursorEnabled(bool enalbed)
{
    m_isCursor = enalbed;
}

void BackgroundButton::enterEvent(QEvent *)
{
    setButtonStatus(BUTTON_ENTER);
    if(m_isCursor)
    {
        m_preCursor = cursor();
        setCursor(Qt::OpenHandCursor);
    }
    emit enterSignal();
}

void BackgroundButton::leaveEvent(QEvent *)
{
    setButtonStatus(BUTTON_LEAVE);
    if(m_isCursor)
    {
        setCursor(m_preCursor);
    }
    emit leaveSignal();
}

void BackgroundButton::mousePressEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }
    setButtonStatus(BUTTON_PRESSED);
}

void BackgroundButton::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }

    if(rect().contains(e->pos()))
    {
        if(this->isEnabled())
            emit buttonClicked();
        setButtonStatus(BUTTON_ENTER);
        e->accept();
    }else{
        setButtonStatus(BUTTON_LEAVE);
        e->ignore();
    }
}


void BackgroundButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), m_backPix);
}
