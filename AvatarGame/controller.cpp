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
    connect(vistaLista->getBottoneGioca(),SIGNAL(clicked()),this,SLOT(mostraScontro()));
    connect(vistaLista->getBottoneModifica(),SIGNAL(clicked()),this,SLOT(modificaAvatar()));
    connect(vistaLista->getBottoneInfoLista(),SIGNAL(clicked()),this,SLOT(infoPopLista()));
    connect(vistaLista->getTipoElfo(),SIGNAL(clicked()),this,SLOT(carica()));
    connect(vistaLista->getTipoNano(),SIGNAL(clicked()),this,SLOT(carica()));
    connect(vistaLista->getTipoUmano(),SIGNAL(clicked()),this,SLOT(carica()));
    connect(vistaLista->getTipoAlieno(),SIGNAL(clicked()),this,SLOT(carica()));
    connect(vistaLista->getTipoMostro(),SIGNAL(clicked()),this,SLOT(carica()));
    connect(vistaLista->getBottoneRimuovi(),SIGNAL(clicked()),this,SLOT(rimuoviAvatar()));
    connect(vistaLista->getBottoneRimuoviTutto(),SIGNAL(clicked()),this,SLOT(svuotaElenco()));

    //CONNECT SCONTRO
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

}

void Controller::mostraScontro() {
    vistaScontro->show();
    vistaModifica->hide();
    vistaLista->hide();
    vistaHome->hide();
    vistaCrea->hide();
}

void Controller::infoPopHome()
{
    QMessageBox::information(this,"Cosa posso fare in questa finestra?","Quì puoi fare questo.\nChiudi questa finestra per scegliere un avatar");
}

