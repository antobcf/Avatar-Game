#include "modificaavatar.h"

ModificaAvatar::ModificaAvatar(QWidget *parent) :
    formCrea(new QFormLayout),
    maxPowerUp(new QLabel("Scegli massimo 2 power Up", this)),
    lvl(new QLabel("LVL", this)),
    valoreForza(new QLabel(this)), //qui il valore cambia in base al personaggio e al power up quindi vedere come fare
    valoreScienza(new QLabel(this)),
    valoreDifesa(new QLabel(this)),
    valoreMagia(new QLabel(this)),
    valoreMedia(new QLabel(this)),
    labelSesso(new QLabel("Scegli il sesso del tuo Avatar: ", this)),
    inserisciNome(new QLineEdit(this)),
    bottoneSalvaModifiche(new QPushButton("Salva modifiche", this)),
    resetCampi(new QPushButton("Cancella tutto", this)),
    powerUp1(new QCheckBox("Scudo", this)),
    powerUp2(new QCheckBox("Spada", this)),
    powerUp3(new QCheckBox("Anello", this)),
    powerUp4(new QCheckBox("Libro", this)),
    powerUp5(new QCheckBox("Barriera", this)),
    powerUp6(new QCheckBox("Laser", this)),
    powerUp7(new QCheckBox("Amuleto", this)),
    powerUp8(new QCheckBox("Chip", this)),
    boxValori(new QGroupBox("Statistiche", this)),
    boxDescrizione(new QTextEdit(this)),
    sceltaTipo(new QComboBox(this)),
    modificaImmagine(new QPushButton("Cambia Immagine")),
    sessoM(new QRadioButton("Maschio", this)),
    sessoF(new QRadioButton("Femmina", this))
{
    QHBoxLayout* layoutCrea = new QHBoxLayout(this);
    QVBoxLayout* layoutSx = new QVBoxLayout();
    QVBoxLayout* layoutDx = new QVBoxLayout();
    QHBoxLayout* layoutSesso = new QHBoxLayout();
    QHBoxLayout* layoutPu = new QHBoxLayout();
    QVBoxLayout* layoutValori = new QVBoxLayout();

    boxValori->setLayout(layoutValori);

    layoutCrea->addLayout(layoutSx);
    layoutCrea->addLayout(layoutDx);
    layoutSx->addLayout(formCrea);


    layoutSx->addWidget(sceltaTipo);
    layoutSx->addLayout(layoutSesso);
    layoutSesso->addWidget(labelSesso);
    layoutSesso->addWidget(sessoM);
    layoutSesso->addWidget(sessoF);
    layoutSx->addWidget(inserisciNome);
    layoutSx->addWidget(maxPowerUp);
    layoutSx->addLayout(layoutPu);
    layoutPu->addWidget(powerUp1);
    layoutPu->addWidget(powerUp2);
    layoutPu->addWidget(powerUp3);
    layoutPu->addWidget(powerUp4);
    layoutPu->addWidget(powerUp5);
    layoutPu->addWidget(powerUp6);
    layoutPu->addWidget(powerUp7);
    layoutPu->addWidget(powerUp8);
    layoutSx->addWidget(boxDescrizione);
    layoutSx->addWidget(bottoneSalvaModifiche);
    layoutDx->addWidget(modificaImmagine);
    layoutDx->addLayout(layoutValori);
    layoutDx->addWidget(boxValori);
    layoutValori->addWidget(valoreForza);
    layoutValori->addWidget(valoreScienza);
    layoutValori->addWidget(valoreMagia);
    layoutValori->addWidget(valoreDifesa);
    layoutValori->addWidget(valoreMedia);
    layoutValori->addWidget(lvl);
    layoutDx->addWidget(resetCampi);


    formCrea->addRow("Scegli il tipo di Avatar:", sceltaTipo);
    formCrea->addRow("Nome:", inserisciNome);

    boxDescrizione->setMaximumSize(300,200);
    boxDescrizione->setPlaceholderText("Descrizione storia del tuo Avatar");

    powerUp5->hide();
    powerUp6->hide();
    powerUp7->hide();
    powerUp8->hide();

    sceltaTipo->addItem("Elfo");
    sceltaTipo->addItem("Nano");
    sceltaTipo->addItem("Umano");
    sceltaTipo->addItem("Alieno");
    sceltaTipo->addItem("Mostro");

    connect(powerUp1,SIGNAL(clicked()),this,SLOT(checkUno()));
    connect(powerUp2,SIGNAL(clicked()),this,SLOT(checkDue()));
    connect(powerUp3,SIGNAL(clicked()),this,SLOT(checkTre()));
    connect(powerUp4,SIGNAL(clicked()),this,SLOT(checkQuattro()));
    connect(powerUp5,SIGNAL(clicked()),this,SLOT(checkCinque()));
    connect(powerUp6,SIGNAL(clicked()),this,SLOT(checkSei()));
    connect(powerUp7,SIGNAL(clicked()),this,SLOT(checkSette()));
    connect(powerUp8,SIGNAL(clicked()),this,SLOT(checkOtto()));

    connect(resetCampi,SIGNAL(clicked()),this,SLOT(resetTutto()));

    connect(sceltaTipo,SIGNAL(activated(int)),this,SLOT(groupTipo()));
    connect(modificaImmagine,SIGNAL(clicked()),this,SLOT(cambiaImmagine()));

}

