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
    connect(vistaLista->getBottoneHome(),SIGNAL(clicked()),this,SLOT(mostraHome()));
    connect(vistaLista->getBottoneGioca(),SIGNAL(clicked()),this,SLOT(scontroTraAvatar()));
    connect(vistaLista->getBottoneModifica(),SIGNAL(clicked()),this,SLOT(modificaAvatar()));
    connect(vistaLista->getBottoneInfoLista(),SIGNAL(clicked()),this,SLOT(infoPopLista()));
    connect(vistaLista->getTipoElfo(),SIGNAL(clicked()),this,SLOT(carica()));
    connect(vistaLista->getTipoNano(),SIGNAL(clicked()),this,SLOT(carica()));
    connect(vistaLista->getTipoUmano(),SIGNAL(clicked()),this,SLOT(carica()));
    connect(vistaLista->getTipoAlieno(),SIGNAL(clicked()),this,SLOT(carica()));
    connect(vistaLista->getTipoMostro(),SIGNAL(clicked()),this,SLOT(carica()));
    connect(vistaLista->getBottoneRimuovi(),SIGNAL(clicked()),this,SLOT(rimuoviAvatar()));
    connect(vistaLista->getBottoneRimuoviTutto(),SIGNAL(clicked()),this,SLOT(svuotaElenco()));
    connect(vistaLista->getAvviaRicerca(),SIGNAL(clicked()),this,SLOT(ricercaAvatar()));

    connect(vistaModifica->getBottoneSalvaModifiche(), SIGNAL(clicked()),this,SLOT(salva()));

    //CONNECT SCONTRO
    connect(vistaScontro->getBottoneHomeScontro(),SIGNAL(clicked()),this,SLOT(mostraHome()));
    connect(vistaScontro->getBottoneCombatti(),SIGNAL(clicked()),this,SLOT(mostraFineScontro()));
    connect(vistaScontro->getBottoneCambioAvatar(),SIGNAL(clicked()),this,SLOT(mostraLista()));

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
    vistaLista->show();
    vistaHome->hide();
    vistaCrea->hide();
    vistaModifica->hide();
    vistaScontro->hide();
    vistaFineScontro->hide();
    vistaLista->resetLista();
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
    QMessageBox::about(this,"Cosa posso fare in questa finestra?","Quì puoi fare questo.\nChiudi questa finestra per scegliere un avatar");
}

