#include "creaavatar.h"

CreaAvatar::CreaAvatar(QWidget *parent) :
    formCrea(new QFormLayout),
    maxPowerUp(new QLabel("Scegli massimo due Power Up:", this)),
    lvl(new QLabel(this)),
    valoreForza(new QLabel(this)),
    valoreMagia(new QLabel(this)),
    valoreDifesa(new QLabel(this)),
    valoreScienza(new QLabel(this)),
    valoreMedia(new QLabel(this)),
    valoreSpeciale(new QLabel(this)),
    exp(new QLabel(this)),
    nomeLvl(new QLabel("LVL:", this)),
    nomeForza(new QLabel("Forza:", this)),
    nomeMagia(new QLabel("Magia:", this)),
    nomeDifesa(new QLabel("Difesa:", this)),
    nomeScienza(new QLabel("Scienza:", this)),
    nomeMedia(new QLabel("Media:", this)),
    nomeSpeciale(new QLabel("V. speciale:", this)),
    nomeExp(new QLabel("Exp:", this)),
    nomeTerreno(new QLabel("Terreno:", this)),
    labelSesso(new QLabel("Scegli il sesso del tuo Avatar: ", this)),
    terrenoPreferito(new QLabel(this)),
    immagineAvatar(new QLabel(this)),
    nome(new QLabel("Nome:",this)),
    inserisciNome(new QLineEdit(this)),
    bottoneHome(new QPushButton(this)),
    bottoneCreaDef(new QPushButton("Crea Avatar", this)),
    resetCampi(new QPushButton("Cancella tutto", this)),
    powerUp1(new QCheckBox("Spada", this)),
    powerUp2(new QCheckBox("Anello", this)),
    powerUp3(new QCheckBox("Scudo", this)),
    powerUp4(new QCheckBox("Libro", this)),
    powerUp5(new QCheckBox("Laser", this)),
    powerUp6(new QCheckBox("Amuleto", this)),
    powerUp7(new QCheckBox("Barriera", this)),
    powerUp8(new QCheckBox("Chip", this)),
    boxValori(new QGroupBox("Statistiche", this)),
    boxDescrizione(new QTextEdit(this)),
    sceltaTipo(new QComboBox(this)),
    sessoM(new QRadioButton("Maschio", this)),
    sessoF(new QRadioButton("Femmina", this))
{
    setImmagine();

    QHBoxLayout* layoutCrea = new QHBoxLayout(this);
    QVBoxLayout* layoutSx = new QVBoxLayout();
    QHBoxLayout* layoutHomeNome = new QHBoxLayout();
    QVBoxLayout* layoutHomeDestra = new QVBoxLayout();
    QHBoxLayout* layoutNome = new QHBoxLayout();
    QVBoxLayout* layoutDx = new QVBoxLayout();
    QHBoxLayout* layoutSesso = new QHBoxLayout();
    QHBoxLayout* layoutPu = new QHBoxLayout();
    QHBoxLayout* layoutNV = new QHBoxLayout();
    QVBoxLayout* layoutNomi = new QVBoxLayout();
    QVBoxLayout* layoutValori = new QVBoxLayout();
    QHBoxLayout* layoutBottoni = new QHBoxLayout();

    layoutCrea->addLayout(layoutSx);
    layoutCrea->addLayout(layoutDx);
    layoutSx->addLayout(layoutHomeNome);
    layoutHomeNome->addWidget(bottoneHome);
    layoutHomeNome->addLayout(layoutHomeDestra);
    layoutHomeDestra->addLayout(formCrea);
    layoutHomeDestra->addLayout(layoutNome);

    layoutHomeDestra->addWidget(sceltaTipo);
    layoutNome->addWidget(nome);
    layoutNome->addWidget(inserisciNome);
    layoutSx->addWidget(labelSesso);
    layoutSx->addLayout(layoutSesso);
    layoutSesso->addWidget(sessoM);
    layoutSesso->addWidget(sessoF);
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
    layoutSx->addLayout(layoutBottoni);
    layoutBottoni->addWidget(bottoneCreaDef);
    layoutBottoni->addWidget(resetCampi);
    layoutDx->addWidget(immagineAvatar,0, Qt::AlignHCenter);
    boxValori->setLayout(layoutNV);
    layoutDx->addWidget(boxValori);
    layoutNV->addLayout(layoutNomi);
    layoutNV->addLayout(layoutValori);  
    layoutNomi->addWidget(nomeForza);
    layoutNomi->addWidget(nomeMagia);
    layoutNomi->addWidget(nomeDifesa);
    layoutNomi->addWidget(nomeScienza);
    layoutNomi->addWidget(nomeMedia);
    layoutNomi->addWidget(nomeSpeciale);
    layoutNomi->addWidget(nomeLvl);
    layoutNomi->addWidget(nomeExp);
    layoutNomi->addWidget(nomeTerreno);
    layoutValori->addWidget(valoreForza);
    layoutValori->addWidget(valoreMagia);
    layoutValori->addWidget(valoreDifesa);
    layoutValori->addWidget(valoreScienza);
    layoutValori->addWidget(valoreMedia);
    layoutValori->addWidget(valoreSpeciale);
    layoutValori->addWidget(lvl);
    layoutValori->addWidget(exp);
    layoutValori->addWidget(terrenoPreferito);

    formCrea->addRow("Scegli il tipo di Avatar:", sceltaTipo);

    bottoneHome->setIcon(QIcon(":/Risorse/Immagini Avatar/home.png"));
    bottoneHome->setIconSize(QSize(35,35));
    bottoneHome->setFixedSize(50,50);
    bottoneCreaDef->setFixedHeight(40);
    resetCampi->setFixedHeight(40);
    boxValori->setFixedWidth(270);
    boxValori->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    terrenoPreferito->setFixedWidth(150);
    boxDescrizione->setFixedHeight(250);
    boxDescrizione->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    boxDescrizione->setPlaceholderText("Storia del tuo Avatar");
    inserisciNome->setPlaceholderText("Inserisci nome");

    powerUp5->hide();
    powerUp6->hide();
    powerUp7->hide();
    powerUp8->hide();

    sceltaTipo->addItem("Scegli tipo");
    sceltaTipo->addItem("Elfo");
    sceltaTipo->addItem("Nano");
    sceltaTipo->addItem("Umano");
    sceltaTipo->addItem("Alieno");
    sceltaTipo->addItem("Mostro");

    sessoM->setChecked(true);

    connect(sceltaTipo,SIGNAL(activated(int)),this,SLOT(groupTipo()));

    connect(powerUp1,SIGNAL(clicked()),this,SLOT(checkUno()));
    connect(powerUp2,SIGNAL(clicked()),this,SLOT(checkDue()));
    connect(powerUp3,SIGNAL(clicked()),this,SLOT(checkTre()));
    connect(powerUp4,SIGNAL(clicked()),this,SLOT(checkQuattro()));
    connect(powerUp5,SIGNAL(clicked()),this,SLOT(checkCinque()));
    connect(powerUp6,SIGNAL(clicked()),this,SLOT(checkSei()));
    connect(powerUp7,SIGNAL(clicked()),this,SLOT(checkSette()));
    connect(powerUp8,SIGNAL(clicked()),this,SLOT(checkOtto()));
    connect(sessoM,SIGNAL(clicked()),this,SLOT(setImmagine()));
    connect(sessoF,SIGNAL(clicked()),this,SLOT(setImmagine()));

    connect(resetCampi,SIGNAL(clicked()),this,SLOT(resetTutto()));
    connect(resetCampi,SIGNAL(clicked()),this,SLOT(calcoloValori()));

    immagineAvatar->setFixedSize(200,200);

    nomeForza->setObjectName("grassetto");
    nomeMagia->setObjectName("grassetto");
    nomeDifesa->setObjectName("grassetto");
    nomeScienza->setObjectName("grassetto");
    nomeMedia->setObjectName("grassetto");
    nomeSpeciale->setObjectName("grassetto");
    nomeLvl->setObjectName("grassetto");
    nomeExp->setObjectName("grassetto");
    nomeTerreno->setObjectName("grassetto");

    inserisciNome->setMaxLength(12);
}


