#include "creaavatar.h"
#include "controller.h"

CreaAvatar::CreaAvatar(QWidget *parent) :
    formCrea(new QFormLayout),
    maxPowerUp(new QLabel("Scegli massimo 2 power Up", this)),
    lvl(new QLabel("LVL 1", this)),
    valoreForza(new QLabel("6", this)),
    valoreMagia(new QLabel("10", this)),
    valoreDifesa(new QLabel("6", this)),
    valoreScienza(new QLabel("5", this)),
    valoreMedia(new QLabel("6.8", this)),
    labelSesso(new QLabel("Scegli il sesso del tuo Avatar: ", this)),
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
    immagineAvatar(new QLabel("inserire immagine qui", this)),
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
    layoutSx->addWidget(bottoneHome);
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
    layoutSx->addWidget(bottoneCreaDef);
    layoutDx->addWidget(immagineAvatar);
    layoutDx->addLayout(layoutValori);
    layoutDx->addWidget(boxValori);
    layoutValori->addWidget(valoreForza);
    layoutValori->addWidget(valoreMagia);
    layoutValori->addWidget(valoreDifesa);
    layoutValori->addWidget(valoreScienza);
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

    connect(sceltaTipo,SIGNAL(activated(int)),this,SLOT(groupTipo()));
    connect(sceltaTipo,SIGNAL(activated(int)),this,SLOT(calcoloValori()));

    connect(powerUp1,SIGNAL(clicked()),this,SLOT(checkUno()));
    connect(powerUp2,SIGNAL(clicked()),this,SLOT(checkDue()));
    connect(powerUp3,SIGNAL(clicked()),this,SLOT(checkTre()));
    connect(powerUp4,SIGNAL(clicked()),this,SLOT(checkQuattro()));
    connect(powerUp5,SIGNAL(clicked()),this,SLOT(checkCinque()));
    connect(powerUp6,SIGNAL(clicked()),this,SLOT(checkSei()));
    connect(powerUp7,SIGNAL(clicked()),this,SLOT(checkSette()));
    connect(powerUp8,SIGNAL(clicked()),this,SLOT(checkOtto()));
    connect(powerUp1,SIGNAL(clicked()),this,SLOT(calcoloValori()));
    connect(powerUp2,SIGNAL(clicked()),this,SLOT(calcoloValori()));
    connect(powerUp3,SIGNAL(clicked()),this,SLOT(calcoloValori()));
    connect(powerUp4,SIGNAL(clicked()),this,SLOT(calcoloValori()));
    connect(powerUp5,SIGNAL(clicked()),this,SLOT(calcoloValori()));
    connect(powerUp6,SIGNAL(clicked()),this,SLOT(calcoloValori()));
    connect(powerUp7,SIGNAL(clicked()),this,SLOT(calcoloValori()));
    connect(powerUp8,SIGNAL(clicked()),this,SLOT(calcoloValori()));

    connect(resetCampi,SIGNAL(clicked()),this,SLOT(resetTutto()));
    connect(resetCampi,SIGNAL(clicked()),this,SLOT(calcoloValori()));

    bottoneCreaDef->setEnabled(false);
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

QLabel *CreaAvatar::getLabelSesso() const
{
    return labelSesso;
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

QRadioButton *CreaAvatar::getSessoM() const
{
    return sessoM;
}

QRadioButton *CreaAvatar::getSessoF() const
{
    return sessoF;
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

void CreaAvatar::checkCinque() const
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

void CreaAvatar::checkSei() const
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

void CreaAvatar::checkSette() const
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

void CreaAvatar::checkOtto() const
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

void CreaAvatar::resetTutto() const
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

void CreaAvatar::resetCheck() const
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

void CreaAvatar::calcoloValori() const
{
    int indexAttuale = sceltaTipo->currentIndex();
    double forza = 0;
    double magia = 0;
    double difesa = 0;
    double scienza = 0;
    if(indexAttuale == 0) {
        forza = 6;
        if(powerUp1->isChecked()) {
            forza+=8;
        }
        magia = 10;
        if(powerUp2->isChecked()) {
            magia += 6;
        }
        difesa = 6;
        if(powerUp3->isChecked()) {
            difesa += 10;
        }
        scienza = 5;
        if(powerUp4->isChecked()) {
            scienza += 5;
        }
    }
    if(indexAttuale == 1) {
        forza = 7;
        if(powerUp1->isChecked()) {
            forza+=8;
        }
        magia = 2;
        if(powerUp2->isChecked()) {
            magia += 6;
        }
        difesa = 10;
        if(powerUp3->isChecked()) {
            difesa += 10;
        }
        scienza = 6;
        if(powerUp4->isChecked()) {
            scienza += 5;
        }
    }
    if(indexAttuale == 2) {
        forza = 5;
        if(powerUp1->isChecked()) {
            forza+=8;
        }
        magia = 3;
        if(powerUp2->isChecked()) {
            magia += 6;
        }
        difesa = 8;
        if(powerUp3->isChecked()) {
            difesa += 2;
        }
        scienza = 8;
        if(powerUp4->isChecked()) {
            scienza += 5;
        }
    }
    if(indexAttuale == 3) {
        forza = 3;
        if(powerUp5->isChecked()) {
            forza+=7;
        }
        magia = 10;
        if(powerUp6->isChecked()) {
            magia += 6;
        }
        difesa = 0;
        if(powerUp7->isChecked()) {
            difesa += 8;
        }
        scienza = 7;
        if(powerUp8->isChecked()) {
            scienza += 9;
        }
    }
    if(indexAttuale == 4) {
        forza = 10;
        if(powerUp5->isChecked()) {
            forza+=7;
        }
        magia = 0;
        if(powerUp6->isChecked()) {
            magia += 6;
        }
        difesa = 5;
        if(powerUp7->isChecked()) {
            difesa += 8;
        }
        scienza = 9;
        if(powerUp8->isChecked()) {
            scienza += 9;
        }
    }
    double media = (forza+magia+difesa+scienza)/4;
    valoreForza->setText(QString::number(forza));
    valoreMagia->setText(QString::number(magia));
    valoreDifesa->setText(QString::number(difesa));
    valoreScienza->setText(QString::number(scienza));
    valoreMedia->setText(QString::number(media,'f',1));
}
