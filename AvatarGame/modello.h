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
    void salva();
    void carica();
    void rimuovi(Avatar*);
    Container<Avatar*> getLista() const;
    Container<Avatar*>::iteratore begin();
    Container<Avatar*>::iteratore end();
    Container<Avatar*>::iteratoreConst begin() const;
    Container<Avatar*>::iteratoreConst end() const;

};

#endif // MODELLO_H