/*void ModificaAvatar::inserisciPercorso(std::string p){
    pathImmagine = QString::fromStdString(p);
    modificaImmagine->setIcon(QIcon(pathImmagine));
}*/

void ModificaAvatar::cambiaImmagine(){
    QString pathImmagine = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/SalvataggioDati" , "File immagini(*.JPG;*.PNG)"); //QString pathImmagine = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/SalvataggioDati" , "File immagini(*.JPG;*.PNG)");
    if(pathImmagine != "") {
        //pathImmagine = pathImm;
        modificaImmagine->setIcon(QIcon(pathImmagine));
    }
}

QString ModificaAvatar::getPath() const{
    return pathImmagine;
}

QFormLayout *ModificaAvatar::getFormCrea() const
{
    return formCrea;
}

QLabel *ModificaAvatar::getMaxPowerUp() const
{
    return maxPowerUp;
}

QLabel *ModificaAvatar::getLvl() const
{
    return lvl;
}

QLabel *ModificaAvatar::getValoreForza() const
{
    return valoreForza;
}

QLabel *ModificaAvatar::getValoreScienza() const
{
    return valoreScienza;
}

QLabel *ModificaAvatar::getValoreDifesa() const
{
    return valoreDifesa;
}

QLabel *ModificaAvatar::getValoreMagia() const
{
    return valoreMagia;
}

QLabel *ModificaAvatar::getValoreMedia() const
{
    return valoreMedia;
}

QLabel *ModificaAvatar::getLabelSesso() const
{
    return labelSesso;
}

QLineEdit *ModificaAvatar::getInserisciNome() const
{
    return inserisciNome;
}

QPushButton *ModificaAvatar::getbottoneSalvaModifiche() const
{
    return bottoneSalvaModifiche;
}

QPushButton *ModificaAvatar::getResetCampi() const
{
    return resetCampi;
}

QCheckBox *ModificaAvatar::getPowerUp1() const
{
    return powerUp1;
}

QCheckBox *ModificaAvatar::getPowerUp2() const
{
    return powerUp2;
}

QCheckBox *ModificaAvatar::getPowerUp3() const
{
    return powerUp3;
}

QCheckBox *ModificaAvatar::getPowerUp4() const
{
    return powerUp4;
}

QCheckBox *ModificaAvatar::getPowerUp5() const
{
    return powerUp5;
}

QCheckBox *ModificaAvatar::getPowerUp6() const
{
    return powerUp6;
}

QCheckBox *ModificaAvatar::getPowerUp7() const
{
    return powerUp7;
}

QCheckBox *ModificaAvatar::getPowerUp8() const
{
    return powerUp8;
}

QGroupBox *ModificaAvatar::getBoxValori() const
{
    return boxValori;
}

QTextEdit *ModificaAvatar::getBoxDescrizione() const
{
    return boxDescrizione;
}

QComboBox *ModificaAvatar::getSceltaTipo() const
{
    return sceltaTipo;
}

QRadioButton *ModificaAvatar::getSessoM() const
{
    return sessoM;
}

QRadioButton *ModificaAvatar::getSessoF() const
{
    return sessoF;
}

void ModificaAvatar::checkUno() const
{
    if(powerUp1->isChecked()) {
        if(powerUp2->isChecked()) {
            powerUp3->setEnabled(false);
            powerUp4->setEnabled(false);
            return;
        }
        if(powerUp3->isChecked()) {
            powerUp2->setEnabled(false);
            powerUp4->setEnabled(false);
            return;
        }
        if(powerUp4->isChecked()) {
            powerUp2->setEnabled(false);
            powerUp3->setEnabled(false);
            return;
        }
    } else {
        if(powerUp2->isChecked()) {
            powerUp3->setEnabled(true);
            powerUp4->setEnabled(true);
            return;
        }
        if(powerUp3->isChecked()) {
            powerUp2->setEnabled(true);
            powerUp4->setEnabled(true);
            return;
        }
        if(powerUp4->isChecked()) {
            powerUp2->setEnabled(true);
            powerUp3->setEnabled(true);
            return;
        }
    }
}

