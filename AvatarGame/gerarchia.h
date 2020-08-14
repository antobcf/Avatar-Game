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
    unsigned int GetLiv() const;
    bool GetSesso() const;
    unsigned int GetExp() const;
    std::string GetNome() const;
    std::string getDescrizione() const;
    unsigned int getForza() const;
    unsigned int getMagia() const;
    unsigned int getDifesa() const;
    unsigned int getScienza() const;
    double getMedia() const;
    std::string getTerreno() const;
    std::string getPercorsoImmagine() const;

    //SET
    void SetNome(std::string);
    void setDescrizione(std::string);
    void SetLvl(unsigned int);
    void SetSesso(bool);
    void SetExp(unsigned int);
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
    bool scudo;
    bool spada;
    bool anello;
    bool libro;
public:
    Terrestre(std::string n="0", std::string ds="0", unsigned int lvl=1, unsigned int e=0,  unsigned int f=0, unsigned int m=0, unsigned int d=0, unsigned int s=0, double med=0, std::string t="0", bool sx = true, std::string p="0", bool sc = false, bool sp = false, bool a = false, bool lib = false): Avatar(n,ds,lvl,e,f,m,d,s,med,t,sx,p), scudo(sc), spada(sp), anello(a), libro(lib) {}
    //GET
    virtual std::string getTerrNon() const override;
    bool GetScu() const;
    bool GetSpada() const;
    bool GetAnello() const;
    bool GetLibro() const;

    //SET
    void SetScudo(bool);
    void SetSpada(bool);
    void SetAnello(bool);
    void SetLibro(bool);

};

class Elfo: public Terrestre {
private:
    double trasparentia;
public:
    Elfo(std::string n="0", std::string ds="0", unsigned int lvl=1, unsigned int e=0,  unsigned int f=0, unsigned int m=0, unsigned int d=0, unsigned int s=0, double med=0, std::string t="0", bool sx = true, std::string p="0", bool sc = false, bool sp = false, bool a = false, bool lib = false, double tr = 0): Terrestre(n,ds,lvl,e,f,m,d,s,med,t,sx,p,sc,sp,a,lib), trasparentia(tr) {}
    double GetTrasparentia() const;
    void setTrasparentia(double);
    virtual std::string getTipo() const override;
    virtual bool operator==(const Avatar&) const override;
    virtual std::string datiAvatar() override;
};

class Nano: public Terrestre {
private:
    double corteccia;
public:
    Nano(std::string n="0", std::string ds="0", unsigned int lvl=1, unsigned int e=0,  unsigned int f=0, unsigned int m=0, unsigned int d=0, unsigned int s=0, double med=0, std::string t="0", bool sx = true, std::string p="0", bool sc = false, bool sp = false, bool a = false, bool lib = false, double cor = 0): Terrestre(n,ds,lvl,e,f,m,d,s,med,t,sx,p,sc,sp,a,lib), corteccia(cor) {}
    double GetCorteccia() const;
    void setCorteccia(double);
    virtual std::string getTipo() const override;
    virtual bool operator==(const Avatar&) const override;
    virtual std::string datiAvatar() override;
};

class Umano: public Terrestre {
private:
    double ingegnoScientifico;
public:
    Umano(std::string n="0", std::string ds="0", unsigned int lvl=1, unsigned int e=0,  unsigned int f=0, unsigned int m=0, unsigned int d=0, unsigned int s=0, double med=0, std::string t="0", bool sx = true, std::string p="0", bool sc = false, bool sp = false, bool a = false, bool lib = false, double is = 20): Terrestre(n,ds,lvl,e,f,m,d,s,med,t,sx,p,sc,sp,a,lib), ingegnoScientifico(is) {}
    double GetIngegno() const;
    void setIngegno(double);
    virtual std::string getTipo() const override;
    virtual bool operator==(const Avatar&) const override;
    virtual std::string datiAvatar() override;
};

class NOTerrestre: public Avatar {
private:
    bool barriera;
    bool laser;
    bool amuleto;
    bool chip;
public:
    NOTerrestre(std::string n="0", std::string ds="0", unsigned int lvl=1, unsigned int e=0,  unsigned int f=0, unsigned int m=0, unsigned int d=0, unsigned int s=0, double med=0, std::string t="0", bool sx = true, std::string p="0", bool ba = false, bool las = false, bool am = false, bool ch = false): Avatar(n,ds,lvl,e,f,m,d,s,med,t,sx,p), barriera(ba), laser(las), amuleto(am), chip(ch) {}
    //GET
    virtual std::string getTerrNon() const override;
    bool GetBar() const;
    bool GetLaser() const;
    bool GetAmuleto() const;
    bool GetChip() const;

    //SET
    void SetBarriera(bool);
    void SetLaser(bool);
    void SetAmuleto(bool);
    void SetChip(bool);

};

class Alieno: public NOTerrestre {
private:
    double ufo;
public:
    Alieno(std::string n="0", std::string ds="0", unsigned int lvl=1, unsigned int e=0,  unsigned int f=0, unsigned int m=0, unsigned int d=0, unsigned int s=0, double med=0, std::string t="0", bool sx = true, std::string p="0", bool ba = false, bool las = false, bool am = false, bool ch = false, double ufo = 30): NOTerrestre(n,ds,lvl,e,f,m,d,s,med,t,sx,p,ba,las,am,ch), ufo(ufo) {}
    double GetUfo() const;
    void setUfo(double);
    virtual std::string getTipo() const override;
    virtual bool operator==(const Avatar&) const override;
    virtual std::string datiAvatar() override;
};

class Mostro: public NOTerrestre {
private:
    double portaDemoniaca;
public:
    Mostro(std::string n="0", std::string ds="0", unsigned int lvl=1, unsigned int e=0,  unsigned int f=0, unsigned int m=0, unsigned int d=0, unsigned int s=0, double med=0, std::string t="0", bool sx = true, std::string p="0", bool ba = false, bool las = false, bool am = false, bool ch = false, double pd = 60): NOTerrestre(n,ds,lvl,e,f,m,d,s,med,t,sx,p,ba,las,am,ch), portaDemoniaca(pd) {}
    double GetPorta() const;
    void setPorta(double);
    virtual std::string getTipo() const override;
    virtual bool operator==(const Avatar&) const override;
    virtual std::string datiAvatar() override;
};

#endif // GERARCHIA_H
