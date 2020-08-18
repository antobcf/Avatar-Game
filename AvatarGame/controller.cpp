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
    vistaFineScontro(new FineScontro(this)),
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
    carica();

    //CONNECT HOME
    connect(vistaHome->getBottoneCrea(),SIGNAL(clicked()),this,SLOT(mostraCrea()));
    connect(vistaHome->getBottoneGioca(),SIGNAL(clicked()),this,SLOT(mostraLista()));
    connect(vistaHome->getBottoneInfo(),SIGNAL(clicked()),this,SLOT(infoPopHome()));

    //CONNECT CREA
    connect(vistaCrea->getBottoneHome(),SIGNAL(clicked()),this,SLOT(mostraHome()));
    connect(vistaCrea->getBottoneCreaDef(), SIGNAL(clicked()),this,SLOT(inserisciAvatar()));

    //CONNECT LISTA
    connect(vistaLista->getTipoElfo(),SIGNAL(clicked()),this,SLOT(carica()));
    connect(vistaLista->getTipoNano(),SIGNAL(clicked()),this,SLOT(carica()));
    connect(vistaLista->getTipoUmano(),SIGNAL(clicked()),this,SLOT(carica()));
    connect(vistaLista->getTipoAlieno(),SIGNAL(clicked()),this,SLOT(carica()));
    connect(vistaLista->getTipoMostro(),SIGNAL(clicked()),this,SLOT(carica()));
    connect(vistaLista->getAvviaRicerca(),SIGNAL(clicked()),this,SLOT(ricercaAvatar()));
    connect(vistaLista->getBottoneModifica(),SIGNAL(clicked()),this,SLOT(modificaAvatar()));
    connect(vistaLista->getBottoneRimuovi(),SIGNAL(clicked()),this,SLOT(rimuoviAvatar()));
    connect(vistaLista->getBottoneGioca(),SIGNAL(clicked()),this,SLOT(scontroTraAvatar()));
    connect(vistaLista->getBottoneHome(),SIGNAL(clicked()),this,SLOT(mostraHome()));
    connect(vistaLista->getBottoneInfoLista(),SIGNAL(clicked()),this,SLOT(infoPopLista()));
    connect(vistaModifica->getBottoneSalvaModifiche(), SIGNAL(clicked()),this,SLOT(salva()));
    connect(vistaLista->getPulisciFiltri(),SIGNAL(clicked()),this,SLOT(resetRicerca()));

    //CONNECT SCONTRO
    connect(vistaScontro->getBottoneHomeScontro(),SIGNAL(clicked()),this,SLOT(mostraHome()));
    connect(vistaScontro->getBottoneCombatti(),SIGNAL(clicked()),this,SLOT(scontro()));
    connect(vistaScontro->getBottoneCambioAvatar(),SIGNAL(clicked()),this,SLOT(mostraLista()));
    connect(vistaScontro->getBottoneCambioAvversario(),SIGNAL(clicked()),this,SLOT(scontroTraAvatar()));

    //CONNECT FINE SCONTRO
    connect(vistaFineScontro->getHomeFine(),SIGNAL(clicked()),this,SLOT(mostraHome()));
    connect(vistaFineScontro->getCambioAvatarFine(),SIGNAL(clicked()),this,SLOT(mostraLista()));
    connect(vistaFineScontro->getContinuaFine(),SIGNAL(clicked()),this,SLOT(mostraScontro()));

    setAvatarGameStyle();

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
    vistaFineScontro->hide();
}

void Controller::mostraCrea() {
    vistaCrea->show();
    vistaHome->hide();
    vistaLista->hide();
    vistaModifica->hide();
    vistaScontro->hide();
    vistaFineScontro->hide();

    vistaCrea->resetTutto();
}

void Controller::mostraLista() {
    vistaHome->hide();
    vistaCrea->hide();
    vistaModifica->hide();
    vistaScontro->hide();
    vistaFineScontro->hide();
    vistaLista->resetLista();
    vistaLista->show();
    carica();
}

void Controller::mostraScontro() { //forse inutile
    vistaScontro->show();
    vistaModifica->hide();
    vistaLista->hide();
    vistaHome->hide();
    vistaCrea->hide();
    vistaFineScontro->hide();
}

void Controller::mostraFineScontro() {
    vistaFineScontro->setModal(true);
    vistaFineScontro->setWindowTitle("Fine Scontro");
    vistaFineScontro->show();
    vistaScontro->show();
    vistaModifica->hide();
    vistaLista->hide();
    vistaHome->hide();
    vistaCrea->hide();
}

void Controller::infoPopHome()
{
    QMessageBox::about(this,"Info","Premi GIOCA se vuoi iniziare una nuova\npartita, altrimenti premi CREA AVATAR per\ncreare un nuovo avatar personalizzato.");
}

void Controller::infoPopLista()
{
    QMessageBox::about(this,"Info","In questa schermata puoi interagire con\ni tuoi avatar. Puoi cercarli per nome o per tipo,\npuoi modificarli, eliminarli oppure puoi iniziare\nun nuovo scontro.");
}