void ModificaAvatar::checkDue() const
{
    if(powerUp2->isChecked()) {
        if(powerUp1->isChecked()) {
            powerUp3->setEnabled(false);
            powerUp4->setEnabled(false);
            return;
        }
        if(powerUp3->isChecked()) {
            powerUp1->setEnabled(false);
            powerUp4->setEnabled(false);
            return;
        }
        if(powerUp4->isChecked()) {
            powerUp1->setEnabled(false);
            powerUp3->setEnabled(false);
            return;
        }
    } else {
        if(powerUp1->isChecked()) {
            powerUp3->setEnabled(true);
            powerUp4->setEnabled(true);
            return;
        }
        if(powerUp3->isChecked()) {
            powerUp1->setEnabled(true);
            powerUp4->setEnabled(true);
            return;
        }
        if(powerUp4->isChecked()) {
            powerUp1->setEnabled(true);
            powerUp3->setEnabled(true);
            return;
        }
    }
}

void ModificaAvatar::checkTre() const
{
    if(powerUp3->isChecked()) {
        if(powerUp2->isChecked()) {
            powerUp1->setEnabled(false);
            powerUp4->setEnabled(false);
            return;
        }
        if(powerUp1->isChecked()) {
            powerUp2->setEnabled(false);
            powerUp4->setEnabled(false);
            return;
        }
        if(powerUp4->isChecked()) {
            powerUp2->setEnabled(false);
            powerUp1->setEnabled(false);
            return;
        }
    } else {
        if(powerUp2->isChecked()) {
            powerUp1->setEnabled(true);
            powerUp4->setEnabled(true);
            return;
        }
        if(powerUp1->isChecked()) {
            powerUp2->setEnabled(true);
            powerUp4->setEnabled(true);
            return;
        }
        if(powerUp4->isChecked()) {
            powerUp2->setEnabled(true);
            powerUp1->setEnabled(true);
            return;
        }
    }
}

void ModificaAvatar::checkQuattro() const
{
    if(powerUp4->isChecked()) {
        if(powerUp2->isChecked()) {
            powerUp3->setEnabled(false);
            powerUp1->setEnabled(false);
            return;
        }
        if(powerUp3->isChecked()) {
            powerUp2->setEnabled(false);
            powerUp1->setEnabled(false);
            return;
        }
        if(powerUp1->isChecked()) {
            powerUp2->setEnabled(false);
            powerUp3->setEnabled(false);
            return;
        }
    } else {
        if(powerUp2->isChecked()) {
            powerUp3->setEnabled(true);
            powerUp1->setEnabled(true);
            return;
        }
        if(powerUp3->isChecked()) {
            powerUp2->setEnabled(true);
            powerUp1->setEnabled(true);
            return;
        }
        if(powerUp1->isChecked()) {
            powerUp2->setEnabled(true);
            powerUp3->setEnabled(true);
            return;
        }
    }
}

void ModificaAvatar::checkCinque() const
{
    if(powerUp5->isChecked()) {
        if(powerUp6->isChecked()) {
            powerUp7->setEnabled(false);
            powerUp8->setEnabled(false);
            return;
        }
        if(powerUp7->isChecked()) {
            powerUp6->setEnabled(false);
            powerUp8->setEnabled(false);
            return;
        }
        if(powerUp8->isChecked()) {
            powerUp6->setEnabled(false);
            powerUp7->setEnabled(false);
            return;
        }
    } else {
        if(powerUp6->isChecked()) {
            powerUp7->setEnabled(true);
            powerUp8->setEnabled(true);
            return;
        }
        if(powerUp7->isChecked()) {
            powerUp6->setEnabled(true);
            powerUp8->setEnabled(true);
            return;
        }
        if(powerUp8->isChecked()) {
            powerUp6->setEnabled(true);
            powerUp7->setEnabled(true);
            return;
        }
    }
}

