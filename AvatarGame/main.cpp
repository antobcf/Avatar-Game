#include "modello.h"
#include "GUI\controller.h"
#include "GUI\menu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller w(new Modello());
    w.show();
    return a.exec();



}