void Controller::inserisciAvatar()
{
    std::string nome = vistaCrea->getInserisciNome()->text().toStdString();
    std::string descrizione = vistaCrea->getBoxDescrizione()->toPlainText().toStdString();
    unsigned int lvl = vistaCrea->getLvl()->text().toUInt();
    unsigned int exp = vistaCrea->getExp()->text().toUInt();
    unsigned int forza = vistaCrea->getValoreForza()->text().toUInt();
    unsigned int magia = vistaCrea->getValoreMagia()->text().toUInt();
    unsigned int difesa = vistaCrea->getValoreDifesa()->text().toUInt();
    unsigned int scienza = vistaCrea->getValoreScienza()->text().toUInt();
    double media = vistaCrea->getValoreMedia()->text().toDouble();
    std::string terreno = vistaCrea->getTerrenoPreferito()->text().toStdString();
    bool sesso;
    int check = vistaCrea->getSessoM()->isChecked();
    if(check == 1) sesso = true;
    else sesso = false;
    std::string percorso = vistaCrea->getPercorso().toStdString();

    int index = vistaCrea->getSceltaTipo()->currentIndex();

    //parte che manda avviso se nome già usato
    Avatar* item = new Elfo(nome);
    Avatar* item2 = new Nano(nome);
    Avatar* item3 = new Umano(nome);
    Avatar* item4 = new Alieno(nome);
    Avatar* item5 = new Mostro(nome);

    if(modello->getLista()->ricerca(item)) {
        vistaLista->getElenco()->clear();
        modello->setPercorso(destinazione.toStdString());
        modello->caricare();
        bool match = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !match) {
            if(*item == *(*val)) {
                vistaLista->getElenco()->insertAvatar(*val);
                match = true;
                QMessageBox::warning(this, "Errore",  "Nome già usato");
            }
            ++val;
        }

    } else if(modello->getLista()->ricerca(item2)) {
        vistaLista->getElenco()->clear();
        modello->setPercorso(destinazione.toStdString());
        modello->caricare();
        bool match = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !match) {
            if(*item2 == *(*val)) {
                vistaLista->getElenco()->insertAvatar(*val);
                match = true;
                QMessageBox::warning(this, "Errore",  "Nome già usato");
            }
            ++val;
        }
    } else if(modello->getLista()->ricerca(item3)) {
        vistaLista->getElenco()->clear();
        modello->setPercorso(destinazione.toStdString());
        modello->caricare();
        bool match = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !match) {
            if(*item2 == *(*val)) {
                vistaLista->getElenco()->insertAvatar(*val);
                match = true;
                QMessageBox::warning(this, "Errore",  "Nome già usato");
            }
            ++val;
        }
    } else if(modello->getLista()->ricerca(item4)) {
        vistaLista->getElenco()->clear();
        modello->setPercorso(destinazione.toStdString());
        modello->caricare();
        bool match = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !match) {
            if(*item2 == *(*val)) {
                vistaLista->getElenco()->insertAvatar(*val);
                match = true;
                QMessageBox::warning(this, "Errore",  "Nome già usato");
            }
            ++val;
        }
    } else if(modello->getLista()->ricerca(item5)) {
        vistaLista->getElenco()->clear();
        modello->setPercorso(destinazione.toStdString());
        modello->caricare();
        bool match = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !match) {
            if(*item2 == *(*val)) {
                vistaLista->getElenco()->insertAvatar(*val);
                match = true;
                QMessageBox::warning(this, "Errore",  "Nome già usato");
            }
            ++val;
        }
    }
    //parte per campi non compilati
    else if(nome == "" || (!(vistaCrea->getSessoM()->isChecked()) && !(vistaCrea->getSessoF()->isChecked())) || index == 0) {
        QMessageBox::warning(this, "Compila tutti i campi", "per creare un nuovo Avatar");
    } else { //parte per creazione avatar


        if(index == 1 || index == 2 || index == 3) {
            bool scudo;
            check = vistaCrea->getPowerUp1()->isChecked();
            if(check == 1) scudo = true;
            else scudo = false;

            bool spada;
            check = vistaCrea->getPowerUp2()->isChecked();
            if(check == 1) spada = true;
            else spada = false;

            bool anello;
            check = vistaCrea->getPowerUp3()->isChecked();
            if(check == 1) anello = true;
            else anello = false;

            bool libro;
            check = vistaCrea->getPowerUp4()->isChecked();
            if(check == 1) libro = true;
            else libro = false;

            if(index == 1) {
                double trasparentia = vistaCrea->getValoreSpeciale()->text().toDouble();
                Elfo* personaggio = new Elfo(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, percorso, scudo, spada, anello, libro, trasparentia);
                modello->getLista()->inserisci(personaggio);
                modello->salvare();
                carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            } else if(index == 2) {
                double corteccia = vistaCrea->getValoreSpeciale()->text().toDouble();
                Nano* personaggio = new Nano(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, percorso, scudo, spada, anello, libro, corteccia);
                modello->getLista()->inserisci(personaggio);
                modello->salvare();
                carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            } else if(index == 3) {
                double ingegnoScientifico = vistaCrea->getValoreSpeciale()->text().toDouble();
                Umano* personaggio = new Umano(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, percorso, scudo, spada, anello, libro, ingegnoScientifico);
                modello->getLista()->inserisci(personaggio);
                modello->salvare();
                carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            }

        } else if (index == 4 || index == 5) {
            bool barriera;
            check = vistaCrea->getPowerUp5()->isChecked();
            if(check == 1) barriera = true;
            else barriera = false;

            bool laser;
            check = vistaCrea->getPowerUp6()->isChecked();
            if(check == 1) laser = true;
            else laser = false;

            bool amuleto;
            check = vistaCrea->getPowerUp7()->isChecked();
            if(check == 1) amuleto = true;
            else amuleto = false;

            bool chip;
            check = vistaCrea->getPowerUp8()->isChecked();
            if(check == 1) chip = true;
            else chip = false;

            if(index == 4) {
                double ufo = vistaCrea->getValoreSpeciale()->text().toDouble();
                Alieno* personaggio = new Alieno(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, percorso, barriera, laser, amuleto, chip, ufo);
                modello->getLista()->inserisci(personaggio);
                modello->salvare();
                carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            } else if(index == 5) {
                double portaDemoniaca = vistaCrea->getValoreSpeciale()->text().toDouble();
                Mostro* personaggio = new Mostro(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, percorso, barriera, laser, amuleto, chip, portaDemoniaca);
                modello->getLista()->inserisci(personaggio);
                modello->salvare();
                carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            }
        }
    }
}