void ModificaAvatar::checkSei() const
{
    if(powerUp6->isChecked()) {
        if(powerUp5->isChecked()) {
            powerUp7->setEnabled(false);
            powerUp8->setEnabled(false);
            return;
        }
        if(powerUp7->isChecked()) {
            powerUp5->setEnabled(false);
            powerUp8->setEnabled(false);
            return;
        }
        if(powerUp8->isChecked()) {
            powerUp5->setEnabled(false);
            powerUp7->setEnabled(false);
            return;
        }
    } else {
        if(powerUp5->isChecked()) {
            powerUp7->setEnabled(true);
            powerUp8->setEnabled(true);
            return;
        }
        if(powerUp7->isChecked()) {
            powerUp5->setEnabled(true);
            powerUp8->setEnabled(true);
            return;
        }
        if(powerUp8->isChecked()) {
            powerUp5->setEnabled(true);
            powerUp7->setEnabled(true);
            return;
        }
    }
}

void ModificaAvatar::checkSette() const
{
    if(powerUp7->isChecked()) {
        if(powerUp6->isChecked()) {
            powerUp5->setEnabled(false);
            powerUp8->setEnabled(false);
            return;
        }
        if(powerUp5->isChecked()) {
            powerUp6->setEnabled(false);
            powerUp8->setEnabled(false);
            return;
        }
        if(powerUp8->isChecked()) {
            powerUp6->setEnabled(false);
            powerUp5->setEnabled(false);
            return;
        }
    } else {
        if(powerUp6->isChecked()) {
            powerUp5->setEnabled(true);
            powerUp8->setEnabled(true);
            return;
        }
        if(powerUp5->isChecked()) {
            powerUp6->setEnabled(true);
            powerUp8->setEnabled(true);
            return;
        }
        if(powerUp8->isChecked()) {
            powerUp6->setEnabled(true);
            powerUp5->setEnabled(true);
            return;
        }
    }
}

void ModificaAvatar::checkOtto() const
{
    if(powerUp8->isChecked()) {
        if(powerUp6->isChecked()) {
            powerUp7->setEnabled(false);
            powerUp5->setEnabled(false);
            return;
        }
        if(powerUp7->isChecked()) {
            powerUp6->setEnabled(false);
            powerUp5->setEnabled(false);
            return;
        }
        if(powerUp5->isChecked()) {
            powerUp6->setEnabled(false);
            powerUp7->setEnabled(false);
            return;
        }
    } else {
        if(powerUp6->isChecked()) {
            powerUp7->setEnabled(true);
            powerUp5->setEnabled(true);
            return;
        }
        if(powerUp7->isChecked()) {
            powerUp6->setEnabled(true);
            powerUp5->setEnabled(true);
            return;
        }
        if(powerUp5->isChecked()) {
            powerUp6->setEnabled(true);
            powerUp7->setEnabled(true);
            return;
        }
    }
}

void ModificaAvatar::groupTipo() const
{
    int indexAttuale = sceltaTipo->currentIndex();
    if(indexAttuale == 0 || indexAttuale == 1 || indexAttuale == 2) {
        powerUp5->hide();
        powerUp6->hide();
        powerUp7->hide();
        powerUp8->hide();
        powerUp1->show();
        powerUp2->show();
        powerUp3->show();
        powerUp4->show();
        resetCheck();
     } else {
        powerUp1->hide();
        powerUp2->hide();
        powerUp3->hide();
        powerUp4->hide();
        powerUp5->show();
        powerUp6->show();
        powerUp7->show();
        powerUp8->show();
        resetCheck();
    }
    if(indexAttuale == 0) {

    }
}

void ModificaAvatar::resetTutto() const
{
    inserisciNome->clear();
    resetCheck();
    boxDescrizione->clear();
    sceltaTipo->setCurrentIndex(0);
    sessoF->setAutoExclusive(false);
    sessoF->setChecked(false);
    sessoF->setAutoExclusive(true);
    sessoM->setAutoExclusive(false);
    sessoM->setChecked(false);
    sessoM->setAutoExclusive(true);
}

void ModificaAvatar::resetCheck() const
{
    powerUp1->setChecked(false);
    powerUp2->setChecked(false);
    powerUp3->setChecked(false);
    powerUp4->setChecked(false);
    powerUp5->setChecked(false);
    powerUp6->setChecked(false);
    powerUp7->setChecked(false);
    powerUp8->setChecked(false);
    powerUp1->setEnabled(true);
    powerUp2->setEnabled(true);
    powerUp3->setEnabled(true);
    powerUp4->setEnabled(true);
    powerUp5->setEnabled(true);
    powerUp6->setEnabled(true);
    powerUp7->setEnabled(true);
    powerUp8->setEnabled(true);
}
