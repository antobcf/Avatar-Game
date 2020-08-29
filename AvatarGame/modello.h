#ifndef MODELLO_H
#define MODELLO_H

#include "Gerarchia/container.h"
#include "Gerarchia/gerarchia.h"

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
    void salvare();
    void caricare();
    void rimuovi(Avatar* =nullptr);
    void setPercorso(std::string);
    Container<Avatar*>* getLista() const;
    Container<Avatar*>::iteratore begin();
    Container<Avatar*>::iteratore end();
    Container<Avatar*>::iteratoreConst beginConst() const;
    Container<Avatar*>::iteratoreConst endConst() const;

};

#endif // MODELLO_H
