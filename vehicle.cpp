#include "chassis.cpp"

// IMPLEMENTAÇÃO

int Vehicle::numVehicles = 0;
const int Vehicle::MAXLEN = 30;
const int Vehicle::MAXVEHICLES = 10;

Vehicle::Vehicle(const string &nameVehicle, const int hpStock) {
  this -> nameVehicle = nameVehicle;
  this -> hpStock = hpStock;
  this -> hpAtual = hpStock;
  this -> diaCria = getDiaCria();
  this -> numVehicles++;
}

Vehicle::Vehicle(const Vehicle &other) {
  this -> nameVehicle = other.nameVehicle;
  this -> hpStock = other.hpStock;
  this -> hpAtual = other.hpStock;
  this -> diaCria = getDiaCria();
  this -> numVehicles++;
}

Vehicle::~Vehicle() { this -> numVehicles--; }

Vehicle *Vehicle::create(const newVeh &vehicle) {
  if (vehicle.typeVehicle == 1)
    return new Carros(vehicle.nameVehicle, vehicle.hpStock);
  if (vehicle.typeVehicle == 2)
    return new Trucks(vehicle.nameVehicle, vehicle.hpStock);
  return 0;
}

const int Vehicle::getNumVehicle() { return numVehicles; }

const int Vehicle::getMaxLen() { return MAXLEN; }

const int Vehicle::getMaxVehicle() { return MAXVEHICLES; }

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Vehicle &vehicle) {
  output << "Veiculo: " << vehicle.nameVehicle << "\n";
  output << "Horsepower: " << vehicle.hpAtual << "\n";
  output << "Criacao: " << vehicle.diaCria << "\n\n";
  vehicle.getout(output);
  return output;
}

ostream &operator<<(ostream &output, const Vehicle *vehicle) {
  output << vehicle->nameVehicle;
  return output;
}

// SOBRECARGAS DOS STRUCTS

ostream &operator<<(ostream &output, const diaCria &elem) {
  output << elem.dia << "/" << elem.mes << "/" << elem.ano;
  return output;
}

const diaCria getDiaCria() {
  time_t now = time(0);
  tm *ltm = localtime(&now);
  const int dia = ltm->tm_mday;
  const int mes = 1 + ltm->tm_mon;
  const int ano = 1900 + ltm->tm_year;
  return {dia, mes, ano};
}