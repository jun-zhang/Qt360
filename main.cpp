#include "src/test/mainwidget.h"
#include "src/main/mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *localCode = QTextCodec::codecForName("System");
    QTextCodec::setCodecForLocale(localCode);
    QTextCodec::setCodecForCStrings(localCode);
    QTextCodec::setCodecForTr(localCode);
    QFile qss(":/qss/default");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();

//    MainWidget w;
//    w.show();
    MainWindow *w = new MainWindow;
    w->show();

    return a.exec();
}
