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
    void insertAvatar(Avatar*);
    ElencoAvatar* itemAttuale() const;
    ElencoAvatar* itemCasuale(int) const;
};

#endif // ITEM_H
