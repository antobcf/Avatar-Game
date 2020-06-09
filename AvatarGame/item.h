#ifndef ITEM_H
#define ITEM_H

#include "elencoavatar.h"

#include <QListWidget>
#include <QScrollBar>

class item : public QListWidget
{
    Q_OBJECT
private:
    QWidget* parent;
public:
    item(QWidget* = nullptr);
    void inserisciAvatar(Avatar*);
    ElencoAvatar* itemAttuale() const;
};

#endif // ITEM_H