void Controller::modificaAvatar()
{
    vistaModifica->resetTutto();

    ElencoAvatar* aux = nullptr;
    Avatar* itemA = nullptr;

    if(vistaLista->getElenco()->itemAttuale() == nullptr) {
        QMessageBox::warning(this, "Attenzione", "Non hai selezionato alcun avatar da modificare");
    } else {
        aux = vistaLista->getElenco()->itemAttuale();
        itemA = aux->getItem();

        vistaModifica->getInserisciNome()->insert(QString::fromStdString(itemA->getNome()));
        vistaModifica->getBoxDescrizione()->insertPlainText(QString::fromStdString(itemA->getDescrizione()));
        std::string lvl = (std::to_string(itemA->getLiv()));
        vistaModifica->getLvl()->setText(QString::fromStdString(lvl));
        std::string exp = (std::to_string(itemA->getExp()));
        vistaModifica->getExp()->setText(QString::fromStdString(exp));
        std::string forza = (std::to_string(itemA->getForza()));
        vistaModifica->getValoreForza()->setText(QString::fromStdString(forza));
        std::string magia = (std::to_string(itemA->getMagia()));
        vistaModifica->getValoreMagia()->setText(QString::fromStdString(magia));
        std::string difesa = (std::to_string(itemA->getDifesa()));
        vistaModifica->getValoreDifesa()->setText(QString::fromStdString(difesa));
        std::string scienza = (std::to_string(itemA->getScienza()));
        vistaModifica->getValoreScienza()->setText(QString::fromStdString(scienza));
        std::string media = (std::to_string(itemA->getMedia()));
        vistaModifica->getValoreMedia()->setText(QString::fromStdString(media));
        vistaModifica->getTerrenoPreferito()->setText(QString::fromStdString(itemA->getTerreno()));
        itemA->getSesso() ? vistaModifica->getSessoM()->setChecked(true) : vistaModifica->getSessoF()->setChecked(true);
        std::string percorsoFoto = itemA->getPercorsoImmagine();
        vistaModifica->inserisciPercorso(percorsoFoto);

        if(dynamic_cast<Elfo*>(itemA)) {
            Elfo* e = static_cast<Elfo*>(itemA);

            vistaModifica->getTipoAvatar()->setText(QString::fromStdString(itemA->getTipo()));
            vistaModifica->groupTipo();
            e->getScu() ? vistaModifica->getPowerUp1()->setChecked(true), vistaModifica->checkUno() : vistaModifica->getPowerUp1()->setChecked(false);
            e->getSpada() ? vistaModifica->getPowerUp2()->setChecked(true), vistaModifica->checkDue() : vistaModifica->getPowerUp2()->setChecked(false);
            e->getAnello() ? vistaModifica->getPowerUp3()->setChecked(true), vistaModifica->checkTre() : vistaModifica->getPowerUp3()->setChecked(false);
            e->getLibro() ? vistaModifica->getPowerUp4()->setChecked(true), vistaModifica->checkQuattro() : vistaModifica->getPowerUp4()->setChecked(false);

            std::string trasparentia = (std::to_string(e->getTrasparentia()));
            vistaModifica->getValoreSpeciale()->setText(QString::fromStdString(trasparentia));
            vistaModifica->setModal(true);
            vistaModifica->setWindowTitle("Modifica Avatar");
            vistaModifica->setWindowIcon(QIcon(":/Risorse/Immagini Avatar/Elfo Maschio.png"));
            vistaModifica->show();

        } else if(dynamic_cast<Nano*>(itemA)) {
            Nano* n = static_cast<Nano*>(itemA);

            vistaModifica->getTipoAvatar()->setText(QString::fromStdString(itemA->getTipo()));
            vistaModifica->groupTipo();
            n->getScu() ? vistaModifica->getPowerUp1()->setChecked(true), vistaModifica->checkUno() : vistaModifica->getPowerUp1()->setChecked(false);
            n->getSpada() ? vistaModifica->getPowerUp2()->setChecked(true), vistaModifica->checkDue() : vistaModifica->getPowerUp2()->setChecked(false);
            n->getAnello() ? vistaModifica->getPowerUp3()->setChecked(true), vistaModifica->checkTre() : vistaModifica->getPowerUp3()->setChecked(false);
            n->getLibro() ? vistaModifica->getPowerUp4()->setChecked(true), vistaModifica->checkQuattro() : vistaModifica->getPowerUp4()->setChecked(false);

            std::string corteccia = (std::to_string(n->getCorteccia()));
            vistaModifica->getValoreSpeciale()->setText(QString::fromStdString(corteccia));
            vistaModifica->setModal(true);
            vistaModifica->setWindowTitle("Modifica Avatar");
            vistaModifica->setWindowIcon(QIcon(":/Risorse/Immagini Avatar/Nano Maschio.png"));
            vistaModifica->show();

        } else if(dynamic_cast<Umano*>(itemA)) {
            Umano* u = static_cast<Umano*>(itemA);

            vistaModifica->getTipoAvatar()->setText(QString::fromStdString(itemA->getTipo()));
            vistaModifica->groupTipo();
            u->getScu() ? vistaModifica->getPowerUp1()->setChecked(true), vistaModifica->checkUno() : vistaModifica->getPowerUp1()->setChecked(false);
            u->getSpada() ? vistaModifica->getPowerUp2()->setChecked(true), vistaModifica->checkDue() : vistaModifica->getPowerUp2()->setChecked(false);
            u->getAnello() ? vistaModifica->getPowerUp3()->setChecked(true), vistaModifica->checkTre() : vistaModifica->getPowerUp3()->setChecked(false);
            u->getLibro() ? vistaModifica->getPowerUp4()->setChecked(true), vistaModifica->checkQuattro() : vistaModifica->getPowerUp4()->setChecked(false);

            std::string ingegno = (std::to_string(u->getIngegno()));
            vistaModifica->getValoreSpeciale()->setText(QString::fromStdString(ingegno));
            vistaModifica->setModal(true);
            vistaModifica->setWindowTitle("Modifica Avatar");
            vistaModifica->setWindowIcon(QIcon(":/Risorse/Immagini Avatar/Umano Maschio.png"));
            vistaModifica->show();

        } else if(dynamic_cast<Alieno*>(itemA)) {
            Alieno* a = static_cast<Alieno*>(itemA);

            vistaModifica->getTipoAvatar()->setText(QString::fromStdString(itemA->getTipo()));
            vistaModifica->groupTipo();
            a->getBar() ? vistaModifica->getPowerUp5()->setChecked(true), vistaModifica->checkCinque() : vistaModifica->getPowerUp5()->setChecked(false);
            a->getLaser() ? vistaModifica->getPowerUp6()->setChecked(true), vistaModifica->checkSei() : vistaModifica->getPowerUp6()->setChecked(false);
            a->getAmuleto() ? vistaModifica->getPowerUp7()->setChecked(true), vistaModifica->checkSette() : vistaModifica->getPowerUp7()->setChecked(false);
            a->getChip() ? vistaModifica->getPowerUp8()->setChecked(true), vistaModifica->checkOtto() : vistaModifica->getPowerUp8()->setChecked(false);

            std::string ufo = (std::to_string(a->getUfo()));
            vistaModifica->getValoreSpeciale()->setText(QString::fromStdString(ufo));
            vistaModifica->setModal(true);
            vistaModifica->setWindowTitle("Modifica Avatar");
            vistaModifica->setWindowIcon(QIcon(":/Risorse/Immagini Avatar/Alieno.png"));

            vistaModifica->show();

        } else if(dynamic_cast<Mostro*>(itemA)) {
            Mostro* m = static_cast<Mostro*>(itemA);

            vistaModifica->getTipoAvatar()->setText(QString::fromStdString(itemA->getTipo()));
            vistaModifica->groupTipo();
            m->getBar() ? vistaModifica->getPowerUp5()->setChecked(true), vistaModifica->checkCinque() : vistaModifica->getPowerUp5()->setChecked(false);
            m->getLaser() ? vistaModifica->getPowerUp6()->setChecked(true), vistaModifica->checkSei() : vistaModifica->getPowerUp6()->setChecked(false);
            m->getAmuleto() ? vistaModifica->getPowerUp7()->setChecked(true), vistaModifica->checkSette() : vistaModifica->getPowerUp7()->setChecked(false);
            m->getChip() ? vistaModifica->getPowerUp8()->setChecked(true), vistaModifica->checkOtto() : vistaModifica->getPowerUp8()->setChecked(false);

            std::string porta = (std::to_string(m->getPorta()));
            vistaModifica->getValoreSpeciale()->setText(QString::fromStdString(porta));
            vistaModifica->setModal(true);
            vistaModifica->setWindowTitle("Modifica Avatar");
            vistaModifica->setWindowIcon(QIcon(":/Risorse/Immagini Avatar/Mostro Maschio.png"));
            vistaModifica->show();
        }
    }

}

