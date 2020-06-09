#include "controller.h"


Controller::Controller(Modello* m, QWidget *parent) :
    QWidget(parent),
    layoutPrincipale(new QVBoxLayout(this)),
    menuGenerale(new Menu(this)),
    vistaHome(new AvatarHome(this)),
    vistaCrea(new CreaAvatar(this)),
    vistaLista(new ListaAvatar(this)),
    vistaModifica(new ModificaAvatar),
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
    connect(vistaHome->getBottoneInfo(),SIGNAL(clicked()),this,SLOT(infoPopHome()));

    //CONNECT CREA
    connect(vistaCrea->getBottoneHome(),SIGNAL(clicked()),this,SLOT(mostraHome()));
    connect(vistaCrea->getBottoneCreaDef(), SIGNAL(clicked()),this,SLOT(inserisciAvatar()));

    //CONNECT LISTA
    connect(vistaLista->getBottoneHome(),SIGNAL(clicked()),this,SLOT(mostraHome()));
    connect(vistaLista->getBottoneGioca(),SIGNAL(clicked()),this,SLOT(mostraScontro()));
    connect(vistaLista->getBottoneModifica(),SIGNAL(clicked()),this,SLOT(mostraModifica()));
    connect(vistaLista->getBottoneInfoLista(),SIGNAL(clicked()),this,SLOT(infoPopLista()));

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

void Controller::mostraModifica() {
    QDialog vistaModifica( this );
    vistaModifica.setModal( true );
    vistaModifica.exec();
    /*vistaModifica->show();
    vistaLista->show();
    vistaHome->hide();
    vistaCrea->hide();
    vistaScontro->hide();*/
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
    std::string descrizione = vistaCrea->getInserisciNome()->text().toStdString();
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

    if(nome == "" || (sesso != 0 && sesso != 1)) {
        QMessageBox::warning(this, "Compila tutti i campi", "per creare un nuovo Avatar");
    } else {

        if(vistaCrea->getSceltaTipo()->currentIndex() == 0 || 1 || 2) {
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

            if(vistaCrea->getSceltaTipo()->currentIndex() == 0) {
                unsigned int trasparentia = vistaCrea->getValoreSpeciale()->text().toUInt();
                Elfo* personaggio = new Elfo(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, scudo, spada, anello, libro, trasparentia);
                modello->getLista()->insert(personaggio);
                modello->salva();
                //carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            } else if(vistaCrea->getSceltaTipo()->currentIndex() == 1) {
                unsigned int corteccia = vistaCrea->getValoreSpeciale()->text().toUInt();
                Nano* personaggio = new Nano(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, scudo, spada, anello, libro, corteccia);
                modello->getLista()->insert(personaggio);
                modello->salva();
                //carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            } else if(vistaCrea->getSceltaTipo()->currentIndex() == 2) {
                unsigned int ingegnoScientifico = vistaCrea->getValoreSpeciale()->text().toUInt();
                Umano* personaggio = new Umano(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, scudo, spada, anello, libro, ingegnoScientifico);
                modello->getLista()->insert(personaggio);
                modello->salva();
                //carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            }

        } else if (vistaCrea->getSceltaTipo()->currentIndex() == 3 || 4) {
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

            if(vistaCrea->getSceltaTipo()->currentIndex() == 3) {
                unsigned int ufo = vistaCrea->getValoreSpeciale()->text().toUInt();
                Alieno* personaggio = new Alieno(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, barriera, laser, amuleto, chip, ufo);
                modello->getLista()->insert(personaggio);
                modello->salva();
                //carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            } else if(vistaCrea->getSceltaTipo()->currentIndex() == 4) {
                unsigned int portaDemoniaca = vistaCrea->getValoreSpeciale()->text().toUInt();
                Mostro* personaggio = new Mostro(nome, descrizione, lvl, exp, forza, magia, difesa, scienza, media, terreno, sesso, barriera, laser, amuleto, chip, portaDemoniaca);
                modello->getLista()->insert(personaggio);
                modello->salva();
                //carica();
                QMessageBox::about(this, "Complimenti!", "Hai appena creato un nuovo Avatar");
                vistaCrea->hide();
                vistaLista->show();
            }
        }
    }
}

void Controller::modificaAvatar()
{

}

void Controller::rimuoviAvatar()
{

}

void Controller::ricercaAvatar()
{

}

void Controller::caricaDb()
{
    destinazione = QFileDialog::getOpenFileName(this, "Scegli file", ":Risorse", "File XML(*.xml)");
    //carica();
}

void Controller::carica()
{

}

void Controller::salva()
{

}
