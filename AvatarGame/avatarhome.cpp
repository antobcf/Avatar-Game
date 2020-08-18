#include "avatarhome.h"

AvatarHome::AvatarHome(QWidget* p):
    parent(p),
    bottoneCrea(new QPushButton("Crea Avatar", p)),
    bottoneGioca(new QPushButton("Gioca", p)),
    bottoneInfo(new QPushButton("?", p)),
    titoloGioco(new QLabel("Inserire logo", p))
{    

    const QSize dimBottone = QSize(120,60);
    bottoneCrea->setFixedSize(dimBottone);
    bottoneGioca->setFixedSize(dimBottone);
    bottoneInfo->setFixedSize(30,30);
    titoloGioco->setAlignment(Qt::AlignCenter);

    QVBoxLayout* layoutHome = new QVBoxLayout(this);
    QHBoxLayout* layoutBottoniSopra = new QHBoxLayout();

    layoutHome->addWidget(titoloGioco);
    layoutBottoniSopra->addWidget(bottoneGioca);
    layoutBottoniSopra->addWidget(bottoneCrea);
    layoutHome->addLayout(layoutBottoniSopra);
    layoutHome->addWidget(bottoneInfo, 0, Qt::AlignRight);
    bottoneInfo->setObjectName("info");
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