void Controller::scontroTraAvatar()
{
    vistaScontro->getPowerup1selezionatoSx()->hide();
    vistaScontro->getPowerup2selezionatoSx()->hide();
    vistaScontro->getPowerup3selezionatoSx()->hide();
    vistaScontro->getPowerup4selezionatoSx()->hide();
    vistaScontro->getPowerup1selezionatoDx()->hide();
    vistaScontro->getPowerup2selezionatoDx()->hide();
    vistaScontro->getPowerup3selezionatoDx()->hide();
    vistaScontro->getPowerup4selezionatoDx()->hide();


    if(vistaLista->getElenco()->itemAttuale() == nullptr) {
        QMessageBox::warning(this, "Attenzione", "Non hai selezionato alcun avatar");
    } else if(modello->getLista()->counter() < 2) {
        QMessageBox::warning(this, "Attenzione", "Non ci sono abbastanza avversari. \nCrea un nuovo Avatar");
    } else {

        ElencoAvatar* aux = nullptr;
        Avatar* itemA = nullptr;

        aux = vistaLista->getElenco()->itemAttuale();
        itemA = aux->getItem();

        //Avversario random
        int max = modello->getLista()->counter();
        int numeroCasuale = rand()%(max);
        ElencoAvatar* itemCasuale = nullptr;
        Avatar* itemB = nullptr;
        itemCasuale = vistaLista->getElenco()->itemCasuale(numeroCasuale);
        itemB = itemCasuale->getItem();

        if(itemA == itemB) {
            itemA = nullptr;
            itemB = nullptr;
            scontroTraAvatar();
        } else {

            vistaScontro->getNomeAvatarSx()->setText(QString::fromStdString(itemA->getNome()));
            std::string media = (std::to_string(itemA->getMedia()));
            vistaScontro->getMediaSx()->setText(QString::fromStdString(media));
            std::string forza = (std::to_string(itemA->getForza()));
            std::string magia = (std::to_string(itemA->getMagia()));
            std::string difesa = (std::to_string(itemA->getDifesa()));
            std::string scienza = (std::to_string(itemA->getScienza()));
            std::string lvl = (std::to_string(itemA->getLiv()));
            std::string exp = (std::to_string(itemA->getExp()));
            std::string terrenoPreferito = (itemA->getTerreno());

            //foto
            QString foto = QString::fromStdString(itemA->getPercorsoImmagine());
            QPixmap fotoPix(foto);
            vistaScontro->getFotoAvatar1()->setPixmap(fotoPix);
            vistaScontro->getFotoAvatar1()->setPixmap(fotoPix.scaled(200,200, Qt::AspectRatioMode::KeepAspectRatio));


        //    unsigned int Lvl = vistaCrea->getLvl()->text().toUInt();
        //    if (Lvl>99){
        //        QMessageBox::about(this, "Errore", "Il livello dell'avatar è al massimo.\nScegli un altro avatar");
        //    } else {
        //        mostraScontro(); questo mostra scontro non ci va
        //    }

            if(dynamic_cast<Elfo*>(itemA)) {
                Elfo* e = static_cast<Elfo*>(itemA);
                e->getScu() ? vistaScontro->getPowerup1selezionatoSx()->setText("Scudo"), vistaScontro->getPowerup1selezionatoSx()->show(): (vistaScontro->getPowerup1selezionatoSx()->setText(""));
                e->getSpada() ? vistaScontro->getPowerup2selezionatoSx()->setText("Spada"), vistaScontro->getPowerup2selezionatoSx()->show() : (vistaScontro->getPowerup2selezionatoSx()->setText(""));
                e->getAnello() ? vistaScontro->getPowerup3selezionatoSx()->setText("Anello"), vistaScontro->getPowerup3selezionatoSx()->show() : (vistaScontro->getPowerup3selezionatoSx()->setText(""));
                e->getLibro() ? vistaScontro->getPowerup4selezionatoSx()->setText("Libro"), vistaScontro->getPowerup4selezionatoSx()->show() : (vistaScontro->getPowerup4selezionatoSx()->setText(""));
                std::string valoreSpeciale = (std::to_string(e->getTrasparentia()));
                vistaLista->hide();
                vistaScontro->show();

            } else if(dynamic_cast<Nano*>(itemA)) {
                Nano* n = static_cast<Nano*>(itemA);
                n->getScu() ? vistaScontro->getPowerup1selezionatoSx()->setText("Scudo"), vistaScontro->getPowerup1selezionatoSx()->show(): (vistaScontro->getPowerup1selezionatoSx()->setText(""));
                n->getSpada() ? vistaScontro->getPowerup2selezionatoSx()->setText("Spada"), vistaScontro->getPowerup2selezionatoSx()->show() : (vistaScontro->getPowerup2selezionatoSx()->setText(""));
                n->getAnello() ? vistaScontro->getPowerup3selezionatoSx()->setText("Anello"), vistaScontro->getPowerup3selezionatoSx()->show() : (vistaScontro->getPowerup3selezionatoSx()->setText(""));
                n->getLibro() ? vistaScontro->getPowerup4selezionatoSx()->setText("Libro"), vistaScontro->getPowerup4selezionatoSx()->show() : (vistaScontro->getPowerup4selezionatoSx()->setText(""));
                std::string valoreSpeciale = (std::to_string(n->getCorteccia()));
                vistaLista->hide();
                vistaScontro->show();

            } else if(dynamic_cast<Umano*>(itemA)) {
                Umano* u = static_cast<Umano*>(itemA);
                u->getScu() ? vistaScontro->getPowerup1selezionatoSx()->setText("Scudo"), vistaScontro->getPowerup1selezionatoSx()->show() : (vistaScontro->getPowerup1selezionatoSx()->setText(""));
                u->getSpada() ? vistaScontro->getPowerup2selezionatoSx()->setText("Spada"), vistaScontro->getPowerup2selezionatoSx()->show() : (vistaScontro->getPowerup2selezionatoSx()->setText(""));
                u->getAnello() ? vistaScontro->getPowerup3selezionatoSx()->setText("Anello"), vistaScontro->getPowerup3selezionatoSx()->show() : (vistaScontro->getPowerup3selezionatoSx()->setText(""));
                u->getLibro() ? vistaScontro->getPowerup4selezionatoSx()->setText("Libro"), vistaScontro->getPowerup4selezionatoSx()->show() : (vistaScontro->getPowerup4selezionatoSx()->setText(""));
                std::string valoreSpeciale = (std::to_string(u->getIngegno()));
                vistaLista->hide();
                vistaScontro->show();

            } else if(dynamic_cast<Alieno*>(itemA)) {
                Alieno* a = static_cast<Alieno*>(itemA);
                a->getBar() ? vistaScontro->getPowerup1selezionatoSx()->setText("Barriera"), vistaScontro->getPowerup1selezionatoSx()->show() : (vistaScontro->getPowerup1selezionatoSx()->setText(""));
                a->getLaser() ? vistaScontro->getPowerup2selezionatoSx()->setText("Laser"), vistaScontro->getPowerup2selezionatoSx()->show() : (vistaScontro->getPowerup2selezionatoSx()->setText(""));
                a->getAmuleto() ? vistaScontro->getPowerup3selezionatoSx()->setText("Amuleto"), vistaScontro->getPowerup3selezionatoSx()->show() : (vistaScontro->getPowerup3selezionatoSx()->setText(""));
                a->getChip() ? vistaScontro->getPowerup4selezionatoSx()->setText("Chip"), vistaScontro->getPowerup4selezionatoSx()->show() : (vistaScontro->getPowerup4selezionatoSx()->setText(""));
                std::string valoreSpeciale = (std::to_string(a->getUfo()));
                vistaLista->hide();
                vistaScontro->show();

            } else if(dynamic_cast<Mostro*>(itemA)) {
                Mostro* m = static_cast<Mostro*>(itemA);
                m->getBar() ? vistaScontro->getPowerup1selezionatoSx()->setText("Barriera"), vistaScontro->getPowerup1selezionatoSx()->show() : (vistaScontro->getPowerup1selezionatoSx()->setText(""));
                m->getLaser() ? vistaScontro->getPowerup2selezionatoSx()->setText("Laser"), vistaScontro->getPowerup2selezionatoSx()->show() : (vistaScontro->getPowerup2selezionatoSx()->setText(""));
                m->getAmuleto() ? vistaScontro->getPowerup3selezionatoSx()->setText("Amuleto"), vistaScontro->getPowerup3selezionatoSx()->show() : (vistaScontro->getPowerup3selezionatoSx()->setText(""));
                m->getChip() ? vistaScontro->getPowerup4selezionatoSx()->setText("Chip"), vistaScontro->getPowerup4selezionatoSx()->show() : (vistaScontro->getPowerup4selezionatoSx()->setText(""));
                std::string valoreSpeciale = (std::to_string(m->getPorta()));
                vistaLista->hide();
                vistaScontro->show();
            }



            vistaScontro->getNomeAvatarDx()->setText(QString::fromStdString(itemB->getNome()));
            std::string media2 = (std::to_string(itemB->getMedia()));
            vistaScontro->getMediaDx()->setText(QString::fromStdString(media2));
            std::string forza2 = (std::to_string(itemB->getForza()));
            std::string magia2 = (std::to_string(itemB->getMagia()));
            std::string difesa2 = (std::to_string(itemB->getDifesa()));
            std::string scienza2 = (std::to_string(itemB->getScienza()));
            std::string lvl2 = (std::to_string(itemB->getLiv()));
            std::string exp2 = (std::to_string(itemB->getExp()));
            std::string terrenoPreferito2 = (itemB->getTerreno());

            //foto
            QString foto2 = QString::fromStdString(itemB->getPercorsoImmagine());
            QPixmap fotoPix2(foto2);
            vistaScontro->getFotoAvatar2()->setPixmap(fotoPix2);
            vistaScontro->getFotoAvatar2()->setPixmap(fotoPix2.scaled(200,200, Qt::AspectRatioMode::KeepAspectRatio));


            if(dynamic_cast<Elfo*>(itemB)) {
                Elfo* e = static_cast<Elfo*>(itemB);
                e->getScu() ? vistaScontro->getPowerup1selezionatoDx()->setText("Scudo"), vistaScontro->getPowerup1selezionatoDx()->show(): (vistaScontro->getPowerup1selezionatoDx()->setText(""));
                e->getSpada() ? vistaScontro->getPowerup2selezionatoDx()->setText("Spada"), vistaScontro->getPowerup2selezionatoDx()->show() : (vistaScontro->getPowerup2selezionatoDx()->setText(""));
                e->getAnello() ? vistaScontro->getPowerup3selezionatoDx()->setText("Anello"), vistaScontro->getPowerup3selezionatoDx()->show() : (vistaScontro->getPowerup3selezionatoDx()->setText(""));
                e->getLibro() ? vistaScontro->getPowerup4selezionatoDx()->setText("Libro"), vistaScontro->getPowerup4selezionatoDx()->show() : (vistaScontro->getPowerup4selezionatoDx()->setText(""));
                std::string valoreSpeciale2 = (std::to_string(e->getTrasparentia()));

            } else if(dynamic_cast<Nano*>(itemB)) {
                Nano* n = static_cast<Nano*>(itemB);
                n->getScu() ? vistaScontro->getPowerup1selezionatoDx()->setText("Scudo"), vistaScontro->getPowerup1selezionatoDx()->show(): (vistaScontro->getPowerup1selezionatoDx()->setText(""));
                n->getSpada() ? vistaScontro->getPowerup2selezionatoDx()->setText("Spada"), vistaScontro->getPowerup2selezionatoDx()->show() : (vistaScontro->getPowerup2selezionatoDx()->setText(""));
                n->getAnello() ? vistaScontro->getPowerup3selezionatoDx()->setText("Anello"), vistaScontro->getPowerup3selezionatoDx()->show() : (vistaScontro->getPowerup3selezionatoDx()->setText(""));
                n->getLibro() ? vistaScontro->getPowerup4selezionatoDx()->setText("Libro"), vistaScontro->getPowerup4selezionatoDx()->show() : (vistaScontro->getPowerup4selezionatoDx()->setText(""));
                std::string valoreSpeciale2 = (std::to_string(n->getCorteccia()));

            } else if(dynamic_cast<Umano*>(itemB)) {
                Umano* u = static_cast<Umano*>(itemB);
                u->getScu() ? vistaScontro->getPowerup1selezionatoDx()->setText("Scudo"), vistaScontro->getPowerup1selezionatoDx()->show() : (vistaScontro->getPowerup1selezionatoDx()->setText(""));
                u->getSpada() ? vistaScontro->getPowerup2selezionatoDx()->setText("Spada"), vistaScontro->getPowerup2selezionatoDx()->show() : (vistaScontro->getPowerup2selezionatoDx()->setText(""));
                u->getAnello() ? vistaScontro->getPowerup3selezionatoDx()->setText("Anello"), vistaScontro->getPowerup3selezionatoDx()->show() : (vistaScontro->getPowerup3selezionatoDx()->setText(""));
                u->getLibro() ? vistaScontro->getPowerup4selezionatoDx()->setText("Libro"), vistaScontro->getPowerup4selezionatoDx()->show() : (vistaScontro->getPowerup4selezionatoDx()->setText(""));
                std::string valoreSpeciale2 = (std::to_string(u->getIngegno()));

            } else if(dynamic_cast<Alieno*>(itemB)) {
                Alieno* a = static_cast<Alieno*>(itemB);
                a->getBar() ? vistaScontro->getPowerup1selezionatoDx()->setText("Barriera"), vistaScontro->getPowerup1selezionatoDx()->show() : (vistaScontro->getPowerup1selezionatoDx()->setText(""));
                a->getLaser() ? vistaScontro->getPowerup2selezionatoDx()->setText("Laser"), vistaScontro->getPowerup2selezionatoDx()->show() : (vistaScontro->getPowerup2selezionatoDx()->setText(""));
                a->getAmuleto() ? vistaScontro->getPowerup3selezionatoDx()->setText("Amuleto"), vistaScontro->getPowerup3selezionatoDx()->show() : (vistaScontro->getPowerup3selezionatoDx()->setText(""));
                a->getChip() ? vistaScontro->getPowerup4selezionatoDx()->setText("Chip"), vistaScontro->getPowerup4selezionatoDx()->show() : (vistaScontro->getPowerup4selezionatoDx()->setText(""));
                std::string valoreSpeciale2 = (std::to_string(a->getUfo()));

            } else if(dynamic_cast<Mostro*>(itemB)) {
                Mostro* m = static_cast<Mostro*>(itemB);
                m->getBar() ? vistaScontro->getPowerup1selezionatoDx()->setText("Barriera"), vistaScontro->getPowerup1selezionatoDx()->show() : (vistaScontro->getPowerup1selezionatoDx()->setText(""));
                m->getLaser() ? vistaScontro->getPowerup2selezionatoDx()->setText("Laser"), vistaScontro->getPowerup2selezionatoDx()->show() : (vistaScontro->getPowerup2selezionatoDx()->setText(""));
                m->getAmuleto() ? vistaScontro->getPowerup3selezionatoDx()->setText("Amuleto"), vistaScontro->getPowerup3selezionatoDx()->show() : (vistaScontro->getPowerup3selezionatoDx()->setText(""));
                m->getChip() ? vistaScontro->getPowerup4selezionatoDx()->setText("Chip"), vistaScontro->getPowerup4selezionatoDx()->show() : (vistaScontro->getPowerup4selezionatoDx()->setText(""));
                std::string valoreSpeciale2 = (std::to_string(m->getPorta()));
            }

            //Terreno casuale
            int numeroC = rand() % 5;
            if(numeroC == 0) {
                vistaScontro->getTerreno()->setText("Regno incantato");
            } else if(numeroC == 1) {
                vistaScontro->getTerreno()->setText("Regno del sottosuolo");
            } else if(numeroC == 2) {
                vistaScontro->getTerreno()->setText("Regno delle macchine");
            } else if(numeroC == 3) {
                vistaScontro->getTerreno()->setText("Regno dello spazio");
            } else {
                vistaScontro->getTerreno()->setText("Regno dei demoni");
            }
        }
    }
}

