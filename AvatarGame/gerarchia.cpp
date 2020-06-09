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

std::string Avatar::SetNome(std::string n) {
    return nome = n;
}

std::string Avatar::setDescrizione(std::string d)
{
    return descrizione = d;
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

double Avatar::setMedia()
{
    return (setForza()+setMagia()+setDifesa()+setScienza())/4;
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
        trasparentia = trasparentia+(setMagia()%GetLiv());
    }
    return trasparentia;
}

std::string Elfo::getTipo() const
{
    return "Elfo";
}

unsigned int Elfo::setForza() {
    if(GetSpada()) return GetLiv()*6+8;
    return GetLiv()*6;
}

unsigned int Elfo::setMagia() {
        if(GetAnello()) return GetLiv()*10+6;
        return GetLiv()*10;
}

unsigned int Elfo::setDifesa() {
    if(GetScu()) return GetLiv()*6+10;
    return GetLiv()*6;
}

unsigned int Elfo::setScienza() {
    if(GetLibro()) return GetLiv()*5+5;
    return GetLiv()*5;
}

std::string Elfo::setTerreno()
{
    return "Regno incantato";
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
        corteccia = corteccia+(setDifesa()%GetLiv());
    }
    return corteccia;
}

std::string Nano::getTipo() const
{
    return "Nano";
}

unsigned int Nano::setForza() {
    if(GetSpada()) return GetLiv()*7+8;
    return GetLiv()*7;
}

unsigned int Nano::setMagia() {
    if(GetAnello()) return GetLiv()*2+6;
    return GetLiv()*2;
}

unsigned int Nano::setDifesa() {
    if(GetScu()) return GetLiv()*10+10;
    return GetLiv()*10;
}

unsigned int Nano::setScienza() {    if(GetLibro()) return GetLiv()*6+5;
    return GetLiv()*6;
                                }

std::string Nano::setTerreno()
{
    return "Regno del sottosuolo";
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
        ingegnoScientifico = ingegnoScientifico+(setScienza()%GetLiv());
    }
    return ingegnoScientifico;
}

std::string Umano::getTipo() const
{
    return "Umano";
}

unsigned int Umano::setForza() {
    if(GetSpada()) return GetLiv()*5+8;
    return GetLiv()*5;
}

unsigned int Umano::setMagia() {
    if(GetAnello()) return GetLiv()*3+6;
    return GetLiv()*3;
}

unsigned int Umano::setDifesa() {
    if(GetScu()) return GetLiv()*8+2;
    return GetLiv()*8;
}

unsigned int Umano::setScienza() {
    if(GetLibro()) return GetLiv()*8+5;
    return GetLiv()*8;
}

std::string Umano::setTerreno()
{
    return "Regno delle macchine";
}

bool Umano::operator==(const Avatar & a) const {
    if(a.GetNome()==this->GetNome()) return true;
    else return false;
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
        ufo = ufo+(setScienza()%GetLiv());
    }
    return ufo;
}

std::string Alieno::getTipo() const
{
    return "Alieno";
}

unsigned int Alieno::setForza() {
    if(GetLaser()) return GetLiv()*3+7;
    return GetLiv()*3;
}

unsigned int Alieno::setScienza() {
    if(GetChip()) return GetLiv()*10+6;
    return GetLiv()*10;
}

std::string Alieno::setTerreno()
{
    return "Regno dello spazio";
}

unsigned int Alieno::setMagia() {
    if(GetAmuleto()) return GetLiv()*0+8;
    return GetLiv()*0;
}

unsigned int Alieno::setDifesa() {
    if(GetBar()) return GetLiv()*7+9;
    return GetLiv()*7;
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
        portaDemoniaca = portaDemoniaca+(getForza()%GetLiv());
    }
    return portaDemoniaca;
}

std::string Mostro::getTipo() const
{
    return "Mostro";
}

unsigned int Mostro::setForza() {
    if(GetLaser()) return GetLiv()*10+7;
    return GetLiv()*10;
}

unsigned int Mostro::setScienza() {
    if(GetChip()) return GetLiv()*10+6;
    return GetLiv()*0;
}

std::string Mostro::setTerreno()
{
    return "Regno dei demoni";
}
unsigned int Mostro::setMagia() {
    if(GetAmuleto()) return GetLiv()*5+8;
    return GetLiv()*5;
}

unsigned int Mostro::setDifesa() {
    if(GetBar()) return GetLiv()*9+9;
    return GetLiv()*9;
}

bool Mostro::operator==(const Avatar & a) const {
    if(a.GetNome()==this->GetNome()) return true;
    else return false;
}

//metodi della classe ListaPersonaggi
