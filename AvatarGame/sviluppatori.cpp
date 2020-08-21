#include "sviluppatori.h"

Sviluppatori::Sviluppatori(QWidget *parent) :
    immagineSviluppatori(new QLabel(this)),
    testoSviluppatori(new QLabel(this))
{
    QVBoxLayout* layoutSviluppatori = new QVBoxLayout(this);

    QPixmap *y=new QPixmap(":/Risorse/Immagini Avatar/logo_titolo");
    QPixmap y1(y->scaled(400,400, Qt::IgnoreAspectRatio));
    immagineSviluppatori->setPixmap(y1);

    layoutSviluppatori->addWidget(testoSviluppatori);
    testoSviluppatori->setText("Gli sviluppatori di questo gioco sono Antonio Belculfinè e Luca Modica.");
}