void Controller::infoPopLista()
{
    QMessageBox::about(this,"Cosa posso fare in questa finestra?","Quì puoi fare questo.\nChiudi questa finestra per scegliere un avatar");
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
                unsigned int trasparentia = vistaCrea->getValoreSpeciale()->text().toUInt();
                Elfo* personaggio = new Elfo(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, percorso, scudo, spada, anello, libro, trasparentia);
                modello->getLista()->inserisci(personaggio);
                modello->salvare();
                carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            } else if(index == 2) {
                unsigned int corteccia = vistaCrea->getValoreSpeciale()->text().toUInt();
                Nano* personaggio = new Nano(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, percorso, scudo, spada, anello, libro, corteccia);
                modello->getLista()->inserisci(personaggio);
                modello->salvare();
                carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            } else if(index == 3) {
                unsigned int ingegnoScientifico = vistaCrea->getValoreSpeciale()->text().toUInt();
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
                unsigned int ufo = vistaCrea->getValoreSpeciale()->text().toUInt();
                Alieno* personaggio = new Alieno(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, percorso, barriera, laser, amuleto, chip, ufo);
                modello->getLista()->inserisci(personaggio);
                modello->salvare();
                carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            } else if(index == 5) {
                unsigned int portaDemoniaca = vistaCrea->getValoreSpeciale()->text().toUInt();
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

    aux = vistaLista->getElenco()->itemAttuale();
    itemA = aux->getItem();

    vistaModifica->getInserisciNome()->insert(QString::fromStdString(itemA->GetNome()));
    vistaModifica->getBoxDescrizione()->insertPlainText(QString::fromStdString(itemA->getDescrizione()));
    std::string lvl = (std::to_string(itemA->GetLiv()));
    vistaModifica->getLvl()->setText(QString::fromStdString(lvl));
    std::string exp = (std::to_string(itemA->GetExp()));
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
    itemA->GetSesso() ? vistaModifica->getSessoM()->setChecked(true) : vistaModifica->getSessoF()->setChecked(true);
    vistaModifica->inserisciPercorso(itemA->getPercorsoImmagine());

    if(dynamic_cast<Elfo*>(itemA)) {
        Elfo* e = static_cast<Elfo*>(itemA);

        vistaModifica->getSceltaTipo()->setCurrentIndex(1);
        vistaModifica->groupTipo();
        e->GetScu() ? vistaModifica->getPowerUp1()->setChecked(true), vistaModifica->checkUno() : vistaModifica->getPowerUp1()->setChecked(false);
        e->GetSpada() ? vistaModifica->getPowerUp2()->setChecked(true), vistaModifica->checkDue() : vistaModifica->getPowerUp2()->setChecked(false);
        e->GetAnello() ? vistaModifica->getPowerUp3()->setChecked(true), vistaModifica->checkTre() : vistaModifica->getPowerUp3()->setChecked(false);
        e->GetLibro() ? vistaModifica->getPowerUp4()->setChecked(true), vistaModifica->checkQuattro() : vistaModifica->getPowerUp4()->setChecked(false);

        std::string trasparentia = (std::to_string(e->GetTrasparentia()));
        vistaModifica->getValoreSpeciale()->setText(QString::fromStdString(trasparentia));
        vistaModifica->setModal(true);
        vistaModifica->setWindowTitle("Modifica Avatar");
        vistaModifica->setWindowIcon(QIcon(":/Risorse/Immagini Avatar/Elfo Maschio.png"));
        vistaModifica->show();

    } else if(dynamic_cast<Nano*>(itemA)) {
        Nano* n = static_cast<Nano*>(itemA);

        vistaModifica->getSceltaTipo()->setCurrentIndex(2);
        vistaModifica->groupTipo();
        n->GetScu() ? vistaModifica->getPowerUp1()->setChecked(true), vistaModifica->checkUno() : vistaModifica->getPowerUp1()->setChecked(false);
        n->GetSpada() ? vistaModifica->getPowerUp2()->setChecked(true), vistaModifica->checkDue() : vistaModifica->getPowerUp2()->setChecked(false);
        n->GetAnello() ? vistaModifica->getPowerUp3()->setChecked(true), vistaModifica->checkTre() : vistaModifica->getPowerUp3()->setChecked(false);
        n->GetLibro() ? vistaModifica->getPowerUp4()->setChecked(true), vistaModifica->checkQuattro() : vistaModifica->getPowerUp4()->setChecked(false);

        std::string corteccia = (std::to_string(n->GetCorteccia()));
        vistaModifica->getValoreSpeciale()->setText(QString::fromStdString(corteccia));
        vistaModifica->setModal(true);
        vistaModifica->setWindowTitle("Modifica Avatar");
        vistaModifica->setWindowIcon(QIcon(":/Risorse/Immagini Avatar/Nano Maschio.png"));
        vistaModifica->show();

    } else if(dynamic_cast<Umano*>(itemA)) {
        Umano* u = static_cast<Umano*>(itemA);

        vistaModifica->getSceltaTipo()->setCurrentIndex(3);
        vistaModifica->groupTipo();
        u->GetScu() ? vistaModifica->getPowerUp1()->setChecked(true), vistaModifica->checkUno() : vistaModifica->getPowerUp1()->setChecked(false);
        u->GetSpada() ? vistaModifica->getPowerUp2()->setChecked(true), vistaModifica->checkDue() : vistaModifica->getPowerUp2()->setChecked(false);
        u->GetAnello() ? vistaModifica->getPowerUp3()->setChecked(true), vistaModifica->checkTre() : vistaModifica->getPowerUp3()->setChecked(false);
        u->GetLibro() ? vistaModifica->getPowerUp4()->setChecked(true), vistaModifica->checkQuattro() : vistaModifica->getPowerUp4()->setChecked(false);

        std::string ingegno = (std::to_string(u->GetIngegno()));
        vistaModifica->getValoreSpeciale()->setText(QString::fromStdString(ingegno));
        vistaModifica->setModal(true);
        vistaModifica->setWindowTitle("Modifica Avatar");
        vistaModifica->setWindowIcon(QIcon(":/Risorse/Immagini Avatar/Umano Maschio.png"));
        vistaModifica->show();

    } else if(dynamic_cast<Alieno*>(itemA)) {
        Alieno* a = static_cast<Alieno*>(itemA);

        vistaModifica->getSceltaTipo()->setCurrentIndex(4);
        vistaModifica->groupTipo();
        a->GetBar() ? vistaModifica->getPowerUp5()->setChecked(true), vistaModifica->checkCinque() : vistaModifica->getPowerUp5()->setChecked(false);
        a->GetLaser() ? vistaModifica->getPowerUp6()->setChecked(true), vistaModifica->checkSei() : vistaModifica->getPowerUp6()->setChecked(false);
        a->GetAmuleto() ? vistaModifica->getPowerUp7()->setChecked(true), vistaModifica->checkSette() : vistaModifica->getPowerUp7()->setChecked(false);
        a->GetChip() ? vistaModifica->getPowerUp8()->setChecked(true), vistaModifica->checkOtto() : vistaModifica->getPowerUp8()->setChecked(false);

        std::string ufo = (std::to_string(a->GetUfo()));
        vistaModifica->getValoreSpeciale()->setText(QString::fromStdString(ufo));
        vistaModifica->setModal(true);
        vistaModifica->setWindowTitle("Modifica Avatar");
        vistaModifica->setWindowIcon(QIcon(":/Risorse/Immagini Avatar/Alieno.png"));

        vistaModifica->show();

    } else if(dynamic_cast<Mostro*>(itemA)) {
        Mostro* m = static_cast<Mostro*>(itemA);

        vistaModifica->getSceltaTipo()->setCurrentIndex(5);
        vistaModifica->groupTipo();
        m->GetBar() ? vistaModifica->getPowerUp5()->setChecked(true), vistaModifica->checkCinque() : vistaModifica->getPowerUp5()->setChecked(false);
        m->GetLaser() ? vistaModifica->getPowerUp6()->setChecked(true), vistaModifica->checkSei() : vistaModifica->getPowerUp6()->setChecked(false);
        m->GetAmuleto() ? vistaModifica->getPowerUp7()->setChecked(true), vistaModifica->checkSette() : vistaModifica->getPowerUp7()->setChecked(false);
        m->GetChip() ? vistaModifica->getPowerUp8()->setChecked(true), vistaModifica->checkOtto() : vistaModifica->getPowerUp8()->setChecked(false);

        std::string porta = (std::to_string(m->GetPorta()));
        vistaModifica->getValoreSpeciale()->setText(QString::fromStdString(porta));
        vistaModifica->setModal(true);
        vistaModifica->setWindowTitle("Modifica Avatar");
        vistaModifica->setWindowIcon(QIcon(":/Risorse/Immagini Avatar/Mostro Maschio.png"));
        vistaModifica->show();
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

    ElencoAvatar* aux = nullptr;
    Avatar* itemA = nullptr;

    aux = vistaLista->getElenco()->itemAttuale();
    itemA = aux->getItem();

    vistaScontro->getNomeAvatarSx()->setText(QString::fromStdString(itemA->GetNome()));
    std::string media = (std::to_string(itemA->getMedia()));
    vistaScontro->getMediaSx()->setText(QString::fromStdString(media));
    std::string forza = (std::to_string(itemA->getForza()));
    std::string magia = (std::to_string(itemA->getMagia()));
    std::string difesa = (std::to_string(itemA->getDifesa()));
    std::string scienza = (std::to_string(itemA->getScienza()));
    std::string lvl = (std::to_string(itemA->GetLiv()));
    std::string exp = (std::to_string(itemA->GetExp()));
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
        e->GetScu() ? vistaScontro->getPowerup1selezionatoSx()->setText("Scudo"), vistaScontro->getPowerup1selezionatoSx()->show(): (vistaScontro->getPowerup1selezionatoSx()->setText(""));
        e->GetSpada() ? vistaScontro->getPowerup2selezionatoSx()->setText("Spada"), vistaScontro->getPowerup2selezionatoSx()->show() : (vistaScontro->getPowerup2selezionatoSx()->setText(""));
        e->GetAnello() ? vistaScontro->getPowerup3selezionatoSx()->setText("Anello"), vistaScontro->getPowerup3selezionatoSx()->show() : (vistaScontro->getPowerup3selezionatoSx()->setText(""));
        e->GetLibro() ? vistaScontro->getPowerup4selezionatoSx()->setText("Libro"), vistaScontro->getPowerup4selezionatoSx()->show() : (vistaScontro->getPowerup4selezionatoSx()->setText(""));
        std::string valoreSpeciale = (std::to_string(e->GetTrasparentia()));
        vistaLista->hide();
        vistaScontro->show();

    } else if(dynamic_cast<Nano*>(itemA)) {
        Nano* n = static_cast<Nano*>(itemA);
        n->GetScu() ? vistaScontro->getPowerup1selezionatoSx()->setText("Scudo"), vistaScontro->getPowerup1selezionatoSx()->show(): (vistaScontro->getPowerup1selezionatoSx()->setText(""));
        n->GetSpada() ? vistaScontro->getPowerup2selezionatoSx()->setText("Spada"), vistaScontro->getPowerup2selezionatoSx()->show() : (vistaScontro->getPowerup2selezionatoSx()->setText(""));
        n->GetAnello() ? vistaScontro->getPowerup3selezionatoSx()->setText("Anello"), vistaScontro->getPowerup3selezionatoSx()->show() : (vistaScontro->getPowerup3selezionatoSx()->setText(""));
        n->GetLibro() ? vistaScontro->getPowerup4selezionatoSx()->setText("Libro"), vistaScontro->getPowerup4selezionatoSx()->show() : (vistaScontro->getPowerup4selezionatoSx()->setText(""));
        std::string valoreSpeciale = (std::to_string(n->GetCorteccia()));
        vistaLista->hide();
        vistaScontro->show();

    } else if(dynamic_cast<Umano*>(itemA)) {
        Umano* u = static_cast<Umano*>(itemA);
        u->GetScu() ? vistaScontro->getPowerup1selezionatoSx()->setText("Scudo"), vistaScontro->getPowerup1selezionatoSx()->show() : (vistaScontro->getPowerup1selezionatoSx()->setText(""));
        u->GetSpada() ? vistaScontro->getPowerup2selezionatoSx()->setText("Spada"), vistaScontro->getPowerup2selezionatoSx()->show() : (vistaScontro->getPowerup2selezionatoSx()->setText(""));
        u->GetAnello() ? vistaScontro->getPowerup3selezionatoSx()->setText("Anello"), vistaScontro->getPowerup3selezionatoSx()->show() : (vistaScontro->getPowerup3selezionatoSx()->setText(""));
        u->GetLibro() ? vistaScontro->getPowerup4selezionatoSx()->setText("Libro"), vistaScontro->getPowerup4selezionatoSx()->show() : (vistaScontro->getPowerup4selezionatoSx()->setText(""));
        std::string valoreSpeciale = (std::to_string(u->GetIngegno()));
        vistaLista->hide();
        vistaScontro->show();

    } else if(dynamic_cast<Alieno*>(itemA)) {
        Alieno* a = static_cast<Alieno*>(itemA);
        a->GetBar() ? vistaScontro->getPowerup1selezionatoSx()->setText("Barriera"), vistaScontro->getPowerup1selezionatoSx()->show() : (vistaScontro->getPowerup1selezionatoSx()->setText(""));
        a->GetLaser() ? vistaScontro->getPowerup2selezionatoSx()->setText("Laser"), vistaScontro->getPowerup2selezionatoSx()->show() : (vistaScontro->getPowerup2selezionatoSx()->setText(""));
        a->GetAmuleto() ? vistaScontro->getPowerup3selezionatoSx()->setText("Amuleto"), vistaScontro->getPowerup3selezionatoSx()->show() : (vistaScontro->getPowerup3selezionatoSx()->setText(""));
        a->GetChip() ? vistaScontro->getPowerup4selezionatoSx()->setText("Chip"), vistaScontro->getPowerup4selezionatoSx()->show() : (vistaScontro->getPowerup4selezionatoSx()->setText(""));
        std::string valoreSpeciale = (std::to_string(a->GetUfo()));
        vistaLista->hide();
        vistaScontro->show();

    } else if(dynamic_cast<Mostro*>(itemA)) {
        Mostro* m = static_cast<Mostro*>(itemA);
        m->GetBar() ? vistaScontro->getPowerup1selezionatoSx()->setText("Barriera"), vistaScontro->getPowerup1selezionatoSx()->show() : (vistaScontro->getPowerup1selezionatoSx()->setText(""));
        m->GetLaser() ? vistaScontro->getPowerup2selezionatoSx()->setText("Laser"), vistaScontro->getPowerup2selezionatoSx()->show() : (vistaScontro->getPowerup2selezionatoSx()->setText(""));
        m->GetAmuleto() ? vistaScontro->getPowerup3selezionatoSx()->setText("Amuleto"), vistaScontro->getPowerup3selezionatoSx()->show() : (vistaScontro->getPowerup3selezionatoSx()->setText(""));
        m->GetChip() ? vistaScontro->getPowerup4selezionatoSx()->setText("Chip"), vistaScontro->getPowerup4selezionatoSx()->show() : (vistaScontro->getPowerup4selezionatoSx()->setText(""));
        std::string valoreSpeciale = (std::to_string(m->GetPorta()));
        vistaLista->hide();
        vistaScontro->show();
    }

    //Avversario random
    int max = modello->getLista()->counter();
    int numeroCasuale = rand()%(max);
    ElencoAvatar* itemCasuale = nullptr;
    Avatar* itemB= nullptr;
    itemCasuale = vistaLista->getElenco()->itemCasuale(numeroCasuale);
    itemB = itemCasuale->getItem();
    //agiungere controllo diversità player1 e avversario qui

    vistaScontro->getNomeAvatarDx()->setText(QString::fromStdString(itemB->GetNome()));
    std::string media2 = (std::to_string(itemB->getMedia()));
    vistaScontro->getMediaDx()->setText(QString::fromStdString(media2));
    std::string forza2 = (std::to_string(itemB->getForza()));
    std::string magia2 = (std::to_string(itemB->getMagia()));
    std::string difesa2 = (std::to_string(itemB->getDifesa()));
    std::string scienza2 = (std::to_string(itemB->getScienza()));
    std::string lvl2 = (std::to_string(itemB->GetLiv()));
    std::string exp2 = (std::to_string(itemB->GetExp()));
    std::string terrenoPreferito2 = (itemB->getTerreno());

    //foto
    QString foto2 = QString::fromStdString(itemB->getPercorsoImmagine());
    QPixmap fotoPix2(foto2);
    vistaScontro->getFotoAvatar2()->setPixmap(fotoPix2);
    vistaScontro->getFotoAvatar2()->setPixmap(fotoPix2.scaled(200,200, Qt::AspectRatioMode::KeepAspectRatio));

    if(dynamic_cast<Elfo*>(itemB)) {
        Elfo* e = static_cast<Elfo*>(itemB);
        e->GetScu() ? vistaScontro->getPowerup1selezionatoDx()->setText("Scudo"), vistaScontro->getPowerup1selezionatoDx()->show(): (vistaScontro->getPowerup1selezionatoDx()->setText(""));
        e->GetSpada() ? vistaScontro->getPowerup2selezionatoDx()->setText("Spada"), vistaScontro->getPowerup2selezionatoDx()->show() : (vistaScontro->getPowerup2selezionatoDx()->setText(""));
        e->GetAnello() ? vistaScontro->getPowerup3selezionatoDx()->setText("Anello"), vistaScontro->getPowerup3selezionatoDx()->show() : (vistaScontro->getPowerup3selezionatoDx()->setText(""));
        e->GetLibro() ? vistaScontro->getPowerup4selezionatoDx()->setText("Libro"), vistaScontro->getPowerup4selezionatoDx()->show() : (vistaScontro->getPowerup4selezionatoDx()->setText(""));
        std::string valoreSpeciale2 = (std::to_string(e->GetTrasparentia()));

    } else if(dynamic_cast<Nano*>(itemB)) {
        Nano* n = static_cast<Nano*>(itemB);
        n->GetScu() ? vistaScontro->getPowerup1selezionatoDx()->setText("Scudo"), vistaScontro->getPowerup1selezionatoDx()->show(): (vistaScontro->getPowerup1selezionatoDx()->setText(""));
        n->GetSpada() ? vistaScontro->getPowerup2selezionatoDx()->setText("Spada"), vistaScontro->getPowerup2selezionatoDx()->show() : (vistaScontro->getPowerup2selezionatoDx()->setText(""));
        n->GetAnello() ? vistaScontro->getPowerup3selezionatoDx()->setText("Anello"), vistaScontro->getPowerup3selezionatoDx()->show() : (vistaScontro->getPowerup3selezionatoDx()->setText(""));
        n->GetLibro() ? vistaScontro->getPowerup4selezionatoDx()->setText("Libro"), vistaScontro->getPowerup4selezionatoDx()->show() : (vistaScontro->getPowerup4selezionatoDx()->setText(""));
        std::string valoreSpeciale2 = (std::to_string(n->GetCorteccia()));

    } else if(dynamic_cast<Umano*>(itemB)) {
        Umano* u = static_cast<Umano*>(itemB);
        u->GetScu() ? vistaScontro->getPowerup1selezionatoDx()->setText("Scudo"), vistaScontro->getPowerup1selezionatoDx()->show() : (vistaScontro->getPowerup1selezionatoDx()->setText(""));
        u->GetSpada() ? vistaScontro->getPowerup2selezionatoDx()->setText("Spada"), vistaScontro->getPowerup2selezionatoDx()->show() : (vistaScontro->getPowerup2selezionatoDx()->setText(""));
        u->GetAnello() ? vistaScontro->getPowerup3selezionatoDx()->setText("Anello"), vistaScontro->getPowerup3selezionatoDx()->show() : (vistaScontro->getPowerup3selezionatoDx()->setText(""));
        u->GetLibro() ? vistaScontro->getPowerup4selezionatoDx()->setText("Libro"), vistaScontro->getPowerup4selezionatoDx()->show() : (vistaScontro->getPowerup4selezionatoDx()->setText(""));
        std::string valoreSpeciale2 = (std::to_string(u->GetIngegno()));

    } else if(dynamic_cast<Alieno*>(itemB)) {
        Alieno* a = static_cast<Alieno*>(itemB);
        a->GetBar() ? vistaScontro->getPowerup1selezionatoDx()->setText("Barriera"), vistaScontro->getPowerup1selezionatoDx()->show() : (vistaScontro->getPowerup1selezionatoDx()->setText(""));
        a->GetLaser() ? vistaScontro->getPowerup2selezionatoDx()->setText("Laser"), vistaScontro->getPowerup2selezionatoDx()->show() : (vistaScontro->getPowerup2selezionatoDx()->setText(""));
        a->GetAmuleto() ? vistaScontro->getPowerup3selezionatoDx()->setText("Amuleto"), vistaScontro->getPowerup3selezionatoDx()->show() : (vistaScontro->getPowerup3selezionatoDx()->setText(""));
        a->GetChip() ? vistaScontro->getPowerup4selezionatoDx()->setText("Chip"), vistaScontro->getPowerup4selezionatoDx()->show() : (vistaScontro->getPowerup4selezionatoDx()->setText(""));
        std::string valoreSpeciale2 = (std::to_string(a->GetUfo()));

    } else if(dynamic_cast<Mostro*>(itemB)) {
        Mostro* m = static_cast<Mostro*>(itemB);
        m->GetBar() ? vistaScontro->getPowerup1selezionatoDx()->setText("Barriera"), vistaScontro->getPowerup1selezionatoDx()->show() : (vistaScontro->getPowerup1selezionatoDx()->setText(""));
        m->GetLaser() ? vistaScontro->getPowerup2selezionatoDx()->setText("Laser"), vistaScontro->getPowerup2selezionatoDx()->show() : (vistaScontro->getPowerup2selezionatoDx()->setText(""));
        m->GetAmuleto() ? vistaScontro->getPowerup3selezionatoDx()->setText("Amuleto"), vistaScontro->getPowerup3selezionatoDx()->show() : (vistaScontro->getPowerup3selezionatoDx()->setText(""));
        m->GetChip() ? vistaScontro->getPowerup4selezionatoDx()->setText("Chip"), vistaScontro->getPowerup4selezionatoDx()->show() : (vistaScontro->getPowerup4selezionatoDx()->setText(""));
        std::string valoreSpeciale2 = (std::to_string(m->GetPorta()));
    }

}

