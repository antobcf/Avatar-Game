#ifndef AVATARHOME_H
#define AVATARHOME_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

class AvatarHome : public QWidget
{
    Q_OBJECT
private:
    QWidget* parent;
    QPushButton* bottoneCrea;
    QPushButton* bottoneGioca;
    QPushButton* bottoneInfo;
    QLabel* titoloGioco;

public:
    AvatarHome(QWidget* =nullptr);
    QPushButton* getBottoneCrea() const;
    QPushButton* getBottoneGioca() const;
    QPushButton* getBottoneInfo() const;

public slots:


};
#endif // AVATARHOME_H
