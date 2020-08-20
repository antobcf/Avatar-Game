#include "menu.h"
#include "controller.h"

Menu::Menu(QWidget* p):
    parent(p),
    file(new QMenu("File", p)),
    personaggio(new QMenu("Avatar", p)),
    info(new QMenu("Informazioni", p)),
    esci(new QAction("Esci", p)),
    nuovo(new QAction("Nuovo", p)),
    carica(new QAction("Carica", p)),
    lista(new QAction("Lista", p)),
    sviluppatori(new QAction("Contatti Sviluppatori", p)),
    infoSistema(new QAction("Informazioni di Sistema", p)),
    home(new QAction("Homepage", p))
{

    file->addAction(home);
    file->addAction(esci);
    addMenu(file);

    personaggio->addAction(nuovo);
    personaggio->addAction(carica);
    personaggio->addAction(lista);
    addMenu(personaggio);

    info->addAction(sviluppatori);
    info->addAction(infoSistema);
    addMenu(info);

    connect(esci,SIGNAL(triggered()),parent,SLOT(close()));
    connect(home,SIGNAL(triggered()),parent,SLOT(mostraHome()));
    connect(nuovo,SIGNAL(triggered()),parent,SLOT(mostraCrea()));
    connect(lista,SIGNAL(triggered()),parent,SLOT(mostraLista()));
    connect(carica,SIGNAL(triggered()),parent,SLOT(caricaDb()));

    connect(sviluppatori,SIGNAL(triggered()),parent,SLOT(mostraSviluppatori)); //dov'e' questa funzione?
    connect(infoSistema,SIGNAL(triggered()),parent,SLOT(mostraInfoSistema())); //dov'e' questa funzione?
}