void Controller::rimuoviAvatar()
{
    if(vistaLista->getElenco()->itemAttuale() == nullptr) {
        QMessageBox::warning(this, "Attenzione", "Non hai selezionato alcun avatar da eliminare");
    } else {


        ElencoAvatar* aux = nullptr;
        Avatar* item = nullptr;

        if(vistaLista->getElenco()->itemAttuale() != nullptr) {
            aux = vistaLista->getElenco()->itemAttuale();
            item = aux->getItem();
            modello->rimuovi(item);
            modello->salvare();
            carica();

            QMessageBox::about(this, "Eliminazione completata", "L'avatar selezionato è stato eliminato dall'elenco");
        }

        vistaLista->getBottoneRimuovi()->setEnabled(false);
        vistaLista->getBottoneModifica()->setEnabled(false);
        vistaLista->getBottoneGioca()->setEnabled(false);
    }
}

void Controller::ricercaAvatar()
{
    std::string nome = vistaLista->getCercaNome()->text().toStdString();

    if(nome == "") {
        QMessageBox::warning(this, "Errore", "Completa il campo Nome per avviare una ricerca");
        return;
    }

    Avatar* item = new Elfo(nome);
    Avatar* item2 = new Nano(nome);
    Avatar* item3 = new Umano(nome);
    Avatar* item4 = new Alieno(nome);
    Avatar* item5 = new Mostro(nome);

    if(modello->getLista()->ricerca(item)) {
        vistaLista->getElenco()->clear();
        modello->setPercorso(destinazione.toStdString());
        modello->caricare();
        bool match = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !match) {
            if(*item == *(*val)) {
                vistaLista->getElenco()->insertAvatar(*val);
                match = true;
            }
            ++val;
        }

    } else if(modello->getLista()->ricerca(item2)) {
        vistaLista->getElenco()->clear();
        modello->setPercorso(destinazione.toStdString());
        modello->caricare();
        bool match = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !match) {
            if(*item2 == *(*val)) {
                vistaLista->getElenco()->insertAvatar(*val);
                match = true;
            }
            ++val;
        }
    } else if(modello->getLista()->ricerca(item3)) {
        vistaLista->getElenco()->clear();
        modello->setPercorso(destinazione.toStdString());
        modello->caricare();
        bool match = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !match) {
            if(*item3 == *(*val)) {
                vistaLista->getElenco()->insertAvatar(*val);
                match = true;
            }
            ++val;
        }
    } else if(modello->getLista()->ricerca(item4)) {
        vistaLista->getElenco()->clear();
        modello->setPercorso(destinazione.toStdString());
        modello->caricare();
        bool match = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !match) {
            if(*item4 == *(*val)) {
                vistaLista->getElenco()->insertAvatar(*val);
                match = true;
            }
            ++val;
        }
    } else if(modello->getLista()->ricerca(item5)) {
        vistaLista->getElenco()->clear();
        modello->setPercorso(destinazione.toStdString());
        modello->caricare();
        bool match = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !match) {
            if(*item5 == *(*val)) {
                vistaLista->getElenco()->insertAvatar(*val);
                match = true;
            }
            ++val;
        }
    }

    else {
        QMessageBox::warning(this, "Errore",  "Non è stato trovato nessun Avatar");
    }
}

