#include "listaavatar.h"


ListaAvatar::ListaAvatar(QWidget *parent) :
    bottoneHome(new QPushButton("Home", this)),
    ordinaLista(new QLabel("Ordina per", this)),
    ordinaNome(new QPushButton("Nome", this)),
    ordinaLivello(new QPushButton("Livello", this)),
    ordinaMedia(new QPushButton("Media", this)),
    scrollLista(new QScrollArea),
    scrollbarLista(new QScrollBar),
    checkAvatar1(new QCheckBox(this)),
    nomeAvatar1(new QLabel("Gino", this)),
    bottoneDescrizione1(new QPushButton("Info", this)),
    forzaAvatar1(new QLabel("1234", this)),
    magiaAvatar1(new QLabel("134", this)),
    difesaAvatar1(new QLabel("6543", this)),
    scienzaAvatar1(new QLabel("5", this)),
    checkAvatar2(new QCheckBox(this)),
    nomeAvatar2(new QLabel("Giangiorgio", this)),
    bottoneDescrizione2(new QPushButton("Info", this)),
    forzaAvatar2(new QLabel("1234", this)),
    magiaAvatar2(new QLabel("134", this)),
    difesaAvatar2(new QLabel("6543", this)),
    scienzaAvatar2(new QLabel("5", this)),
    checkAvatar3(new QCheckBox(this)),
    nomeAvatar3(new QLabel("Pierangelo", this)),
    bottoneDescrizione3(new QPushButton("Info", this)),
    forzaAvatar3(new QLabel("1234", this)),
    magiaAvatar3(new QLabel("134", this)),
    difesaAvatar3(new QLabel("6543", this)),
    scienzaAvatar3(new QLabel("5", this)),


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
    QHBoxLayout* layoutBoxAvatar1 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar2 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar3 = new QHBoxLayout();

    layoutListaAvatar->addLayout(layoutSelezioneAvatar);
    layoutListaAvatar->addLayout(layoutDx);

    layoutSelezioneAvatar->addWidget(bottoneHome);
    layoutSelezioneAvatar->addLayout(layoutOrdina);
    layoutOrdina->addWidget(ordinaLista);
    layoutOrdina->addWidget(ordinaNome);
    layoutOrdina->addWidget(ordinaMedia);
    layoutOrdina->addWidget(ordinaLivello);
    layoutSelezioneAvatar->addWidget(scrollLista);
    scrollLista->setLayout(layoutincolonnamento);
    //scrollLista->addScrollBarWidget(scrollbarLista, (Qt::Orientation::Vertical, Qt::AlignRight));

    layoutincolonnamento->addLayout(layoutBoxAvatar1);
    layoutBoxAvatar1->addWidget(checkAvatar1);
    layoutBoxAvatar1->addWidget(nomeAvatar1);
    layoutBoxAvatar1->addWidget(bottoneDescrizione1);
    layoutBoxAvatar1->addWidget(forzaAvatar1);
    layoutBoxAvatar1->addWidget(magiaAvatar1);
    layoutBoxAvatar1->addWidget(difesaAvatar1);
    layoutBoxAvatar1->addWidget(scienzaAvatar1);

    layoutincolonnamento->addLayout(layoutBoxAvatar2);
    layoutBoxAvatar2->addWidget(checkAvatar2);
    layoutBoxAvatar2->addWidget(nomeAvatar2);
    layoutBoxAvatar2->addWidget(bottoneDescrizione2);
    layoutBoxAvatar2->addWidget(forzaAvatar2);
    layoutBoxAvatar2->addWidget(magiaAvatar2);
    layoutBoxAvatar2->addWidget(difesaAvatar2);
    layoutBoxAvatar2->addWidget(scienzaAvatar2);

    layoutincolonnamento->addLayout(layoutBoxAvatar3);
    layoutBoxAvatar3->addWidget(checkAvatar3);
    layoutBoxAvatar3->addWidget(nomeAvatar3);
    layoutBoxAvatar3->addWidget(bottoneDescrizione3);
    layoutBoxAvatar3->addWidget(forzaAvatar3);
    layoutBoxAvatar3->addWidget(magiaAvatar3);
    layoutBoxAvatar3->addWidget(difesaAvatar3);
    layoutBoxAvatar3->addWidget(scienzaAvatar3);

    //scroll area
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
