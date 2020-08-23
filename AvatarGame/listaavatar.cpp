#include "listaavatar.h"


ListaAvatar::ListaAvatar(QWidget *parent) :
    bottoneHome(new QPushButton(this)),
    avviaRicerca(new QPushButton("Ricerca",this)),
    azzeraRicerca(new QPushButton("Azzera ricerca",this)),
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
    elenco->setFixedWidth(600);

    connect(elenco,SIGNAL(itemSelectionChanged()), this, SLOT(avatarSelezionato()));
    connect(azzeraRicerca,SIGNAL(clicked()),this,SLOT(resetLista()));

    layoutCheckBox->addWidget(bottoneHome);
    layoutCheckBox->addWidget(tipoElfo);
    layoutCheckBox->addWidget(tipoNano);
    layoutCheckBox->addWidget(tipoUmano);
    layoutCheckBox->addWidget(tipoAlieno);
    layoutCheckBox->addWidget(tipoMostro);
    layoutCheckBox->addWidget(cercaNome);
    cercaNome->setFixedHeight(30);
    cercaNome->setPlaceholderText("Nome");
    layoutCheckBox->addWidget(avviaRicerca);
    layoutCheckBox->addWidget(azzeraRicerca);
    layoutDx->addWidget(bottoneModifica, 0, Qt::AlignCenter);
    layoutDx->addWidget(bottoneRimuovi, 0, Qt::AlignCenter);
    layoutDx->addWidget(bottoneAvvioGioco, 0, Qt::AlignCenter);
    layoutDx->addLayout(layoutBottom);
    layoutBottom->addWidget(bottoneInfoLista, 0, Qt::AlignRight);

    const QSize sizeB = QSize(120,60);
    bottoneModifica->setFixedSize(sizeB);
    bottoneRimuovi->setFixedSize(sizeB);
    bottoneAvvioGioco->setFixedSize(sizeB);
    avviaRicerca->setFixedSize(90,30);
    azzeraRicerca->setFixedSize(120,30);
    bottoneHome->setFixedHeight(30);
    bottoneInfoLista->setFixedSize(30,30);
    bottoneInfoLista->setObjectName("info");

    bottoneHome->setIcon(QIcon(":/Risorse/Immagini Avatar/home.png"));
    bottoneHome->setIconSize(QSize(30, 30));
    bottoneHome->setFixedSize(40,40);

    cercaNome->setMaxLength(12);
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

QPushButton *ListaAvatar::getAzzeraRicerca() const
{
    return azzeraRicerca;
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