void Controller::caricaDb()
{
    destinazione = QFileDialog::getOpenFileName(this, "Scegli file", ":Risorse", "File XML(*.xml)");
    carica();
}

void Controller::carica()
{
    vistaLista->getCercaNome()->clear();
    if(destinazione!="") {
        if(!(vistaLista->getTipoElfo()->isChecked()) && !(vistaLista->getTipoNano()->isChecked()) &&
                !(vistaLista->getTipoUmano()->isChecked()) && !(vistaLista->getTipoAlieno()->isChecked()) &&
                !(vistaLista->getTipoMostro()->isChecked())) {

            vistaLista->getElenco()->clear();
            modello->setPercorso(destinazione.toStdString());
            modello->caricare();

            Container<Avatar*>::iteratoreConst val = modello->beginConst();
            Container<Avatar*>::iteratoreConst valFin = modello->endConst();

            while(val != valFin) {
                vistaLista->getElenco()->insertAvatar(*val);
                ++val;
            }
        }
         else {
            vistaLista->getElenco()->clear();
            modello->setPercorso(destinazione.toStdString());
            modello->caricare();

            if(vistaLista->getTipoElfo()->isChecked()) {
                Container<Avatar*>::iteratoreConst val = modello->beginConst();
                Container<Avatar*>::iteratoreConst valFin = modello->endConst();

                while(val != valFin) {
                    if((*val)->getTipo()=="Elfo") {
                        vistaLista->getElenco()->insertAvatar(*val);
                    }
                    ++val;
                }

            }

            if(vistaLista->getTipoNano()->isChecked()) {
                Container<Avatar*>::iteratoreConst val = modello->beginConst();
                Container<Avatar*>::iteratoreConst valFin = modello->endConst();

                while(val != valFin) {
                    if((*val)->getTipo()=="Nano") {
                        vistaLista->getElenco()->insertAvatar(*val);
                    }
                    ++val;
                }
            }

            if(vistaLista->getTipoUmano()->isChecked()) {
                Container<Avatar*>::iteratoreConst val = modello->beginConst();
                Container<Avatar*>::iteratoreConst valFin = modello->endConst();

                while(val != valFin) {
                    if((*val)->getTipo()=="Umano") {
                        vistaLista->getElenco()->insertAvatar(*val);
                    }
                    ++val;
                }
            }

            if(vistaLista->getTipoAlieno()->isChecked()) {
                Container<Avatar*>::iteratoreConst val = modello->beginConst();
                Container<Avatar*>::iteratoreConst valFin = modello->endConst();

                while(val != valFin) {
                    if((*val)->getTipo()=="Alieno") {
                        vistaLista->getElenco()->insertAvatar(*val);
                    }
                    ++val;
                }
            }

            if(vistaLista->getTipoMostro()->isChecked()) {
                Container<Avatar*>::iteratoreConst val = modello->beginConst();
                Container<Avatar*>::iteratoreConst valFin = modello->endConst();

                while(val != valFin) {
                    if((*val)->getTipo()=="Mostro") {
                        vistaLista->getElenco()->insertAvatar(*val);
                    }
                    ++val;
                }
            }
            vistaLista->getBottoneModifica()->setEnabled(false);
            vistaLista->getBottoneRimuovi()->setEnabled(false);
            vistaLista->getBottoneGioca()->setEnabled(false);
        }
    }
}

