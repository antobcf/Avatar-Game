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

    //bottoneModifica->setEnabled(false);
    bottoneRimuovi->setEnabled(false);
    //bottoneAvvioGioco->setEnabled(false);
}

QFormLayout *ListaAvatar::getFormLista() const
{
    return formLista;
}

QPushButton *ListaAvatar::getBottoneHome() const
{
    return bottoneHome;
}

QPushButton *ListaAvatar::getBottoneModifica() const
{
   return bottoneModifica;
}

QPushButton *ListaAvatar::getBottoneGioca() const
{
    return bottoneAvvioGioco;
}

QLineEdit *ListaAvatar::getCercaNome() const
{
    return cercaNome;
}

QPushButton *ListaAvatar::getBottoneInfoLista() const
{
    return bottoneInfoLista;
}

item *ListaAvatar::getElenco() const
{
    return elenco;
}
