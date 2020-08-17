#include "listaavatar.h"


ListaAvatar::ListaAvatar(QWidget *parent) :
    bottoneHome(new QPushButton("Home", this)),
    avviaRicerca(new QPushButton("Ricerca",this)),
    pulisciFiltri(new QPushButton("Pulisci filtri",this)), //filtri?
    cercaNome(new QLineEdit(this)),
    tipoElfo(new QCheckBox("Elfo", this)),
    tipoNano(new QCheckBox("Nano", this)),
    tipoUmano(new QCheckBox("Umano", this)),
    tipoAlieno(new QCheckBox("Alieno", this)),
    tipoMostro(new QCheckBox("Mostro", this)),
    bottoneModifica(new QPushButton("Modifica", this)),
    bottoneRimuovi(new QPushButton("Rimuovi", this)),
    bottoneAvvioGioco(new QPushButton("Gioca", this)),
    bottoneInfoLista(new QPushButton("?", this)),

    elenco(new item(this))

{
    QVBoxLayout* layoutListaAvatar = new QVBoxLayout(this);
    QVBoxLayout* layoutSx = new QVBoxLayout();
    QVBoxLayout* layoutDx = new QVBoxLayout();
    QHBoxLayout* layoutSelezioneAvatar = new QHBoxLayout();
    QHBoxLayout* layoutCheckBox = new QHBoxLayout();
    QVBoxLayout* layoutincolonnamento = new QVBoxLayout();
    QHBoxLayout* layoutBottom = new QHBoxLayout();

    layoutListaAvatar->addLayout(layoutCheckBox);
    layoutListaAvatar->addLayout(layoutSelezioneAvatar);
    layoutSelezioneAvatar->addLayout(layoutSx);
    layoutSelezioneAvatar->addLayout(layoutDx);

    //scroll area
    layoutSx->addLayout(layoutincolonnamento);
    layoutincolonnamento->addWidget(elenco);
    elenco->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    elenco->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    elenco->setFixedWidth(500);

    connect(pulisciFiltri,SIGNAL(clicked()),this,SLOT(resetRicerca()));

    layoutCheckBox->addWidget(tipoElfo);
    layoutCheckBox->addWidget(tipoNano);
    layoutCheckBox->addWidget(tipoUmano);
    layoutCheckBox->addWidget(tipoAlieno);
    layoutCheckBox->addWidget(tipoMostro);
    layoutCheckBox->addWidget(cercaNome);
    cercaNome->setFixedHeight(30);
    cercaNome->setPlaceholderText("Nome");
    layoutCheckBox->addWidget(avviaRicerca);
    layoutCheckBox->addWidget(pulisciFiltri);
    layoutDx->addWidget(bottoneModifica, 0, Qt::AlignCenter);
    layoutDx->addWidget(bottoneRimuovi, 0, Qt::AlignCenter);
    layoutDx->addWidget(bottoneAvvioGioco, 0, Qt::AlignCenter);
    layoutDx->addLayout(layoutBottom);
    layoutBottom->addWidget(bottoneHome);
    layoutBottom->addWidget(bottoneInfoLista, 0, Qt::AlignRight);

    const QSize sizeB = QSize(120,60);
    const QSize sizeC = QSize(120,30);
    bottoneModifica->setFixedSize(sizeB);
    bottoneRimuovi->setFixedSize(sizeB);
    bottoneAvvioGioco->setFixedSize(sizeB);
    avviaRicerca->setFixedSize(sizeC);
    pulisciFiltri->setFixedSize(sizeC);
    bottoneInfoLista->setFixedSize(30,30);
    bottoneInfoLista->setStyleSheet(
            "border: 0.5px solid black;"
            "border-radius: 15px;"
            );
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

QLineEdit *ListaAvatar::getCercaNome() const
{
    return cercaNome;
}

QPushButton *ListaAvatar::getAvviaRicerca() const
{
    return avviaRicerca;
}

QPushButton *ListaAvatar::getPulisciFiltri() const
{
    return pulisciFiltri;
}

QPushButton *ListaAvatar::getBottoneModifica() const
{
   return bottoneModifica;
}

QPushButton *ListaAvatar::getBottoneRimuovi() const
{
   return bottoneRimuovi;
}

QPushButton *ListaAvatar::getBottoneGioca() const
{
    return bottoneAvvioGioco;
}

QPushButton *ListaAvatar::getBottoneHome() const
{
    return bottoneHome;
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

void ListaAvatar::resetLista() const
{
    bottoneModifica->setEnabled(false);
    bottoneRimuovi->setEnabled(false);
    bottoneAvvioGioco->setEnabled(false);
    cercaNome->clear();
    tipoElfo->setChecked(false);
    tipoNano->setChecked(false);
    tipoUmano->setChecked(false);
    tipoAlieno->setChecked(false);
    tipoMostro->setChecked(false);
}

void ListaAvatar::resetRicerca() const
{
    cercaNome->clear();
}
