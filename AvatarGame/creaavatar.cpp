#include "creaavatar.h"


CreaAvatar::CreaAvatar(QWidget *parent) :
    scrittaNome(new QLabel("Nome", this)),
    maxPowerUps(new QLabel("Massimo 2 Power Up:", this)),
    lvl(new QLabel("LVL", this)),
    valoreForza(new QLabel(this)), //qui il valore cambia in base al personaggio e al power up quindi vedere come fare
    valoreScienza(new QLabel(this)),
    valoreDifesa(new QLabel(this)),
    valoreMagia(new QLabel(this)),
    valoreMedia(new QLabel(this)),
    inserisciNome(new QLineEdit(this)),
    bottoneHome(new QPushButton("Home", this)),
    bottoneCreaDef(new QPushButton("Crea Avatar", this)),
    scegliImmagine(new QPushButton("Scegli Immagine", this)),
    resetCampi(new QPushButton("Cancella tutto", this)),
    powerUp1(new QCheckBox("Power up 1", this)),
    powerUp2(new QCheckBox("Power up 2", this)),
    powerUp3(new QCheckBox("Power up 3", this)),
    powerUp4(new QCheckBox("Power up 4", this)),
    boxValori(new QGroupBox("Statistiche", this)),
    boxDescrizione(new QTextEdit(this))
{
    QHBoxLayout* layoutCrea = new QHBoxLayout(this);
    QVBoxLayout* layoutSx = new QVBoxLayout();
    QVBoxLayout* layoutDx = new QVBoxLayout();
    QHBoxLayout* layoutPu = new QHBoxLayout();
    QVBoxLayout* layoutValori = new QVBoxLayout();
    boxValori->setLayout(layoutValori);

    layoutCrea->addLayout(layoutSx);
    layoutCrea->addLayout(layoutDx);
    layoutSx->addWidget(bottoneHome);
    layoutSx->addWidget(scrittaNome);
    layoutSx->addWidget(inserisciNome);
    layoutSx->addWidget(maxPowerUps);
    layoutSx->addLayout(layoutPu);
    layoutPu->addWidget(powerUp1);
    layoutPu->addWidget(powerUp2);
    layoutPu->addWidget(powerUp3);
    layoutPu->addWidget(powerUp4);
    layoutSx->addWidget(boxDescrizione);
    layoutSx->addWidget(bottoneCreaDef);
    layoutDx->addWidget(scegliImmagine);
    layoutDx->addLayout(layoutValori);
    layoutDx->addWidget(boxValori);
    layoutValori->addWidget(valoreForza);
    layoutValori->addWidget(valoreScienza);
    layoutValori->addWidget(valoreMagia);
    layoutValori->addWidget(valoreDifesa);
    layoutValori->addWidget(valoreMedia);
    layoutValori->addWidget(lvl);
    layoutDx->addWidget(resetCampi);

    powerUp1->setEnabled(true);
    powerUp2->setEnabled(true);
    powerUp3->setEnabled(true);
    powerUp4->setEnabled(true);
    boxDescrizione->setMaximumSize(300,200);

    connect(powerUp1,SIGNAL(clicked()),this,SLOT(checkUnoDue()));
    connect(powerUp1,SIGNAL(clicked()),this,SLOT(checkUnoTre()));
    connect(powerUp1,SIGNAL(clicked()),this,SLOT(checkUnoQuattro()));
    connect(powerUp2,SIGNAL(clicked()),this,SLOT(checkUnoDue()));
    connect(powerUp2,SIGNAL(clicked()),this,SLOT(checkDueTre()));
    connect(powerUp2,SIGNAL(clicked()),this,SLOT(checkDueQuattro()));
    connect(powerUp3,SIGNAL(clicked()),this,SLOT(checkUnoTre()));
    connect(powerUp3,SIGNAL(clicked()),this,SLOT(checkDueTre()));
    connect(powerUp3,SIGNAL(clicked()),this,SLOT(checkTreQuattro()));
    connect(powerUp4,SIGNAL(clicked()),this,SLOT(checkUnoQuattro()));
    connect(powerUp4,SIGNAL(clicked()),this,SLOT(checkDueQuattro()));
    connect(powerUp4,SIGNAL(clicked()),this,SLOT(checkTreQuattro()));
}

