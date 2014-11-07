#include "cleandynamicbuttonwidget.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QMouseEvent>
#include "../../commom/dynamicbutton.h"

CleanDynamicButtonWidget::CleanDynamicButtonWidget(QWidget *parent) :
    QWidget(parent), m_isChecked(true)
{
    this->initUI();
}

void CleanDynamicButtonWidget::initUI()
{
    this->setAttribute(Qt::WA_TranslucentBackground);

    m_checked = new QLabel(this);
    QPixmap checkPix(":/clean/group_check");
    m_checked->setFixedSize(checkPix.size());
    m_checked->setPixmap(checkPix);
    m_checked->raise();
    m_checked->hide();

    m_unChecked = new QLabel(this);
    QPixmap unCheckPix(":/clean/group_uncheck");
    m_unChecked->setFixedSize(unCheckPix.size());
    m_unChecked->setPixmap(unCheckPix);
    m_unChecked->hide();
    m_unChecked->raise();

    m_num = 17;
    m_dynamic = new DynamicButton;
    m_dynamic->setAttribute(Qt::WA_TransparentForMouseEvents);
    m_dynamic->setFirstAnim(":/clean/enter_anim", 11);
    m_dynamic->setNormalIconsInfo(":/clean/select_normal", ":/clean/select_hover");
    m_dynamic->setNoSelectedIconsInfo(":/clean/notselect_normal", ":/clean/notselect_hover");
    connect(m_dynamic, SIGNAL(firstFinished()), this, SLOT(firstFinished()));

    m_titleLabel = new QLabel;
    m_titleLabel->setObjectName("cleanTitleLabel");
    m_descriptionLabel = new QLabel;
    m_descriptionLabel->setObjectName("cleanDescLabel");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_dynamic, 0, Qt::AlignHCenter);
    mainLayout->addWidget(m_titleLabel, 0, Qt::AlignHCenter);
    mainLayout->addWidget(m_descriptionLabel, 0, Qt::AlignHCenter);
    mainLayout->setSpacing(5);
    mainLayout->setContentsMargins(5, 0, 5, 5);

    this->setLayout(mainLayout);
}

void CleanDynamicButtonWidget::firstFinished()
{
    if(m_isChecked)
    {
        m_checked->show();
        m_checked->raise();
    }else
    {
        m_unChecked->show();
        m_unChecked->raise();
    }
}

void CleanDynamicButtonWidget::startFirstAnim()
{
    m_dynamic->startFirstAnim();
}

void CleanDynamicButtonWidget::setNormalAnimInfo(const QString &icon)
{
    m_dynamic->setNormalAnimInfo(icon, m_num);
    m_dynamic->setNoSelectedAnimInfo(icon +"_gray", m_num);
}

void CleanDynamicButtonWidget::setNormalNum(int num)
{
    m_num = num;
}

void CleanDynamicButtonWidget::setTextInfo(const QString &title, const QString &desc)
{
    m_titleLabel->setText(title);
    m_descriptionLabel->setText(desc);
}

void CleanDynamicButtonWidget::setTitle(const QString &title)
{
    m_title = title;
    m_titleLabel->setText(m_title);
}

void CleanDynamicButtonWidget::setDescription(const QString &desc)
{
    m_description = desc;
    m_descriptionLabel->setText(m_description);
}

void CleanDynamicButtonWidget::setCheckedState(bool state)
{
    m_isChecked = state;
    if(m_isChecked)
    {
        m_unChecked->hide();
        m_checked->show();
        m_checked->raise();
    }else{
        m_checked->hide();
        m_unChecked->show();
        m_unChecked->raise();
    }
}

void CleanDynamicButtonWidget::enterEvent(QEvent *)
{
    m_dynamic->setButtonStatus(BUTTON_ENTER);
}

void CleanDynamicButtonWidget::leaveEvent(QEvent *)
{
    m_dynamic->setButtonStatus(BUTTON_LEAVE);
}

void CleanDynamicButtonWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }
    //m_dynamic->setButtonStatus(BUTTON_PRESSED);
}

void CleanDynamicButtonWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }

    if(rect().contains(e->pos()))
    {
        m_dynamic->setButtonStatus(BUTTON_PRESSED);
        this->setCheckedState((!m_isChecked));
        emit checkedChanged(m_isChecked);
        e->accept();
    }else{
        m_dynamic->setButtonStatus(BUTTON_LEAVE);
        e->ignore();
    }
}

void CleanDynamicButtonWidget::resizeEvent(QResizeEvent *)
{
    int dx = m_dynamic->x() + 62;
    int dy = m_dynamic->y() + 45;
    m_checked->move(dx, dy);
    m_unChecked->move(dx, dy);
}
