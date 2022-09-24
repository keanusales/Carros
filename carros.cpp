#include "carros.h"

int Carros::numCars = 0;
const int Carros::MINHP = 100;
const int Carros::MAXHP = 1000;
const int Carros::MODHP = 1800;
const int Carros::MAXCARS = 10;

void Carros::construct(Carros *array[], const string &nameCar, const int hpStock) {
  if (numCars + 1 <= MAXCARS) {
    array[numCars] = new Carros(nameCar, hpStock);
    system("clear||cls");
    cout << "Carro adicionado com sucesso!\n";
  } else {
    system("clear||cls");
    cout << "O número máximo de carros foi alcancado!\n";
  }
}

Carros::Carros(const string &nameCar, const int hpStock) {
  this -> nameCar = nameCar;
  this -> hpStock = verifyHP(hpStock);
  this -> hpAtual = this -> hpStock;
  this -> upLevel = 0;
  this -> numCars++;
}

Carros::Carros(const Carros &other) {
  this -> nameCar = other.nameCar;
  this -> hpStock = other.hpStock;
  this -> hpAtual = other.hpAtual;
  this -> upLevel = other.upLevel;
  this -> numCars++;
}

void Carros::destuct(Carros *array[], const int element) {
  if (verifyEscolha(element) && numCars) {
    delete array[element];
    for (int i = element; i < numCars; i++)
      array[i] = array[i+1];
    array[numCars] = NULL;
    system("clear||cls");
    cout << "Carro deletado com sucesso!\n";
  } else {
    system("clear||cls");
    cout << "Digite um valor especificado!\n";
  }
}

Carros::~Carros() { this -> numCars--; }

int Carros::verifyHP(const int hpStock) const {
  if (MINHP <= hpStock && hpStock <= MAXHP) return hpStock;
  if (hpStock <= MINHP) {
    system("clear||cls");
    cout << "Digite um HP no intervalo [100, 1000]\n";
    return MINHP;
  }
  system("clear||cls");
  cout << "Digite um HP no intervalo [100, 1000]\n";
  return MAXHP;
}

int Carros::verifyLevel(const int level) const {
  if (0 <= level && level <= 6) {
    system("clear||cls");
    cout << "Atualizacao realizada com sucesso!\n";
    return level;
  }
  system("clear||cls");
  cout << "Digite um valor no intevalo dado!\n";
  return upLevel;
}

bool Carros::verifyEscolha(const int escolha) {
  return (0 <= escolha && escolha < numCars);
}

void Carros::setStatus(const int level) {
  int store[7]; //Array é melhor que map
  store[0] = this -> hpStock;
  store[1] = this -> hpStock + 150;
  store[2] = this -> hpStock + 300;
  store[3] = this -> hpStock + 450;
  store[4] = this -> hpStock + 600;
  store[5] = this -> hpStock + 750;
  store[6] = this -> hpStock + 850;
  this -> upLevel = verifyLevel(level);
  this -> hpAtual = store[upLevel];
  this -> hpAtual = (hpAtual <= MODHP) ? hpAtual : MODHP;
}

void Carros::statusArray(Carros *array[]) {
  system("clear||cls");
  for (int i = 0; i < numCars; i++) {
    cout << "Horsepower do " << array[i]->nameCar << ": " << array[i]->hpAtual << "\n";
    cout << "Upgrade Level do " << array[i]->nameCar << ": " << array[i]->upLevel << "\n";
  }
}

void Carros::namesArray(Carros *array[]) {
  system("clear||cls");
  for (int i = 0; i < numCars; i++)
    cout << i << " - " << array[i]->nameCar << "\n";
}

int Carros::getMaxCars() { return MAXCARS; }