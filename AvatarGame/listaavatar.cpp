#include "listaavatar.h"


ListaAvatar::ListaAvatar(QWidget *parent) :
    formCrea(new QFormLayout),
    bottoneHome(new QPushButton("Home", this)),
    boxLista(new QGroupBox("Scegli il tuo avatar", this)),
    bottoneModifica(new QPushButton("Modifica", this)),
    bottoneRimuovi(new QPushButton("Rimuovi", this)),
    bottoneRimuoviTutto(new QPushButton("Rimuovi tutto", this)),
    tipoElfo(new QCheckBox("Elfo", this)),
    tipoNano(new QCheckBox("Nano", this)),
    tipoUmano(new QCheckBox("Umano", this)),
    tipoAlieno(new QCheckBox("Alieno", this)),
    tipoMostro(new QCheckBox("Mostro", this)),
    cercaNome(new QLineEdit(this))
{
    QHBoxLayout* layoutCrea = new QHBoxLayout(this);
    QVBoxLayout* layoutLista = new QVBoxLayout();
    QVBoxLayout* layoutDx = new QVBoxLayout();
    QHBoxLayout* layoutCheckBox = new QHBoxLayout();

    layoutCrea->addLayout(layoutLista);
    layoutCrea->addLayout(layoutDx);
    layoutLista->addWidget(bottoneHome);
    layoutLista->addWidget(boxLista);
    layoutDx->addLayout(formCrea);
    layoutCheckBox->addWidget((tipoElfo));
    layoutCheckBox->addWidget((tipoNano));
    layoutCheckBox->addWidget((tipoUmano));
    layoutCheckBox->addWidget((tipoAlieno));
    layoutCheckBox->addWidget((tipoMostro));
    layoutDx->addLayout(layoutCheckBox);
    layoutDx->addWidget((bottoneModifica));
    layoutDx->addWidget((bottoneRimuovi));
    layoutDx->addWidget((bottoneRimuoviTutto));

    formCrea->addRow("Nome:", cercaNome);
}

QFormLayout *ListaAvatar::getFormCrea() const
{
    return formCrea;
}

QPushButton *ListaAvatar::getBottoneHome() const
{
    return bottoneHome;
}

QLineEdit *ListaAvatar::getCercaNome() const
{
    return cercaNome;
}
