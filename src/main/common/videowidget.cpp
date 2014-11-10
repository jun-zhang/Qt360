#include "videowidget.h"
#include "../../commom/staticbutton.h"
#include <QLabel>


VideoWidget::VideoWidget(QWidget *parent) :
    QDialog(parent), m_isFirst(true)
{
    this->setFixedSize(904, 600);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    m_mediaObject = new Phonon::MediaObject(this);//MediaObject 用于对媒体流基本控制，如播放，暂停，停止等，通过读取MediaSource
    connect(m_mediaObject, SIGNAL(finished()), this, SLOT(playFinished()));
    connect(m_mediaObject, SIGNAL(stateChanged(Phonon::State,Phonon::State)), \
            this, SLOT(playChanged(Phonon::State,Phonon::State)));
    m_audioOutput = new Phonon::AudioOutput(Phonon::VideoCategory,this);//播放声音
    m_videoWidget = new Phonon::VideoWidget(this);//影片播放
    m_videoWidget->setAspectRatio(Phonon::VideoWidget::AspectRatioWidget);

    Phonon::createPath(m_mediaObject,m_audioOutput);//建立一个Path，连接两个MediaNodes，就是source与sink
    Phonon::createPath(m_mediaObject,m_videoWidget);
    m_mediaObject->setCurrentSource(Phonon::MediaSource("./resource/video/360SafeVideo.wmv"));
    m_videoWidget->setGeometry(rect());

    m_close = new StaticButton(this);
    m_close->setOneButtonInfo(":/main/video_close");
    m_close->move(width()-m_close->width() - 5, 5);
    connect(m_close, SIGNAL(buttonClicked()), this, SLOT(closeWidget()));

    m_startLabel = new QLabel(this);
    m_startLabel->setGeometry(rect());
    m_startLabel->setPixmap(QPixmap(":/main/video_start"));

    m_endLabel = new QLabel(this);
    m_endLabel->setGeometry(rect());
    m_endLabel->setPixmap(QPixmap(":/main/video_end"));
    m_endLabel->hide();
}

void VideoWidget::startVideo()
{
    m_mediaObject->play();
}

void VideoWidget::playFinished()
{
    m_endLabel->raise();
    m_endLabel->show();
    this->close();
}

void VideoWidget::closeWidget()
{
    m_mediaObject->stop();
    this->close();
}

void VideoWidget::playChanged(Phonon::State newstate, Phonon::State oldstate)
{
    if(newstate == (Phonon::PlayingState) && m_isFirst)
    {
        m_startLabel->hide();
        m_isFirst = !m_isFirst;
        update();
    }
}
