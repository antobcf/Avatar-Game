#include "modello.h"

Modello::Modello()
{

}

void Modello::salva()
{

}

void Modello::carica()
{

}

void Modello::rimuovi()
{

}

Container<Avatar *> Modello::getLista() const
{
    return lista;
}

Container<Avatar*>::iteratore Modello::begin()
{
    return lista.begin(); //mi trasforma in automatico la freccia in punto
}

Container<Avatar*>::iteratore Modello::end()
{
    return lista.end();
}

Container<Avatar*>::iteratoreConst Modello::begin() const
{

}

Container<Avatar*>::iteratoreConst Modello::end() const
{

}
