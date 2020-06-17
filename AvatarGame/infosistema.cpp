#include "infosistema.h"

infoSistema::infoSistema(QWidget *parent) :
    testoSistema(new QLabel("Stai usando la versione 1.0.0 del gioco", this))
{
    QHBoxLayout* layoutSistema = new QHBoxLayout(this);

    layoutSistema->addWidget(testoSistema);
}
