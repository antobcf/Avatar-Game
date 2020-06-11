#include "listaavatar.h"


ListaAvatar::ListaAvatar(QWidget *parent) :
    bottoneHome(new QPushButton("Home", this)),
    ordinaLista(new QLabel("Ordina per", this)),
    ordinaNome(new QPushButton("Nome", this)),
    ordinaLivello(new QPushButton("Livello", this)),
    ordinaMedia(new QPushButton("Media", this)),

    formLista(new QFormLayout),
    cercaNome(new QLineEdit(this)),
    tipoElfo(new QCheckBox("Elfo", this)),
    tipoNano(new QCheckBox("Nano", this)),
    tipoUmano(new QCheckBox("Umano", this)),
    tipoAlieno(new QCheckBox("Alieno", this)),
    tipoMostro(new QCheckBox("Mostro", this)),
    bottoneModifica(new QPushButton("Modifica", this)),
    bottoneRimuovi(new QPushButton("Rimuovi", this)),
    bottoneRimuoviTutto(new QPushButton("Rimuovi tutto", this)),
    bottoneAvvioGioco(new QPushButton("Gioca", this)),
    bottoneInfoLista(new QPushButton("?", this)),

    elenco(new item(this))

{
    QHBoxLayout* layoutListaAvatar = new QHBoxLayout(this);
    QVBoxLayout* layoutSelezioneAvatar = new QVBoxLayout();
    QVBoxLayout* layoutDx = new QVBoxLayout();
    QHBoxLayout* layoutOrdina = new QHBoxLayout();
    QHBoxLayout* layoutCheckBox = new QHBoxLayout();
    QVBoxLayout* layoutincolonnamento = new QVBoxLayout();

    layoutListaAvatar->addLayout(layoutSelezioneAvatar);
    layoutListaAvatar->addLayout(layoutDx);

    layoutSelezioneAvatar->addWidget(bottoneHome);
    layoutSelezioneAvatar->addLayout(layoutOrdina);
    layoutOrdina->addWidget(ordinaLista);
    layoutOrdina->addWidget(ordinaNome);
    layoutOrdina->addWidget(ordinaMedia);
    layoutOrdina->addWidget(ordinaLivello);

    //scroll area
    layoutSelezioneAvatar->addLayout(layoutincolonnamento);
    layoutincolonnamento->addWidget(elenco);
    elenco->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    elenco->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(elenco,SIGNAL(itemSelectionChanged()),this,SLOT(avatarSelezionato()));

    formLista->addRow("Cerca:", cercaNome);
    layoutDx->addLayout(formLista);
    layoutDx->addLayout(layoutCheckBox);
    layoutCheckBox->addWidget(tipoElfo);
    layoutCheckBox->addWidget(tipoNano);
    layoutCheckBox->addWidget(tipoUmano);
    layoutCheckBox->addWidget(tipoAlieno);
    layoutCheckBox->addWidget(tipoMostro);
    layoutDx->addWidget(bottoneModifica);
    layoutDx->addWidget(bottoneRimuovi);
    layoutDx->addWidget(bottoneRimuoviTutto);
    layoutDx->addWidget(bottoneAvvioGioco);
    layoutDx->addWidget(bottoneInfoLista, 0, Qt::AlignRight);
    bottoneInfoLista->setFixedSize(25,25);

    bottoneModifica->setEnabled(false);
    bottoneRimuovi->setEnabled(false);
    bottoneAvvioGioco->setEnabled(false);
}

QPushButton *ListaAvatar::getBottoneHome() const
{
    return bottoneHome;
}

QLabel *ListaAvatar::getOrdinaLista() const
{
    return ordinaLista;
}

QPushButton *ListaAvatar::getOrdinaNome() const
{
    return ordinaNome;
}

QPushButton *ListaAvatar::getOrdinaLivello() const
{
    return ordinaLivello;
}

QPushButton *ListaAvatar::getOrdinaMedia() const
{
    return ordinaMedia;
}

QFormLayout *ListaAvatar::getFormLista() const
{
    return formLista;
}

QLineEdit *ListaAvatar::getCercaNome() const
{
    return cercaNome;
}

QCheckBox *ListaAvatar::getTipoElfo() const
{
    return tipoElfo;
}

QCheckBox *ListaAvatar::getTipoNano() const
{
    return tipoNano;
}

QCheckBox *ListaAvatar::getTipoUmano() const
{
    return tipoUmano;
}

QCheckBox *ListaAvatar::getTipoAlieno() const
{
    return tipoAlieno;
}

QCheckBox *ListaAvatar::getTipoMostro() const
{
    return tipoMostro;
}

QPushButton *ListaAvatar::getBottoneModifica() const
{
   return bottoneModifica;
}

QPushButton *ListaAvatar::getBottoneRimuovi() const
{
   return bottoneRimuovi;
}

QPushButton *ListaAvatar::getBottoneRimuoviTutto() const
{
   return bottoneRimuoviTutto;
}

QPushButton *ListaAvatar::getBottoneGioca() const
{
    return bottoneAvvioGioco;
}

QPushButton *ListaAvatar::getBottoneInfoLista() const
{
    return bottoneInfoLista;
}

item *ListaAvatar::getElenco() const
{
    return elenco;
}

void ListaAvatar::avatarSelezionato() const
{
    bottoneModifica->setEnabled(true);
    bottoneRimuovi->setEnabled(true);
    bottoneAvvioGioco->setEnabled(true);
}
