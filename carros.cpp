#include "carros.h"

Carros::Carros(const string &nameCar, const int hpStock) {
  this -> strAtributes = new string[ATRIBUTES];
  this -> strAtributes[NAMECAR] = nameCar;
  this -> strAtributes[TYPETIRES] = "Street";
  this -> strAtributes[TYPENGINE] = "Original";
  this -> intAtributes = new int[ATRIBUTES];
  this -> intAtributes[HPSTOCK] = hpStock;
  this -> intAtributes[HPATUAL] = hpStock;
  this -> intAtributes[UPLEVEL] = 0;
  this -> lenList = 0, maxLenList = 10;
  this -> toDoList = new string[maxLenList];
  for (int i = 0; i < maxLenList; i++)
    this -> toDoList[i] = "";
}

Carros::Carros(const Carros &other) {
  this -> strAtributes = new string[ATRIBUTES];
  for(int i = 0; i < ATRIBUTES; i++)
    this -> strAtributes[i] = other.strAtributes[i];
  this -> intAtributes = new int[ATRIBUTES];
  for(int i = 0; i <= ATRIBUTES; i++)
    this -> intAtributes[i] = other.intAtributes[i];
  this -> lenList = other.lenList;
  this -> maxLenList = other.maxLenList;
  this -> toDoList = new string[maxLenList];
  for (int i = 0; i < maxLenList; i++)
    this -> toDoList[i] = other.toDoList[i];
}

Carros::~Carros() {}

void Carros::verifyLevel(const int level) {
  if (0 <= level && level <= 6) {
    this -> setStatus(level);
    system("cls||clear");
    cout << "Atualizacao realizada com sucesso!\n";
    return;
  }
  system("cls||clear");
  cout << "Digite um nivel no intevalo dado!\n";
}

void Carros::setStatus(const int level) {
  this -> mapModHP(level);
  this -> mapTypeTires(level);
  this -> mapTypeEngine(level);
  this -> intAtributes[UPLEVEL] = level;
}

void Carros::mapModHP(const int level) {
  map <const int, int> modHP;
  modHP[0] = intAtributes[HPSTOCK];
  modHP[1] = intAtributes[HPSTOCK] + 150;
  modHP[2] = intAtributes[HPSTOCK] + 300;
  modHP[3] = intAtributes[HPSTOCK] + 450;
  modHP[4] = intAtributes[HPSTOCK] + 600;
  modHP[5] = intAtributes[HPSTOCK] + 750;
  modHP[6] = intAtributes[HPSTOCK] + 850;
  this -> intAtributes[HPATUAL] = modHP[level];
}

void Carros::mapTypeTires (const int level) {
  map <const int, string> typeTires;
  typeTires[0] = "Street";
  typeTires[1] = "Semi-Slick";
  typeTires[2] = "Semi-Slick";
  typeTires[3] = "Semi-Slick";
  typeTires[4] = "Slick";
  typeTires[5] = "Slick";
  typeTires[6] = "Slick";
  this -> strAtributes[TYPETIRES] = typeTires[level];
}

void Carros::mapTypeEngine(const int level) {
  map <const int, string> typeEngine;
  typeEngine[0] = "Original";
  typeEngine[1] = "Original w/ remap";
  typeEngine[2] = "Street";
  typeEngine[3] = "Street w/ remap";
  typeEngine[4] = "Sport";
  typeEngine[5] = "Sport w/ remap";
  typeEngine[6] = "Full Racing";
  this -> strAtributes[TYPENGINE] = typeEngine[level];
}

void Carros::getToDoList() const {
  system("cls||clear");
  if (!lenList) {
    cout << "Nao ha tarefas na lista!\n";
    return;
  }
  for (int i = 0; i < lenList; i++)
    cout << i << " - " << toDoList[i] << "\n";
}

void Carros::addToList(const string &newTarefa) {
  if (lenList + 1 > maxLenList) {
    string* aux = new string[lenList];
    for (int i = 0; i < lenList; i++)
      aux[i] = this -> toDoList[i];
    delete [] this -> toDoList;
    maxLenList += int(ceil(maxLenList*.5));
    this -> toDoList = new string[maxLenList];
    for (int i = 0; i < lenList; i++)
      this -> toDoList[i] = aux[i];
    for (int i = lenList; i < maxLenList; i++)
      this -> toDoList[i] = "";
    delete [] aux;
  }
  this -> toDoList[lenList] = newTarefa;
  lenList++; system("cls||clear");
  cout << "Tarefa Adicionada com sucesso!\n";
}

void Carros::getListIndex() {
  system("cls||clear");
  if (!lenList) {
    cout << "Nao ha tarefas na lista!\n";
    return;
  }
  int index;
  while (1) {
    string input;
    for (int i = 0; i < lenList; i++)
      cout << i << " - " << toDoList[i] << "\n";
    cout << "Qual opcao voce escolhe? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> index) break;
    system("cls||clear");
    cout << "Entrada invalida! Tente de novo!\n";
  }
  this -> verifyIndex(index);
}

void Carros::verifyIndex(const int index) {
  if (0 <= index && index < lenList) {
    this -> popFromList(index);
    system("cls||clear");
    cout << "Tarefa removida com sucesso!\n";
    return;
  }
  system("cls||clear");
  cout << "Digite um nivel no intevalo dado!\n";
}

void Carros::popFromList(const int index) {
  this -> lenList--;
  for (int i = index; i < lenList; i++)
    this -> toDoList[i] = toDoList[i+1];
  this -> toDoList[lenList] = "";
}

string Carros::getNameCar() const {
  return strAtributes[NAMECAR];
}

string Carros::getTTires() const {
  return strAtributes[TYPETIRES];
}

string Carros::getTEngine() const {
  return strAtributes[TYPENGINE];
}

int Carros::getHpAtual() const {
  return intAtributes[HPATUAL];
}

int Carros::getUpLevel() const {
  return intAtributes[UPLEVEL];
}

int Carros::getMaxLen() { return MAXLEN; }

int Carros::getMinHP() { return MINHP; }

int Carros::getMaxHP() { return MAXHP; }

int Carros::getMaxCars() { return MAXCARS; }