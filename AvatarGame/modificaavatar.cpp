 #include "modificaavatar.h"

ModificaAvatar::ModificaAvatar(QWidget *parent) :
    formCrea(new QFormLayout),
    tipoAvatar(new QLabel(this)),
    maxPowerUp(new QLabel("Scegli massimo due Power Up:", this)),
    lvl(new QLabel("LVL", this)),
    valoreForza(new QLabel(this)),
    valoreMagia(new QLabel(this)),
    valoreScienza(new QLabel(this)),
    valoreDifesa(new QLabel(this)),
    valoreMedia(new QLabel(this)),
    valoreSpeciale(new QLabel(this)),
    exp(new QLabel(this)),
    nomeLvl(new QLabel("LVL:", this)),
    nomeForza(new QLabel("Forza:", this)),
    nomeMagia(new QLabel("Magia:", this)),
    nomeDifesa(new QLabel("Difesa:", this)),
    nomeScienza(new QLabel("Scienza:", this)),
    nomeMedia(new QLabel("Media:", this)),
    nomeSpeciale(new QLabel("V. Speciale:", this)),
    nomeExp(new QLabel("Exp:", this)),
    nomeTerreno(new QLabel("Terreno:", this)),
    labelSesso(new QLabel("Scegli il sesso del tuo Avatar: ", this)),
    terrenoPreferito(new QLabel(this)),
    immagineAvatar(new QLabel(this)),
    nome(new QLabel("Nome:", this)),
    inserisciNome(new QLineEdit(this)),
    bottoneSalvaModifiche(new QPushButton("Salva modifiche", this)),
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
    sessoM(new QRadioButton("Maschio", this)),
    sessoF(new QRadioButton("Femmina", this)),
    pImmagine()
{
    QHBoxLayout* layoutCrea = new QHBoxLayout(this);
    QVBoxLayout* layoutSx = new QVBoxLayout();
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
    layoutSx->addLayout(formCrea);
    layoutSx->addLayout(layoutNome);

    layoutSx->addWidget(tipoAvatar);
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
    layoutBottoni->addWidget(bottoneSalvaModifiche);
    layoutBottoni->addWidget(resetCampi);
    layoutDx->addWidget(immagineAvatar,0, Qt::AlignCenter);
    boxValori->setLayout(layoutNV);
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
    layoutDx->addWidget(boxValori);
    layoutValori->addWidget(valoreForza);
    layoutValori->addWidget(valoreMagia);
    layoutValori->addWidget(valoreDifesa);
    layoutValori->addWidget(valoreScienza);
    layoutValori->addWidget(valoreMedia);
    layoutValori->addWidget(valoreSpeciale);
    layoutValori->addWidget(lvl);
    layoutValori->addWidget(exp);
    layoutValori->addWidget(terrenoPreferito);

    formCrea->addRow("Tipo di Avatar:", tipoAvatar);
    inserisciNome->setPlaceholderText("Inserisci nome");

    setFixedSize(580,480);
    bottoneSalvaModifiche->setFixedHeight(40);
    resetCampi->setFixedHeight(40);
    boxDescrizione->setFixedHeight(200);
    boxDescrizione->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    boxDescrizione->setPlaceholderText("Storia del tuo Avatar");
    boxValori->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

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

    immagineAvatar->setFixedSize(150,150);

    nomeForza->setObjectName("grassetto");
    nomeMagia->setObjectName("grassetto");
    nomeDifesa->setObjectName("grassetto");
    nomeScienza->setObjectName("grassetto");
    nomeMedia->setObjectName("grassetto");
    nomeSpeciale->setObjectName("grassetto");
    nomeLvl->setObjectName("grassetto");
    nomeExp->setObjectName("grassetto");
    nomeTerreno->setObjectName("grassetto");

    setStyleModifica();

    inserisciNome->setMaxLength(12);
}


