#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "modello.h"
#include "menu.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QMenuBar>

class Controller : public QWidget {
    Q_OBJECT

private:
    QVBoxLayout* layoutPrincipale;
    Modello* modello; //capire a cosa serve
    Menu* menuGenerale;

public:
    Controller(Modello *, QWidget *parent = nullptr);
    ~Controller();
    Modello *getModello(); //ci servirà per i metodi di caricamento e salvataggio in Modello

public slots:



signals:

};

#endif // CONTROLLER_H
