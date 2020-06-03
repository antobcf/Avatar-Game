#include "controller.h"


Controller::Controller(Modello* m, QWidget *parent) :
    QWidget(parent),
    layoutPrincipale(new QVBoxLayout(this)),
    menuGenerale(new Menu(this)),
    vistaHome(new AvatarHome(this)),
    vistaCrea(new CreaAvatar(this)),
    vistaLista(new ListaAvatar(this)),
    vistaModifica(new ModificaAvatar(this)),
    vistaScontro(new Scontro(this)),
    modello(m),
    destinazione(QFileDialog::getOpenFileName(parent, "Scegli il tuo DB di Avatar", ":/listavatar", "File XML(*.xml)"))
{
    layoutPrincipale->setMenuBar(menuGenerale);
    layoutPrincipale->addWidget(vistaHome);
    layoutPrincipale->addWidget(vistaCrea);
    layoutPrincipale->addWidget(vistaLista);
    layoutPrincipale->addWidget(vistaScontro);

    vistaCrea->hide();
    vistaLista->hide();
    vistaModifica->hide();
    vistaScontro->hide();
    setLayout(layoutPrincipale);

    //CONNECT HOME
    connect(vistaHome->getBottoneCrea(),SIGNAL(clicked()),this,SLOT(mostraCrea()));
    connect(vistaHome->getBottoneGioca(),SIGNAL(clicked()),this,SLOT(mostraLista()));

    //CONNECT CREA
    connect(vistaCrea->getBottoneHome(),SIGNAL(clicked()),this,SLOT(mostraHome()));

    //CONNECT LISTA
    connect(vistaLista->getBottoneHome(),SIGNAL(clicked()),this,SLOT(mostraHome()));
    connect(vistaLista->getBottoneGioca(),SIGNAL(clicked()),this,SLOT(mostraScontro()));
    connect(vistaLista->getBottoneModifica(),SIGNAL(clicked()),this,SLOT(mostraModifica()));

    //CONNECT SCONTRO
    connect(vistaScontro->getBottoneCambioAvatar(),SIGNAL(clicked()),this,SLOT(mostraLista()));
    connect(vistaScontro->getBottoneHomeScontro(),SIGNAL(clicked()),this,SLOT(mostraHome()));
}

Controller::~Controller()
{

}

void Controller::mostraHome()
{
    vistaHome->show();
    vistaCrea->hide();
    vistaLista->hide();
    vistaModifica->hide();
    vistaScontro->hide();
}

void Controller::mostraCrea() {
    vistaCrea->show();
    vistaHome->hide();
    vistaLista->hide();
    vistaModifica->hide();
    vistaScontro->hide();

    vistaCrea->resetTutto();
}

void Controller::mostraLista() {
    vistaLista->show();
    vistaHome->hide();
    vistaCrea->hide();
    vistaModifica->hide();
    vistaScontro->hide();

    vistaLista->azzeraTutto();
}

void Controller::mostraModifica() {
    vistaModifica->show();
    vistaLista->show();
    vistaHome->hide();
    vistaCrea->hide();
    vistaScontro->hide();
}

void Controller::mostraScontro() {
    vistaScontro->show();
    vistaModifica->hide();
    vistaLista->hide();
    vistaHome->hide();
    vistaCrea->hide();
}
