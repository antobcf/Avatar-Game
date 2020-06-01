#include "scontro.h"

Scontro::Scontro(QWidget *parent) :
    bottoneCambioAvatar(new QPushButton("Cambia Avatar", this)),
    bottoneHomeScontro(new QPushButton("Home", this)),
    vs(new QLabel("VS", this)),
    nomeAvatarSx(new QLabel("Avatar1", this)),
    nomeAvatarDx(new QLabel("Avatar2", this)),
    terreno(new QLabel("Terreno", this)),
    bottoneCombatti(new QPushButton("Combatti", this)),
    mediaSx(new QLabel("Media: ", this)),
    mediaDx(new QLabel("Media: ", this))
{
    QHBoxLayout* layoutScontro = new QHBoxLayout(this);
    QVBoxLayout* layoutScontroSx = new QVBoxLayout();
    QVBoxLayout* layoutScontroCentrale = new QVBoxLayout();
    QVBoxLayout* layoutScontroDx = new QVBoxLayout();

    layoutScontro->addLayout(layoutScontroSx);
    layoutScontro->addLayout(layoutScontroCentrale);
    layoutScontro->addLayout(layoutScontroDx);

    layoutScontroSx->addWidget(nomeAvatarSx);
    layoutScontroSx->addWidget(mediaSx);
    layoutScontroCentrale->addWidget(vs);
    layoutScontroCentrale->addWidget(terreno);
    layoutScontroCentrale->addWidget(bottoneHomeScontro);
    layoutScontroCentrale->addWidget(bottoneCambioAvatar);
    layoutScontroCentrale->addWidget(bottoneCombatti);
    layoutScontroDx->addWidget(nomeAvatarDx);
    layoutScontroDx->addWidget(mediaDx);
}

QPushButton *Scontro::getBottoneCombatti() const
{
    return bottoneCombatti;
}

QPushButton *Scontro::getBottoneCambioAvatar() const
{
    return bottoneCambioAvatar;
}

QPushButton *Scontro::getBottoneHomeScontro() const
{
    return bottoneHomeScontro;
}
