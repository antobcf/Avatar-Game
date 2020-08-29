#ifndef GERARCHIA_H
#define GERARCHIA_H

#include <iostream>
#include "container.h"

class Avatar {
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
    Avatar(std::string ="0", std::string ="0", unsigned int =1, unsigned int =0,  unsigned int =0, unsigned int =0, unsigned int =0, unsigned int =0, double =0, std::string ="0", bool = true, std::string ="0");

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
    Terrestre(std::string ="0", std::string ="0", unsigned int =1, unsigned int =0,  unsigned int =0, unsigned int =0, unsigned int =0, unsigned int =0, double =0, std::string ="0", bool = true, std::string ="0", bool = false, bool = false, bool = false, bool = false);

    virtual std::string getTerrNon() const override;
    bool getSpada() const;
    bool getAnello() const;
    bool getScu() const;
    bool getLibro() const;

    void setSpada(bool);
    void setAnello(bool);
    void setScudo(bool);
    void setLibro(bool);

};

class Elfo: public Terrestre {
private:
    double trasparentia;
public:
    Elfo(std::string ="0", std::string ="0", unsigned int =1, unsigned int =0,  unsigned int =0, unsigned int =0, unsigned int =0, unsigned int =0, double =0, std::string ="0", bool = true, std::string ="0", bool = false, bool = false, bool = false, bool = false, double = 0);
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
    Nano(std::string ="0", std::string ="0", unsigned int =1, unsigned int =0,  unsigned int =0, unsigned int =0, unsigned int =0, unsigned int =0, double =0, std::string ="0", bool = true, std::string ="0", bool = false, bool = false, bool = false, bool = false, double = 0);
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
    Umano(std::string ="0", std::string ="0", unsigned int =1, unsigned int =0,  unsigned int =0, unsigned int =0, unsigned int =0, unsigned int =0, double =0, std::string ="0", bool = true, std::string ="0", bool = false, bool = false, bool = false, bool = false, double = 0);
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
    NOTerrestre(std::string ="0", std::string ="0", unsigned int =1, unsigned int =0,  unsigned int =0, unsigned int =0, unsigned int =0, unsigned int =0, double =0, std::string ="0", bool = true, std::string ="0", bool = false, bool = false, bool = false, bool = false);

    virtual std::string getTerrNon() const override;
    bool getLaser() const;
    bool getAmuleto() const;
    bool getBar() const;
    bool getChip() const;

    void setLaser(bool);
    void setAmuleto(bool);
    void setBarriera(bool);
    void setChip(bool);

};

class Alieno: public NOTerrestre {
private:
    double ufo;
public:
    Alieno(std::string ="0", std::string ="0", unsigned int =1, unsigned int =0,  unsigned int =0, unsigned int =0, unsigned int =0, unsigned int =0, double =0, std::string ="0", bool = true, std::string ="0", bool = false, bool = false, bool = false, bool = false, double = 0);
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
    Mostro(std::string ="0", std::string ="0", unsigned int =1, unsigned int =0,  unsigned int =0, unsigned int =0, unsigned int =0, unsigned int =0, double =0, std::string ="0", bool = true, std::string ="0", bool = false, bool = false, bool = false, bool  = false, double = 0);
    double getPorta() const;
    void setPorta(double);
    virtual std::string getTipo() const override;
    virtual bool operator==(const Avatar&) const override;
    virtual std::string datiAvatar() override;
};

#endif // GERARCHIA_H
