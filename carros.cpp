#include "carros.h"

int Carros::numCars = 0;
int Carros::numUpDone = 0;
const int Carros::MINHP = 250;
const int Carros::MAXHP = 700;
const int Carros::MODHP = 1500;

Carros::Carros(const string & nameCar, int hpStock)
:upLevel(0), isDanger(0) {
  this -> nameCar = nameCar;
  this -> hpStock = verifyHP(hpStock);
  this -> hpAtual = this -> hpStock;
  this -> numCars++;
}

Carros::Carros(const Carros & other) {
  this -> nameCar = other.nameCar;
  this -> hpStock = other.hpStock;
  this -> hpAtual = other.hpAtual;
  this -> upLevel = other.upLevel;
  this -> isDanger = other.isDanger;
  this -> numCars++;
}

int Carros::verifyHP(int hpStock) const {
  if (MINHP <= hpStock && hpStock <= MAXHP) return hpStock;
  if (MINHP >= hpStock) {
    // system("clear||cls");
    cout << "Digite um HP no intervalo [250, 700]\n";
    return MINHP;
  }
  // system("clear||cls");
  cout << "Digite um HP no intervalo [250, 700]\n";
  return MAXHP;
}

int Carros::verifyLevel(int level) const {
  if (0 <= level && level <= 6) {
    // system("clear||cls");
    cout << "Atualizacao realizada com sucesso!\n";
    return level;
  }
  // system("clear||cls");
  cout << "Digite um valor no intevalo dado!\n";
  return upLevel;
}

void Carros::setStatus(int level) {
  map <const int, int> store;
  store[0] = this -> hpStock;
  store[1] = this -> hpStock + 150;
  store[2] = this -> hpStock + 300;
  store[3] = this -> hpStock + 450;
  store[4] = this -> hpStock + 600;
  store[5] = this -> hpStock + 750;
  store[6] = this -> hpStock + 850;
  this -> upLevel = verifyLevel(level);
  int temp = store.find(upLevel) -> second;
  this -> isDanger = (temp > 1000) ? 1 : 0;
  this -> hpAtual = (temp <= MODHP) ? temp : MODHP;
  numUpDone++;
}

void Carros::getStatus() const {
  cout << "Horsepower do " << nameCar << ": " << hpAtual << "\n";
  cout << "Upgrade Level do " << nameCar << ": " << upLevel << "\n";
}

void Carros::getDanger() const {
  cout << "E perigoso? " << isDanger << "\n";
}

string Carros::getName() const { return nameCar; }

void Carros::getNumCars() {
  cout << "Quantidade atual de carros: " << numCars << "\n";
}

void Carros::getNumDone() {
  cout << "Numero de alteracoes feitas: " << numUpDone << "\n";
}