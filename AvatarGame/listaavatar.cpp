#include "listaavatar.h"


ListaAvatar::ListaAvatar(QWidget *parent) :
    formLista(new QFormLayout),
    bottoneHome(new QPushButton("Home", this)),
    boxLista(new QGroupBox("Scegli il tuo avatar", this)),
    nomeAvatar1(new QLabel("Gino", this)),
    checkAvatar1(new QCheckBox(this)),
    bottoneDescrizione1(new QPushButton("Storia1", this)),
    /*nomeAvatar2(new QLabel("GianGiorgio", this)),
    checkAvatar2(new QCheckBox(this)),*/
    bottoneModifica(new QPushButton("Modifica", this)),
    bottoneRimuovi(new QPushButton("Rimuovi", this)),
    bottoneRimuoviTutto(new QPushButton("Rimuovi tutto", this)),
    bottoneAvvioGioco(new QPushButton("Gioca", this)),
    tipoElfo(new QCheckBox("Elfo", this)),
    tipoNano(new QCheckBox("Nano", this)),
    tipoUmano(new QCheckBox("Umano", this)),
    tipoAlieno(new QCheckBox("Alieno", this)),
    tipoMostro(new QCheckBox("Mostro", this)),
    cercaNome(new QLineEdit(this))
{
    QHBoxLayout* layoutScelta = new QHBoxLayout(this);
    QVBoxLayout* layoutLista = new QVBoxLayout();
    QVBoxLayout* layoutDx = new QVBoxLayout();
    QHBoxLayout* layoutCheckBox = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar1 = new QHBoxLayout();
    //QHBoxLayout* layoutBoxAvatar2 = new QHBoxLayout();

    layoutScelta->addLayout(layoutLista);
    layoutScelta->addLayout(layoutDx);
    layoutDx->addLayout(formLista);
    layoutDx->addLayout(layoutCheckBox);
    boxLista->setLayout(layoutBoxAvatar1);
    layoutBoxAvatar1->addWidget(checkAvatar1);
    layoutBoxAvatar1->addWidget(nomeAvatar1);
    layoutBoxAvatar1->addWidget(bottoneDescrizione1);
    /*boxLista->setLayout(layoutBoxAvatar2);
    layoutBoxAvatar2->addWidget(checkAvatar2);
    layoutBoxAvatar2->addWidget(nomeAvatar2);*/
    layoutLista->addWidget(bottoneHome);
    layoutLista->addWidget(boxLista);
    layoutCheckBox->addWidget((tipoElfo));
    layoutCheckBox->addWidget((tipoNano));
    layoutCheckBox->addWidget((tipoUmano));
    layoutCheckBox->addWidget((tipoAlieno));
    layoutCheckBox->addWidget((tipoMostro));
    layoutDx->addWidget((bottoneModifica));
    layoutDx->addWidget((bottoneRimuovi));
    layoutDx->addWidget((bottoneRimuoviTutto));
    layoutDx->addWidget((bottoneAvvioGioco));

    formLista->addRow("Cerca:", cercaNome);
}

QFormLayout *ListaAvatar::getFormLista() const
{
    return formLista;
}

QPushButton *ListaAvatar::getBottoneHome() const
{
    return bottoneHome;
}

QLineEdit *ListaAvatar::getCercaNome() const
{
    return cercaNome;
}
