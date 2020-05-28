#ifndef GERARCHIA_H
#define GERARCHIA_H

#include <iostream>
#include "container.h"

class Avatar { //classe base astratta e polimorfa
private:
    std::string nome; //nome del personaggio
    unsigned int livello;
    unsigned int exp;
    bool sesso; //se true maschio, altrimenti femmina
public:
    virtual ~Avatar() = default;
    //metodi forza, magia e difesa devono essere virtuali puri perchè li implementiamo nelle classi derivate
    virtual unsigned int forza() = 0;
    virtual unsigned int magia() = 0;
    virtual unsigned int difesa() = 0;
    virtual unsigned int scienza() = 0;
    Avatar(std::string n, unsigned int lvl, unsigned int e, bool s = true): nome(n), livello(lvl),  exp(e), sesso(s) {}
    //GET
    unsigned int GetLiv() const;
    bool GetSesso() const;
    unsigned int GetExp() const;
    std::string GetNome() const;
    //SET
    std::string SetNome(std::string);
    unsigned int SetLvl(unsigned int);
    bool SetSesso(bool);
    unsigned int SetExp(unsigned int);
    unsigned int SetForza(bool);
    unsigned int SetMagia(bool);
    unsigned int SetDifesa(bool);
    unsigned int SetScienza(bool);
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
    Terrestre(std::string n, unsigned int lvl, bool s, unsigned int e, bool sc = false, bool sp = false, bool a = false, bool lib = false): Avatar(n,lvl,e,s), scudo(sc), spada(sp), anello(a), libro(lib) {}
    /*virtual unsigned int forza() override = 0;
    virtual unsigned int magia() override = 0;
    virtual unsigned int difesa() override = 0;
    virtual unsigned int scienza() override = 0;*/
    //GET
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
    Elfo(std::string n, unsigned int lvl, bool s, unsigned int e, bool sc = false, bool sp = false, bool a = false, bool lib = false,unsigned int tr = 50): Terrestre(n,lvl,e,s,sc,sp,a,lib), trasparentia(tr) {}
    unsigned int GetTrasparentia() const;
    unsigned int SetTrasparentia();
    virtual unsigned int forza() override;
    virtual unsigned int magia() override;
    virtual unsigned int difesa() override;
    virtual unsigned int scienza() override;
    virtual bool operator==(const Avatar&) const override;
};

class Nano: public Terrestre {
private:
    unsigned int corteccia;
    std::string regnoDelSottosuolo="rsot";
public:
    Nano(std::string n, unsigned int lvl, bool s, unsigned int e, bool sc = false, bool sp = false, bool a = false, bool lib = false, unsigned int cor = 10): Terrestre(n,lvl,e,s,sc,sp,a,lib), corteccia(cor) {}
    unsigned int GetCorteccia() const;
    unsigned int SetCorteccia();
    virtual unsigned int forza() override;
    virtual unsigned int magia() override;
    virtual unsigned int difesa() override;
    virtual unsigned int scienza() override;
    virtual bool operator==(const Avatar&) const override;
};

class Umano: public Terrestre {
private:
    unsigned int ingegnoScientifico;
    std::string regnoDelleMacchine="rmac";
public:
    Umano(std::string n, unsigned int lvl, bool s, unsigned int e, bool sc = false, bool sp = false, bool a = false, bool lib = false, unsigned int is = 20): Terrestre(n,lvl,e,s,sc,sp,a,lib), ingegnoScientifico(is) {}
    unsigned int GetIngegno() const;
    unsigned int SetIngegno();
    virtual unsigned int forza() override;
    virtual unsigned int magia() override;
    virtual unsigned int difesa() override;
    virtual unsigned int scienza() override;
    virtual bool operator==(const Avatar&) const override;
};

class NOTerrestre: public Avatar {
private:
    bool barriera;
    bool laser;
    bool amuleto;
    bool chip;
public:
    NOTerrestre(std::string n, unsigned int lvl, bool s, unsigned int e, bool ba = false, bool las = false, bool am = false, bool ch = false): Avatar(n,lvl,e,s), barriera(ba), laser(las), amuleto(am), chip(ch) {}
    /*virtual unsigned int forza() override = 0;
    virtual unsigned int magia() override = 0;
    virtual unsigned int difesa() override = 0;
    virtual unsigned int scienza() override = 0;*/
    //GET
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
    Alieno(std::string n, unsigned int lvl, bool s,  unsigned int e, bool ba = false, bool las = false, bool am = false, bool ch = false, unsigned int ufo = 30): NOTerrestre(n,lvl,e,s,ba,las,am,ch), ufo(ufo) {}
    unsigned int GetUfo() const;
    unsigned int SetUfo();
    virtual unsigned int forza() override;
    virtual unsigned int scienza() override;
    virtual unsigned int magia() override;
    virtual unsigned int difesa() override;
    virtual unsigned int velocitaVolo() override; //la velocità dell'alieno dipende dal suo livello di scienza
    virtual bool operator==(const Avatar&) const override;
};

class Mostro: public NOTerrestre {
private:
    unsigned int portaDemoniaca;
    std::string regnoDeiDemoni="rdem";
public:
    Mostro(std::string n, unsigned int lvl, bool s, unsigned int e, bool ba = false, bool las = false, bool am = false, bool ch = false, unsigned int pd = 60): NOTerrestre(n,lvl,e,s,ba,las,am,ch), portaDemoniaca(pd) {}
    unsigned int GetPorta() const;
    unsigned int SetPorta();
    virtual unsigned int forza() override;
    virtual unsigned int scienza() override;
    virtual unsigned int magia() override;
    virtual unsigned int difesa() override;
    virtual unsigned int velocitaVolo() override; //la velocità del mostro dipende dal suo livello di forza
   virtual bool operator==(const Avatar&) const override;
};

#endif // GERARCHIA_H
