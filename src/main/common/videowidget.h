#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <QDialog>

#if (QT_VERSION < QT_VERSION_CHECK(5,0,0))
    #include <phonon/mediasource.h>
    #include <phonon/mediaobject.h>
    #include <phonon/AudioOutput>
    #include <phonon/videoplayer.h>
    #include <phonon/VideoWidget>
#define USE_QT4 1
#else
    #include <QVideoWidget>
    #include <QMediaPlayer>
    #include <QMediaPlaylist>
#endif

class StaticButton;
class QLabel;

class VideoWidget : public QDialog
{
    Q_OBJECT
public:
    explicit VideoWidget(QWidget *parent = 0);
    void startVideo();
private slots:
    void playFinished();
    void closeWidget();
//只能使用这种形式在slot中判断版本，否则moc会报错
#if QT_VERSION < 0x050000
    void playChanged(Phonon::State newstate, Phonon::State oldstate);
#else
    void durationChanged(qint64 duration);
    void positionChanged(qint64 position);
#endif

private:
#if (QT_VERSION < QT_VERSION_CHECK(5,0,0))
    Phonon::MediaObject *m_mediaObject;
    Phonon::VideoWidget *m_videoWidget;
    Phonon::AudioOutput *m_audioOutput;
#else
    QMediaPlayer    *m_player;
    qint64  m_duration;
    qint64  m_oldPosition;
#endif
    StaticButton    *m_close;
    QLabel  *m_startLabel;
    QLabel  *m_endLabel;
    bool    m_isFirst;
};

#endif // VIDEOWIDGET_H
