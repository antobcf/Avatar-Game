#ifndef GERARCHIA_H
#define GERARCHIA_H

#include <iostream>
#include "container.h"

class Avatar { //classe base astratta e polimorfa
private:
    std::string nome;
    std::string descrizione;
    unsigned int livello;
    unsigned int exp;
    unsigned int forza;
    unsigned int magia;
    unsigned int difesa;
    unsigned int scienza;
    double media;
    std::string terreno;
    bool sesso; //se true maschio, altrimenti femmina
    std::string percorsoImmagine;

public:
    virtual ~Avatar() = default;
    //o metto tutti a zero o i valori di default tipo sesso va messo alla fine
    Avatar(std::string n="0", std::string ds="0", unsigned int lvl=1, unsigned int e=0,  unsigned int f=0, unsigned int m=0, unsigned int d=0, unsigned int s=0, double med=0, std::string t="0", bool sx = true, std::string p="0"): nome(n), descrizione(ds), livello(lvl), exp(e),  forza(f), magia(m), difesa(d), scienza(s), media(med), terreno(t), sesso(sx), percorsoImmagine(p) {}
    //GET
    virtual std::string getTerrNon() const = 0;
    virtual std::string getTipo() const = 0;
    unsigned int getLiv() const;
    bool getSesso() const;
    unsigned int getExp() const;
    std::string getNome() const;
    std::string getDescrizione() const;
    unsigned int getForza() const;
    unsigned int getMagia() const;
    unsigned int getDifesa() const;
    unsigned int getScienza() const;
    double getMedia() const;
    std::string getTerreno() const;
    std::string getPercorsoImmagine() const;

    //SET
    void setNome(std::string);
    void setDescrizione(std::string);
    void setLvl(unsigned int);
    void setSesso(bool);
    void setExp(unsigned int);
    void setForza(int);
    void setMagia(int);
    void setDifesa(int);
    void setScienza(int);
    void setMedia(double);
    void setTerreno(std::string);
    void setPercorsoImmagine(std::string);
    //OPERATORI
    virtual bool operator==(const Avatar&) const;

    virtual std::string datiAvatar();
};

class Terrestre: public Avatar {
private:
    bool spada;
    bool anello;
    bool scudo;
    bool libro;
public:
    Terrestre(std::string n="0", std::string ds="0", unsigned int lvl=1, unsigned int e=0,  unsigned int f=0, unsigned int m=0, unsigned int d=0, unsigned int s=0, double med=0, std::string t="0", bool sx = true, std::string p="0", bool sp = false, bool a = false, bool sc = false, bool lib = false): Avatar(n,ds,lvl,e,f,m,d,s,med,t,sx,p), spada(sp), anello(a), scudo(sc), libro(lib) {}
    //GET
    virtual std::string getTerrNon() const override;

    bool getSpada() const;
    bool getAnello() const;
    bool getScu() const;
    bool getLibro() const;

    //SET
    void setSpada(bool);
    void setAnello(bool);
    void setScudo(bool);
    void setLibro(bool);

};

class Elfo: public Terrestre {
private:
    double trasparentia;
public:
    Elfo(std::string n="0", std::string ds="0", unsigned int lvl=1, unsigned int e=0,  unsigned int f=0, unsigned int m=0, unsigned int d=0, unsigned int s=0, double med=0, std::string t="0", bool sx = true, std::string p="0", bool sp = false, bool a = false, bool sc = false, bool lib = false, double tr = 0): Terrestre(n,ds,lvl,e,f,m,d,s,med,t,sx,p,sp,a,sc,lib), trasparentia(tr) {}
    double getTrasparentia() const;
    void setTrasparentia(double);
    virtual std::string getTipo() const override;
    virtual bool operator==(const Avatar&) const override;
    virtual std::string datiAvatar() override;
};

