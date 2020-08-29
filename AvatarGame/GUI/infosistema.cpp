#include "GUI\infosistema.h"

InfoSistema::InfoSistema(QWidget *parent) :
    testoSistema(new QLabel(this))
{
    QVBoxLayout* layoutSistema = new QVBoxLayout(this);

    layoutSistema->addWidget(testoSistema);
    testoSistema->setText("Interfaccia grafica utente di Avatar Game.\nVersione 1.0.0.\nCopyright © 2020 Università degli studi di Padova. Tutti i diritti riservati.");
}
