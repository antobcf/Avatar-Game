#include "menu.h"

Menu::Menu(QWidget* p):
    parent(p),
    menuBar(new QMenuBar(this)),
    file(new QMenu("File", p)),
    personaggio(new QMenu("Avatar", p)),
    finestra(new QMenu("Finestra", p)),
    info(new QMenu("Informazioni", p)),
    esci(new QAction("Esci", p)), //da qui in poi non sono sicuro del p
    nuovo(new QAction("Nuovo", p)),
    carica(new QAction("Carica", file)),
    salva(new QAction("Salva", file)),
    lista(new QAction("Lista", file)),
    sviluppatori(new QAction("Contatti Sviluppatori", file)),
    infoSistema(new QAction("Informazioni di Sistema", file)),
    schermoIntero(new QAction("Schermo Intero", file)),
    riduci(new QAction("Riduci", file)),
    darkMode(new QAction("Dark Mode", file)),
    home(new QAction("Homepage", file))
{
    file->addAction(esci);
    menuBar->addMenu(file);

    personaggio->addAction(nuovo);
    personaggio->addAction(carica);
    personaggio->addAction(salva);
    personaggio->addAction(lista);
    menuBar->addMenu(personaggio);

    finestra->addAction(schermoIntero);
    finestra->addAction(riduci);
    finestra->addAction(darkMode);
    finestra->addAction(home);
    menuBar->addMenu(finestra);

    home->setEnabled(false);

    info->addAction(sviluppatori);
    info->addAction(infoSistema);
    menuBar->addMenu(info);


}