QLabel *CreaAvatar::getScrittaNome() const
{
    return scrittaNome;
}

QLabel *CreaAvatar::getMaxPowerUps() const
{
    return maxPowerUps;
}

QLabel *CreaAvatar::getLvl() const
{
    return lvl;
}

QLabel *CreaAvatar::getValoreForza() const
{
    return valoreForza;
}

QLabel *CreaAvatar::getValoreScienza() const
{
    return valoreScienza;
}

QLabel *CreaAvatar::getValoreDifesa() const
{
    return valoreDifesa;
}

QLabel *CreaAvatar::getValoreMagia() const
{
    return valoreMagia;
}

QLabel *CreaAvatar::getValoreMedia() const
{
    return valoreMedia;
}

QLineEdit *CreaAvatar::getInserisciNome() const
{
    return inserisciNome;
}

QPushButton *CreaAvatar::getBottoneHome() const
{
    return bottoneHome;
}

QPushButton *CreaAvatar::getBottoneCreaDef() const
{
    return bottoneCreaDef;
}

QPushButton *CreaAvatar::getScegliImmagine() const
{
    return scegliImmagine;
}

QPushButton *CreaAvatar::getResetCampi() const
{
    return resetCampi;
}

QCheckBox *CreaAvatar::getPowerUp1() const
{
    return powerUp1;
}

QCheckBox *CreaAvatar::getPowerUp2() const
{
    return powerUp2;
}

QCheckBox *CreaAvatar::getPowerUp3() const
{
    return powerUp3;
}

QCheckBox *CreaAvatar::getPowerUp4() const
{
    return powerUp4;
}

QGroupBox *CreaAvatar::getBoxValori() const
{
    return boxValori;
}

QTextEdit *CreaAvatar::getBoxDescrizione() const
{
    return boxDescrizione;
}

void CreaAvatar::checkUnoDue() const {
    if(powerUp1->isChecked()) {
        powerUp3->setEnabled(false);
        powerUp4->setEnabled(false);
        powerUp2->setEnabled(false);
    }
}

/*void CreaAvatar::checkUnoDue() const
{
    (powerUp1->isChecked() && powerUp2->isChecked()) ? (powerUp3->setEnabled(false), powerUp4->setEnabled(false)) : (powerUp3->setEnabled(true), powerUp4->setEnabled(true));
}*/

void CreaAvatar::checkUnoTre() const
{
    (powerUp1->isChecked() && powerUp3->isChecked()) ? (powerUp2->setEnabled(false), powerUp4->setEnabled(false)) : (powerUp2->setEnabled(true), powerUp4->setEnabled(true));
}

void CreaAvatar::checkUnoQuattro() const
{
    (powerUp1->isChecked() && powerUp4->isChecked()) ? (powerUp2->setEnabled(false), powerUp2->setEnabled(false)) : (powerUp2->setEnabled(true), powerUp3->setEnabled(true));
}

void CreaAvatar::checkDueTre() const
{
    (powerUp2->isChecked() && powerUp3->isChecked()) ? (powerUp1->setEnabled(false), powerUp4->setEnabled(false)) : (powerUp1->setEnabled(true), powerUp4->setEnabled(true));
}

void CreaAvatar::checkDueQuattro() const
{
    (powerUp2->isChecked() && powerUp4->isChecked()) ? (powerUp1->setEnabled(false), powerUp3->setEnabled(false)) : (powerUp1->setEnabled(true), powerUp3->setEnabled(true));
}

void CreaAvatar::checkTreQuattro() const
{
    (powerUp3->isChecked() && powerUp4->isChecked()) ? (powerUp1->setEnabled(false), powerUp2->setEnabled(false)) : (powerUp1->setEnabled(true), powerUp2->setEnabled(true));
}




