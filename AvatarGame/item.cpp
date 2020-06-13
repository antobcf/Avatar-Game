#include "item.h"

item::item(QWidget* p) : parent(p)
{
    //setIconSize(QSize(100,100));
    addScrollBarWidget(new QScrollBar(Qt::Orientation::Vertical, parent), Qt::AlignRight);
}

void item::insertAvatar(Avatar* avatar)
{
    ElencoAvatar* oggetto = new ElencoAvatar(parent, avatar);
    addItem(oggetto);
}


ElencoAvatar *item::itemAttuale() const
{
    return static_cast<ElencoAvatar*>(QListWidget::currentItem());
}
