#include "src/test/mainwidget.h"
#include "src/main/maintopwidget.h"
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
    MainTopWidget *w = new MainTopWidget;
    w->show();
    w->setNums(85);

    return a.exec();
}
