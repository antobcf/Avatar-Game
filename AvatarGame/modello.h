#ifndef MODELLO_H
#define MODELLO_H

#include "container.h"
#include "gerarchia.h"

class Modello
{
private:
    Container<Avatar*> lista;
public:
    Modello();
    ~Modello();

    Container<Avatar*> getLista() const;
};

#endif // MODELLO_H
