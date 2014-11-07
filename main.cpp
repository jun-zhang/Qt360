#include "src/test/mainwidget.h"
#include "src/main/mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QFile>
//#define MAIN_TEST
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QTextCodec::setCodecForLocale(codec);
        QTextCodec::setCodecForCStrings(codec);
        QTextCodec::setCodecForTr(codec);
#endif
    QFile qss(":/qss/default");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
#ifdef MAIN_TEST
    MainWidget w;
    w.show();
#else
    MainWindow *w = new MainWindow;
    w->show();
#endif

    return a.exec();
}
