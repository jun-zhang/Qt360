#include "videowidget.h"
#include "../../commom/staticbutton.h"
#include <QLabel>
#include <QDir>
#include <QDebug>
VideoWidget::VideoWidget(QWidget *parent) :
    QDialog(parent), m_isFirst(true)
{
    this->setFixedSize(904, 600);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
#if (QT_VERSION < QT_VERSION_CHECK(5,0,0))

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
#else
    m_oldPosition = 0;
    QMediaPlaylist *playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl::fromLocalFile(QDir::currentPath() + "/resource/video/360SafeVideo.wmv"));

    m_player = new QMediaPlayer;
    m_player->setPlaylist(playlist);
    connect(m_player, SIGNAL(durationChanged(qint64)), this, SLOT(durationChanged(qint64)));
    connect(m_player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    QVideoWidget *videoWidget = new QVideoWidget(this);
    videoWidget->setGeometry(rect());
    m_player->setVideoOutput(videoWidget);
    videoWidget->show();
#endif
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

    m_endLabel->hide();
    m_startLabel->show();
#if (QT_VERSION < QT_VERSION_CHECK(5,0,0))
    m_isFirst = true;
    m_mediaObject->play();
#else
    m_oldPosition = 0;
    m_player->stop();
    m_player->setPosition(0);
    m_player->play();
#endif
    m_close->repaint();
}

void VideoWidget::playFinished()
{
    m_endLabel->raise();
    m_endLabel->show();
    this->close();
}

void VideoWidget::closeWidget()
{
#if (QT_VERSION < QT_VERSION_CHECK(5,0,0))
    m_mediaObject->stop();
#else
    m_player->stop();
#endif
    m_endLabel->hide();
    m_startLabel->show();
    this->close();
}

#if QT_VERSION < 0x050000
void VideoWidget::playChanged(Phonon::State newstate, Phonon::State oldstate)
{
    if(newstate == (Phonon::PlayingState) && m_isFirst)
    {
        m_startLabel->hide();
        m_isFirst = !m_isFirst;
        update();
    }
}
#else
void VideoWidget::durationChanged(qint64 duration)
{
    if(duration > 0)
        m_duration = duration;
}

void VideoWidget::positionChanged(qint64 position)
{
    if(position > 0)
        m_startLabel->hide();
    if(m_oldPosition > 0 && position == 0)
        this->playFinished();
    m_oldPosition = position;
}

#endif
