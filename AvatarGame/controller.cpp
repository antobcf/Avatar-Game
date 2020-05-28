#include "controller.h"


Controller::Controller(Modello* m, QWidget *parent) :
    QWidget(parent),
    layoutPrincipale(new QVBoxLayout(this)),
    menuGenerale(new Menu(this)),
    vistaHome(new AvatarHome(this)),
    modello(m)
{
    layoutPrincipale->setMenuBar(menuGenerale);
    layoutPrincipale->addWidget(vistaHome);

    setLayout(layoutPrincipale);
}

Controller::~Controller()
{

}

void Controller::mostraHome()
{
    vistaHome->show();
    //qui vanno le hide delle altre pagine



}
