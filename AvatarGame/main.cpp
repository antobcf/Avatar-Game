#include "modello.h"
#include "controller.h"
#include "menu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller w(new Modello());
    w.show();
    return a.exec();
}
