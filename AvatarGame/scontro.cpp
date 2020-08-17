#include "scontro.h"
#include "finescontro.h"
#include "controller.h"

Scontro::Scontro(QWidget *parent) :
    nomeAvatarSx(new QLabel("Avatar1", this)),
    powerupSx(new QLabel("PowerUp:", this)),
    powerup1selezionatoSx(new QLabel(this)),
    powerup2selezionatoSx(new QLabel(this)),
    powerup3selezionatoSx(new QLabel(this)),
    powerup4selezionatoSx(new QLabel(this)),
    titoloMediaSx(new QLabel("Media:", this)),
    mediaSx(new QLabel(this)),

    vs(new QLabel("VS", this)),
    terreno(new QLabel(this)),
    bottoneHomeScontro(new QPushButton("Home", this)),
    bottoneCambioAvatar(new QPushButton("Cambia avatar", this)),
    bottoneCambioAvversario(new QPushButton("Cambia avversario", this)),
    bottoneCombatti(new QPushButton("Combatti", this)),

    nomeAvatarDx(new QLabel("Avatar2", this)),
    formPowerupDx(new QFormLayout),
    powerup1selezionatoDx(new QLabel(this)),
    powerup2selezionatoDx(new QLabel(this)),
    powerup3selezionatoDx(new QLabel(this)),
    powerup4selezionatoDx(new QLabel(this)),
    formMediaDx(new QFormLayout),
    mediaDx(new QLabel(this)),
    fotoAvatar1(new QLabel(this)),
    fotoAvatar2(new QLabel(this))
{
    QVBoxLayout* layoutScontro = new QVBoxLayout(this);
    QHBoxLayout* layoutTastiNavigazione = new QHBoxLayout();
    QHBoxLayout* layoutCombattimento = new QHBoxLayout();
    QVBoxLayout* layoutScontroSx = new QVBoxLayout();
    //QVBoxLayout* layoutPowerupSx = new QVBoxLayout();
    //QVBoxLayout* layoutMediaSx = new QVBoxLayout();
    QVBoxLayout* layoutScontroCentrale = new QVBoxLayout();
    QVBoxLayout* layoutScontroDx = new QVBoxLayout();
    QVBoxLayout* layoutPowerupDx = new QVBoxLayout();

    layoutScontro->addLayout(layoutTastiNavigazione);
    layoutScontro->addLayout(layoutCombattimento);
    layoutCombattimento->addLayout(layoutScontroSx);
    layoutCombattimento->addLayout(layoutScontroCentrale);
    layoutCombattimento->addLayout(layoutScontroDx);

    layoutTastiNavigazione->addWidget(bottoneCambioAvatar);
    layoutTastiNavigazione->addWidget(bottoneHomeScontro);
    layoutTastiNavigazione->addWidget(bottoneCambioAvversario);
    const QSize dimBottoneHomeCambio = QSize(120,40);
    bottoneCambioAvatar->setFixedSize(dimBottoneHomeCambio);
    bottoneHomeScontro->setFixedSize(dimBottoneHomeCambio);
    bottoneCambioAvversario->setFixedSize(dimBottoneHomeCambio);
    bottoneCombatti->setFixedSize(130,60);

    layoutScontroSx->addWidget(fotoAvatar1);
    layoutScontroSx->addWidget(nomeAvatarSx, 0, Qt::AlignCenter);
    //layoutScontroSx->addLayout(layoutPowerupSx);
    layoutScontroSx->addWidget(powerupSx);
    layoutScontroSx->addWidget(powerup1selezionatoSx);
    layoutScontroSx->addWidget(powerup2selezionatoSx);
    layoutScontroSx->addWidget(powerup3selezionatoSx);
    layoutScontroSx->addWidget(powerup4selezionatoSx);
    //layoutScontroSx->addLayout(layoutMediaSx);
    layoutScontroSx->addWidget(titoloMediaSx);
    layoutScontroSx->addWidget(mediaSx);

    layoutScontroCentrale->addWidget(vs, 0, Qt::AlignCenter);
    layoutScontroCentrale->addWidget(terreno, 0, Qt::AlignCenter);
    layoutScontroCentrale->addWidget(bottoneCombatti, 0, Qt::AlignCenter);

    layoutScontroDx->addWidget(fotoAvatar2);
    layoutScontroDx->addWidget(nomeAvatarDx, 0, Qt::AlignCenter);
    layoutScontroDx->addLayout(formPowerupDx);
    layoutPowerupDx->addWidget(powerup1selezionatoDx);
    layoutPowerupDx->addWidget(powerup2selezionatoDx);
    layoutPowerupDx->addWidget(powerup3selezionatoDx);
    layoutPowerupDx->addWidget(powerup4selezionatoDx);
    formPowerupDx->addRow("Powerup: ", layoutPowerupDx);
    layoutScontroDx->addLayout(formMediaDx);
    formMediaDx->addRow("Media: ", mediaDx);

}

QLabel *Scontro::getNomeAvatarSx() const
{
    return nomeAvatarSx;
}

QLabel *Scontro::getPowerup1selezionatoSx() const
{
    return powerup1selezionatoSx;
}

QLabel *Scontro::getPowerup2selezionatoSx() const
{
    return powerup2selezionatoSx;
}

QLabel *Scontro::getPowerup3selezionatoSx() const
{
    return powerup3selezionatoSx;
}

QLabel *Scontro::getPowerup4selezionatoSx() const
{
    return powerup4selezionatoSx;
}

QLabel *Scontro::getMediaSx() const
{
    return mediaSx;
}

QLabel *Scontro::getVs() const
{
    return vs;
}

QLabel *Scontro::getTerreno() const
{
    return terreno;
}

QPushButton *Scontro::getBottoneCombatti() const
{
    return bottoneCombatti;
}

QPushButton *Scontro::getBottoneCambioAvatar() const
{
    return bottoneCambioAvatar;
}

QPushButton *Scontro::getBottoneCambioAvversario() const
{
    return bottoneCambioAvversario;
}

QPushButton *Scontro::getBottoneHomeScontro() const
{
    return bottoneHomeScontro;
}

QLabel *Scontro::getNomeAvatarDx() const
{
    return nomeAvatarDx;
}

QFormLayout *Scontro::getFormPowerupDx() const
{
    return formPowerupDx;
}

QLabel *Scontro::getPowerup1selezionatoDx() const
{
    return powerup1selezionatoDx;
}

QLabel *Scontro::getPowerup2selezionatoDx() const
{
    return powerup2selezionatoDx;
}

QLabel *Scontro::getPowerup3selezionatoDx() const
{
    return powerup3selezionatoDx;
}

QLabel *Scontro::getPowerup4selezionatoDx() const
{
    return powerup4selezionatoDx;
}

QFormLayout *Scontro::getFormMediaDx() const
{
    return formMediaDx;
}

QLabel *Scontro::getMediaDx() const
{
    return mediaDx;
}

QString *Scontro::getForza() const
{
    return forza;
}

QString *Scontro::getMagia() const
{
    return magia;
}

QString *Scontro::getDifesa() const
{
    return difesa;
}

QString *Scontro::getScienza() const
{
    return scienza;
}

QString *Scontro::getValoreSpeciale2() const
{
    return valoreSpeciale2;
}

QLabel *Scontro::getFotoAvatar1() const
{
    return fotoAvatar1;
}

QLabel *Scontro::getFotoAvatar2() const
{
    return fotoAvatar2;
}


