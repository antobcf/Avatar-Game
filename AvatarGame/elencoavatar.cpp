#include "elencoavatar.h"

ElencoAvatar::ElencoAvatar(QWidget * p, Avatar * i) : parent(p), item(i)
{
    aggiorna();
}

Avatar *ElencoAvatar::getItem() const
{
    return item;
}

void ElencoAvatar::aggiorna()
{
    QString percorso = QString::fromStdString(item->getPercorsoImmagine());
    QPixmap p(percorso);
    setIcon(p.scaled(500,500,Qt::AspectRatioMode::KeepAspectRatio));
    setText(QString::fromStdString(item->datiAvatar()));
}
