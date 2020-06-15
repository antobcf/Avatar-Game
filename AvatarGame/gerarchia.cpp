#include "gerarchia.h"

//Metodi della classe Avatar
unsigned int Avatar::GetLiv() const{
    return livello;
}

bool Avatar::GetSesso() const {
    return sesso;
}

std::string Avatar::GetNome() const {
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
    return media;
}

std::string Avatar::getTerreno() const
{
    return terreno;
}

void Avatar::SetNome(std::string n) {
    nome = n;
}

void Avatar::setDescrizione(std::string d)
{
    descrizione = d;
}

void Avatar::SetLvl(unsigned int lvl) {
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

void Avatar::SetSesso(bool s) {
    sesso=s;
}

unsigned int Avatar::GetExp() const {
    return exp;
}

void Avatar::SetExp(unsigned int e) { //forse non va bene ma bisogna farla "normale"
    exp = exp+e;
    if(exp >99){
        SetLvl(livello+1);
        exp = exp -100;
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

std::string Avatar::datiAvatar()
{
    return ("Tipo Avatar: "+getTipo()).append("   Nome: "+GetNome()).append("   Sesso: ").append(GetSesso() ? "Maschio" : "Femmina")
            .append("\nForza: "+std::to_string(getForza())).append("   Magia: "+std::to_string(getMagia()))
            .append("\nDifesa: "+std::to_string(getDifesa())).append("   Scienza: "+std::to_string(getScienza()))
            .append("\nMedia: "+std::to_string(getMedia())).append("   Lvl: "+std::to_string(GetLiv()))
            .append("\nStoria: "+getDescrizione());
}


//Metodi della classe Terrestre
std::string Terrestre::getTerrNon() const
{
    return "Terrestre";
}

bool Terrestre::GetScu() const {
    return scudo;
}

bool Terrestre::GetSpada() const {
    return spada;
}

bool Terrestre::GetAnello() const {
    return anello;
}

bool Terrestre::GetLibro() const {
    return libro;
}

void Terrestre::SetScudo(bool s) {
    scudo=s;
}

void Terrestre::SetSpada(bool sp) {
    spada=sp;
}

void Terrestre::SetAnello(bool a) {
    anello=a;
}

void Terrestre::SetLibro(bool lib) {
    libro=lib;
}

//Metodi della classe Elfo
unsigned int Elfo::GetTrasparentia() const {
    return trasparentia;
}

void Elfo::setTrasparentia(int t) {
    trasparentia = t;
}

std::string Elfo::getTipo() const
{
    return "Elfo";
}

bool Elfo::operator==(const Avatar & a) const {
    if(a.GetNome()==this->GetNome()) return true;
    else return false;
}

std::string Elfo::datiAvatar()
{
    std::string dati = Avatar::datiAvatar();
    return dati.append("\nTrasparentia: "+std::to_string(GetTrasparentia()));
}

//Metodi della classe Nano
unsigned int Nano::GetCorteccia() const {
    return corteccia;
}

void Nano::setCorteccia(int c) {
    corteccia = c;
}

std::string Nano::getTipo() const
{
    return "Nano";
}

bool Nano::operator==(const Avatar & a) const {
    if(a.GetNome()==this->GetNome()) return true;
    else return false;
}

std::string Nano::datiAvatar()
{
    std::string dati = Avatar::datiAvatar();
    return dati.append("\nCorteccia: "+std::to_string(GetCorteccia()));
}

//Metodi della classe Umano
unsigned int Umano::GetIngegno() const {
    return ingegnoScientifico;
}

void Umano::setIngegno(int i) {
    ingegnoScientifico = i;
}

std::string Umano::getTipo() const
{
    return "Umano";
}

bool Umano::operator==(const Avatar & a) const {
    if(a.GetNome()==this->GetNome()) return true;
    else return false;
}

std::string Umano::datiAvatar()
{
    std::string dati = Avatar::datiAvatar();
    return dati.append("\nIngegno Scientifico: "+std::to_string(GetIngegno()));
}

//Metodi della classe NOTerrestre
std::string NOTerrestre::getTerrNon() const
{
    return "Non terrestre";
}

bool NOTerrestre::GetBar() const {
    return barriera;
}

bool NOTerrestre::GetLaser() const {
    return laser;
}

bool NOTerrestre::GetAmuleto() const {
    return amuleto;
}

bool NOTerrestre::GetChip() const {
    return chip;
}

void NOTerrestre::SetBarriera(bool ba) {
    barriera=ba;
}

void NOTerrestre::SetLaser(bool las) {
    laser=las;
}

void NOTerrestre::SetAmuleto(bool am) {
    amuleto=am;
}

void NOTerrestre::SetChip(bool ch) {
    chip=ch;
}

//Metodi della classe Alieno
unsigned int Alieno::GetUfo() const {
    return ufo;
}

void Alieno::setUfo(int u)
{
    ufo = u;
}

std::string Alieno::getTipo() const
{
    return "Alieno";
}

bool Alieno::operator==(const Avatar & a) const {
    if(a.GetNome()==this->GetNome()) return true;
    else return false;
}

std::string Alieno::datiAvatar()
{
    std::string dati = Avatar::datiAvatar();
    return dati.append("\nUfo: "+std::to_string(GetUfo()));
}

//Metodi della classe Mostro
unsigned int Mostro::GetPorta() const {
    return portaDemoniaca;
}

void Mostro::setPorta(int p) {
    portaDemoniaca = p;
}

std::string Mostro::getTipo() const
{
    return "Mostro";
}

bool Mostro::operator==(const Avatar & a) const {
    if(a.GetNome()==this->GetNome()) return true;
    else return false;
}

std::string Mostro::datiAvatar()
{
    std::string dati = Avatar::datiAvatar();
    return dati.append("\nPorta Demoniaca: "+std::to_string(GetPorta()));
}
