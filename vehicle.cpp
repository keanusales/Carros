#include "chassis.cpp"

// IMPLEMENTAÇÃO

Vehicle::Vehicle(const string &nameVehicle, const unsigned hpStock) {
  this -> nameVehicle = nameVehicle;
  this -> hpStock = hpStock;
  this -> hpAtual = hpStock;
  this -> diaCria = getDiaCria();
}

Vehicle::Vehicle(const Vehicle &other) {
  this -> nameVehicle = other.nameVehicle;
  this -> hpStock = other.hpStock;
  this -> hpAtual = other.hpStock;
  this -> diaCria = getDiaCria();
}

string Vehicle::getName() const { return nameVehicle; }

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Vehicle &vehicle) {
  output << "Veiculo: " << vehicle.nameVehicle << "\n";
  output << "Horsepower: " << vehicle.hpAtual << "\n";
  output << "Criacao: " << vehicle.diaCria << "\n";
  return output;
}

// SOBRECARGAS DOS STRUCTS

ostream &operator<<(ostream &output, const diaCria &elem) {
  output << elem.dia << "/" << elem.mes << "/" << elem.ano;
  return output;
}

const diaCria getDiaCria() {
  const time_t now = time(0);
  const tm ltm = *localtime(&now);
  const unsigned dia = ltm.tm_mday;
  const unsigned mes = 1 + ltm.tm_mon;
  const unsigned ano = 1900 + ltm.tm_year;
  return {dia, mes, ano};
}