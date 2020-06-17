#include "sviluppatori.h"

Sviluppatori::Sviluppatori(QWidget *parent) :
    testoSviluppatori(new QLabel("Gli sviluppatori di questo gioco sono Antonio Belculfinè e Luca Modica", this))
{
    QHBoxLayout* layoutSviluppatori = new QHBoxLayout(this);

    layoutSviluppatori->addWidget(testoSviluppatori);
}
