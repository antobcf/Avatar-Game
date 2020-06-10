#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include "gerarchia.h"

template <class T>
class Container {
private:
    class nodo;
    class smartP {
        public:
            nodo* ptr;
            smartP(nodo* p=0); //agisce da convertitore da nodo* a smartP e funziona anche da costruttore senza argomenti
            smartP(const smartP&);
            ~smartP();
            smartP& operator=(const smartP&);
            nodo& operator*() const;
            nodo* operator->() const;
            bool operator==(const smartP&) const;
            bool operator!=(const smartP&) const;
    };

    class nodo{
    public:
        T info;
        smartP prev, next;
        nodo();
        nodo(const T&, const smartP&, const smartP&); //vanno gli & su smartP?
        int riferimenti;
    };
    smartP primo;
    smartP ultimo;

public:
    class iteratore {
    private:
        smartP* punt; //forse ci va *
        bool pte; //vero se past the end
    public:
        iteratore();
        iteratore(smartP* = nullptr, bool = false);
        iteratore(const iteratore&);
        T operator*();
        T operator->();
        bool operator==(const iteratore&) const;
        bool operator!=(const iteratore&) const;
        iteratore& operator++();
        iteratore& operator--();
    };

    class iteratoreConst {
    private:
        const smartP* punt; //forse ci va *
        bool pte; //vero se past the end
    public:
        iteratoreConst();
        iteratoreConst(const smartP* = nullptr, bool = false);
        iteratoreConst(const iteratoreConst&);
        const T operator*() const;
        const T operator->() const;
        bool operator==(const iteratoreConst&) const;
        bool operator!=(const iteratoreConst&) const;
        iteratoreConst& operator++();
        iteratoreConst& operator--();

    };

    //METODI CONTAINER
    Container(): primo(nullptr), ultimo(nullptr) {} //la definizione sicuro non va qui, il nullptr serve?
    bool isEmpty() const;//controlla se il container è vuoto
    void inserisci(const T&);//metodo per l'inserimento alla fine della lista di un nuovo elemento
    void remove(); //rimuove valore in testa
    void removeElement(const T&);
    void clean(); //svuota contenitore
    T ricercaNome(T); //servirebbe per cercare un personaggio, ma non riesco a farlo andare
    iteratore begin();
    iteratore end();
    int counter();
    iteratoreConst beginC() const;
    iteratoreConst endC() const;
};

//METODI SMARTP
template  <class T>
Container<T>::smartP::smartP(nodo* p):ptr(p) { //COSTRUTTORE
    if(ptr) ptr->riferimenti++;
}

template  <class T>
Container<T>::smartP::smartP(const smartP& s):ptr(s.ptr) { //COSTRUTTORE DI COPIA
    if(ptr) ptr->riferimenti++;
}

template <class T>
Container<T>::smartP::~smartP() { //DISTRUTTORE
    if(ptr) {
        ptr->riferimenti--;
        if(ptr->riferimenti==0)
            delete ptr;
    }
}

template  <class T>
typename Container<T>::smartP& Container<T>::smartP::operator=(const smartP& s) { //ASSEGNAZIONE
    if(this!=&s) {
        nodo* t=ptr;
        ptr=s.ptr;
        if(ptr) ptr->riferimenti++;
        if(t) {
            t->riferimenti--;
            if(t->riferimenti==0) delete t;
        }
    }
    return *this;
}

template  <class T>
typename Container<T>::nodo& Container<T>::smartP::operator*() const {
    return *ptr;
}

template  <class T>
typename Container<T>::nodo* Container<T>::smartP::operator->() const {
    return ptr;
}

template  <class T>
bool Container<T>::smartP::operator==(const smartP& s) const {
    return ptr==s.ptr;
}

template  <class T>
bool Container<T>::smartP::operator!=(const smartP& s) const {
    return ptr!=s.ptr;
}

//METODI CONTAINER
template <class T>
bool Container<T>::isEmpty() const {
    if(!(primo.ptr)) {
        //std::cout<<"prova"<<std::endl;
        return true;
    }
    return false;
}

