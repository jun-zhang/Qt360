#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <QDialog>
#include <phonon/videoplayer.h>
#include <phonon/mediasource.h>
#include <phonon/VideoWidget>
#include <phonon>
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
    void playChanged(Phonon::State newstate, Phonon::State oldstate);
private:
    Phonon::MediaObject *m_mediaObject;
    Phonon::VideoWidget *m_videoWidget;
    Phonon::AudioOutput *m_audioOutput;
    StaticButton    *m_close;
    QLabel  *m_startLabel;
    QLabel  *m_endLabel;
    bool    m_isFirst;
};

#endif // VIDEOWIDGET_H
