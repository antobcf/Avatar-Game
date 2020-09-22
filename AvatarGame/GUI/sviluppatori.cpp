#include "sviluppatori.h"

Sviluppatori::Sviluppatori(QWidget *parent) : QDialog(parent),
    immagineSviluppatori(new QLabel(this)),
    testoSviluppatori(new QLabel(this))
{
    QVBoxLayout* layoutSviluppatori = new QVBoxLayout(this);

    layoutSviluppatori->addWidget(testoSviluppatori);
    testoSviluppatori->setText("Il seguente software è stato sviluppato da:\n- Antonio Belculfinè\n- Luca Modica");
}
