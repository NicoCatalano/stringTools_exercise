#include "stringtools.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StringTools w;
    w.show();

    return a.exec();
}
