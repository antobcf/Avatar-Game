#include "finescontro.h"

FineScontro::FineScontro(QWidget *parent) :
    esito(new QLabel("Hai vinto/Hai perso", this)),
    guadagno(new QLabel("Hai guadagnato.......", this)),
    ritornoHome(new QPushButton("Ritorna alla Home", this)),
    cambioAvatarFineScontro(new QPushButton("Cambia Avatar", this)),
    continua(new QPushButton("Continua", this))
{
    QVBoxLayout* layoutFineScontro = new QVBoxLayout(this);

    layoutFineScontro->addWidget(esito, 0, Qt::AlignCenter);
    layoutFineScontro->addWidget(guadagno, 0, Qt::AlignCenter);
    layoutFineScontro->addWidget(ritornoHome);
    layoutFineScontro->addWidget(cambioAvatarFineScontro);
    layoutFineScontro->addWidget(continua);
}

QPushButton *FineScontro::getHomeFine() const
{
    return ritornoHome;
}

QPushButton *FineScontro::getCambioAvatarFine() const
{
    return cambioAvatarFineScontro;
}

QPushButton *FineScontro::getContinuaFine() const
{
    return continua;
}

