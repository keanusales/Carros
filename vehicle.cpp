#include "chassis.cpp"

// IMPLEMENTAÇÃO

const unsigned Vehicle::MAXLEN = 40;

Vehicle::Vehicle(const string &nameVeh) {
  this->nameVeh = nameVeh;
  this->diaCria = getDiaCria();
}

Vehicle::Vehicle(const Vehicle &other) {
  this->nameVeh = other.nameVeh;
  this->diaCria = getDiaCria();
}

Vehicle *Vehicle::create(const newVeh &vehicle) {
  if (vehicle.type == 1) {
    const argCarros args = {
      Engine::getHpStock(),
      Transm::getTimeSwap(),
      Chassis::getGForce()
    };
    return new Carros(vehicle.name, args);
  }
  const argTrucks args = {
    Engine::getHpStock(),
    Transm::getTimeSwap()
  };
  return new Trucks(vehicle.name, args);
}

const bool Vehicle::verString(const string &nameVeh) {
  return (nameVeh.size() <= MAXLEN);
}

const bool Vehicle::verCreate(const unsigned escolha) {
  return (1 <= escolha && escolha <= 2);
}

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Vehicle &vehicle) {
  output << "Veiculo: " << vehicle.nameVeh << "\n";
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