void Controller::salva()
{
    ElencoAvatar* aux = nullptr;
    Avatar* itemA = nullptr;

    aux = vistaLista->getElenco()->itemAttuale();
    itemA = aux->getItem();

    std::string nomeOriginale = itemA->getNome();
    std::string nome = vistaModifica->getInserisciNome()->text().toStdString();
    Avatar* item = new Elfo(nome);
    Avatar* item2 = new Nano(nome);
    Avatar* item3 = new Umano(nome);
    Avatar* item4 = new Alieno(nome);
    Avatar* item5 = new Mostro(nome);



    if(nome == "")
        QMessageBox::warning(this, "Attenzione", "Compila tutti i campi");
    else if(nome != nomeOriginale) {
        if(modello->getLista()->ricerca(item)) {
            bool match = false;
            Container<Avatar*>::iteratoreConst val = modello->beginConst();
            Container<Avatar*>::iteratoreConst valFin = modello->endConst();
            while(val != valFin && !match) {
                if(*item == *(*val)) {
                    match = true;
                    QMessageBox::warning(this, "Errore",  "Nome già usato");
                }
                ++val;
            }
        } else if(modello->getLista()->ricerca(item2)) {
            bool match = false;
            Container<Avatar*>::iteratoreConst val = modello->beginConst();
            Container<Avatar*>::iteratoreConst valFin = modello->endConst();
            while(val != valFin && !match) {
                if(*item2 == *(*val)) {
                    match = true;
                    QMessageBox::warning(this, "Errore",  "Nome già usato");
                }
                ++val;
            }
        } else if(modello->getLista()->ricerca(item3)) {
            bool match = false;
            Container<Avatar*>::iteratoreConst val = modello->beginConst();
            Container<Avatar*>::iteratoreConst valFin = modello->endConst();
            while(val != valFin && !match) {
                if(*item3 == *(*val)) {
                    match = true;
                    QMessageBox::warning(this, "Errore",  "Nome già usato");
                }
                ++val;
            }
        } else if(modello->getLista()->ricerca(item4)) {
            bool match = false;
            Container<Avatar*>::iteratoreConst val = modello->beginConst();
            Container<Avatar*>::iteratoreConst valFin = modello->endConst();
            while(val != valFin && !match) {
                if(*item4 == *(*val)) {
                    match = true;
                    QMessageBox::warning(this, "Errore",  "Nome già usato");
                }
                ++val;
            }
        } else if(modello->getLista()->ricerca(item5)) {
            bool match = false;
            Container<Avatar*>::iteratoreConst val = modello->beginConst();
            Container<Avatar*>::iteratoreConst valFin = modello->endConst();
            while(val != valFin && !match) {
                if(*item5 == *(*val)) {
                    match = true;
                    QMessageBox::warning(this, "Errore",  "Nome già usato");
                }
                ++val;
            }
        }
    } else {

        itemA->setNome(nome);
        itemA->setDescrizione(vistaModifica->getBoxDescrizione()->toPlainText().toStdString());
        itemA->setLvl(vistaModifica->getLvl()->text().toUInt());
        itemA->setExp(vistaModifica->getExp()->text().toUInt());
        itemA->setForza(vistaModifica->getValoreForza()->text().toUInt());
        itemA->setMagia(vistaModifica->getValoreMagia()->text().toUInt());
        itemA->setDifesa(vistaModifica->getValoreDifesa()->text().toUInt());
        itemA->setScienza(vistaModifica->getValoreScienza()->text().toUInt());
        itemA->setMedia(vistaModifica->getValoreMedia()->text().toDouble());
        itemA->setTerreno(vistaModifica->getTerrenoPreferito()->text().toStdString());
        itemA->setSesso(vistaModifica->getSessoM()->isChecked());
        itemA->setPercorsoImmagine(vistaModifica->getPercorsoImmagine().toStdString());

        if(dynamic_cast<Elfo*>(itemA)) {
            Elfo* e = static_cast<Elfo*>(itemA);

            e->setScudo(vistaModifica->getPowerUp1()->isChecked());
            e->setSpada(vistaModifica->getPowerUp2()->isChecked());
            e->setAnello(vistaModifica->getPowerUp3()->isChecked());
            e->setLibro(vistaModifica->getPowerUp4()->isChecked());
            e->setTrasparentia(vistaModifica->getValoreSpeciale()->text().toDouble());
            modello->salvare();
            carica();
            vistaModifica->close();
            QMessageBox::about(this, "Modifica effettuta", "L'Avatar è stato correttamente modificato :)");

        } else if(dynamic_cast<Nano*>(itemA)) {
            Nano* n = static_cast<Nano*>(itemA);

            n->setScudo(vistaModifica->getPowerUp1()->isChecked());
            n->setSpada(vistaModifica->getPowerUp2()->isChecked());
            n->setAnello(vistaModifica->getPowerUp3()->isChecked());
            n->setLibro(vistaModifica->getPowerUp4()->isChecked());
            n->setCorteccia(vistaModifica->getValoreSpeciale()->text().toDouble());
            modello->salvare();
            carica();
            vistaModifica->close();
            QMessageBox::about(this, "Modifica effettuta", "L'Avatar è stato correttamente modificato :)");

        } else if(dynamic_cast<Umano*>(itemA)) {
            Umano* u = static_cast<Umano*>(itemA);

            u->setScudo(vistaModifica->getPowerUp1()->isChecked());
            u->setSpada(vistaModifica->getPowerUp2()->isChecked());
            u->setAnello(vistaModifica->getPowerUp3()->isChecked());
            u->setLibro(vistaModifica->getPowerUp4()->isChecked());
            u->setIngegno(vistaModifica->getValoreSpeciale()->text().toDouble());
            modello->salvare();
            carica();
            vistaModifica->close();
            QMessageBox::about(this, "Modifica effettuta", "L'Avatar è stato correttamente modificato :)");

        } else if(dynamic_cast<Alieno*>(itemA)) {
            Alieno* a = static_cast<Alieno*>(itemA);

            a->setBarriera(vistaModifica->getPowerUp5()->isChecked());
            a->setLaser(vistaModifica->getPowerUp6()->isChecked());
            a->setAmuleto(vistaModifica->getPowerUp7()->isChecked());
            a->setChip(vistaModifica->getPowerUp8()->isChecked());
            a->setUfo(vistaModifica->getValoreSpeciale()->text().toDouble());
            modello->salvare();
            carica();
            vistaModifica->close();
            QMessageBox::about(this, "Modifica effettuta", "L'Avatar è stato correttamente modificato :)");

        } else if(dynamic_cast<Mostro*>(itemA)) {
            Mostro* m = static_cast<Mostro*>(itemA);

            m->setBarriera(vistaModifica->getPowerUp5()->isChecked());
            m->setLaser(vistaModifica->getPowerUp6()->isChecked());
            m->setAmuleto(vistaModifica->getPowerUp7()->isChecked());
            m->setChip(vistaModifica->getPowerUp8()->isChecked());
            m->setPorta(vistaModifica->getValoreSpeciale()->text().toDouble());
            modello->salvare();
            carica();
            vistaModifica->close();
            QMessageBox::about(this, "Modifica effettuta", "L'Avatar è stato correttamente modificato :)");
        }
    }
}

