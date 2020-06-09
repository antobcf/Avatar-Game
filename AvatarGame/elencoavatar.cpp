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
    //manca la foto qui
    setText(QString::fromStdString(item->datiAvatar()));
}
