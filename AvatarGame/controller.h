#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "modello.h"
#include "menu.h"
#include "avatarhome.h"
#include "creaavatar.h"
#include "listaavatar.h"
#include "modificaavatar.h"
#include "scontro.h"
#include "finescontro.h"
#include "elencoavatar.h" //prova


#include <QWidget>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QFileDialog>
#include <QIcon>
#include <QFile>

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
    FineScontro* vistaFineScontro;
    Modello* modello;
    QString destinazione;
    void setAvatarGameStyle();

public:
    Controller(Modello *, QWidget *parent = nullptr);
    ~Controller();
    Modello *getModello();
public slots:
    void mostraHome();
    void mostraCrea();
    void mostraLista();
    void mostraScontro();
    void mostraFineScontro();
    void infoPopHome();
    void infoPopLista();
    void inserisciAvatar();
    void modificaAvatar();
    void scontroTraAvatar();
    void rimuoviAvatar();
    void ricercaAvatar();
    void caricaDb();
    void carica();
    void salva();
    void scontro();

    //void ordinaMedia();
    //void ordinaNome();

signals:

};

#endif // CONTROLLER_H
