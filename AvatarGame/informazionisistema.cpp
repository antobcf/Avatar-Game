#include "informazionisistema.h"

InformazioniSistema::InformazioniSistema(QWidget *parent):
    testoSistema(new QLabel(this))
{
    QVBoxLayout* layoutSistema = new QVBoxLayout(this);

    layoutSistema->addWidget(testoSistema);
    testoSistema->setText("Stai usando la versione 1.0.0 del gioco");
}
