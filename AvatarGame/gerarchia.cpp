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

void Avatar::SetSesso(bool s) {
    sesso=s;
}

unsigned int Avatar::GetExp() const {
    return exp;
}

void Avatar::SetExp(unsigned int e) {
    exp = exp+e;
    if(exp >99){
        SetLvl(livello+1);
        exp = exp -100;
    }
}

void Avatar::setMedia()
{
    media = (forza+magia+difesa+scienza)/4;
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

unsigned int Elfo::SetTrasparentia(unsigned l, unsigned int m) {
    if(l%5 == 0){
        trasparentia = trasparentia+(m%l);
    }
    return trasparentia;
}

std::string Elfo::getTipo() const
{
    return "Elfo";
}

void Elfo::setForza() {

    if(GetSpada()) return GetLiv()*6+8;
    return GetLiv()*6;
}

void Elfo::setMagia(unsigned int m) {
    magia = m;
    if(GetAnello()) return GetLiv()*10+6;
    return GetLiv()*10;
}

void Elfo::setDifesa() {
    if(GetScu()) return GetLiv()*6+10;
    return GetLiv()*6;
}

void Elfo::setScienza() {
    if(GetLibro()) return GetLiv()*5+5;
    return GetLiv()*5;
}

void Elfo::setTerreno()
{
    terreno = "Regno incantato";
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

unsigned int Nano::SetCorteccia() {
    if(GetLiv()%5 == 0){
        corteccia = corteccia+(setDifesa()%GetLiv());
    }
    return corteccia;
}

std::string Nano::getTipo() const
{
    return "Nano";
}

void Nano::setForza(int p) {

//    if(GetSpada()) return GetLiv()*7+8;
//    return GetLiv()*7;
}

void Nano::setMagia() {
    if(GetAnello()) return GetLiv()*2+6;
    return GetLiv()*2;
}

void Nano::setDifesa() {
    if(GetScu()) return GetLiv()*10+10;
    return GetLiv()*10;
}

void Nano::setScienza() {    if(GetLibro()) return GetLiv()*6+5;
    return GetLiv()*6;
                                }

void Nano::setTerreno()
{
    "Regno del sottosuolo";
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

unsigned int Umano::SetIngegno() {
    if(GetLiv()%5 == 0){
        ingegnoScientifico = ingegnoScientifico+(setScienza()%GetLiv());
    }
    return ingegnoScientifico;
}

std::string Umano::getTipo() const
{
    return "Umano";
}

void Umano::setForza() {
    if(GetSpada()) return GetLiv()*5+8;
    return GetLiv()*5;
}

void Umano::setMagia() {
    if(GetAnello()) return GetLiv()*3+6;
    return GetLiv()*3;
}

void Umano::setDifesa() {
    if(GetScu()) return GetLiv()*8+2;
    return GetLiv()*8;
}

void Umano::setScienza() {
    if(GetLibro()) return GetLiv()*8+5;
    return GetLiv()*8;
}

void Umano::setTerreno()
{
    "Regno delle macchine";
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

unsigned int Alieno::SetUfo() {
    if(GetLiv()%5 == 0){
        ufo = ufo+(setScienza()%GetLiv());
    }
    return ufo;
}

std::string Alieno::getTipo() const
{
    return "Alieno";
}

void Alieno::setForza() {
    if(GetLaser()) return GetLiv()*3+7;
    return GetLiv()*3;
}

void Alieno::setScienza() {
    if(GetChip()) return GetLiv()*10+6;
    return GetLiv()*10;
}

void Alieno::setTerreno()
{
    "Regno dello spazio";
}

void Alieno::setMagia() {
    if(GetAmuleto()) return GetLiv()*0+8;
    return GetLiv()*0;
}
void Alieno::setDifesa() {
    if(GetBar()) return GetLiv()*7+9;
    return GetLiv()*7;
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

unsigned int Mostro::SetPorta() {
    if(GetLiv()%5 == 0) {
        portaDemoniaca = portaDemoniaca+(getForza()%GetLiv());
    }
    return portaDemoniaca;
}

std::string Mostro::getTipo() const
{
    return "Mostro";
}

void Mostro::setForza() {
    if(GetLaser()) return GetLiv()*10+7;
    return GetLiv()*10;
}

void Mostro::setScienza() {
    if(GetChip()) return GetLiv()*10+6;
    return GetLiv()*0;
}

void Mostro::setTerreno()
{
    "Regno dei demoni";
}

void Mostro::setMagia() {
    if(GetAmuleto()) return GetLiv()*5+8;
    return GetLiv()*5;
}

void Mostro::setDifesa() {
    if(GetBar()) return GetLiv()*9+9;
    return GetLiv()*9;
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
