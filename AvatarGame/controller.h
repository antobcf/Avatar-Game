#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "modello.h"
#include "menu.h"
#include "avatarhome.h"
#include "creaavatar.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QMenuBar>

class Controller : public QWidget {
    Q_OBJECT

private:
    QVBoxLayout* layoutPrincipale;
    Menu* menuGenerale;
    AvatarHome* vistaHome;
    CreaAvatar* vistaCrea;
    Modello* modello; //capire a cosa serve

public:
    Controller(Modello *, QWidget *parent = nullptr);
    ~Controller();
    Modello *getModello(); //ci servirà per i metodi di caricamento e salvataggio in Modello


public slots:
    void mostraHome();
    void mostraCrea();



signals:

};

#endif // CONTROLLER_H
