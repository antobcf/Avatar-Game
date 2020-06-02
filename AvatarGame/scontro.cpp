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

    const QSize dimBottoneHomeCambio = QSize(100,30);
    bottoneCambioAvatar->setFixedSize(dimBottoneHomeCambio);
    bottoneHomeScontro->setFixedSize(dimBottoneHomeCambio);
    bottoneCombatti->setFixedSize(130,60);

    layoutScontroSx->addWidget(nomeAvatarSx, 0, Qt::AlignCenter);
    layoutScontroSx->addWidget(mediaSx, 0, Qt::AlignCenter);
    layoutScontroCentrale->addWidget(vs, 0, Qt::AlignCenter);
    layoutScontroCentrale->addWidget(terreno, 0, Qt::AlignCenter);
    layoutScontroCentrale->addWidget(bottoneHomeScontro, 0, Qt::AlignCenter);
    layoutScontroCentrale->addWidget(bottoneCambioAvatar, 0, Qt::AlignCenter);
    layoutScontroCentrale->addWidget(bottoneCombatti, 0, Qt::AlignCenter);
    layoutScontroDx->addWidget(nomeAvatarDx, 0, Qt::AlignCenter);
    layoutScontroDx->addWidget(mediaDx, 0, Qt::AlignCenter);
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