void Controller::infoPopLista()
{
    QMessageBox::information(this,"Cosa posso fare in questa finestra?","Quì puoi fare questo.\nChiudi questa finestra per scegliere un avatar");
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

    /*
    if ((vistaCrea->getInserisciNome()->text().toStdString())==.......){
        QMessageBox::warning(this, "Errore", "Il nome è uguale ad un altro");
    }
     */

    if(nome == "" || (!(vistaCrea->getSessoM()->isChecked()) && !(vistaCrea->getSessoF()->isChecked()))) {
        QMessageBox::warning(this, "Compila tutti i campi", "per creare un nuovo Avatar");
    } else {
        int index = vistaCrea->getSceltaTipo()->currentIndex();

        if(index == 0 || index == 1 || index == 2) {
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

            if(index == 0) {
                unsigned int trasparentia = vistaCrea->getValoreSpeciale()->text().toUInt();
                Elfo* personaggio = new Elfo(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, scudo, spada, anello, libro, trasparentia);
                modello->getLista()->inserisci(personaggio);
                modello->salvare();
                carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            } else if(index == 1) {
                unsigned int corteccia = vistaCrea->getValoreSpeciale()->text().toUInt();
                Nano* personaggio = new Nano(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, scudo, spada, anello, libro, corteccia);
                modello->getLista()->inserisci(personaggio);
                modello->salvare();
                carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            } else if(index == 2) {
                unsigned int ingegnoScientifico = vistaCrea->getValoreSpeciale()->text().toUInt();
                Umano* personaggio = new Umano(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, scudo, spada, anello, libro, ingegnoScientifico);
                modello->getLista()->inserisci(personaggio);
                modello->salvare();
                carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            }

        } else if (index == 3 || index == 4) {
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

            if(index == 3) {
                unsigned int ufo = vistaCrea->getValoreSpeciale()->text().toUInt();
                Alieno* personaggio = new Alieno(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, barriera, laser, amuleto, chip, ufo);
                modello->getLista()->inserisci(personaggio);
                modello->salvare();
                carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            } else if(index == 4) {
                unsigned int portaDemoniaca = vistaCrea->getValoreSpeciale()->text().toUInt();
                Mostro* personaggio = new Mostro(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, barriera, laser, amuleto, chip, portaDemoniaca);
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

    if(dynamic_cast<Elfo*>(itemA)) {
        Elfo* e = static_cast<Elfo*>(itemA);

        vistaModifica->getSceltaTipo()->setCurrentIndex(0);
        e->GetScu() ? vistaModifica->getPowerUp1()->setChecked(true) : vistaModifica->getPowerUp1()->setChecked(false);
        e->GetSpada() ? vistaModifica->getPowerUp2()->setChecked(true) : vistaModifica->getPowerUp2()->setChecked(false);
        e->GetAnello() ? vistaModifica->getPowerUp3()->setChecked(true) : vistaModifica->getPowerUp3()->setChecked(false);
        e->GetLibro() ? vistaModifica->getPowerUp4()->setChecked(true) : vistaModifica->getPowerUp4()->setChecked(false);
        std::string trasparentia = (std::to_string(e->GetTrasparentia()));
        vistaModifica->getValoreSpeciale()->setText(QString::fromStdString(trasparentia));
        //vistaModifica->setModal(true);
        vistaModifica->show();

    } else if(dynamic_cast<Nano*>(itemA)) {
        Nano* n = static_cast<Nano*>(itemA);

        vistaModifica->getSceltaTipo()->setCurrentIndex(1);
        n->GetScu() ? vistaModifica->getPowerUp1()->setChecked(true) : vistaModifica->getPowerUp1()->setChecked(false);
        n->GetSpada() ? vistaModifica->getPowerUp2()->setChecked(true) : vistaModifica->getPowerUp2()->setChecked(false);
        n->GetAnello() ? vistaModifica->getPowerUp3()->setChecked(true) : vistaModifica->getPowerUp3()->setChecked(false);
        n->GetLibro() ? vistaModifica->getPowerUp4()->setChecked(true) : vistaModifica->getPowerUp4()->setChecked(false);
        std::string corteccia = (std::to_string(n->GetCorteccia()));
        vistaModifica->getValoreSpeciale()->setText(QString::fromStdString(corteccia));
        vistaModifica->show();
    } else if(dynamic_cast<Umano*>(itemA)) {
        Umano* u = static_cast<Umano*>(itemA);

        vistaModifica->getSceltaTipo()->setCurrentIndex(2);
        u->GetScu() ? vistaModifica->getPowerUp1()->setChecked(true) : vistaModifica->getPowerUp1()->setChecked(false);
        u->GetSpada() ? vistaModifica->getPowerUp2()->setChecked(true) : vistaModifica->getPowerUp2()->setChecked(false);
        u->GetAnello() ? vistaModifica->getPowerUp3()->setChecked(true) : vistaModifica->getPowerUp3()->setChecked(false);
        u->GetLibro() ? vistaModifica->getPowerUp4()->setChecked(true) : vistaModifica->getPowerUp4()->setChecked(false);
        std::string ingegno = (std::to_string(u->GetIngegno()));
        vistaModifica->getValoreSpeciale()->setText(QString::fromStdString(ingegno));
        vistaModifica->show();
    } else if(dynamic_cast<Alieno*>(itemA)) {
        Alieno* a = static_cast<Alieno*>(itemA);

        vistaModifica->getSceltaTipo()->setCurrentIndex(3);
        a->GetBar() ? vistaModifica->getPowerUp1()->setChecked(true) : vistaModifica->getPowerUp1()->setChecked(false);
        a->GetLaser() ? vistaModifica->getPowerUp2()->setChecked(true) : vistaModifica->getPowerUp2()->setChecked(false);
        a->GetAmuleto() ? vistaModifica->getPowerUp3()->setChecked(true) : vistaModifica->getPowerUp3()->setChecked(false);
        a->GetChip() ? vistaModifica->getPowerUp4()->setChecked(true) : vistaModifica->getPowerUp4()->setChecked(false);
        std::string ufo = (std::to_string(a->GetUfo()));
        vistaModifica->getValoreSpeciale()->setText(QString::fromStdString(ufo));
        vistaModifica->show();
    } else if(dynamic_cast<Mostro*>(itemA)) {
        Mostro* m = static_cast<Mostro*>(itemA);

        vistaModifica->getSceltaTipo()->setCurrentIndex(4);
        m->GetBar() ? vistaModifica->getPowerUp1()->setChecked(true) : vistaModifica->getPowerUp1()->setChecked(false);
        m->GetLaser() ? vistaModifica->getPowerUp2()->setChecked(true) : vistaModifica->getPowerUp2()->setChecked(false);
        m->GetAmuleto() ? vistaModifica->getPowerUp3()->setChecked(true) : vistaModifica->getPowerUp3()->setChecked(false);
        m->GetChip() ? vistaModifica->getPowerUp4()->setChecked(true) : vistaModifica->getPowerUp4()->setChecked(false);
        std::string porta = (std::to_string(m->GetPorta()));
        vistaModifica->getValoreSpeciale()->setText(QString::fromStdString(porta));
        vistaModifica->show();
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
    //itemA->setForza(vistaModifica->getValoreForza()->text().toUInt());
    itemA->SetLvl(vistaModifica->getLvl()->text().toUInt());
    itemA->SetLvl(vistaModifica->getLvl()->text().toUInt());
    itemA->SetLvl(vistaModifica->getLvl()->text().toUInt());
    itemA->SetLvl(vistaModifica->getLvl()->text().toUInt());

}


