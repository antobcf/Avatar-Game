#ifndef GERARCHIA_H
#define GERARCHIA_H

#include <iostream>
#include "container.h"

class Avatar { //classe base astratta e polimorfa
private:
    std::string nome;
    unsigned int livello;
    unsigned int exp;
    unsigned int forza;
    unsigned int magia;
    unsigned int difesa;
    unsigned int scienza;
    bool sesso; //se true maschio, altrimenti femmina
public:
    virtual ~Avatar() = default;
    //o metto tutti a zero o i valori di default tipo sesso va messo alla fine
    Avatar(std::string n, unsigned int lvl, unsigned int e,  unsigned int f, unsigned int m, unsigned int d, unsigned int s, bool sx = true): nome(n), livello(lvl), exp(e),  forza(f), magia(m), difesa(d), scienza(s), sesso(sx) {}
    //GET
    virtual std::string getTerrNon() const = 0;
    virtual std::string getTipo() const = 0;
    unsigned int GetLiv() const;
    bool GetSesso() const;
    unsigned int GetExp() const;
    std::string GetNome() const;
    unsigned int getForza() const;
    unsigned int getMagia() const;
    unsigned int getDifesa() const;
    unsigned int getScienza() const;
    //SET
    std::string SetNome(std::string);
    unsigned int SetLvl(unsigned int);
    bool SetSesso(bool);
    unsigned int SetExp(unsigned int);
    virtual unsigned int setForza() = 0;
    virtual unsigned int setMagia() = 0;
    virtual unsigned int setDifesa() = 0;
    virtual unsigned int setScienza() = 0;
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
    Terrestre(std::string n, unsigned int lvl, unsigned int e, unsigned int f, unsigned int m, unsigned int d, unsigned int s, bool sx = true, bool sc = false, bool sp = false, bool a = false, bool lib = false): Avatar(n,lvl,e,f,m,d,s,sx), scudo(sc), spada(sp), anello(a), libro(lib) {}
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
    std::string regnoIncantato="rinc";
public:
    Elfo(std::string n, unsigned int lvl, unsigned int e, unsigned int f, unsigned int m, unsigned int d, unsigned int s, bool sx = true, bool sc = false, bool sp = false, bool a = false, bool lib = false,unsigned int tr = 50): Terrestre(n,lvl,e,f,m,d,s,sx,sc,sp,a,lib), trasparentia(tr) {}
    unsigned int GetTrasparentia() const;
    unsigned int SetTrasparentia();
    virtual std::string getTipo() const override;
    virtual unsigned int setForza() override;
    virtual unsigned int setMagia() override;
    virtual unsigned int setDifesa() override;
    virtual unsigned int setScienza() override;
    virtual bool operator==(const Avatar&) const override;
};

class Nano: public Terrestre {
private:
    unsigned int corteccia;
    std::string regnoDelSottosuolo="rsot";
public:
    Nano(std::string n, unsigned int lvl, unsigned int e, unsigned int f, unsigned int m, unsigned int d, unsigned int s, bool sx = true, bool sc = false, bool sp = false, bool a = false, bool lib = false, unsigned int cor = 10): Terrestre(n,lvl,e,f,m,d,s,sx,sc,sp,a,lib), corteccia(cor) {}
    unsigned int GetCorteccia() const;
    unsigned int SetCorteccia();
    virtual std::string getTipo() const override;
    virtual unsigned int setForza() override;
    virtual unsigned int setMagia() override;
    virtual unsigned int setDifesa() override;
    virtual unsigned int setScienza() override;
    virtual bool operator==(const Avatar&) const override;
};

class Umano: public Terrestre {
private:
    unsigned int ingegnoScientifico;
    std::string regnoDelleMacchine="rmac";
public:
    Umano(std::string n, unsigned int lvl, unsigned int e, unsigned int f, unsigned int m, unsigned int d, unsigned int s, bool sx = true, bool sc = false, bool sp = false, bool a = false, bool lib = false, unsigned int is = 20): Terrestre(n,lvl,e,f,m,d,s,sx,sc,sp,a,lib), ingegnoScientifico(is) {}
    unsigned int GetIngegno() const;
    unsigned int SetIngegno();
    virtual std::string getTipo() const override;
    virtual unsigned int setForza() override;
    virtual unsigned int setMagia() override;
    virtual unsigned int setDifesa() override;
    virtual unsigned int setScienza() override;
    virtual bool operator==(const Avatar&) const override;
};

class NOTerrestre: public Avatar {
private:
    bool barriera;
    bool laser;
    bool amuleto;
    bool chip;
public:
    NOTerrestre(std::string n, unsigned int lvl, unsigned int e, unsigned int f, unsigned int m, unsigned int d, unsigned int s, bool sx = true, bool ba = false, bool las = false, bool am = false, bool ch = false): Avatar(n,lvl,e,f,m,d,s,sx), barriera(ba), laser(las), amuleto(am), chip(ch) {}
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
    virtual unsigned int velocitaVolo () = 0;
    //OPERATORI
    virtual bool operator==(const Avatar&) const override =0;
};

class Alieno: public NOTerrestre {
private:
    unsigned int ufo;
    std::string regnoDelloSpazio="rspaz";
public:
    Alieno(std::string n, unsigned int lvl, unsigned int e,  unsigned int f, unsigned int m, unsigned int d, unsigned int s, bool sx = true, bool ba = false, bool las = false, bool am = false, bool ch = false, unsigned int ufo = 30): NOTerrestre(n,lvl,e,f,m,d,s,sx,ba,las,am,ch), ufo(ufo) {}
    unsigned int GetUfo() const;
    unsigned int SetUfo();
    virtual std::string getTipo() const override;
    virtual unsigned int setForza() override;
    virtual unsigned int setMagia() override;
    virtual unsigned int setDifesa() override;
    virtual unsigned int setScienza() override;
    virtual unsigned int velocitaVolo() override; //la velocità dell'alieno dipende dal suo livello di scienza
    virtual bool operator==(const Avatar&) const override;
};

class Mostro: public NOTerrestre {
private:
    unsigned int portaDemoniaca;
    std::string regnoDeiDemoni="rdem";
public:
    Mostro(std::string n, unsigned int lvl, unsigned int e,  unsigned int f, unsigned int m, unsigned int d, unsigned int s, bool sx = true, bool ba = false, bool las = false, bool am = false, bool ch = false, unsigned int pd = 60): NOTerrestre(n,lvl,e,f,m,d,s,sx,ba,las,am,ch), portaDemoniaca(pd) {}
    unsigned int GetPorta() const;
    unsigned int SetPorta();
    virtual std::string getTipo() const override;
    virtual unsigned int setForza() override;
    virtual unsigned int setMagia() override;
    virtual unsigned int setDifesa() override;
    virtual unsigned int setScienza() override;
    virtual unsigned int velocitaVolo() override; //la velocità del mostro dipende dal suo livello di forza
   virtual bool operator==(const Avatar&) const override;
};

#endif // GERARCHIA_H
