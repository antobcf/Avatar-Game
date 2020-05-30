#include "controller.h"


Controller::Controller(Modello* m, QWidget *parent) :
    QWidget(parent),
    layoutPrincipale(new QVBoxLayout(this)),
    menuGenerale(new Menu(this)),
    vistaHome(new AvatarHome(this)),
    vistaCrea(new CreaAvatar(this)),
    vistaLista(new ListaAvatar(this)),
    modello(m)
{
    layoutPrincipale->setMenuBar(menuGenerale);
    layoutPrincipale->addWidget(vistaHome);
    layoutPrincipale->addWidget(vistaCrea);
    layoutPrincipale->addWidget(vistaLista);

    vistaCrea->hide();
    vistaLista->hide();
    setLayout(layoutPrincipale);

    //CONNECT HOME
    connect(vistaHome->getBottoneCrea(),SIGNAL(clicked()),this,SLOT(mostraCrea()));
    connect(vistaHome->getBottoneGioca(),SIGNAL(clicked()),this,SLOT(mostraLista()));

    //CONNECT CREA
    connect(vistaCrea->getBottoneHome(),SIGNAL(clicked()),this,SLOT(mostraHome()));

    //CONNECT LISTA
    connect(vistaLista->getBottoneHome(),SIGNAL(clicked()),this,SLOT(mostraHome()));
}

Controller::~Controller()
{

}

void Controller::mostraHome()
{
    vistaHome->show();
    vistaCrea->hide();
    vistaLista->hide();
    //qui vanno le hide delle altre pagine
}

void Controller::mostraCrea() {
    vistaCrea->show();
    vistaHome->hide();
    vistaLista->hide();

}

void Controller::mostraLista() {
    vistaLista->show();
    vistaHome->hide();
    vistaCrea->hide();


}
