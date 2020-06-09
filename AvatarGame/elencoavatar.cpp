#include "elencoavatar.h"

elencoAvatar::elencoAvatar(QWidget * p, Avatar * i) : parent(p), item(i)
{
    aggiorna();
}

Avatar *elencoAvatar::getItem() const
{
    return item;
}

void elencoAvatar::aggiorna()
{
    //manca la foto qui
    setText(QString::fromStdString(item->datiAvatar()));
}
