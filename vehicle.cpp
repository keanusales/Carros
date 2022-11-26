#include "chassis.cpp"

// IMPLEMENTAÇÃO

const unsigned Vehicle::MAXLEN = 40;
const unsigned Vehicle::MINPOWER = 100;
const unsigned Vehicle::MAXPOWER = 1000;

Vehicle::Vehicle(const string &nameVeh, const unsigned hpStock) {
  this -> nameVeh = nameVeh;
  this -> hpStock = hpStock;
  this -> hpAtual = hpStock;
  this -> diaCria = getDiaCria();
}

Vehicle::Vehicle(const Vehicle &other) {
  this -> nameVeh = other.nameVeh;
  this -> hpStock = other.hpStock;
  this -> hpAtual = other.hpStock;
  this -> diaCria = getDiaCria();
}

Vehicle *Vehicle::create(const newVeh &vehicle) {
  if (vehicle.type == 1)
    return new Carros(vehicle.name, vehicle.hpStock);
  return new Trucks(vehicle.name, vehicle.hpStock);
}

const bool Vehicle::verString(const string &nameVeh) {
  return (nameVeh.size() <= MAXLEN);
}

const bool Vehicle::verCreate(const unsigned escolha) {
  return (1 <= escolha && escolha <= 2);
}

const bool Vehicle::verHpower(const unsigned hpStock) {
  return (MINPOWER <= hpStock && hpStock <= MAXPOWER);
}

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Vehicle &vehicle) {
  output << "Veiculo: " << vehicle.nameVeh << "\n";
  output << "Horsepower: " << vehicle.hpAtual << "\n";
  output << "Criacao: " << vehicle.diaCria << "\n\n";
  vehicle.output(output);
  return output;
}

ostream &operator<<(ostream &output, const Vehicle *vehicle) {
  output << vehicle->nameVeh;
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