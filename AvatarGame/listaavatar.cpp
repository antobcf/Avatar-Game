#include "listaavatar.h"


ListaAvatar::ListaAvatar(QWidget *parent) :
    formLista(new QFormLayout),
    bottoneHome(new QPushButton("Home", this)),
    boxLista(new QGroupBox("Scegli il tuo avatar", this)),
    checkAvatar1(new QCheckBox(this)),
    nomeAvatar1(new QLabel("Gino", this)),
    bottoneDescrizione1(new QPushButton("Storia1", this)),
    forzaAvatar1(new QLabel("1234", this)),
    magiaAvatar1(new QLabel("134", this)),
    difesaAvatar1(new QLabel("6543", this)),
    scienzaAvatar1(new QLabel("5", this)),
    checkAvatar2(new QCheckBox(this)),
    nomeAvatar2(new QLabel("Giangiorgio", this)),
    bottoneDescrizione2(new QPushButton("Storia2", this)),
    checkAvatar3(new QCheckBox(this)),
    nomeAvatar3(new QLabel("Pierangelo", this)),
    bottoneDescrizione3(new QPushButton("Storia3", this)),
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
    QHBoxLayout* layoutListaAvatar = new QHBoxLayout(this);
    QVBoxLayout* layoutSelezioneAvatar = new QVBoxLayout();
    QVBoxLayout* layoutDx = new QVBoxLayout();
    QHBoxLayout* layoutCheckBox = new QHBoxLayout();
    QVBoxLayout* layoutincolonnamento = new QVBoxLayout();
    QHBoxLayout* layoutBoxAvatar1 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar2 = new QHBoxLayout();
    QHBoxLayout* layoutBoxAvatar3 = new QHBoxLayout();

    layoutListaAvatar->addLayout(layoutSelezioneAvatar);
    layoutListaAvatar->addLayout(layoutDx);
    layoutDx->addLayout(formLista);
    layoutDx->addLayout(layoutCheckBox);

    boxLista->setLayout(layoutincolonnamento);

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

    layoutincolonnamento->addLayout(layoutBoxAvatar3);
    layoutBoxAvatar3->addWidget(checkAvatar3);
    layoutBoxAvatar3->addWidget(nomeAvatar3);
    layoutBoxAvatar3->addWidget(bottoneDescrizione3);

    layoutSelezioneAvatar->addWidget(bottoneHome);
    layoutSelezioneAvatar->addWidget(boxLista);
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
