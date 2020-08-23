#include "gerarchia.h"

//Metodi della classe Avatar
unsigned int Avatar::getLiv() const{
    return livello;
}

bool Avatar::getSesso() const {
    return sesso;
}

std::string Avatar::getNome() const {
    return nome;
}

std::string Avatar::getDescrizione() const
{
    return descrizione;
}

unsigned int Avatar::getForza() const
{
    return forza;
}

unsigned int Avatar::getMagia() const
{
    return magia;
}

unsigned int Avatar::getDifesa() const
{
    return difesa;
}

unsigned int Avatar::getScienza() const
{
    return scienza;
}

double Avatar::getMedia() const
{
    return  media;
}

std::string Avatar::getTerreno() const
{
    return terreno;
}

std::string Avatar::getPercorsoImmagine() const
{
    return percorsoImmagine;
}

void Avatar::setNome(std::string n) {
    nome = n;
}

void Avatar::setDescrizione(std::string d)
{
    descrizione = d;
}

void Avatar::setLvl(unsigned int lvl) {
    livello=lvl;
}

void Avatar::setForza(int f) {
    forza = f;
}

void Avatar::setMagia(int m)
{
    magia = m;
}

void Avatar::setDifesa(int d)
{
    difesa = d;
}

void Avatar::setScienza(int s)
{
    scienza = s;
}

void Avatar::setSesso(bool s) {
    sesso=s;
}

unsigned int Avatar::getExp() const {
    return exp;
}

void Avatar::setExp(unsigned int e) {
    if(e > 99) {
        exp = e - 100;
        setLvl(getLiv()+1);
        if(e > 99)
            setExp(exp);
    } else {
        exp = e;
    }
}

void Avatar::setMedia(double m)
{
    media = m;
}

void Avatar::setTerreno(std::string t)
{
    terreno = t;
}

void Avatar::setPercorsoImmagine(std::string p)
{
    percorsoImmagine = p;
}

bool Avatar::operator==(const Avatar & a) const
{
    return nome == a.nome;
}

std::string Avatar::datiAvatar()
{
    std::string m = std::to_string(getMedia());
    if(getMedia() < 10) {
        m.resize(3);
    } else if(getMedia() < 100) {
        m.resize(4);
    } else
        m.resize(5);
    return ("Tipo Avatar: "+getTipo()).append("   Nome: "+getNome()).append("   Sesso: ").append(getSesso() ? "Maschio" : "Femmina")
            .append("\nForza: "+std::to_string(getForza())).append("   Magia: "+std::to_string(getMagia()))
            .append("\nDifesa: "+std::to_string(getDifesa())).append("   Scienza: "+std::to_string(getScienza()))
            .append("\nMedia: "+m).append("   Lvl: "+std::to_string(getLiv()));
}


//Metodi della classe Terrestre
std::string Terrestre::getTerrNon() const
{
    return "Terrestre";
}

bool Terrestre::getScu() const {
    return scudo;
}

bool Terrestre::getSpada() const {
    return spada;
}

bool Terrestre::getAnello() const {
    return anello;
}

bool Terrestre::getLibro() const {
    return libro;
}

void Terrestre::setScudo(bool s) {
    scudo=s;
}

void Terrestre::setSpada(bool sp) {
    spada=sp;
}

void Terrestre::setAnello(bool a) {
    anello=a;
}

void Terrestre::setLibro(bool lib) {
    libro=lib;
}

//Metodi della classe Elfo
double Elfo::getTrasparentia() const {
    return trasparentia;
}

void Elfo::setTrasparentia(double t) {
    trasparentia = t;
}

std::string Elfo::getTipo() const
{
    return "Elfo";
}

bool Elfo::operator==(const Avatar & a) const {
    const Elfo* e = dynamic_cast<const Elfo*>(&a);
    return e && Avatar::operator==(a);
}

std::string Elfo::datiAvatar()
{
    std::string t = std::to_string(getTrasparentia());
    if(getTrasparentia() < 10) {
        t.resize(3);
    } else if(getTrasparentia() < 100) {
        t.resize(4);
    } else if(getTrasparentia() < 1000) {
        t.resize(5);
    } else
        t.resize(6);
    std::string dati = Avatar::datiAvatar();
    return dati.append("\nTrasparentia: "+t).append("\nStoria: "+getDescrizione());
}