void CreaAvatar::setImmagine()
{
    int indexAttuale = sceltaTipo->currentIndex();
    if(indexAttuale == 1) {
        if(sessoM->isChecked()) {
            QPixmap *elfoM = new QPixmap(":Risorse/Immagini Avatar/Elfo Maschio.png");
            QPixmap elfoM1(elfoM->scaled(200,200,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(elfoM1);
            pImmagine=":Risorse/Immagini Avatar/Elfo Maschio.png";
        }
        else {
            QPixmap *elfoF = new QPixmap(":Risorse/Immagini Avatar/Elfo Femmina.png");
            QPixmap elfoF1(elfoF->scaled(200,200,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(elfoF1);
            pImmagine=":Risorse/Immagini Avatar/Elfo Femmina.png";
        }
    } else if(indexAttuale == 2) {
        if(sessoM->isChecked()) {
            QPixmap *nanoM = new QPixmap(":Risorse/Immagini Avatar/Nano Maschio.png");
            QPixmap nanoM1(nanoM->scaled(200,200,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(nanoM1);
            pImmagine=":Risorse/Immagini Avatar/Nano Maschio.png";
        }
        else {
            QPixmap *nanoF = new QPixmap(":Risorse/Immagini Avatar/Nano Femmina.png");
            QPixmap nanoF1(nanoF->scaled(200,200,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(nanoF1);
            pImmagine=":Risorse/Immagini Avatar/Nano Femmina.png";
        }
    } else if(indexAttuale == 3) {
        if(sessoM->isChecked()) {
            QPixmap *umanoM = new QPixmap(":Risorse/Immagini Avatar/Umano Maschio.png");
            QPixmap umanoM1(umanoM->scaled(200,200,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(umanoM1);
            pImmagine=":Risorse/Immagini Avatar/Umano Maschio.png";
        }
        else {
            QPixmap *umanoF = new QPixmap(":Risorse/Immagini Avatar/Umano Femmina.png");
            QPixmap umanoF1(umanoF->scaled(200,200,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(umanoF1);
            pImmagine=":Risorse/Immagini Avatar/Umano Femmina.png";
        }
    } else if(indexAttuale == 4) {
        QPixmap *alieno = new QPixmap(":Risorse/Immagini Avatar/Alieno.png");
        QPixmap alieno1(alieno->scaled(200,200,Qt::KeepAspectRatio));
        immagineAvatar->setPixmap(alieno1);
        pImmagine=":Risorse/Immagini Avatar/Alieno.png";
    } else if(indexAttuale == 5) {
        if(sessoM->isChecked()) {
            QPixmap *mostroM = new QPixmap(":Risorse/Immagini Avatar/Mostro Maschio.png");
            QPixmap mostroM1(mostroM->scaled(200,200,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(mostroM1);
            pImmagine=":Risorse/Immagini Avatar/Mostro Maschio.png";
        }
        else {
            QPixmap *mostroF = new QPixmap(":Risorse/Immagini Avatar/Mostro Femmina.png");
            QPixmap mostroF1(mostroF->scaled(200,200,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(mostroF1);
            pImmagine=":Risorse/Immagini Avatar/Mostro Femmina.png";
        }
    } else {
        immagineAvatar->clear();
    }
}

QString CreaAvatar::getPercorso() const{
    return pImmagine;
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

QLabel *CreaAvatar::getValoreSpeciale() const
{
    return valoreSpeciale;
}

QLabel *CreaAvatar::getExp() const
{
    return exp;
}

QLabel *CreaAvatar::getLabelSesso() const
{
    return labelSesso;
}

QLabel *CreaAvatar::getTerrenoPreferito() const
{
    return terrenoPreferito;
}

QLabel *CreaAvatar::getImmagineAvatar() const
{
    return immagineAvatar;
}

QLabel *CreaAvatar::getNome() const
{
    return nome;
}

QLabel *CreaAvatar::getNomeLvl() const
{
    return nomeLvl;
}

QLabel *CreaAvatar::getNomeForza() const
{
    return nomeForza;
}

QLabel *CreaAvatar::getNomeMagia() const
{
    return nomeMagia;
}

QLabel *CreaAvatar::getNomeDifesa() const
{
    return nomeDifesa;
}

QLabel *CreaAvatar::getNomeScienza() const
{
    return nomeScienza;
}

QLabel *CreaAvatar::getNomeMedia() const
{
    return nomeMedia;
}

QLabel *CreaAvatar::getNomeSpeciale() const
{
    return nomeSpeciale;
}

QLabel *CreaAvatar::getNomeExp() const
{
    return nomeExp;
}

QLabel *CreaAvatar::getNomeTerreno() const
{
    return nomeTerreno;
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

void CreaAvatar::checkUno()
{
    int indexAttuale = sceltaTipo->currentIndex();
    if(indexAttuale == 1) {
        calcoloValori();
        if(powerUp1->isChecked()) {
            if(powerUp2->isChecked()) {
                powerUp7->setEnabled(false);
                powerUp8->setEnabled(false);
                return;
            }
            if(powerUp7->isChecked()) {
                powerUp2->setEnabled(false);
                powerUp8->setEnabled(false);
                return;
            }
            if(powerUp8->isChecked()) {
                powerUp2->setEnabled(false);
                powerUp7->setEnabled(false);
                return;
            }
        } else {
            if(powerUp2->isChecked()) {
                powerUp7->setEnabled(true);
                powerUp8->setEnabled(true);
                return;
            }
            if(powerUp7->isChecked()) {
                powerUp2->setEnabled(true);
                powerUp8->setEnabled(true);
                return;
            }
            if(powerUp8->isChecked()) {
                powerUp2->setEnabled(true);
                powerUp7->setEnabled(true);
                return;
            }
        }
    } else {
        calcoloValori();
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

}

void CreaAvatar::checkDue()
{
    int indexAttuale = sceltaTipo->currentIndex();
    if(indexAttuale == 1) {
        calcoloValori();
        if(powerUp2->isChecked()) {
            if(powerUp1->isChecked()) {
                powerUp7->setEnabled(false);
                powerUp8->setEnabled(false);
                return;
            }
            if(powerUp7->isChecked()) {
                powerUp1->setEnabled(false);
                powerUp8->setEnabled(false);
                return;
            }
            if(powerUp8->isChecked()) {
                powerUp1->setEnabled(false);
                powerUp7->setEnabled(false);
                return;
            }
        } else {
            if(powerUp1->isChecked()) {
                powerUp7->setEnabled(true);
                powerUp8->setEnabled(true);
                return;
            }
            if(powerUp7->isChecked()) {
                powerUp1->setEnabled(true);
                powerUp8->setEnabled(true);
                return;
            }
            if(powerUp8->isChecked()) {
                powerUp1->setEnabled(true);
                powerUp7->setEnabled(true);
                return;
            }
        }
    } else {
        calcoloValori();
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
}

void CreaAvatar::checkTre()
{
    calcoloValori();
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

void CreaAvatar::checkQuattro()
{
    calcoloValori();
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

void CreaAvatar::checkCinque()
{
    calcoloValori();
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

void CreaAvatar::checkSei()
{
    calcoloValori();
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

void CreaAvatar::checkSette()
{
    int indexAttuale = sceltaTipo->currentIndex();
    if(indexAttuale == 1) {
        calcoloValori();
        if(powerUp7->isChecked()) {
            if(powerUp2->isChecked()) {
                powerUp1->setEnabled(false);
                powerUp8->setEnabled(false);
                return;
            }
            if(powerUp1->isChecked()) {
                powerUp2->setEnabled(false);
                powerUp8->setEnabled(false);
                return;
            }
            if(powerUp8->isChecked()) {
                powerUp2->setEnabled(false);
                powerUp1->setEnabled(false);
                return;
            }
        } else {
            if(powerUp2->isChecked()) {
                powerUp1->setEnabled(true);
                powerUp8->setEnabled(true);
                return;
            }
            if(powerUp1->isChecked()) {
                powerUp2->setEnabled(true);
                powerUp8->setEnabled(true);
                return;
            }
            if(powerUp8->isChecked()) {
                powerUp2->setEnabled(true);
                powerUp1->setEnabled(true);
                return;
            }
        }
    } else {
        calcoloValori();
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
}

void CreaAvatar::checkOtto()
{
    int indexAttuale = sceltaTipo->currentIndex();
    if(indexAttuale == 1) {
        calcoloValori();
        if(powerUp8->isChecked()) {
            if(powerUp2->isChecked()) {
                powerUp7->setEnabled(false);
                powerUp1->setEnabled(false);
                return;
            }
            if(powerUp7->isChecked()) {
                powerUp2->setEnabled(false);
                powerUp1->setEnabled(false);
                return;
            }
            if(powerUp1->isChecked()) {
                powerUp2->setEnabled(false);
                powerUp7->setEnabled(false);
                return;
            }
        } else {
            if(powerUp2->isChecked()) {
                powerUp7->setEnabled(true);
                powerUp1->setEnabled(true);
                return;
            }
            if(powerUp7->isChecked()) {
                powerUp2->setEnabled(true);
                powerUp1->setEnabled(true);
                return;
            }
            if(powerUp1->isChecked()) {
                powerUp2->setEnabled(true);
                powerUp7->setEnabled(true);
                return;
            }
        }
    } else {
        calcoloValori();
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
}

void CreaAvatar::groupTipo()
{
    int indexAttuale = sceltaTipo->currentIndex();
    if(indexAttuale == 1) {
        powerUp5->hide();
        powerUp6->hide();
        powerUp7->show();
        powerUp8->show();
        powerUp1->show();
        powerUp2->show();
        powerUp3->hide();
        powerUp4->hide();
        resetCheck();
    } else if(indexAttuale == 2 || indexAttuale == 3) {
        powerUp5->hide();
        powerUp6->hide();
        powerUp7->hide();
        powerUp8->hide();
        powerUp1->show();
        powerUp2->show();
        powerUp3->show();
        powerUp4->show();
        resetCheck();
     } else if (indexAttuale == 4 || indexAttuale == 5){
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
    calcoloValori();
    setImmagine();
}

void CreaAvatar::resetTutto() const
{
    immagineAvatar->clear();
    inserisciNome->clear();
    valoreForza->clear();
    valoreMagia->clear();
    valoreDifesa->clear();
    valoreScienza->clear();
    valoreMedia->clear();
    valoreSpeciale->clear();
    terrenoPreferito->clear();
    lvl->clear();
    exp->clear();
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

void CreaAvatar::calcoloValori()
{
    int indexAttuale = sceltaTipo->currentIndex();
    double forza = 0;
    double magia = 0;
    double difesa = 0;
    double scienza = 0;
    unsigned int livello = 1;
    unsigned int esperienza = 0;
    double valoreExtra = 0;
    std::string terreno;

    if(indexAttuale == 1) {
        forza = 6;
        if(powerUp1->isChecked()) {
            forza+=8;
        }
        magia = 10;
        if(powerUp2->isChecked()) {
            magia += 6;
        }
        difesa = 6;
        if(powerUp7->isChecked()) {
            difesa += 10;
        }
        scienza = 5;
        if(powerUp8->isChecked()) {
            scienza += 5;
        }
        terreno = "Regno incantato";
        valoreExtra = (magia+difesa)*livello*0.05;

    } else
    if(indexAttuale == 2) {
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
        terreno = "Regno del sottosuolo";
        valoreExtra = (forza+difesa)*livello*0.05;

    } else
    if(indexAttuale == 3) {
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
        terreno = "Regno delle macchine";
        valoreExtra = (difesa+scienza)*livello*0.05;

    } else
    if(indexAttuale == 4) {
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
        terreno = "Regno dello spazio";
        valoreExtra = (forza+scienza)*livello*0.05;

    } else
    if(indexAttuale == 5) {
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
        terreno = "Regno dei demoni";
        valoreExtra = (forza+difesa)*livello*0.05;

    }

    double media = (forza+magia+difesa+scienza)/4;
    valoreForza->setText(QString::number(forza));
    valoreMagia->setText(QString::number(magia));
    valoreDifesa->setText(QString::number(difesa));
    valoreScienza->setText(QString::number(scienza));
    valoreMedia->setText(QString::number(media,'f',2));
    terrenoPreferito->setText(QString::fromStdString(terreno));
    lvl->setText(QString::number(livello));
    exp->setText(QString::number(esperienza));
    valoreSpeciale->setText(QString::number(valoreExtra,'f',2));
}
