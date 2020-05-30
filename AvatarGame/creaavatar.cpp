#include "creaavatar.h"


CreaAvatar::CreaAvatar(QWidget *parent) :
    formCrea(new QFormLayout),
    maxPowerUp(new QLabel("Scegli massimo 2 power Up", this)),
    lvl(new QLabel("LVL", this)),
    valoreForza(new QLabel(this)), //qui il valore cambia in base al personaggio e al power up quindi vedere come fare
    valoreScienza(new QLabel(this)),
    valoreDifesa(new QLabel(this)),
    valoreMagia(new QLabel(this)),
    valoreMedia(new QLabel(this)),
    inserisciNome(new QLineEdit(this)),
    bottoneHome(new QPushButton("Home", this)),
    bottoneCreaDef(new QPushButton("Crea Avatar", this)),
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
    immagineAvatar(new QLabel("inserire immagine qui", this))
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
    layoutSx->addLayout(formCrea);
    layoutSx->addWidget(maxPowerUp);
    layoutSx->addWidget(sceltaTipo);
    layoutSx->addWidget(inserisciNome);
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
    layoutSx->addWidget(bottoneCreaDef);
    layoutDx->addWidget(immagineAvatar);
    layoutDx->addLayout(layoutValori);
    layoutDx->addWidget(boxValori);
    layoutValori->addWidget(valoreForza);
    layoutValori->addWidget(valoreScienza);
    layoutValori->addWidget(valoreMagia);
    layoutValori->addWidget(valoreDifesa);
    layoutValori->addWidget(valoreMedia);
    layoutValori->addWidget(lvl);
    layoutDx->addWidget(resetCampi);

    formCrea->addRow("Nome:", inserisciNome);
    formCrea->addRow("Scegli il tipo di Avatar:", sceltaTipo);

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

    connect(sceltaTipo,SIGNAL(activated(int)),this,SLOT(groupTipo()));

}

QFormLayout *CreaAvatar::getFormCrea() const
{
    return formCrea;
}

QLabel *CreaAvatar::getMaxPowerUp() const
{
    return maxPowerUp;
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

QCheckBox *CreaAvatar::getPowerUp5() const
{
    return powerUp5;
}

QCheckBox *CreaAvatar::getPowerUp6() const
{
    return powerUp6;
}

QCheckBox *CreaAvatar::getPowerUp7() const
{
    return powerUp7;
}

QCheckBox *CreaAvatar::getPowerUp8() const
{
    return powerUp8;
}

QGroupBox *CreaAvatar::getBoxValori() const
{
    return boxValori;
}

QTextEdit *CreaAvatar::getBoxDescrizione() const
{
    return boxDescrizione;
}

QComboBox *CreaAvatar::getSceltaTipo() const
{
    return sceltaTipo;
}

void CreaAvatar::checkUno() const
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

void CreaAvatar::checkDue() const
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

void CreaAvatar::checkTre() const
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

void CreaAvatar::checkQuattro() const
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

void CreaAvatar::groupTipo() const
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

     } else {
        powerUp1->hide();
        powerUp2->hide();
        powerUp3->hide();
        powerUp4->hide();
        powerUp5->show();
        powerUp6->show();
        powerUp7->show();
        powerUp8->show();
    }
}






