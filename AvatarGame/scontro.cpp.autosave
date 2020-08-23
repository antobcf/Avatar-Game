#include "scontro.h"
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
    vs(new QLabel(this)),
    terreno(new QLabel(this)),
    bottoneHomeScontro(new QPushButton(this)),
    bottoneCambioAvatar(new QPushButton("Cambia avatar", this)),
    bottoneCambioAvversario(new QPushButton("Cambia avversario", this)),
    bottoneCombatti(new QPushButton("Combatti", this)),
    nomeAvatarDx(new QLabel("Avatar2", this)),
    powerupDx(new QLabel("PowerUp:", this)),
    powerup1selezionatoDx(new QLabel(this)),
    powerup2selezionatoDx(new QLabel(this)),
    powerup3selezionatoDx(new QLabel(this)),
    powerup4selezionatoDx(new QLabel(this)),
    titoloMediaDx(new QLabel("Media:", this)),
    mediaDx(new QLabel(this)),
    fotoAvatar1(new QLabel(this)),
    fotoAvatar2(new QLabel(this))
{
    QVBoxLayout* layoutScontro = new QVBoxLayout(this);
    QHBoxLayout* layoutTastiNavigazione = new QHBoxLayout();
    QHBoxLayout* layoutCombattimento = new QHBoxLayout();
    QVBoxLayout* layoutScontroSx = new QVBoxLayout();
    QVBoxLayout* layoutScontroCentrale = new QVBoxLayout();
    QVBoxLayout* layoutScontroDx = new QVBoxLayout();

    layoutScontro->addLayout(layoutTastiNavigazione);
    layoutScontro->addLayout(layoutCombattimento);
    layoutCombattimento->addLayout(layoutScontroSx);
    layoutCombattimento->addLayout(layoutScontroCentrale);
    layoutCombattimento->addLayout(layoutScontroDx);

    layoutTastiNavigazione->addWidget(bottoneCambioAvatar);
    layoutTastiNavigazione->addWidget(bottoneHomeScontro);
    layoutTastiNavigazione->addWidget(bottoneCambioAvversario);
    const QSize dimBottoneScontro = QSize(130,40);
    bottoneCambioAvatar->setFixedSize(dimBottoneScontro);
    bottoneHomeScontro->setFixedSize(40,40);
    bottoneHomeScontro->setIcon(QIcon(":/Risorse/Immagini Avatar/home.png"));
    bottoneHomeScontro->setIconSize(QSize(30,30));
    bottoneCambioAvversario->setFixedSize(dimBottoneScontro);
    bottoneCombatti->setFixedSize(130,60);

    layoutScontroSx->addWidget(fotoAvatar1, 0, Qt::AlignCenter);
    layoutScontroSx->addWidget(nomeAvatarSx, 0, Qt::AlignCenter);
    layoutScontroSx->addWidget(powerupSx, 0, Qt::AlignCenter);
    layoutScontroSx->addWidget(powerup1selezionatoSx, 0, Qt::AlignCenter);
    layoutScontroSx->addWidget(powerup2selezionatoSx, 0, Qt::AlignCenter);
    layoutScontroSx->addWidget(powerup3selezionatoSx, 0, Qt::AlignCenter);
    layoutScontroSx->addWidget(powerup4selezionatoSx, 0, Qt::AlignCenter);
    layoutScontroSx->addWidget(titoloMediaSx, 0, Qt::AlignCenter);
    layoutScontroSx->addWidget(mediaSx, 0, Qt::AlignCenter);

    layoutScontroCentrale->addWidget(vs, 0, Qt::AlignCenter);
    layoutScontroCentrale->addWidget(terreno, 0, Qt::AlignCenter);
    layoutScontroCentrale->addWidget(bottoneCombatti, 0, Qt::AlignCenter);

    layoutScontroDx->addWidget(fotoAvatar2, 0, Qt::AlignCenter);
    layoutScontroDx->addWidget(nomeAvatarDx, 0, Qt::AlignCenter);
    layoutScontroDx->addWidget(powerupDx, 0, Qt::AlignCenter);
    layoutScontroDx->addWidget(powerup1selezionatoDx, 0, Qt::AlignCenter);
    layoutScontroDx->addWidget(powerup2selezionatoDx, 0, Qt::AlignCenter);
    layoutScontroDx->addWidget(powerup3selezionatoDx, 0, Qt::AlignCenter);
    layoutScontroDx->addWidget(powerup4selezionatoDx, 0, Qt::AlignCenter);
    layoutScontroDx->addWidget(titoloMediaDx, 0, Qt::AlignCenter);
    layoutScontroDx->addWidget(mediaDx, 0, Qt::AlignCenter);

    powerupSx->setObjectName("grassetto");
    titoloMediaSx->setObjectName("grassetto");
    powerupDx->setObjectName("grassetto");
    titoloMediaDx->setObjectName("grassetto");

    QPixmap *p=new QPixmap(":/Risorse/Immagini Avatar/vs");
    QPixmap p1(p->scaled(85,85, Qt::IgnoreAspectRatio));
    vs->setPixmap(p1);
}

QLabel *Scontro::getNomeAvatarSx() const
{
    return nomeAvatarSx;
}

QLabel *Scontro::getPowerupSx() const
{
    return powerupSx;
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

QLabel *Scontro::getTitoloMediaSx() const
{
    return titoloMediaSx;
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

QLabel *Scontro::getPowerupDx() const
{
    return powerupDx;
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

QLabel *Scontro::getTitoloMediaDx() const
{
    return titoloMediaSx;
}

QLabel *Scontro::getMediaDx() const
{
    return mediaDx;
}

QLabel *Scontro::getFotoAvatar1() const
{
    return fotoAvatar1;
}

QLabel *Scontro::getFotoAvatar2() const
{
    return fotoAvatar2;
}
