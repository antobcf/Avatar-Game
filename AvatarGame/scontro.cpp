#include "scontro.h"

Scontro::Scontro(QWidget *parent) :
    vs(new QLabel("VS", this)),
    nomeAvatarSx(new QLabel("Avatar1", this)),
    nomeAvatarDx(new QLabel("Avatar2", this)),
    terreno(new QLabel("Terreno", this)),
    bottoneCombatti(new QPushButton("Combatti", this))
{
    QHBoxLayout* layoutScontro = new QHBoxLayout(this);
    QVBoxLayout* layoutScontroSx = new QVBoxLayout(this);
    QVBoxLayout* layoutScontroCentrale = new QVBoxLayout(this);
    QVBoxLayout* layoutScontroDx = new QVBoxLayout(this);

    layoutScontro->addLayout(layoutScontroSx);
    layoutScontro->addLayout(layoutScontroCentrale);
    layoutScontro->addLayout(layoutScontroDx);

    layoutScontroSx->addWidget(nomeAvatarSx);
    layoutScontroCentrale->addWidget(vs);
    layoutScontroCentrale->addWidget(terreno);
    layoutScontroCentrale->addWidget(bottoneCombatti);
    layoutScontroDx->addWidget(nomeAvatarDx);
}
