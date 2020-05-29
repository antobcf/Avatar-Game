#include "listaavatar.h"


ListaAvatar::ListaAvatar(QWidget *parent) :
    bottoneHome(new QPushButton("Home", this)),
    boxLista(new QGroupBox("Scegli il tuo avatar", this)),
    bottoneModifica(new QPushButton("Modifica", this)),
    bottoneRimuovi(new QPushButton("Rimuovi", this)),
    bottoneRimuoviTutto(new QPushButton("Rimuovi tutto", this)),
    tipoElfo(new QCheckBox("Elfo", this)),
    tipoNano(new QCheckBox("Nano", this)),
    tipoUmano(new QCheckBox("Umano", this)),
    tipoAlieno(new QCheckBox("Alieno", this)),
    tipoMostro(new QCheckBox("Mostro", this))
{
    QHBoxLayout* layoutCrea = new QHBoxLayout(this);
    QVBoxLayout* layoutLista = new QVBoxLayout();
    QVBoxLayout* layoutDx = new QVBoxLayout();

    layoutCrea->addLayout(layoutLista);
    layoutCrea->addLayout(layoutDx);
    layoutLista->addWidget(bottoneHome);
    layoutLista->addWidget(boxLista);
    layoutDx->addWidget((tipoElfo));
    layoutDx->addWidget((bottoneModifica));
    layoutDx->addWidget((bottoneRimuovi));
    layoutDx->addWidget((bottoneRimuoviTutto));
}

QPushButton *ListaAvatar::getBottoneHome() const
{
    return bottoneHome;
}
