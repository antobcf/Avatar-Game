#include "listaavatar.h"


ListaAvatar::ListaAvatar(QWidget *parent) :
    bottoneHome(new QPushButton("Home", this)),
    avviaRicerca(new QPushButton("Ricerca",this)),
    formLista(new QFormLayout),
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
    QHBoxLayout* layoutListaAvatar = new QHBoxLayout(this);
    QVBoxLayout* layoutSelezioneAvatar = new QVBoxLayout();
    QVBoxLayout* layoutDx = new QVBoxLayout();
    //QHBoxLayout* layoutOrdina = new QHBoxLayout();
    QHBoxLayout* layoutRicerca = new QHBoxLayout();
    QHBoxLayout* layoutCheckBox = new QHBoxLayout();
    QVBoxLayout* layoutincolonnamento = new QVBoxLayout();
    QHBoxLayout* layoutBottom = new QHBoxLayout();

    layoutListaAvatar->addLayout(layoutSelezioneAvatar);
    layoutListaAvatar->addLayout(layoutDx);

    layoutSelezioneAvatar->addLayout(layoutCheckBox);

    //scroll area
    layoutSelezioneAvatar->addLayout(layoutincolonnamento);
    layoutincolonnamento->addWidget(elenco);
    elenco->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    elenco->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    elenco->setFixedWidth(500);

    connect(elenco,SIGNAL(itemSelectionChanged()),this,SLOT(avatarSelezionato()));

    layoutDx->addLayout(layoutRicerca);
    formLista->addRow(cercaNome);
    layoutRicerca->addLayout(formLista);
    layoutRicerca->addWidget(avviaRicerca);
    layoutCheckBox->addWidget(tipoElfo);
    layoutCheckBox->addWidget(tipoNano);
    layoutCheckBox->addWidget(tipoUmano);
    layoutCheckBox->addWidget(tipoAlieno);
    layoutCheckBox->addWidget(tipoMostro);
    layoutDx->addWidget(bottoneModifica, 0, Qt::AlignCenter);
    layoutDx->addWidget(bottoneRimuovi, 0, Qt::AlignCenter);
    layoutDx->addWidget(bottoneAvvioGioco, 0, Qt::AlignCenter);
    layoutDx->addLayout(layoutBottom);
    layoutBottom->addWidget(bottoneHome);
    layoutBottom->addWidget(bottoneInfoLista);

    const QSize sizeB = QSize(120,60);
    bottoneModifica->setFixedSize(sizeB);
    bottoneRimuovi->setFixedSize(sizeB);
    bottoneAvvioGioco->setFixedSize(sizeB);
    cercaNome->setFixedHeight(30);
    avviaRicerca->setFixedSize(120,30);
    bottoneInfoLista->setFixedSize(25,25);

    cercaNome->setPlaceholderText("Nome");

}

QPushButton *ListaAvatar::getBottoneHome() const
{
    return bottoneHome;
}

QPushButton *ListaAvatar::getAvviaRicerca() const
{
    return avviaRicerca;
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
