#include "src/test/mainwidget.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/qss/default");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();

    MainWidget w;
    w.show();

    return a.exec();
}
