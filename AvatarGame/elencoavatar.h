#ifndef ELENCOAVATAR_H
#define ELENCOAVATAR_H

#include "gerarchia.h"

#include <QListWidgetItem>

class ElencoAvatar : public QListWidgetItem
{
private:
    QWidget* parent;
    Avatar* item;

public:
    ElencoAvatar(QWidget*, Avatar* = nullptr);
    Avatar* getItem() const;
    void aggiorna();
};

#endif // ELENCOAVATAR_H
