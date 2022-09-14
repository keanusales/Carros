#include "carros.h"

Carros::Carros(int hpStock)
:MINHP(250)
{
  this -> hpStock = verifyHP(hpStock);
  this -> hpAtual = this -> hpStock;
  this -> upLevel = 0;
}

Carros::Carros(const Carros & other) 
:MINHP(250)
{
  this -> hpStock = other.hpStock;
  this -> hpAtual = other.hpAtual;
}

int Carros::verifyHP(int hpStock) const {
  if (MINHP <= hpStock && hpStock <= MAXHP) return hpStock;
  system("clear||cls");
  cout << "Digite um HP no intervalo [250, 700]\n";
  return MINHP;
}

int Carros::verifyLevel(int level) const {
  if (0 <= level && level <= 6) {
    system("clear||cls");
    cout << "Atualizacao realizada com sucesso!\n";
    return level;
  }
  system("clear||cls");
  cout << "Digite um valor no intevalo dado!\n";
  return upLevel;
}

void Carros::setStatus(int level) {
  this -> upLevel = verifyLevel(level);
  if (upLevel == 0) this -> hpAtual = hpStock;
  else if (upLevel == 1) this -> hpAtual = hpStock + 150;
  else if (upLevel == 2) this -> hpAtual = hpStock + 300;
  else if (upLevel == 3) this -> hpAtual = hpStock + 450;
  else if (upLevel == 4) this -> hpAtual = hpStock + 600;
  else if (upLevel == 5) this -> hpAtual = hpStock + 750;
  else this -> hpAtual = hpStock + 850;
  this -> hpAtual = (hpAtual <= MODHP) ? hpAtual : MODHP;
}

void Carros::getStatus(string nome) const {
  cout << "Horsepower do " << nome << ": " << hpAtual << "\n";
  cout << "Upgrade Level do " << nome << ": " << upLevel << "\n";
}