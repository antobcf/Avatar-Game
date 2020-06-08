#include "scontro.h"

Scontro::Scontro(QWidget *parent) :
    nomeAvatarSx(new QLabel("Avatar1", this)),
    mediaSx(new QLabel("Media: ", this)),
    vs(new QLabel("VS", this)),
    terreno(new QLabel("Terreno", this)),
    bottoneHomeScontro(new QPushButton("Home", this)),
    bottoneCambioAvatar(new QPushButton("Cambia Avatar", this)),
    bottoneCombatti(new QPushButton("Combatti", this)),
    nomeAvatarDx(new QLabel("Avatar2", this)),
    mediaDx(new QLabel("Media: ", this))
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

    layoutTastiNavigazione->addWidget(bottoneHomeScontro);
    layoutTastiNavigazione->addWidget(bottoneCambioAvatar);

    const QSize dimBottoneHomeCambio = QSize(100,30);
    bottoneCambioAvatar->setFixedSize(dimBottoneHomeCambio);
    bottoneHomeScontro->setFixedSize(dimBottoneHomeCambio);
    bottoneCombatti->setFixedSize(130,60);

    layoutScontroSx->addWidget(nomeAvatarSx, 0, Qt::AlignCenter);
    layoutScontroSx->addWidget(mediaSx, 0, Qt::AlignCenter);
    layoutScontroCentrale->addWidget(vs, 0, Qt::AlignCenter);
    layoutScontroCentrale->addWidget(terreno, 0, Qt::AlignCenter);

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
