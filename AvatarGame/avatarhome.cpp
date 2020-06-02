#include "avatarhome.h"

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

AvatarHome::AvatarHome(QWidget* p):
    QWidget(p),
    bottoneCrea(new QPushButton("Crea Avatar", p)),
    bottoneGioca(new QPushButton("Gioca", p)),
    bottoneInfo(new QPushButton("?", p)),
    titoloGioco(new QLabel("Inserire logo", p))
{    
    const QSize dimBottone = QSize(90,50);
    bottoneCrea->setFixedSize(dimBottone);
    bottoneGioca->setFixedSize(dimBottone);
    bottoneInfo->setFixedSize(25,25);
    titoloGioco->setAlignment(Qt::AlignCenter);


    //setStyleSheet bottoni o tramite fogli di stile

    QVBoxLayout* layoutHome = new QVBoxLayout(this);
    QHBoxLayout* layoutBottoniSopra = new QHBoxLayout();

    layoutHome->addWidget(titoloGioco);
    layoutBottoniSopra->addWidget(bottoneGioca);
    layoutBottoniSopra->addWidget(bottoneCrea);
    layoutHome->addLayout(layoutBottoniSopra);
    layoutHome->addWidget(bottoneInfo, 0, Qt::AlignRight);

}

