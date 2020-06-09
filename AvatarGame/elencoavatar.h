#ifndef ELENCOAVATAR_H
#define ELENCOAVATAR_H

#include "gerarchia.h"

#include <QObject>
#include <QListWidgetItem>

class elencoAvatar : public QListWidgetItem
{
    Q_OBJECT
private:
    QWidget* parent;
    Avatar* item;

public:
    elencoAvatar(QWidget*, Avatar* = nullptr);
    Avatar* getItem() const;
    void aggiorna();
};

#endif // ELENCOAVATAR_H
