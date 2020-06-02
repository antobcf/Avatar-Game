#include "listaavatar.h"


ListaAvatar::ListaAvatar(QWidget *parent) :
    formLista(new QFormLayout),
    bottoneHome(new QPushButton("Home", this)),
    scrollLista(new QScrollArea),
    scrollbarLista(new QScrollBar),
    ordinaLista(new QLabel("Ordina per", this)),
    ordinaNome(new QPushButton("Nome", this)),
    ordinaMedia(new QPushButton("Media", this)),
    ordinaLivello(new QPushButton("Livello", this)),
    checkAvatar1(new QCheckBox(this)),
    nomeAvatar1(new QLabel("Gino", this)),
    bottoneDescrizione1(new QPushButton("Info", this)),
    forzaAvatar1(new QLabel("1234", this)),
    magiaAvatar1(new QLabel("134", this)),
    difesaAvatar1(new QLabel("6543", this)),
    scienzaAvatar1(new QLabel("5", this)),
    forzaAvatar2(new QLabel("1234", this)),
    magiaAvatar2(new QLabel("134", this)),
    difesaAvatar2(new QLabel("6543", this)),
    scienzaAvatar2(new QLabel("5", this)),
    forzaAvatar3(new QLabel("1234", this)),
    magiaAvatar3(new QLabel("134", this)),
    difesaAvatar3(new QLabel("6543", this)),
    scienzaAvatar3(new QLabel("5", this)),
    checkAvatar2(new QCheckBox(this)),
    nomeAvatar2(new QLabel("Giangiorgio", this)),
    bottoneDescrizione2(new QPushButton("Info", this)),
    checkAvatar3(new QCheckBox(this)),
    nomeAvatar3(new QLabel("Pierangelo", this)),
    bottoneDescrizione3(new QPushButton("Info", this)),
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

    /*checkAvatar4(new QCheckBox(this)),
    checkAvatar5(new QCheckBox(this)),
    checkAvatar6(new QCheckBox(this)),
    checkAvatar7(new QCheckBox(this)),
    checkAvatar8(new QCheckBox(this)),
    checkAvatar9(new QCheckBox(this)),
    checkAvatar10(new QCheckBox(this)),
    checkAvatar11(new QCheckBox(this)),
    checkAvatar12(new QCheckBox(this)),
    checkAvatar13(new QCheckBox(this)),
    checkAvatar14(new QCheckBox(this)),
    checkAvatar15(new QCheckBox(this)),
    checkAvatar16(new QCheckBox(this)),
    checkAvatar17(new QCheckBox(this)),
    checkAvatar18(new QCheckBox(this)),
    checkAvatar19(new QCheckBox(this)),
    checkAvatar20(new QCheckBox(this))*/
{
    QHBoxLayout* layoutListaAvatar = new QHBoxLayout(this);
    QVBoxLayout* layoutSelezioneAvatar = new QVBoxLayout();
    QVBoxLayout* layoutDx = new QVBoxLayout();
    QHBoxLayout* layoutOrdina = new QHBoxLayout();
    QVBoxLayout* layoutOrdinaNome = new QVBoxLayout();
    QVBoxLayout* layoutOrdinaMedia = new QVBoxLayout();
    QVBoxLayout* layoutOrdinaLivello = new QVBoxLayout();
    QHBoxLayout* layoutCheckBox = new QHBoxLayout();
    QVBoxLayout* layoutincolonnamento = new QVBoxLayout();
    QHBoxLayout* layoutBoxAvatar1 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar2 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar3 = new QHBoxLayout();

    /*QHBoxLayout* layoutBoxAvatar4 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar5 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar6 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar7 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar8 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar9 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar10 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar11 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar12 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar13 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar14 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar15 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar16 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar17 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar18 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar19 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar20 = new QHBoxLayout();*/

    layoutListaAvatar->addLayout(layoutSelezioneAvatar);
    layoutListaAvatar->addLayout(layoutDx);
    layoutDx->addLayout(formLista);
    layoutDx->addLayout(layoutCheckBox);

    layoutOrdina->addWidget(ordinaLista);
    layoutOrdina->addWidget(ordinaNome);
    layoutOrdina->addWidget(ordinaMedia);
    layoutOrdina->addWidget(ordinaLivello);

    scrollLista->setLayout(layoutincolonnamento);
    scrollLista->addScrollBarWidget(scrollbarLista, (Qt::Orientation::Vertical, Qt::AlignRight));

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

    layoutSelezioneAvatar->addWidget(bottoneHome);
    layoutSelezioneAvatar->addLayout(layoutOrdina);
    layoutSelezioneAvatar->addWidget(scrollLista);
    layoutCheckBox->addWidget(tipoElfo);
    layoutCheckBox->addWidget(tipoNano);
    layoutCheckBox->addWidget(tipoUmano);
    layoutCheckBox->addWidget(tipoAlieno);
    layoutCheckBox->addWidget(tipoMostro);
    layoutDx->addWidget(bottoneModifica);
    layoutDx->addWidget(bottoneRimuovi);
    layoutDx->addWidget(bottoneRimuoviTutto);
    layoutDx->addWidget(bottoneAvvioGioco);

    formLista->addRow("Cerca:", cercaNome);

    /*layoutincolonnamento->addLayout(layoutBoxAvatar4);
    layoutBoxAvatar4->addWidget(checkAvatar4);

    layoutincolonnamento->addLayout(layoutBoxAvatar5);
    layoutBoxAvatar5->addWidget(checkAvatar5);

    layoutincolonnamento->addLayout(layoutBoxAvatar6);
    layoutBoxAvatar6->addWidget(checkAvatar6);

    layoutincolonnamento->addLayout(layoutBoxAvatar7);
    layoutBoxAvatar7->addWidget(checkAvatar7);

    layoutincolonnamento->addLayout(layoutBoxAvatar8);
    layoutBoxAvatar8->addWidget(checkAvatar8);

    layoutincolonnamento->addLayout(layoutBoxAvatar9);
    layoutBoxAvatar9->addWidget(checkAvatar9);

    layoutincolonnamento->addLayout(layoutBoxAvatar10);
    layoutBoxAvatar10->addWidget(checkAvatar10);

    layoutincolonnamento->addLayout(layoutBoxAvatar11);
    layoutBoxAvatar11->addWidget(checkAvatar11);

    layoutincolonnamento->addLayout(layoutBoxAvatar12);
    layoutBoxAvatar12->addWidget(checkAvatar12);

    layoutincolonnamento->addLayout(layoutBoxAvatar13);
    layoutBoxAvatar13->addWidget(checkAvatar13);

    layoutincolonnamento->addLayout(layoutBoxAvatar14);
    layoutBoxAvatar14->addWidget(checkAvatar14);

    layoutincolonnamento->addLayout(layoutBoxAvatar15);
    layoutBoxAvatar15->addWidget(checkAvatar15);

    layoutincolonnamento->addLayout(layoutBoxAvatar16);
    layoutBoxAvatar16->addWidget(checkAvatar16);

    layoutincolonnamento->addLayout(layoutBoxAvatar17);
    layoutBoxAvatar17->addWidget(checkAvatar17);

    layoutincolonnamento->addLayout(layoutBoxAvatar18);
    layoutBoxAvatar18->addWidget(checkAvatar18);

    layoutincolonnamento->addLayout(layoutBoxAvatar19);
    layoutBoxAvatar19->addWidget(checkAvatar19);

    layoutincolonnamento->addLayout(layoutBoxAvatar20);
    layoutBoxAvatar20->addWidget(checkAvatar20);*/
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

