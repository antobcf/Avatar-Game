#include "avatarhome.h"

AvatarHome::AvatarHome(QWidget* p):
    parent(p),
    bottoneCrea(new QPushButton("Crea Avatar", p)),
    bottoneGioca(new QPushButton("Gioca", p)),
    bottoneInfo(new QPushButton("?", p)),
    titoloGioco(new QLabel(p))
{    
    const QSize dimBottone = QSize(120,60);
    bottoneCrea->setFixedSize(dimBottone);
    bottoneGioca->setFixedSize(dimBottone);
    bottoneInfo->setFixedSize(30,30);
    titoloGioco->setAlignment(Qt::AlignCenter);

    QVBoxLayout* layoutHome = new QVBoxLayout(this);
    QHBoxLayout* layoutBottoniPrincipali = new QHBoxLayout();

    layoutHome->addWidget(titoloGioco, 0, Qt::AlignCenter);
    layoutBottoniPrincipali->addWidget(bottoneGioca);
    layoutBottoniPrincipali->addWidget(bottoneCrea);
    layoutHome->addLayout(layoutBottoniPrincipali);
    layoutHome->addWidget(bottoneInfo, 0, Qt::AlignRight);
    bottoneInfo->setObjectName("info");

    QPixmap *y=new QPixmap(":/Risorse/Immagini Avatar/logo_titolo");
    QPixmap y1(y->scaled(400,400, Qt::IgnoreAspectRatio));
    titoloGioco->setPixmap(y1);
}

QPushButton *AvatarHome::getBottoneCrea() const
{
    return bottoneCrea;
}

QPushButton *AvatarHome::getBottoneGioca() const
{
    return bottoneGioca;
}

QPushButton *AvatarHome::getBottoneInfo() const
{
   return bottoneInfo;
}
