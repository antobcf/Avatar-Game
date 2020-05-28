#include "menu.h"

Menu::Menu(QWidget* p):
    parent(p),
    //menuBar(new QMenuBar(this)),
    file(new QMenu("File", p)),
    personaggio(new QMenu("Avatar", p)),
    finestra(new QMenu("Finestra", p)),
    info(new QMenu("Informazioni", p)),
    esci(new QAction("Esci", p)), //da qui in poi non sono sicuro del p
    nuovo(new QAction("Nuovo", p)),
    carica(new QAction("Carica", p)),
    salva(new QAction("Salva", p)),
    lista(new QAction("Lista", p)),
    sviluppatori(new QAction("Contatti Sviluppatori", p)),
    infoSistema(new QAction("Informazioni di Sistema", p)),
    schermoIntero(new QAction("Schermo Intero", p)),
    riduci(new QAction("Riduci", p)),
    darkMode(new QAction("Dark Mode", p)),
    home(new QAction("Homepage", p))
{

    file->addAction(esci);
    addMenu(file);

    personaggio->addAction(nuovo);
    personaggio->addAction(carica);
    personaggio->addAction(salva);
    personaggio->addAction(lista);
    addMenu(personaggio);

    finestra->addAction(schermoIntero);
    finestra->addAction(riduci);
    finestra->addAction(darkMode);
    finestra->addAction(home);
    addMenu(finestra);

    home->setEnabled(false);

    info->addAction(sviluppatori);
    info->addAction(infoSistema);
    addMenu(info);


}
