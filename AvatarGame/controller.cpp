#include "controller.h"

Controller::Controller(Modello* m, QWidget *parent) :
    QWidget(parent),
    layoutPrincipale(new QVBoxLayout(this)),
    menuGenerale(new Menu(this)),
    modello(m)
{
    layoutPrincipale->setMenuBar(menuGenerale);

    setLayout(layoutPrincipale);
}

Controller::~Controller()
{

}
