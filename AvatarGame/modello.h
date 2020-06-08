#ifndef MODELLO_H
#define MODELLO_H

#include "container.h"
#include "gerarchia.h"

#include <QSaveFile>
#include <QFile>
#include <iostream>
#include <QXmlStreamWriter>
#include <QDebug>

class Modello
{
private:
    Container<Avatar*>* lista;
    bool salvato;
    std::string percorso;
public:
    Modello(std::string = ":/Risorse");
    ~Modello();
    void salva();
    void carica();
    void rimuovi(Avatar* =nullptr);
    void setPercorso(std::string);
    Container<Avatar*>* getLista() const;
    Container<Avatar*>::iteratore begin();
    Container<Avatar*>::iteratore end();
    Container<Avatar*>::iteratoreConst begin() const;
    Container<Avatar*>::iteratoreConst end() const;

};

#endif // MODELLO_H
