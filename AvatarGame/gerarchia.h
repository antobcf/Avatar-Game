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
    std::string terreno;
    bool sesso; //se true maschio, altrimenti femmina

public:
    virtual ~Avatar() = default;
    //o metto tutti a zero o i valori di default tipo sesso va messo alla fine
    Avatar(std::string n, unsigned int lvl, unsigned int e,  unsigned int f, unsigned int m, unsigned int d, unsigned int s, std::string t, bool sx = true): nome(n), livello(lvl), exp(e),  forza(f), magia(m), difesa(d), scienza(s), terreno(t), sesso(sx) {}
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
    std::string getTerreno() const;
    //SET
    std::string SetNome(std::string);
    std::string setDescrizione(std::string);
    unsigned int SetLvl(unsigned int);
    bool SetSesso(bool);
    unsigned int SetExp(unsigned int);
    virtual unsigned int setForza() = 0;
    virtual unsigned int setMagia() = 0;
    virtual unsigned int setDifesa() = 0;
    virtual unsigned int setScienza() = 0;
    virtual std::string setTerreno() = 0;
    //OPERATORI
    virtual bool operator==(const Avatar&) const =0;
};

class Terrestre: public Avatar {
private:
    bool scudo;
    bool spada;
    bool anello;
    bool libro;
public:
    Terrestre(std::string n, unsigned int lvl, unsigned int e, unsigned int f, unsigned int m, unsigned int d, unsigned int s, std::string t, bool sx = true, bool sc = false, bool sp = false, bool a = false, bool lib = false): Avatar(n,lvl,e,f,m,d,s,t,sx), scudo(sc), spada(sp), anello(a), libro(lib) {}
    //GET
    virtual std::string getTerrNon() const override;
    bool GetScu() const;
    bool GetSpada() const;
    bool GetAnello() const;
    bool GetLibro() const;
    //SET
    bool SetScudo(bool);
    bool SetSpada(bool);
    bool SetAnello(bool);
    bool SetLibro(bool);
    //OPERATORI
    virtual bool operator==(const Avatar&) const override =0;
};

class Elfo: public Terrestre {
private:
    unsigned int trasparentia;
public:
    Elfo(std::string n, unsigned int lvl, unsigned int e, unsigned int f, unsigned int m, unsigned int d, unsigned int s, std::string t, bool sx = true, bool sc = false, bool sp = false, bool a = false, bool lib = false, unsigned int tr = 0): Terrestre(n,lvl,e,f,m,d,s,t,sx,sc,sp,a,lib), trasparentia(tr) {}
    unsigned int GetTrasparentia() const;
    unsigned int SetTrasparentia();
    virtual std::string getTipo() const override;
    virtual unsigned int setForza() override;
    virtual unsigned int setMagia() override;
    virtual unsigned int setDifesa() override;
    virtual unsigned int setScienza() override;
    virtual std::string setTerreno() override;
    virtual bool operator==(const Avatar&) const override;

};

class Nano: public Terrestre {
private:
    unsigned int corteccia;
public:
    Nano(std::string n, unsigned int lvl, unsigned int e, unsigned int f, unsigned int m, unsigned int d, unsigned int s, std::string t, bool sx = true, bool sc = false, bool sp = false, bool a = false, bool lib = false, unsigned int cor = 0): Terrestre(n,lvl,e,f,m,d,s,t,sx,sc,sp,a,lib), corteccia(cor) {}
    unsigned int GetCorteccia() const;
    unsigned int SetCorteccia();
    virtual std::string getTipo() const override;
    virtual unsigned int setForza() override;
    virtual unsigned int setMagia() override;
    virtual unsigned int setDifesa() override;
    virtual unsigned int setScienza() override;
    virtual std::string setTerreno() override;
    virtual bool operator==(const Avatar&) const override;
};

class Umano: public Terrestre {
private:
    unsigned int ingegnoScientifico;
public:
    Umano(std::string n, unsigned int lvl, unsigned int e, unsigned int f, unsigned int m, unsigned int d, unsigned int s, std::string t, bool sx = true, bool sc = false, bool sp = false, bool a = false, bool lib = false, unsigned int is = 20): Terrestre(n,lvl,e,f,m,d,s,t,sx,sc,sp,a,lib), ingegnoScientifico(is) {}
    unsigned int GetIngegno() const;
    unsigned int SetIngegno();
    virtual std::string getTipo() const override;
    virtual unsigned int setForza() override;
    virtual unsigned int setMagia() override;
    virtual unsigned int setDifesa() override;
    virtual unsigned int setScienza() override;
    virtual std::string setTerreno() override;
    virtual bool operator==(const Avatar&) const override;
};

class NOTerrestre: public Avatar {
private:
    bool barriera;
    bool laser;
    bool amuleto;
    bool chip;
public:
    NOTerrestre(std::string n, unsigned int lvl, unsigned int e, unsigned int f, unsigned int m, unsigned int d, unsigned int s, std::string t, bool sx = true, bool ba = false, bool las = false, bool am = false, bool ch = false): Avatar(n,lvl,e,f,m,d,s,t,sx), barriera(ba), laser(las), amuleto(am), chip(ch) {}
    /*virtual unsigned int forza() override = 0;
    virtual unsigned int magia() override = 0;
    virtual unsigned int difesa() override = 0;
    virtual unsigned int scienza() override = 0;*/
    //GET
    virtual std::string getTerrNon() const override;
    bool GetBar() const;
    bool GetLaser() const;
    bool GetAmuleto() const;
    bool GetChip() const;
    //SET
    bool SetBarriera(bool);
    bool SetLaser(bool);
    bool SetAmuleto(bool);
    bool SetChip(bool);
    //OPERATORI
    virtual bool operator==(const Avatar&) const override =0;
};

class Alieno: public NOTerrestre {
private:
    unsigned int ufo;
    std::string regnoDelloSpazio="rspaz";
public:
    Alieno(std::string n, unsigned int lvl, unsigned int e,  unsigned int f, unsigned int m, unsigned int d, unsigned int s, std::string t, bool sx = true, bool ba = false, bool las = false, bool am = false, bool ch = false, unsigned int ufo = 30): NOTerrestre(n,lvl,e,f,m,d,s,t,sx,ba,las,am,ch), ufo(ufo) {}
    unsigned int GetUfo() const;
    unsigned int SetUfo();
    virtual std::string getTipo() const override;
    virtual unsigned int setForza() override;
    virtual unsigned int setMagia() override;
    virtual unsigned int setDifesa() override;
    virtual unsigned int setScienza() override;
    virtual std::string setTerreno() override;
    virtual bool operator==(const Avatar&) const override;
};

class Mostro: public NOTerrestre {
private:
    unsigned int portaDemoniaca;
    std::string regnoDeiDemoni="rdem";
public:
    Mostro(std::string n, unsigned int lvl, unsigned int e,  unsigned int f, unsigned int m, unsigned int d, unsigned int s, std::string t, bool sx = true, bool ba = false, bool las = false, bool am = false, bool ch = false, unsigned int pd = 60): NOTerrestre(n,lvl,e,f,m,d,s,t,sx,ba,las,am,ch), portaDemoniaca(pd) {}
    unsigned int GetPorta() const;
    unsigned int SetPorta();
    virtual std::string getTipo() const override;
    virtual unsigned int setForza() override;
    virtual unsigned int setMagia() override;
    virtual unsigned int setDifesa() override;
    virtual unsigned int setScienza() override;
    virtual std::string setTerreno() override;
   virtual bool operator==(const Avatar&) const override;
};

#endif // GERARCHIA_H
