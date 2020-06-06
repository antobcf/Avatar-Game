#include "menu.h"

Menu::Menu(QWidget* p):
    parent(p),
    file(new QMenu("File", p)),
    personaggio(new QMenu("Avatar", p)),
    info(new QMenu("Informazioni", p)),
    esci(new QAction("Esci", p)),
    nuovo(new QAction("Nuovo", p)),
    carica(new QAction("Carica", p)),
    salva(new QAction("Salva", p)),
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
    personaggio->addAction(salva);
    personaggio->addAction(lista);
    addMenu(personaggio);

    info->addAction(sviluppatori);
    info->addAction(infoSistema);
    addMenu(info);

    connect(esci,SIGNAL(triggered()),parent,SLOT(close()));
    connect(home,SIGNAL(triggered()),parent,SLOT(mostraHome()));
    connect(nuovo,SIGNAL(triggered()),parent,SLOT(mostraCrea()));
    connect(sviluppatori,SIGNAL(triggered()),parent,SLOT(infoSviluppatori()));
    connect(infoSistema,SIGNAL(triggered()),parent,SLOT(infoPopSistema()));
}