void Controller::rimuoviAvatar()
{
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

void Controller::svuotaElenco()
{
    modello->rimuoviTutto();
    modello->salvare();
    carica();
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
            if(*item2 == *(*val)) {
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
            if(*item2 == *(*val)) {
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
            if(*item2 == *(*val)) {
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

    itemA->SetNome(vistaModifica->getInserisciNome()->text().toStdString());
    itemA->setDescrizione(vistaModifica->getBoxDescrizione()->toPlainText().toStdString());
    itemA->SetLvl(vistaModifica->getLvl()->text().toUInt());
    itemA->SetExp(vistaModifica->getExp()->text().toUInt());
    itemA->setForza(vistaModifica->getValoreForza()->text().toUInt());
    itemA->setMagia(vistaModifica->getValoreMagia()->text().toUInt());
    itemA->setDifesa(vistaModifica->getValoreDifesa()->text().toUInt());
    itemA->setScienza(vistaModifica->getValoreScienza()->text().toUInt());
    itemA->setMedia(vistaModifica->getValoreMedia()->text().toDouble());
    itemA->setTerreno(vistaModifica->getTerrenoPreferito()->text().toStdString());
    itemA->SetSesso(vistaModifica->getSessoM()->isChecked());
    itemA->setPercorsoImmagine(vistaModifica->getPercorsoImmagine().toStdString());

    if(dynamic_cast<Elfo*>(itemA)) {
        Elfo* e = static_cast<Elfo*>(itemA);

        e->SetScudo(vistaModifica->getPowerUp1()->isChecked());
        e->SetSpada(vistaModifica->getPowerUp2()->isChecked());
        e->SetAnello(vistaModifica->getPowerUp3()->isChecked());
        e->SetLibro(vistaModifica->getPowerUp4()->isChecked());
        e->setTrasparentia(vistaModifica->getValoreSpeciale()->text().toUInt());
        modello->salvare();
        carica();
        vistaModifica->close();
        QMessageBox::about(this, "Modifica effettuta", "L'Avatar è stato correttamente modificato :)");

    } else if(dynamic_cast<Nano*>(itemA)) {
        Nano* n = static_cast<Nano*>(itemA);

        n->SetScudo(vistaModifica->getPowerUp1()->isChecked());
        n->SetSpada(vistaModifica->getPowerUp2()->isChecked());
        n->SetAnello(vistaModifica->getPowerUp3()->isChecked());
        n->SetLibro(vistaModifica->getPowerUp4()->isChecked());
        n->setCorteccia(vistaModifica->getValoreSpeciale()->text().toUInt());
        modello->salvare();
        carica();
        vistaModifica->close();
        QMessageBox::about(this, "Modifica effettuta", "L'Avatar è stato correttamente modificato :)");

    } else if(dynamic_cast<Umano*>(itemA)) {
        Umano* u = static_cast<Umano*>(itemA);

        u->SetScudo(vistaModifica->getPowerUp1()->isChecked());
        u->SetSpada(vistaModifica->getPowerUp2()->isChecked());
        u->SetAnello(vistaModifica->getPowerUp3()->isChecked());
        u->SetLibro(vistaModifica->getPowerUp4()->isChecked());
        u->setIngegno(vistaModifica->getValoreSpeciale()->text().toUInt());
        modello->salvare();
        carica();
        vistaModifica->close();
        QMessageBox::about(this, "Modifica effettuta", "L'Avatar è stato correttamente modificato :)");

    } else if(dynamic_cast<Alieno*>(itemA)) {
        Alieno* a = static_cast<Alieno*>(itemA);

        a->SetBarriera(vistaModifica->getPowerUp5()->isChecked());
        a->SetLaser(vistaModifica->getPowerUp6()->isChecked());
        a->SetAmuleto(vistaModifica->getPowerUp7()->isChecked());
        a->SetChip(vistaModifica->getPowerUp8()->isChecked());
        a->setUfo(vistaModifica->getValoreSpeciale()->text().toUInt());
        modello->salvare();
        carica();
        vistaModifica->close();
        QMessageBox::about(this, "Modifica effettuta", "L'Avatar è stato correttamente modificato :)");

    } else if(dynamic_cast<Mostro*>(itemA)) {
        Mostro* m = static_cast<Mostro*>(itemA);

        m->SetBarriera(vistaModifica->getPowerUp5()->isChecked());
        m->SetLaser(vistaModifica->getPowerUp6()->isChecked());
        m->SetAmuleto(vistaModifica->getPowerUp7()->isChecked());
        m->SetChip(vistaModifica->getPowerUp8()->isChecked());
        m->setPorta(vistaModifica->getValoreSpeciale()->text().toUInt());
        modello->salvare();
        carica();
        vistaModifica->close();
        QMessageBox::about(this, "Modifica effettuta", "L'Avatar è stato correttamente modificato :)");
    }
}

void Controller::ordinaNome()
{

}

void Controller::setAvatarGameStyle()
{
    setMinimumSize(QSize(1200,600));
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QFile file(":/Risorse/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    //setStyleSheet(styleSheet());

    setWindowIcon(QIcon(":/Risorse/Immagini Avatar/Umano Maschio.png"));
}

/*void Controller::ordinaMedia()
{
    std::string media = vistaCrea->getValoreMedia()->text().toStdString();
    Avatar* item = new Elfo(media);
    Container<Avatar*>::iteratore inizio = modello->begin();
    Container<Avatar*>::iteratore fine = modello->end();

    if() {

    }
}*/