void ModificaAvatar::setImmagine()
{
    std::string tipo = tipoAvatar->text().toStdString();
    if(tipo == "Elfo") {
        if(sessoM->isChecked()) {
            QPixmap *elfoM = new QPixmap(":Risorse/Immagini Avatar/Elfo Maschio.png");
            QPixmap elfoM1(elfoM->scaled(150,150,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(elfoM1);
            pImmagine=":Risorse/Immagini Avatar/Elfo Maschio.png";
        }
        else {
            QPixmap *elfoF = new QPixmap(":Risorse/Immagini Avatar/Elfo Femmina.png");
            QPixmap elfoF1(elfoF->scaled(150,150,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(elfoF1);
            pImmagine=":Risorse/Immagini Avatar/Elfo Femmina.png";
        }
    } else if(tipo == "Nano") {
        if(sessoM->isChecked()) {
            QPixmap *nanoM = new QPixmap(":Risorse/Immagini Avatar/Nano Maschio.png");
            QPixmap nanoM1(nanoM->scaled(150,150,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(nanoM1);
            pImmagine=":Risorse/Immagini Avatar/Nano Maschio.png";
        }
        else {
            QPixmap *nanoF = new QPixmap(":Risorse/Immagini Avatar/Nano Femmina.png");
            QPixmap nanoF1(nanoF->scaled(150,150,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(nanoF1);
            pImmagine=":Risorse/Immagini Avatar/Nano Femmina.png";
        }
    } else if(tipo == "Umano") {
        if(sessoM->isChecked()) {
            QPixmap *umanoM = new QPixmap(":Risorse/Immagini Avatar/Umano Maschio.png");
            QPixmap umanoM1(umanoM->scaled(150,150,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(umanoM1);
            pImmagine=":Risorse/Immagini Avatar/Umano Maschio.png";
        }
        else {
            QPixmap *umanoF = new QPixmap(":Risorse/Immagini Avatar/Umano Femmina.png");
            QPixmap umanoF1(umanoF->scaled(150,150,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(umanoF1);
            pImmagine=":Risorse/Immagini Avatar/Umano Femmina.png";
        }
    } else if(tipo == "Alieno") {
        QPixmap *alieno = new QPixmap(":Risorse/Immagini Avatar/Alieno.png");
        QPixmap alieno1(alieno->scaled(150,150,Qt::KeepAspectRatio));
        immagineAvatar->setPixmap(alieno1);
        pImmagine=":Risorse/Immagini Avatar/Alieno.png";
    } else if(tipo == "Mostro") {
        if(sessoM->isChecked()) {
            QPixmap *mostroM = new QPixmap(":Risorse/Immagini Avatar/Mostro Maschio.png");
            QPixmap mostroM1(mostroM->scaled(150,150,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(mostroM1);
            pImmagine=":Risorse/Immagini Avatar/Mostro Maschio.png";
        }
        else {
            QPixmap *mostroF = new QPixmap(":Risorse/Immagini Avatar/Mostro Femmina.png");
            QPixmap mostroF1(mostroF->scaled(150,150,Qt::KeepAspectRatio));
            immagineAvatar->setPixmap(mostroF1);
            pImmagine=":Risorse/Immagini Avatar/Mostro Femmina.png";
        }
    }
}

QString ModificaAvatar::getPercorsoImmagine() const{
    return pImmagine;
}

void ModificaAvatar::inserisciPercorso(std::string p)
{
    pImmagine = QString::fromStdString(p);
}

QFormLayout *ModificaAvatar::getFormCrea() const
{
    return formCrea;
}

QLabel *ModificaAvatar::getTipoAvatar() const
{
    return tipoAvatar;
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

QLabel *ModificaAvatar::getValoreSpeciale() const
{
    return valoreSpeciale;
}

QLabel *ModificaAvatar::getExp() const
{
    return exp;
}

QLabel *ModificaAvatar::getNomeLvl() const
{
    return nomeLvl;
}

QLabel *ModificaAvatar::getNomeForza() const
{
    return nomeForza;
}

QLabel *ModificaAvatar::getNomeMagia() const
{
    return nomeMagia;
}

QLabel *ModificaAvatar::getNomeDifesa() const
{
    return nomeDifesa;
}

QLabel *ModificaAvatar::getNomeScienza() const
{
    return nomeScienza;
}

QLabel *ModificaAvatar::getNomeMedia() const
{
    return nomeMedia;
}

QLabel *ModificaAvatar::getNomeSpeciale() const
{
    return nomeSpeciale;
}

QLabel *ModificaAvatar::getNomeExp() const
{
    return nomeExp;
}

QLabel *ModificaAvatar::getNomeTerreno() const
{
    return nomeTerreno;
}

QLabel *ModificaAvatar::getLabelSesso() const
{
    return labelSesso;
}

QLabel *ModificaAvatar::getTerrenoPreferito() const
{
    return terrenoPreferito;
}

QLabel *ModificaAvatar::getImmagineAvatar() const
{
    return immagineAvatar;
}

QLabel *ModificaAvatar::getNome() const
{
    return nome;
}

QLineEdit *ModificaAvatar::getInserisciNome() const
{
    return inserisciNome;
}

QPushButton *ModificaAvatar::getBottoneSalvaModifiche() const
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

QRadioButton *ModificaAvatar::getSessoM() const
{
    return sessoM;
}

QRadioButton *ModificaAvatar::getSessoF() const
{
    return sessoF;
}

void ModificaAvatar::checkUno()
{
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

void ModificaAvatar::checkDue()
{
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

void ModificaAvatar::checkTre()
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

void ModificaAvatar::checkQuattro()
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

void ModificaAvatar::checkCinque()
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

void ModificaAvatar::checkSei()
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

void ModificaAvatar::checkSette()
{
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

void ModificaAvatar::checkOtto()
{
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

void ModificaAvatar::groupTipo()
{
    std::string tipo = tipoAvatar->text().toStdString();
    if(tipo == "Elfo" || tipo == "Nano" || tipo == "Umano") {
        powerUp5->hide();
        powerUp6->hide();
        powerUp7->hide();
        powerUp8->hide();
        powerUp1->show();
        powerUp2->show();
        powerUp3->show();
        powerUp4->show();
        resetCheck();
     } else if(tipo == "Alieno" || tipo == "Mostro"){
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

void ModificaAvatar::resetTutto() const
{
    inserisciNome->clear();
    resetCheck();
    boxDescrizione->clear();
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

void ModificaAvatar::calcoloValori()
{
    std::string tipo = tipoAvatar->text().toStdString();    
    double forza = 0;
    double magia = 0;
    double difesa = 0;
    double scienza = 0;
    unsigned int livello = getLvl()->text().toUInt();
    double valoreExtra = 0;

    if(tipo == "Elfo") {
        forza = livello*6;
        if(powerUp1->isChecked()) {
            forza+=8;
        }
        magia = livello*10;
        if(powerUp2->isChecked()) {
            magia += 6;
        }
        difesa = livello*6;
        if(powerUp3->isChecked()) {
            difesa += 10;
        }
        scienza = livello*5;
        if(powerUp4->isChecked()) {
            scienza += 5;
        }
        valoreExtra = (magia+difesa)*livello*0.05;

    } else
    if(tipo == "Nano") {
        forza = livello*7;
        if(powerUp1->isChecked()) {
            forza+=8;
        }
        magia = livello*2;
        if(powerUp2->isChecked()) {
            magia += 6;
        }
        difesa = livello*10;
        if(powerUp3->isChecked()) {
            difesa += 10;
        }
        scienza = livello*6;
        if(powerUp4->isChecked()) {
            scienza += 5;
        }

        valoreExtra = (forza+difesa)*livello*0.05;

    } else
    if(tipo == "Umano") {
        forza = livello*5;
        if(powerUp1->isChecked()) {
            forza+=8;
        }
        magia = livello*3;
        if(powerUp2->isChecked()) {
            magia += 6;
        }
        difesa = livello*8;
        if(powerUp3->isChecked()) {
            difesa += 2;
        }
        scienza = livello*8;
        if(powerUp4->isChecked()) {
            scienza += 5;
        }

        valoreExtra = (difesa+scienza)*livello*0.05;

    } else
    if(tipo == "Alieno") {
        forza = livello*3;
        if(powerUp5->isChecked()) {
            forza+=7;
        }
        magia = livello*10;
        if(powerUp6->isChecked()) {
            magia += 6;
        }
        difesa = livello*0;
        if(powerUp7->isChecked()) {
            difesa += 8;
        }
        scienza = livello*7;
        if(powerUp8->isChecked()) {
            scienza += 9;
        }

        valoreExtra = (forza+scienza)*livello*0.05;

    } else
    if(tipo == "Mostro") {
        forza = livello*10;
        if(powerUp5->isChecked()) {
            forza+=7;
        }
        magia = livello*0;
        if(powerUp6->isChecked()) {
            magia += 6;
        }
        difesa = livello*5;
        if(powerUp7->isChecked()) {
            difesa += 8;
        }
        scienza = livello*9;
        if(powerUp8->isChecked()) {
            scienza += 9;
        }
        valoreExtra = (forza+difesa)*livello*0.05;

    }

    double media = (forza+magia+difesa+scienza)/4;
    valoreForza->setText(QString::number(forza));
    valoreMagia->setText(QString::number(magia));
    valoreDifesa->setText(QString::number(difesa));
    valoreScienza->setText(QString::number(scienza));
    valoreMedia->setText(QString::number(media,'f',2));
    lvl->setText(QString::number(livello));
    valoreSpeciale->setText(QString::number(valoreExtra,'f',2));
}

void ModificaAvatar::setStyleModifica()
{
    QFile file(":/Risorse/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    setStyleSheet(styleSheet);
}
