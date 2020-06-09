#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "modello.h"
#include "menu.h"
#include "avatarhome.h"
#include "creaavatar.h"
#include "listaavatar.h"
#include "modificaavatar.h"
#include "scontro.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QFileDialog>

class Controller : public QWidget {
    Q_OBJECT

private:
    QVBoxLayout* layoutPrincipale;
    Menu* menuGenerale;
    AvatarHome* vistaHome;
    CreaAvatar* vistaCrea;
    ListaAvatar* vistaLista;
    ModificaAvatar* vistaModifica;
    Scontro* vistaScontro;
    Modello* modello; //capire a cosa serve
    QString destinazione;

public:
    Controller(Modello *, QWidget *parent = nullptr);
    ~Controller();
    Modello *getModello(); //ci servirà per i metodi di caricamento e salvataggio in Modello


public slots:
    void mostraHome();
    void mostraCrea();
    void mostraLista();
    void mostraModifica();
    void mostraScontro();
    void infoPopHome();
    void infoPopLista();
    void infoPopCrea();
    void inserisciAvatar();
    void modificaAvatar();
    void rimuoviAvatar();
    void ricercaAvatar();
    void caricaDb();
    void carica();
    void salva();


signals:

};

#endif // CONTROLLER_H