void Controller::scontro()
{
    std::string nome = vistaScontro->getNomeAvatarSx()->text().toStdString();
    std::string nomeCPU = vistaScontro->getNomeAvatarDx()->text().toStdString();

    Avatar* player = nullptr;
    Avatar* CPU = nullptr;

    Avatar* item = new Elfo(nome);
    Avatar* item2 = new Nano(nome);
    Avatar* item3 = new Umano(nome);
    Avatar* item4 = new Alieno(nome);
    Avatar* item5 = new Mostro(nome);

    if(modello->getLista()->ricerca(item)) {
        bool trovato = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !trovato) {
            if(*item == *(*val)) {
                player = *val;
                trovato = true;
            }
            ++val;
        }
    } else if(modello->getLista()->ricerca(item2)) {
        bool trovato = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !trovato) {
            if(*item2 == *(*val)) {
                player = *val;
                trovato = true;
            }
            ++val;
        }
    } else if(modello->getLista()->ricerca(item3)) {
        bool trovato = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !trovato) {
            if(*item3 == *(*val)) {
                player = *val;
                trovato = true;
            }
            ++val;
        }
    } else if(modello->getLista()->ricerca(item4)) {
        bool trovato = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !trovato) {
            if(*item4 == *(*val)) {
                player = *val;
                trovato = true;
            }
            ++val;
        }
    } else if(modello->getLista()->ricerca(item5)) {
        bool trovato = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !trovato) {
            if(*item5 == *(*val)) {
                player = *val;
                trovato = true;
            }
            ++val;
        }
    }

    Avatar* itemCPU = new Elfo(nomeCPU);
    Avatar* item2CPU = new Nano(nomeCPU);
    Avatar* item3CPU = new Umano(nomeCPU);
    Avatar* item4CPU = new Alieno(nomeCPU);
    Avatar* item5CPU = new Mostro(nomeCPU);

    if(modello->getLista()->ricerca(itemCPU)) {
        bool trovato = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !trovato) {
            if(*itemCPU == *(*val)) {
                CPU = *val;
                trovato = true;
            }
            ++val;
        }
    } else if(modello->getLista()->ricerca(item2CPU)) {
        bool trovato = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !trovato) {
            if(*item2CPU == *(*val)) {
                CPU = *val;
                trovato = true;
            }
            ++val;
        }
    } else if(modello->getLista()->ricerca(item3CPU)) {
        bool trovato = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !trovato) {
            if(*item3CPU == *(*val)) {
                CPU = *val;
                trovato = true;
            }
            ++val;
        }
    } else if(modello->getLista()->ricerca(item4CPU)) {
        bool trovato = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !trovato) {
            if(*item4CPU == *(*val)) {
                CPU = *val;
                trovato = true;
            }
            ++val;
        }
    } else if(modello->getLista()->ricerca(item5CPU)) {
        bool trovato = false;

        Container<Avatar*>::iteratoreConst val = modello->beginConst();
        Container<Avatar*>::iteratoreConst valFin = modello->endConst();

        while(val != valFin && !trovato) {
            if(*item5CPU == *(*val)) {
                CPU = *val;
                trovato = true;
            }
            ++val;
        }
    }



    int forzaP = player->getForza();
    int forzaCPU = CPU->getForza();
    int difesaP = player->getDifesa();
    int difesaCPU = CPU->getDifesa();
    int scienzaP = player->getScienza();
    int scienzaCPU = CPU->getScienza();
    int magiaP = player->getMagia();
    int magiaCPU = CPU->getMagia();
    double mediaP = player->getMedia();
    double mediaCPU = CPU->getMedia();

    //Cambio stats in base a terreno
    std::string campo = vistaScontro->getTerreno()->text().toStdString();
    if(player->getTerreno() == campo) {
        forzaP=forzaP+1;
        difesaP=difesaP+1;
        magiaP=magiaP+1;
        scienzaP=scienzaP+1;
    }
    if(CPU->getTerreno() == campo) {
        forzaCPU=forzaCPU+1;
        difesaCPU=difesaCPU+1;
        magiaCPU=magiaCPU+1;
        scienzaCPU=scienzaCPU+1;
    }

    double valoreSP;
    double valoreSCPU;
    Elfo* e = dynamic_cast<Elfo*>(player);
    Nano* n = dynamic_cast<Nano*>(player);
    Umano* u = dynamic_cast<Umano*>(player);
    Alieno* a = dynamic_cast<Alieno*>(player);
    Mostro* m = dynamic_cast<Mostro*>(player);
    Elfo* ec = dynamic_cast<Elfo*>(CPU);
    Nano* nc = dynamic_cast<Nano*>(CPU);
    Umano* uc = dynamic_cast<Umano*>(CPU);
    Alieno* ac = dynamic_cast<Alieno*>(CPU);
    Mostro* mc = dynamic_cast<Mostro*>(CPU);

    if(e) {
        valoreSP = e->getTrasparentia();
    } else if(n) {
        valoreSP = n->getCorteccia();
    } else if(u) {
        valoreSP = u->getIngegno();
    } else if(a) {
        valoreSP = a->getUfo();
    } else {
        valoreSP = m->getPorta();
    }

    if(ec) {
        valoreSCPU = ec->getTrasparentia();
    } else if(nc) {
        valoreSCPU = nc->getCorteccia();
    } else if(uc) {
        valoreSCPU = uc->getIngegno();
    } else if(ac) {
        valoreSCPU = ac->getUfo();
    } else {
        valoreSCPU = mc->getPorta();
    }

    int punteggio = 0;
    if(forzaP > forzaCPU) {
        punteggio++;
    } else if(forzaP < forzaCPU) {
        punteggio--;
    }

    if(difesaP > difesaCPU) {
        punteggio++;
    } else if(difesaP < difesaCPU) {
        punteggio--;
    }

    if(scienzaP > scienzaCPU) {
        punteggio++;
    } else if(scienzaP < scienzaCPU) {
        punteggio--;
    }

    if(magiaP > magiaCPU) {
        punteggio++;
    } else if(magiaP < magiaCPU) {
        punteggio--;
    }

    if(valoreSP > valoreSCPU) {
        punteggio++;
    } else if(valoreSP < valoreSCPU) {
        punteggio--;
    }

    if(player->getTerreno() == campo) {
        forzaP=forzaP-1;
        difesaP=difesaP-1;
        magiaP=magiaP-1;
        scienzaP=scienzaP-1;
    }

    if(punteggio>0) {
        int x = 40;
        if(player->getExp()>59) {
            if(e) {
                player->setForza(forzaP+6);
                player->setMagia(magiaP+10);
                player->setDifesa(difesaP+6);
                player->setScienza(scienzaP+5);
                e->setTrasparentia((e->getMagia()+e->getDifesa())*(e->getLiv()+1)*0.3);
            } else if(n) {
                player->setForza(forzaP+7);
                player->setMagia(magiaP+2);
                player->setDifesa(difesaP+10);
                player->setScienza(scienzaP+6);

            } else if(u) {
                player->setForza(forzaP+5);
                player->setMagia(magiaP+3);
                player->setDifesa(difesaP+8);
                player->setScienza(scienzaP+8);

            } else if(a) {
                player->setForza(forzaP+3);
                player->setMagia(magiaP+10);
                player->setDifesa(difesaP+0);
                player->setScienza(scienzaP+7);

            } else if(m) {
                player->setForza(forzaP+10);
                player->setMagia(magiaP+0);
                player->setDifesa(difesaP+5);
                player->setScienza(scienzaP+9);

            }
            double newF = player->getForza();
            double newM = player->getMagia();
            double newD = player->getDifesa();
            double newS = player->getScienza();
            mediaP = (newF + newM + newD + newS)/4;
            player->setMedia(mediaP);

        }
        player->setExp(player->getExp()+40);
        int exp = player->getExp();
        int lvl = player->getLiv();
        QMessageBox::about(this, "Vittoria", QString("Complimenti!\nHai vinto la battaglia e hai guadagnato %1 punti esperienza.\nOra hai %2 punti esperienza e il tuo avatar è al livello %3.").arg(x).arg(exp).arg(lvl));
        modello->salvare();
    } else if(punteggio<0){
        int x = 10;
        if(player->getExp()>9) {
            player->setExp(player->getExp()-10);
        }
        QMessageBox::about(this, "Sconfitta", QString("Peccato, hai perso la battaglia.\nNon demoralizzarti, hai perso solo %1 punti esperienza.").arg(x));
        modello->salvare();
    } else {
        if(mediaP > mediaCPU) {
            int x = 40;
            if(player->getExp()>59) {
                if(e) {
                    player->setForza(forzaP+6);
                    player->setMagia(magiaP+10);
                    player->setDifesa(difesaP+6);
                    player->setScienza(scienzaP+5);

                } else if(n) {
                    player->setForza(forzaP+7);
                    player->setMagia(magiaP+2);
                    player->setDifesa(difesaP+10);
                    player->setScienza(scienzaP+6);

                } else if(u) {
                    player->setForza(forzaP+5);
                    player->setMagia(magiaP+3);
                    player->setDifesa(difesaP+8);
                    player->setScienza(scienzaP+8);

                } else if(a) {
                    player->setForza(forzaP+3);
                    player->setMagia(magiaP+10);
                    player->setDifesa(difesaP+0);
                    player->setScienza(scienzaP+7);

                } else if(m) {
                    player->setForza(forzaP+10);
                    player->setMagia(magiaP+0);
                    player->setDifesa(difesaP+5);
                    player->setScienza(scienzaP+9);

                }
                mediaP = (player->getForza()+player->getMagia()+player->getDifesa()+player->getScienza())/4;
                player->setMedia(mediaP);

            }
            player->setExp(player->getExp()+40);
            int exp = player->getExp();
            int lvl = player->getLiv();
            QMessageBox::about(this, "Vittoria", QString("Complimenti!\nHai vinto la battaglia e hai guadagnato %1 punti esperienza.\nOra hai %2 punti esperienza e il tuo avatar è al livello %3.").arg(x).arg(exp).arg(lvl));
            modello->salvare();
        } else if(mediaP < mediaCPU) {
            int x = 10;
            if(player->getExp()>9) {
                player->setExp(player->getExp()-10);
            }
            QMessageBox::about(this, "Sconfitta", QString("Peccato, hai perso la battaglia.\nNon demoralizzarti, hai perso solo %1 punti esperienza.").arg(x));
            modello->salvare();
        } else {
            QMessageBox::about(this, "Pareggio", "Ok. Parità./nI tuoi valori sono rimasti invariati.");
        }
    }

    scontroTraAvatar();

}

void Controller::resetRicerca()
{
    vistaLista->getElenco()->clear();
    carica();
}

void Controller::setAvatarGameStyle()
{
    setFixedSize(QSize(800,500));


    QFile file(":/Risorse/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);

    setWindowIcon(QIcon(":/Risorse/Immagini Avatar/Umano Maschio.png"));
}



