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

std::string Avatar::SetNome(std::string n) {
    return nome=n;
}

unsigned int Avatar::SetLvl(unsigned int lvl) {
    return livello=lvl;
}

bool Avatar::SetSesso(bool s) {
    return sesso=s;
}

unsigned int Avatar::GetExp() const {
    return exp;
}

unsigned int Avatar::SetExp(unsigned int e) {
    exp = exp+e;
    if(exp >99){
        SetLvl(livello+1);
        exp = exp -100;
    }
        return exp;
}

unsigned int Avatar::SetForza(bool t) {
    if(t) return forza()+10;
    return forza()-10;
}

unsigned int Avatar::SetMagia(bool t) {
    if(t) return magia()+10;
    return magia()-10;
}

unsigned int Avatar::SetDifesa(bool t) {
    if(t) return difesa()+10;
    return difesa()-10;
}

unsigned int Avatar::SetScienza(bool t) {
    if(t) return scienza()+10;
    return scienza()-10;
}

//Metodi della classe Terrestre
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

bool Terrestre::SetScudo(bool s) {
    return scudo=s;
}

bool Terrestre::SetSpada(bool sp) {
    return spada=sp;
}

bool Terrestre::SetAnello(bool a) {
    return anello=a;
}

bool Terrestre::SetLibro(bool lib) {
    return libro=lib;
}

//Metodi della classe Elfo
unsigned int Elfo::GetTrasparentia() const {
    return trasparentia;
}

unsigned int Elfo::SetTrasparentia() {
    if(GetLiv()%5 == 0){
        trasparentia = trasparentia+(magia()%GetLiv());
    }
    return trasparentia;
}

unsigned int Elfo::forza() {
    if(GetSpada()) return GetLiv()*6+8;
    return GetLiv()*6;
}

unsigned int Elfo::magia() {
        if(GetAnello()) return GetLiv()*10+6;
        return GetLiv()*10;
}

unsigned int Elfo::difesa() {
    if(GetScu()) return GetLiv()*6+10;
    return GetLiv()*6;
}

unsigned int Elfo::scienza() {
    if(GetLibro()) return GetLiv()*5+5;
    return GetLiv()*5;
}

bool Elfo::operator==(const Avatar & a) const {
    if(a.GetNome()==this->GetNome()) return true;
    else return false;
}

//Metodi della classe Nano
unsigned int Nano::GetCorteccia() const {
    return corteccia;
}

unsigned int Nano::SetCorteccia() {
    if(GetLiv()%5 == 0){
        corteccia = corteccia+(difesa()%GetLiv());
    }
    return corteccia;
}

unsigned int Nano::forza() {
    if(GetSpada()) return GetLiv()*7+8;
    return GetLiv()*7;
}

unsigned int Nano::magia() {
    if(GetAnello()) return GetLiv()*2+6;
    return GetLiv()*2;
}

unsigned int Nano::difesa() {
    if(GetScu()) return GetLiv()*10+10;
    return GetLiv()*10;
}

unsigned int Nano::scienza() {
    if(GetLibro()) return GetLiv()*6+5;
    return GetLiv()*6;
}

bool Nano::operator==(const Avatar & a) const {
    if(a.GetNome()==this->GetNome()) return true;
    else return false;
}

//Metodi della classe Umano
unsigned int Umano::GetIngegno() const {
    return ingegnoScientifico;
}

unsigned int Umano::SetIngegno() {
    if(GetLiv()%5 == 0){
        ingegnoScientifico = ingegnoScientifico+(scienza()%GetLiv());
    }
    return ingegnoScientifico;
}

unsigned int Umano::forza() {
    if(GetSpada()) return GetLiv()*5+8;
    return GetLiv()*5;
}

unsigned int Umano::magia() {
    if(GetAnello()) return GetLiv()*3+6;
    return GetLiv()*3;
}

unsigned int Umano::difesa() {
    if(GetScu()) return GetLiv()*8+2;
    return GetLiv()*8;
}

unsigned int Umano::scienza() {
    if(GetLibro()) return GetLiv()*8+5;
    return GetLiv()*8;
}

bool Umano::operator==(const Avatar & a) const {
    if(a.GetNome()==this->GetNome()) return true;
    else return false;
}

//Metodi della classe NOTerrestre
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

bool NOTerrestre::SetBarriera(bool ba) {
    return barriera=ba;
}

bool NOTerrestre::SetLaser(bool las) {
    return laser=las;
}

bool NOTerrestre::SetAmuleto(bool am) {
    return amuleto=am;
}

bool NOTerrestre::SetChip(bool ch) {
    return chip=ch;
}

//Metodi della classe Alieno
unsigned int Alieno::GetUfo() const {
    return ufo;
}

unsigned int Alieno::SetUfo() {
    if(GetLiv()%5 == 0){
        ufo = ufo+(scienza()%GetLiv());
    }
    return ufo;
}

unsigned int Alieno::forza() {
    if(GetLaser()) return GetLiv()*3+7;
    return GetLiv()*3;
}

unsigned int Alieno::scienza() {
    if(GetChip()) return GetLiv()*10+6;
    return GetLiv()*10;
}

unsigned int Alieno::magia() {
    if(GetAmuleto()) return GetLiv()*0+8;
    return GetLiv()*0;
}

unsigned int Alieno::difesa() {
    if(GetBar()) return GetLiv()*7+9;
    return GetLiv()*7;
}

unsigned int Alieno::velocitaVolo() {
    return 15*scienza();
}

bool Alieno::operator==(const Avatar & a) const {
    if(a.GetNome()==this->GetNome()) return true;
    else return false;
}

//Metodi della classe Mostro
unsigned int Mostro::GetPorta() const {
    return portaDemoniaca;
}

unsigned int Mostro::SetPorta() {
    if(GetLiv()%5 == 0) {
        portaDemoniaca = portaDemoniaca+(forza()%GetLiv());
    }
    return portaDemoniaca;
}

unsigned int Mostro::forza() {
    if(GetLaser()) return GetLiv()*10+7;
    return GetLiv()*10;
}

unsigned int Mostro::scienza() {
    if(GetChip()) return GetLiv()*10+6;
    return GetLiv()*0;
}
unsigned int Mostro::magia() {
    if(GetAmuleto()) return GetLiv()*5+8;
    return GetLiv()*5;
}

unsigned int Mostro::difesa() {
    if(GetBar()) return GetLiv()*9+9;
    return GetLiv()*9;
}

unsigned int Mostro::velocitaVolo(){
    return 15*forza();
}

bool Mostro::operator==(const Avatar & a) const {
    if(a.GetNome()==this->GetNome()) return true;
    else return false;
}

//metodi della classe ListaPersonaggi
