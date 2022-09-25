#include "carros.h"

int Carros::numCars = 0;
const int Carros::MAXLEN = 30;
const int Carros::MINHP = 100;
const int Carros::MAXHP = 1000;
const int Carros::MODHP = 1800;
const int Carros::MAXCARS = 10;

Carros::Carros(const string &nameCar, const int hpStock) {
  this -> nameCar = nameCar;
  this -> hpStock = hpStock;
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

Carros::~Carros() { this -> numCars--; }

void Carros::setNewCar(Carros *array[]) {
  system("cls||clear");
  if (numCars + 1 <= MAXCARS) {
    string nameCar; int hpStock;
    while (1) {
      cout << "Digite o nome do carro: ";
      cin.ignore(); getline(cin, nameCar);
      if (verifyName(nameCar)) break;
      system("cls||clear");
      cout << "Tamanho maximo alcancado!\n";
    }
    while (1) {
      cout << "Digite a potencia do carro: ";
      cin >> hpStock;
      if (verifyHP(hpStock)) break;
      system("cls||clear");
      cout << "Digite entre 100 e 1000!\n";
    }
    int posicao = numCars;
    array[posicao] = new Carros(nameCar, hpStock);
    system("cls||clear");
    cout << "Carro adicionado com sucesso!\n";
    return;
  }
  cout << "Numero maximo de carros alcancado!\n";
}

void Carros::copyExtCar(Carros *array[]) {
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para copiar!\n";
    return;
  }
  if (numCars + 1 > MAXCARS) {
    system("cls||clear");
    cout << "Numero maximo de carros alcancado!\n";
    return;
  }
  int escolha = getEscolha(array);
  if (verifyEscolha(escolha)) {
    int posicao = numCars;
    array[posicao] = new Carros(*array[escolha]);
    system("cls||clear");
    cout << "Carro adicionado com sucesso!\n";
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void Carros::deleteCar(Carros *array[]) {
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para deletar!\n";
    return;
  }
  int escolha = getEscolha(array);
  if (verifyEscolha(escolha)) {
    delete array[escolha];
    for (int i = escolha; i < numCars; i++)
      array[i] = array[i+1];
    array[numCars] = NULL;
    system("cls||clear");
    cout << "Carro deletado com sucesso!\n";
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void Carros::chooseCar(Carros *array[]) {
  int escolha = getEscolha(array);
  if (verifyEscolha(escolha)) {
    cout << "Qual a mofificacao desejada? [0, 6]: ";
    int level; cin >> level;
    array[escolha]->verifyLevel(level);
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

int Carros::getEscolha(Carros *array[]) {
  system("cls||clear");
  for (int i = 0; i < numCars; i++)
    cout << i << " - " << array[i]->nameCar << "\n";
  cout << "Qual opcao voce escolhe? ";
  int escolha; cin >> escolha;
  return escolha;
}

bool Carros::verifyEscolha(const int escolha) {
  return (0 <= escolha && escolha < numCars);
}

bool Carros::verifyName(const string &nameCar) {
  return (nameCar.length() <= MAXLEN);
}

bool Carros::verifyHP(const int hpStock) {
  return (MINHP <= hpStock && hpStock <= MAXHP);
}

void Carros::getStatusArray(Carros *array[]) {
  system("cls||clear");
  for (int i = 0; i < numCars; i++) {
    int hp = array[i]->hpAtual;
    int up = array[i]->upLevel;
    string name = array[i]->nameCar;
    cout << "Horsepower do " << name << ": " << hp << "\n";
    cout << "Upgrade Level do " << name << ": " << up << "\n";
  }
}

void Carros::verifyLevel(const int level) {
  if (0 <= level && level <= 6) {
    setStatus(level);
    system("cls||clear");
    cout << "Atualizacao realizada com sucesso!\n";
    return;
  }
  system("cls||clear");
  cout << "Digite um nivel no intevalo dado!\n";
}

void Carros::setStatus(const int level) {
  const int store[7] = {0, 150, 300, 450, 600, 750, 850};
  this -> hpAtual = this -> hpStock + store[level];
  if (hpAtual > MODHP) this -> hpAtual = MODHP;
  this -> upLevel = level;
}

int Carros::getMaxCars() { return MAXCARS; }