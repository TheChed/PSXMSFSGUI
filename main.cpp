#include<QFuture>
#include <QtConcurrent>
#include "psxmsfsclient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PSXMSFSCLIENT w;
    w.show();
    return a.exec();
}
