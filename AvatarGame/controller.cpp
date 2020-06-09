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
    connect(vistaCrea->getBottoneCreaDef(),SIGNAL(clicked()),this,SLOT(infoPopCrea()));
    connect(vistaCrea->getBottoneCreaDef(),SIGNAL(clicked()),this,SLOT(mostraLista()));

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

void Controller::infoPopCrea()
{
    QMessageBox::information(this,"Creazione nuovo avatar","Hai creato il tuo avatar.\nPuoi selezionarlo dalla lista");
}

void Controller::inserisciAvatar()
{
    std::string nome = vistaCrea->getInserisciNome()->text().toStdString();
    unsigned int lvl = vistaCrea->getLvl()->text().toUInt();
    unsigned int forza = vistaCrea->getValoreForza()->text().toUInt();
    unsigned int magia = vistaCrea->getValoreMagia()->text().toUInt();
    unsigned int difesa = vistaCrea->getValoreDifesa()->text().toUInt();
    unsigned int scienza = vistaCrea->getValoreScienza()->text().toUInt();
    bool sesso;
    int check = vistaCrea->getSessoM()->isChecked();
    if(check == 1) sesso = true;
    else sesso = false;
    double media = vistaCrea->getValoreMedia()->text().toUInt();

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
    }
}
