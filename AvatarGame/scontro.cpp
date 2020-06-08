#include "scontro.h"

Scontro::Scontro(QWidget *parent) :
    nomeAvatarSx(new QLabel("Avatar1", this)),
    formPowerupSx(new QFormLayout),
    powerup1selezionatoSx(new QLabel("powerup1", this)),
    powerup2selezionatoSx(new QLabel("powerup2", this)),
    formMediaSx(new QFormLayout),
    mediaSx(new QLabel("771", this)),

    vs(new QLabel("VS", this)),
    terreno(new QLabel("Terreno", this)),
    bottoneHomeScontro(new QPushButton("Home", this)),
    bottoneCambioAvatar(new QPushButton("Avatar casuale", this)),
    bottoneCombatti(new QPushButton("Combatti", this)),

    nomeAvatarDx(new QLabel("Avatar2", this)),
    formPowerupDx(new QFormLayout),
    powerup1selezionatoDx(new QLabel("powerup1", this)),
    powerup2selezionatoDx(new QLabel("powerup2", this)),
    formMediaDx(new QFormLayout),
    mediaDx(new QLabel("772", this))
{
    QVBoxLayout* layoutScontro = new QVBoxLayout(this);
    QHBoxLayout* layoutTastiNavigazione = new QHBoxLayout();
    QHBoxLayout* layoutCombattimento = new QHBoxLayout();
    QVBoxLayout* layoutScontroSx = new QVBoxLayout();
    QVBoxLayout* layoutPowerupSx = new QVBoxLayout();
    QVBoxLayout* layoutScontroCentrale = new QVBoxLayout();
    QVBoxLayout* layoutScontroDx = new QVBoxLayout();
    QVBoxLayout* layoutPowerupDx = new QVBoxLayout();

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
    layoutScontroSx->addLayout(formPowerupSx);
    layoutPowerupSx->addWidget(powerup1selezionatoSx);
    layoutPowerupSx->addWidget(powerup2selezionatoSx);
    formPowerupSx->addRow("Powerup: ", layoutPowerupSx);
    layoutScontroSx->addLayout(formMediaSx);
    formMediaSx->addRow("Media: ", mediaSx);

    layoutScontroCentrale->addWidget(vs, 0, Qt::AlignCenter);
    layoutScontroCentrale->addWidget(terreno, 0, Qt::AlignCenter);
    layoutScontroCentrale->addWidget(bottoneCombatti, 0, Qt::AlignCenter);

    layoutScontroDx->addWidget(nomeAvatarDx, 0, Qt::AlignCenter);
    layoutScontroDx->addLayout(formPowerupDx);
    layoutPowerupDx->addWidget(powerup1selezionatoDx);
    layoutPowerupDx->addWidget(powerup2selezionatoDx);
    formPowerupDx->addRow("Powerup: ", layoutPowerupDx);
    layoutScontroDx->addLayout(formMediaDx);
    formMediaDx->addRow("Media: ", mediaDx);
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
