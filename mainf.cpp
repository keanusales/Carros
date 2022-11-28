#include "trucks.cpp"

void calling(const unsigned opcao, vecVeh &vehtor) {
  typedef void (*action)(vecVeh &);
  const action actions[] = {
    &createCar, &copyExtCar, &deleteCar, &getStatus,
    &setInterns, &setTurbos, &setIntake, &setExaust, &setECUnit,
    &setTransm, &setSuspens, &setChassis, &exitProgram
  };
  (*actions[opcao])(vehtor);
}

void createCar(vecVeh &vehtor) {
  newVeh vehicle;
  system("cls||clear");
  while (1) {
    string input;
    cout << "1 - O novo veiculo e um Carro\n"
      << "2 - O novo veiculo e um Truck\n"
      << "Qual tipo de veiculo voce quer? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> vehicle.type &&
      Vehicle::verCreate(vehicle.type)) break;
    system("cls||clear");
    cout << "Digite um dos tipos especificados!\n";
  }
  while (1) {
    cout << "Digite o nome do veiculo: ";
    getline(cin, vehicle.name);
    if (Vehicle::verString(vehicle.name)) break;
    system("cls||clear");
    cout << "Nome muito grande! Diminua!\n";
  }
  while (1) {
    string input;
    cout << "Digite a potencia do veiculo: ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> vehicle.hpStock &&
      Vehicle::verHpower(vehicle.hpStock)) break;
    system("cls||clear");
    cout << "Hp deve ficar entre 100 e 1000!\n";
  }
  vehtor.push_back(Vehicle::create(vehicle));
  system("cls||clear");
  cout << "Carro adicionado com sucesso!\n";
}

void copyExtCar(vecVeh &vehtor) {
  if (!exists("copiar", vehtor)) return;
  const unsigned escolha = getEscolha(vehtor);
  vehtor.push_back(vehtor[escolha]->clone());
  system("cls||clear");
  cout << "Carro adicionado com sucesso!\n";
}

void deleteCar(vecVeh &vehtor) {
  if (!exists("deletar", vehtor)) return;
  const unsigned escolha = getEscolha(vehtor);
  delete vehtor[escolha];
  const unsigned tam = vehtor.size() - 1;
  for (unsigned i = escolha; i < tam; i++)
    vehtor[i] = vehtor[i+1];
  vehtor.pop_back();
  system("cls||clear");
  cout << "Carro deletado com sucesso!\n";
}

void getStatus(vecVeh &vehtor) {
  if (!exists("mostrar", vehtor)) return;
  const unsigned escolha = getEscolha(vehtor);
  system("cls||clear");
  cout << *vehtor[escolha];
}

void setInterns(vecVeh &vehtor) {
  if (!exists("modificar", vehtor)) return;
  vehtor[getEscolha(vehtor)]->setInterns();
}

void setTurbos(vecVeh &vehtor) {
  if (!exists("modificar", vehtor)) return;
  vehtor[getEscolha(vehtor)]->setTurbos();
}

void setIntake(vecVeh &vehtor) {
  if (!exists("modificar", vehtor)) return;
  vehtor[getEscolha(vehtor)]->setIntake();
}

void setExaust(vecVeh &vehtor) {
  if (!exists("modificar", vehtor)) return;
  vehtor[getEscolha(vehtor)]->setExaust();
}

void setECUnit(vecVeh &vehtor) {
  if (!exists("modificar", vehtor)) return;
  vehtor[getEscolha(vehtor)]->setECUnit();
}

void setTransm(vecVeh &vehtor) {
  if (!exists("modificar", vehtor)) return;
  vehtor[getEscolha(vehtor)]->setTransm();
}

void setSuspens(vecVeh &vehtor) {
  if (!exists("modificar", vehtor)) return;
  vehtor[getEscolha(vehtor)]->setSuspens();
}

void setChassis(vecVeh &vehtor) {
  if (!exists("modificar", vehtor)) return;
  vehtor[getEscolha(vehtor)]->setChassis();
}

void exitProgram(vecVeh &vehtor) {
  for (Vehicle *elem : vehtor) delete elem;
  vehtor.~vector();
  system("clear||cls");
  cout << "Ate a proxima vez!\n";
  exit(0);
}

const unsigned getEscolha(vecVeh &vehtor) {
  system("cls||clear");
  while (1) {
    string input; unsigned escolha, i = 0;
    for (Vehicle *elem : vehtor)
      cout << i++ << " - " << elem << "\n";
    cout << "Qual opcao voce escolhe? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> escolha &&
      escolha < vehtor.size()) return escolha;
    system("cls||clear");
    cout << "Digite um veiculo especificado!\n";
  }
}

const bool exists(const char *action, vecVeh &vehtor) {
  if (!vehtor.size()) {
    system("cls||clear");
    cout << "Nao ha carros para " << action << "!\n";
    return 0;
  }
  return 1;
}