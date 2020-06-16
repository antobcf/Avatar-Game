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
    Avatar(std::string n, std::string ds, unsigned int lvl, unsigned int e,  unsigned int f, unsigned int m, unsigned int d, unsigned int s, double med, std::string t, bool sx = true, std::string p="0"): nome(n), descrizione(ds), livello(lvl), exp(e),  forza(f), magia(m), difesa(d), scienza(s), media(med), terreno(t), sesso(sx), percorsoImmagine(p) {}
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
    virtual bool operator==(const Avatar&) const =0;

    virtual std::string datiAvatar();
};

class Terrestre: public Avatar {
private:
    bool scudo;
    bool spada;
    bool anello;
    bool libro;
public:
    Terrestre(std::string n, std::string ds, unsigned int lvl, unsigned int e, unsigned int f, unsigned int m, unsigned int d, unsigned int s, double med, std::string t, bool sx = true, std::string p="0", bool sc = false, bool sp = false, bool a = false, bool lib = false): Avatar(n,ds,lvl,e,f,m,d,s,med,t,sx,p), scudo(sc), spada(sp), anello(a), libro(lib) {}
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

    //OPERATORI
    virtual bool operator==(const Avatar&) const override =0;
};

class Elfo: public Terrestre {
private:
    unsigned int trasparentia;
public:
    Elfo(std::string n,std::string ds,  unsigned int lvl, unsigned int e, unsigned int f, unsigned int m, unsigned int d, unsigned int s, double med, std::string t, bool sx = true, std::string p="0", bool sc = false, bool sp = false, bool a = false, bool lib = false, unsigned int tr = 0): Terrestre(n,ds,lvl,e,f,m,d,s,med,t,sx,p,sc,sp,a,lib), trasparentia(tr) {}
    unsigned int GetTrasparentia() const;
    void setTrasparentia(int);
    virtual std::string getTipo() const override;
    virtual bool operator==(const Avatar&) const override;
    virtual std::string datiAvatar() override;
};

class Nano: public Terrestre {
private:
    unsigned int corteccia;
public:
    Nano(std::string n, std::string ds, unsigned int lvl, unsigned int e, unsigned int f, unsigned int m, unsigned int d, unsigned int s, double med, std::string t, bool sx = true, std::string p="0", bool sc = false, bool sp = false, bool a = false, bool lib = false, unsigned int cor = 0): Terrestre(n,ds,lvl,e,f,m,d,s,med,t,sx,p,sc,sp,a,lib), corteccia(cor) {}
    unsigned int GetCorteccia() const;
    void setCorteccia(int);
    virtual std::string getTipo() const override;
    virtual bool operator==(const Avatar&) const override;
    virtual std::string datiAvatar() override;
};

class Umano: public Terrestre {
private:
    unsigned int ingegnoScientifico;
public:
    Umano(std::string n, std::string ds, unsigned int lvl, unsigned int e, unsigned int f, unsigned int m, unsigned int d, unsigned int s, double med, std::string t, bool sx = true, std::string p="0", bool sc = false, bool sp = false, bool a = false, bool lib = false, unsigned int is = 20): Terrestre(n,ds,lvl,e,f,m,d,s,med,t,sx,p,sc,sp,a,lib), ingegnoScientifico(is) {}
    unsigned int GetIngegno() const;
    void setIngegno(int);
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
    NOTerrestre(std::string n, std::string ds, unsigned int lvl, unsigned int e, unsigned int f, unsigned int m, unsigned int d, unsigned int s, double med, std::string t, bool sx = true, std::string p="0", bool ba = false, bool las = false, bool am = false, bool ch = false): Avatar(n,ds,lvl,e,f,m,d,s,med,t,sx,p), barriera(ba), laser(las), amuleto(am), chip(ch) {}
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

    //OPERATORI
    virtual bool operator==(const Avatar&) const override =0;
};

class Alieno: public NOTerrestre {
private:
    unsigned int ufo;
public:
    Alieno(std::string n, std::string ds, unsigned int lvl, unsigned int e,  unsigned int f, unsigned int m, unsigned int d, unsigned int s, double med, std::string t, bool sx = true, std::string p="0", bool ba = false, bool las = false, bool am = false, bool ch = false, unsigned int ufo = 30): NOTerrestre(n,ds,lvl,e,f,m,d,s,med,t,sx,p,ba,las,am,ch), ufo(ufo) {}
    unsigned int GetUfo() const;
    void setUfo(int);
    virtual std::string getTipo() const override;
    virtual bool operator==(const Avatar&) const override;
    virtual std::string datiAvatar() override;
};

class Mostro: public NOTerrestre {
private:
    unsigned int portaDemoniaca;
public:
    Mostro(std::string n, std::string ds, unsigned int lvl, unsigned int e,  unsigned int f, unsigned int m, unsigned int d, unsigned int s, double med, std::string t, bool sx = true, std::string p="0", bool ba = false, bool las = false, bool am = false, bool ch = false, unsigned int pd = 60): NOTerrestre(n,ds,lvl,e,f,m,d,s,med,t,sx,p,ba,las,am,ch), portaDemoniaca(pd) {}
    unsigned int GetPorta() const;
    void setPorta(int);
    virtual std::string getTipo() const override;
    virtual bool operator==(const Avatar&) const override;
    virtual std::string datiAvatar() override;
};

#endif // GERARCHIA_H