template <class T>
void Container<T>::inserisci(const T& p) {
    ultimo = new nodo (p, ultimo, nullptr);

    if(primo == nullptr) {
        primo = ultimo;
    } else {
        (ultimo->prev)->next = ultimo;
    }
}

template <class T>
T Container<T>::ricercaNome(T n) {
    smartP scorri=primo;
    smartP salva=nullptr;
    while(scorri->next!=nullptr){
        if((scorri.ptr)->info==n){
            salva=scorri;
            std::cout<<"BELLAAAA"<<std::endl;
            return (salva.ptr)->info;
        }
        scorri=scorri->next;
    }
    //qua ci va un eccezione nel caso in cui non esista il nodo che cerchiamo mi sa
    return nullptr;
}

template <class T>
int Container<T>::counter() {
    int i=0;
    if(primo.ptr==nullptr) {
        std::cout<<i<<std::endl;
    } else {
        smartP scorri=primo;
        if(scorri.ptr->info!=nullptr) {
            i++;
            while(scorri.ptr->next!=nullptr) {
                scorri=scorri.ptr->next;
                i++;
            }
            std::cout<<i<<std::endl;
        }
    }
    return i;
}

template <class T>
void Container<T>::remove() {
    if(isEmpty()) {
        std::cout<<"è già vuoto"<<std::endl;
        return;
//da mettere eccezione
    }
    //std::cout<<"arrivo qua?"<<std::endl;
    if((primo.ptr)->next==nullptr) {
        primo=nullptr;
        //std::cout<<"arrivo qua? if"<<std::endl;
    } else {
        //std::cout<<"arrivo qua? else"<<std::endl;
        smartP p=primo.ptr;
        //std::cout<<"arrivo qua? else2"<<std::endl;
        primo=(primo.ptr)->next;
        //std::cout<<"arrivo qua? else3"<<std::endl;
        //delete p.ptr;
        //std::cout<<"arrivo qua? else4"<<std::endl;
    }
}

template<class T>
void Container<T>::removeElement(const T& s) {
    smartP p = primo; //lo uso per scorrere la lista
    smartP z; //punta al nodo precedente
    smartP prec = nullptr; //è il nodo precedente a p
    smartP o = primo; //mi salvo il valore originale in prima posizione
    primo = 0;

    while(p!=0 && !((p.ptr)->info==s)) {
        z = new nodo((p.ptr)->info, (p.ptr)->prev, (p.ptr)->next);

        if((p.ptr)->prev == nullptr) //se ci troviamo nella posizione iniziale, allora q diventa primo perchè p diventerà il valore successivo
            primo = z;
        else {
            (prec.ptr)->next=z; //se non siamo nella posizione iniziale, facciamo i dovuti spostamenti
            (z.ptr)->prev=prec;
        }

        prec = z;
        p = p.ptr->next;
    }

    if(p==0) { //cioè se scorro tutta la lista e p mi va a puntare al next di ultimo e quindi non ho trovato s nella lista
        primo = o;
    } else {
        if(prec==nullptr && (p.ptr)->next == nullptr)
            primo = ultimo = nullptr; //c'era sono un elemento nella lista e noi lo abbiamo tolto
        else {
            if(prec == nullptr) {//l'oggettto era nella prima posizione
                primo=p.ptr->next;
                (primo.ptr)->next = nullptr; //il primo non lo facciamo puntare a nulla cosi si rimuove dalla lista
            } else {
                if(p->next!=nullptr) {
                    (prec.ptr)->next=p.ptr->next;
                    p.ptr->next->prev=prec;
                } else {
                    (prec.ptr)->next= p.ptr->next; //cioe nullptr
                    ultimo = prec;
                }
            }

        }
    }

}

template <class T>
void Container<T>::clean() {
    if(isEmpty()) {
        std::cout<<"è già vuoto"<<std::endl;
        return;
        //eccezione
    }
    //std::cout<<"arrivo qua?"<<std::endl;
    while(!isEmpty()) {
        remove();
    }
}

//METODI NODO
template <class T>
Container<T>::nodo::nodo():riferimenti(0) {}

