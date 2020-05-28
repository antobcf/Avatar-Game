#include "avatarhome.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AvatarHome w;
    w.show();
    return a.exec();
}