class Nano: public Terrestre {
private:
    double corteccia;
public:
    Nano(std::string n="0", std::string ds="0", unsigned int lvl=1, unsigned int e=0,  unsigned int f=0, unsigned int m=0, unsigned int d=0, unsigned int s=0, double med=0, std::string t="0", bool sx = true, std::string p="0", bool sp = false, bool a = false, bool sc = false, bool lib = false, double cor = 0): Terrestre(n,ds,lvl,e,f,m,d,s,med,t,sx,p,sp,a,sc,lib), corteccia(cor) {}
    double getCorteccia() const;
    void setCorteccia(double);
    virtual std::string getTipo() const override;
    virtual bool operator==(const Avatar&) const override;
    virtual std::string datiAvatar() override;
};

class Umano: public Terrestre {
private:
    double ingegnoScientifico;
public:
    Umano(std::string n="0", std::string ds="0", unsigned int lvl=1, unsigned int e=0,  unsigned int f=0, unsigned int m=0, unsigned int d=0, unsigned int s=0, double med=0, std::string t="0", bool sx = true, std::string p="0", bool sp = false, bool a = false, bool sc = false, bool lib = false, double is = 20): Terrestre(n,ds,lvl,e,f,m,d,s,med,t,sx,p,sp,a,sc,lib), ingegnoScientifico(is) {}
    double getIngegno() const;
    void setIngegno(double);
    virtual std::string getTipo() const override;
    virtual bool operator==(const Avatar&) const override;
    virtual std::string datiAvatar() override;
};

class NOTerrestre: public Avatar {
private:
    bool laser;
    bool amuleto;
    bool barriera;
    bool chip;
public:
    NOTerrestre(std::string n="0", std::string ds="0", unsigned int lvl=1, unsigned int e=0,  unsigned int f=0, unsigned int m=0, unsigned int d=0, unsigned int s=0, double med=0, std::string t="0", bool sx = true, std::string p="0", bool las = false, bool am = false, bool ba = false, bool ch = false): Avatar(n,ds,lvl,e,f,m,d,s,med,t,sx,p),  laser(las), amuleto(am), barriera(ba), chip(ch) {}
    //GET
    virtual std::string getTerrNon() const override;
    bool getLaser() const;
    bool getAmuleto() const;
    bool getBar() const;
    bool getChip() const;

    //SET    
    void setLaser(bool);
    void setAmuleto(bool);
    void setBarriera(bool);
    void setChip(bool);

};

class Alieno: public NOTerrestre {
private:
    double ufo;
public:
    Alieno(std::string n="0", std::string ds="0", unsigned int lvl=1, unsigned int e=0,  unsigned int f=0, unsigned int m=0, unsigned int d=0, unsigned int s=0, double med=0, std::string t="0", bool sx = true, std::string p="0", bool las = false, bool am = false, bool ba = false, bool ch = false, double ufo = 30): NOTerrestre(n,ds,lvl,e,f,m,d,s,med,t,sx,p,las,am,ba,ch), ufo(ufo) {}
    double getUfo() const;
    void setUfo(double);
    virtual std::string getTipo() const override;
    virtual bool operator==(const Avatar&) const override;
    virtual std::string datiAvatar() override;
};

class Mostro: public NOTerrestre {
private:
    double portaDemoniaca;
public:
    Mostro(std::string n="0", std::string ds="0", unsigned int lvl=1, unsigned int e=0,  unsigned int f=0, unsigned int m=0, unsigned int d=0, unsigned int s=0, double med=0, std::string t="0", bool sx = true, std::string p="0", bool las = false, bool am = false, bool ba = false, bool ch = false, double pd = 60): NOTerrestre(n,ds,lvl,e,f,m,d,s,med,t,sx,p,las,am,ba,ch), portaDemoniaca(pd) {}
    double getPorta() const;
    void setPorta(double);
    virtual std::string getTipo() const override;
    virtual bool operator==(const Avatar&) const override;
    virtual std::string datiAvatar() override;
};

#endif // GERARCHIA_H