template <class T>
Container<T>::nodo::nodo(const T& t, const smartP& p, const smartP& n) : info(t), prev(p), next(n), riferimenti(0) {}

//METODI ITERATORE
template <class T>
Container<T>::iteratore::iteratore(): punt(nullptr), pte(false) {}

template <class T>
Container<T>::iteratore::iteratore(smartP* elemento, bool pastTheEnd): punt(elemento), pte(pastTheEnd) {}

template <class T>
Container<T>::iteratore::iteratore(const iteratore& it) : punt(it.punt), pte(it.pte) {}

template <class T>
T Container<T>::iteratore::operator*() {
    return (**punt).info;
}

template <class T>
T Container<T>::iteratore::operator->() {
    return &(**punt).info;
}

template <class T>
bool Container<T>::iteratore::operator==(const iteratore& elemento) const {
    return punt == elemento.punt;
}

template <class T>
bool Container<T>::iteratore::operator!=(const iteratore& elemento) const {
    return punt != elemento.punt;
}

template <class T>
typename Container<T>::iteratore& Container<T>::iteratore::operator++(){
    if(!pte && punt != 0) {
        if((*punt)->next == nullptr) {
            punt = &((*punt)->next);
            pte = true;
        } else
            punt = &((*punt)->next);
    }
    return *this;
}

template <class T>
typename Container<T>::iteratore& Container<T>::iteratore::operator--(){
    if(!pte && punt != 0) {
        if((*punt)->prev == nullptr) {
            punt = &((*punt)->prev);
            pte = false;
        } else
            punt = &((*punt)->prev);
    }
    return *this;
}

template <class T>
typename Container<T>::iteratore Container<T>::begin(){
    if(primo==nullptr) return iteratore(nullptr);
    return iteratore(&primo, false);
}

template <class T>
typename Container<T>::iteratore Container<T>::end(){
    if(ultimo==nullptr) return iteratore(nullptr);
    return iteratore(&(ultimo->next), true);
}


//METODI ITERATORE COSTANTE
template <class T>
Container<T>::iteratoreConst::iteratoreConst(): punt(nullptr), pte(false) {}

template <class T>
Container<T>::iteratoreConst::iteratoreConst(const smartP* elemento, bool pastTheEnd): punt(elemento), pte(pastTheEnd) {}

template <class T>
Container<T>::iteratoreConst::iteratoreConst(const iteratoreConst& cit) : punt(cit.punt), pte(cit.pte) {}

template <class T>
const T Container<T>::iteratoreConst::operator*() const {
    return (**punt).info;
}

template <class T>
const T Container<T>::iteratoreConst::operator->() const {
    return &(**punt).info;
}

template <class T>
bool Container<T>::iteratoreConst::operator==(const iteratoreConst& elemento) const {
    return punt == elemento.punt;
}

template <class T>
bool Container<T>::iteratoreConst::operator!=(const iteratoreConst& elemento) const {
    return punt != elemento.punt;
}

template <class T>
typename Container<T>::iteratoreConst& Container<T>::iteratoreConst::operator++(){
    if(!pte && punt != 0) {
        if((*punt)->next == nullptr) {
            punt = &((*punt)->next);
            pte = true;
        } else
            punt = &((*punt)->next);
    }
    return *this;
}

template <class T>
typename Container<T>::iteratoreConst& Container<T>::iteratoreConst::operator--(){
    if(!pte && punt != 0) {
        if((*punt)->prev == nullptr) {
            punt = &((*punt)->prev);
            pte = false;
        } else
            punt = &((*punt)->prev);
    }
    return *this;
}

template <class T>
typename Container<T>::iteratoreConst Container<T>::beginC() const {
    if(primo==nullptr) return iteratoreConst(nullptr);
    return iteratoreConst(&primo, false);
}

template <class T>
typename Container<T>::iteratoreConst Container<T>::endC() const {
    if(ultimo==nullptr) return iteratoreConst(nullptr);
    return iteratoreConst(&(ultimo->next), true);
}

#endif // CONTAINER_H
