#include "carros.h"

Carros::Carros() {
  horsepower = 250, upgradeLevel = 0;
}

Carros::~Carros() {}

void Carros::upgrade(int level) {
  if (level == 0) this -> horsepower = 250;
  else if (level == 1) this -> horsepower = 400;
  else if (level == 2) this -> horsepower = 550;
  else if (level == 3) this -> horsepower = 700;
  else if (level == 4) this -> horsepower = 800;
  else this -> horsepower = 900;
  this -> upgradeLevel = level;
}

void Carros::printState(string nome) const {
  cout << "Horsepower do " << nome << ": " << horsepower << endl;
  cout << "Upgrade Level do " << nome << ": " << upgradeLevel << endl;
}