//Metodi della classe Nano
double Nano::getCorteccia() const {
    return corteccia;
}

void Nano::setCorteccia(double c) {
    corteccia = c;
}

std::string Nano::getTipo() const
{
    return "Nano";
}

bool Nano::operator==(const Avatar & a) const {
    const Nano* n = dynamic_cast<const Nano*>(&a);
    return n && Avatar::operator==(a);
}

std::string Nano::datiAvatar()
{
    std::string c = std::to_string(getCorteccia());
    if(getCorteccia() < 10) {
        c.resize(3);
    } else if(getCorteccia() < 100) {
        c.resize(4);
    } else if(getCorteccia() < 1000) {
        c.resize(5);
    } else
        c.resize(6);
    std::string dati = Avatar::datiAvatar();
    return dati.append("\nCorteccia: "+c).append("\nStoria: "+getDescrizione());
}

//Metodi della classe Umano
double Umano::getIngegno() const {
    return ingegnoScientifico;
}

void Umano::setIngegno(double i) {
    ingegnoScientifico = i;
}

std::string Umano::getTipo() const
{
    return "Umano";
}

bool Umano::operator==(const Avatar & a) const {
    const Umano* u = dynamic_cast<const Umano*>(&a);
    return u && Avatar::operator==(a);
}

std::string Umano::datiAvatar()
{
    std::string u = std::to_string(getIngegno());
    if(getIngegno() < 10) {
        u.resize(3);
    } else if(getIngegno() < 100) {
        u.resize(4);
    } else if(getIngegno() < 1000) {
        u.resize(5);
    } else {
        u.resize(6);
}
    std::string dati = Avatar::datiAvatar();
    return dati.append("\nIngegno Scientifico: "+u).append("\nStoria: "+getDescrizione());
}

//Metodi della classe NOTerrestre
std::string NOTerrestre::getTerrNon() const
{
    return "Non terrestre";
}

bool NOTerrestre::getBar() const {
    return barriera;
}

bool NOTerrestre::getLaser() const {
    return laser;
}

bool NOTerrestre::getAmuleto() const {
    return amuleto;
}

bool NOTerrestre::getChip() const {
    return chip;
}

void NOTerrestre::setBarriera(bool ba) {
    barriera=ba;
}

void NOTerrestre::setLaser(bool las) {
    laser=las;
}

void NOTerrestre::setAmuleto(bool am) {
    amuleto=am;
}

void NOTerrestre::setChip(bool ch) {
    chip=ch;
}

//Metodi della classe Alieno
double Alieno::getUfo() const {
    return ufo;
}

void Alieno::setUfo(double u)
{
    ufo = u;
}

std::string Alieno::getTipo() const
{
    return "Alieno";
}

bool Alieno::operator==(const Avatar & a) const {
    const Alieno* al = dynamic_cast<const Alieno*>(&a);
    return al && Avatar::operator==(a);
}

std::string Alieno::datiAvatar()
{
    std::string a = std::to_string(getUfo());
    if(getUfo() < 10) {
        a.resize(3);
    } else if(getUfo() < 100) {
        a.resize(4);
    } else if(getUfo() < 1000) {
        a.resize(5);
    } else
        a.resize(6);
    std::string dati = Avatar::datiAvatar();
    return dati.append("\nUfo: "+a).append("\nStoria: "+getDescrizione());
}

//Metodi della classe Mostro
double Mostro::getPorta() const {
    return portaDemoniaca;
}

void Mostro::setPorta(double p) {
    portaDemoniaca = p;
}

std::string Mostro::getTipo() const
{
    return "Mostro";
}

bool Mostro::operator==(const Avatar & a) const {
    const Mostro* m = dynamic_cast<const Mostro*>(&a);
    return m && Avatar::operator==(a);
}

std::string Mostro::datiAvatar()
{
    std::string m = std::to_string(getPorta());
    if(getPorta() < 10) {
        m.resize(3);
    } else if(getPorta() < 100) {
        m.resize(4);
    } else if(getPorta() < 1000) {
        m.resize(5);
    } else
        m.resize(6);
    std::string dati = Avatar::datiAvatar();
    return dati.append("\nPorta Demoniaca: "+m).append("\nStoria: "+getDescrizione());
}
