#include "carros.h"

int Carros::numCars = 0;
const int Carros::MAXLEN = 30;
const int Carros::MINHP = 100;
const int Carros::MAXHP = 1000;
const int Carros::MODHP = 1800;
const int Carros::MAXCARS = 10;
const int Carros::HPADD[] = {0, 150, 300, 450, 600, 750, 850};

Carros::Carros(const string &nameCar, const int hpStock) {
  this -> nameCar = nameCar;
  this -> hpStock = hpStock;
  this -> hpAtual = this -> hpStock;
  this -> modDone[0] = 0;
  this -> modDone[1] = 0;
  this -> upLevel = 0;
  this -> numCars++;
}

Carros::Carros(const Carros &other) {
  this -> nameCar = other.nameCar;
  this -> hpStock = other.hpStock;
  this -> hpAtual = other.hpAtual;
  this -> modDone[0] = other.modDone[0];
  this -> modDone[1] = other.modDone[1];
  this -> upLevel = other.upLevel;
  this -> numCars++;
}

Carros::~Carros() { this -> numCars--; }

void Carros::createCar(Carros *carroPtr[]) {
  system("cls||clear");
  if (numCars + 1 > MAXCARS) {
    cout << "Estamos no maximo de carros!\n";
    return;
  }
  string nameCar; int hpStock;
  while (1) {
    cout << "Digite o nome do carro: ";
    cin.ignore(); getline(cin, nameCar);
    if (verifyName(nameCar)) break;
    system("cls||clear");
    cout << "Nome muito grande! Diminua!\n";
  }
  while (1) {
    cout << "Digite a potencia do carro: ";
    cin >> hpStock;
    if (verifyHP(hpStock)) break;
    system("cls||clear");
    cout << "Hp deve ficar entre 100 e 1000!\n";
  }
  int posicao = numCars;
  carroPtr[posicao] = new Carros(nameCar, hpStock);
  system("cls||clear");
  cout << "Carro adicionado com sucesso!\n";
}

void Carros::copyExtCar(Carros *carroPtr[]) {
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para copiar!\n";
    return;
  }
  if (numCars + 1 > MAXCARS) {
    system("cls||clear");
    cout << "Estamos no maximo de carros!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (verifyEscolha(escolha)) {
    int posicao = numCars;
    carroPtr[posicao] = new Carros(*carroPtr[escolha]);
    system("cls||clear");
    cout << "Carro adicionado com sucesso!\n";
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void Carros::deleteCar(Carros *carroPtr[]) {
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para deletar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (verifyEscolha(escolha)) {
    delete carroPtr[escolha];
    for (int i = escolha; i < numCars; i++)
      carroPtr[i] = carroPtr[i+1];
    carroPtr[numCars] = NULL;
    system("cls||clear");
    cout << "Carro deletado com sucesso!\n";
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void Carros::modifyCar(Carros *carroPtr[]) {
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para modificar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (verifyEscolha(escolha)) {
    cout << "Qual a mofificacao desejada? [0, 6]: ";
    int level; cin >> level;
    carroPtr[escolha]->verifyLevel(level);
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

int Carros::getEscolha(Carros *carroPtr[]) {
  system("cls||clear");
  for (int i = 0; i < numCars; i++)
    cout << i << " - " << carroPtr[i]->nameCar << "\n";
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

void Carros::displayArray(Carros *carroPtr[]) {
  system("cls||clear");
  if (!numCars) {
    cout << "Nao ha carros para mostrar!\n";
    return;
  }
  for (int i = 0; i < numCars; i++) {
    int hp = carroPtr[i]->hpAtual;
    int up = carroPtr[i]->upLevel;
    string name = carroPtr[i]->nameCar;
    cout << "Horsepower do " << name << ": " << hp << "\n";
    cout << "Upgrade Level do " << name << ": " << up << "\n";
  }
}

void Carros::getModDone(Carros *carroPtr[]) {
  system("cls||clear");
  for (int i = 0; i < numCars; i++) {
    int downDone = carroPtr[i]->modDone[0];
    int upDone = carroPtr[i]->modDone[1];
    string name = carroPtr[i]->nameCar;
    cout << "Carro: " << name << " - Downgrades: " << downDone << "\n";
    cout << "Carro: " << name << " - Upgrades: " << upDone << "\n";
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
  this -> hpAtual = this -> hpStock + HPADD[level];
  if (hpAtual > MODHP) this -> hpAtual = MODHP;
  (level > upLevel) ? modDone[1]++ : modDone[0]++;
  this -> upLevel = level;
}

int Carros::getMaxCars() { return MAXCARS; }