#include "trucks.cpp"

const int MAXVEHICLES = Vehicle::getMaxVehicle();

const int selectOption() {
  while (1) {
    string input; int opcao;
    cout << "1 - Criar um novo veiculo\n"
      << "2 - Copiar um veiculo ja existente\n"
      << "3 - Deletar um veiculo existente\n"
      << "4 - Printar estado atual de um veiculo\n"
      << "5 - Setar internos de um veiculo\n"
      << "6 - Setar turbo de um veiculo\n"
      << "7 - Setar intake de um veiculo\n"
      << "8 - Setar exaust de um veiculo\n"
      << "9 - Setar eletronics de um veiculo\n"
      << "10 - Setar transmission de um veiculo\n"
      << "11 - Setar suspension de um veiculo\n"
      << "12 - Setar chassis de um veiculo\n"
      << "13 - Sair do programa\n"
      << "Qual opcao voce escolhe? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> opcao) return opcao;
    system("clear||cls");
    cout << "Entrada invalida! Tente de novo!\n";
  }
}

void createCar(Vehicle *vehiclePtr[]) {
  if (maximumVehicles()) return;
  const int numVehicle = Vehicle::getNumVehicle();
  newVeh vehicle;
  system("cls||clear");
  while (1) {
    string input;
    cout << "1 - O novo veiculo e um Carro\n"
      << "2 - O novo veiculo e um Truck\n"
      << "Qual tipo de veiculo voce quer? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> vehicle.typeVehicle)
      if (verCreate(vehicle.typeVehicle)) break;
    system("cls||clear");
    cout << "Digite um dos tipos especificados!\n";
  }
  while (1) {
    cout << "Digite o nome do veiculo: ";
    getline(cin, vehicle.nameVehicle);
    if (verName(vehicle.nameVehicle)) break;
    system("cls||clear");
    cout << "Nome muito grande! Diminua!\n";
  }
  while (1) {
    string input;
    cout << "Digite a potencia do veiculo: ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> vehicle.hpStock)
      if (verHpStock(vehicle.hpStock)) break;
    system("cls||clear");
    cout << "Hp deve ficar entre 100 e 1000!\n";
  }
  vehiclePtr[numVehicle] = Vehicle::create(vehicle);
  system("cls||clear");
  cout << "Carro adicionado com sucesso!\n";
}

void copyExtCar(Vehicle *vehiclePtr[]) {
  if (existsVeh("copiar")) return;
  if (maximumVehicles()) return;
  const int numVehicle = Vehicle::getNumVehicle();
  const int escolha = getEscolha(vehiclePtr);
  if (verEscolha(escolha)) {
    vehiclePtr[numVehicle] = vehiclePtr[escolha]->clone();
    system("cls||clear");
    cout << "Carro adicionado com sucesso!\n";
    return;
  }
  system("cls||clear");
  cout << "Digite um veiculo especificado!\n";
}

void deleteCar(Vehicle *vehiclePtr[]) {
  if (existsVeh("deletar")) return;
  int numVehicle = Vehicle::getNumVehicle();
  const int escolha = getEscolha(vehiclePtr);
  if (verEscolha(escolha)) {
    delete vehiclePtr[escolha]; numVehicle--;
    for (int i = escolha; i < numVehicle; i++)
      vehiclePtr[i] = vehiclePtr[i+1];
    vehiclePtr[numVehicle] = 0;
    system("cls||clear");
    cout << "Carro deletado com sucesso!\n";
    return;
  }
  system("cls||clear");
  cout << "Digite um veiculo especificado!\n";
}

void getAtributes(Vehicle *vehiclePtr[]) {
  if (existsVeh("mostrar")) return;
  const int escolha = getEscolha(vehiclePtr);
  if (verEscolha(escolha)) {
    system("cls||clear");
    cout << *vehiclePtr[escolha];
    return;
  }
  system("cls||clear");
  cout << "Digite um veiculo especificado!\n";
}

void setInternals(Vehicle *vehiclePtr[]) {
  if (existsVeh("modificar")) return;
  const int escolha = getEscolha(vehiclePtr);
  if (verEscolha(escolha)) {
    vehiclePtr[escolha]->setInternals();
    return;
  }
  system("cls||clear");
  cout << "Digite um veiculo especificado!\n";
}

void setTurbos(Vehicle *vehiclePtr[]) {
  if (existsVeh("modificar")) return;
  const int escolha = getEscolha(vehiclePtr);
  if (verEscolha(escolha)) {
    vehiclePtr[escolha]->setTurbos();
    return;
  }
  system("cls||clear");
  cout << "Digite um veiculo especificado!\n";
}

void setIntake(Vehicle *vehiclePtr[]) {
  if (existsVeh("modificar")) return;
  const int escolha = getEscolha(vehiclePtr);
  if (verEscolha(escolha)) {
    vehiclePtr[escolha]->setIntake();
    return;
  }
  system("cls||clear");
  cout << "Digite um veiculo especificado!\n";
}

void setExaust(Vehicle *vehiclePtr[]) {
  if (existsVeh("modificar")) return;
  const int escolha = getEscolha(vehiclePtr);
  if (verEscolha(escolha)) {
    vehiclePtr[escolha]->setExaust();
    return;
  }
  system("cls||clear");
  cout << "Digite um veiculo especificado!\n";
}

void setECUnit(Vehicle *vehiclePtr[]) {
  if (existsVeh("modificar")) return;
  const int escolha = getEscolha(vehiclePtr);
  if (verEscolha(escolha)) {
    vehiclePtr[escolha]->setECUnit();
    return;
  }
  system("cls||clear");
  cout << "Digite um veiculo especificado!\n";
}

void setTransmiss(Vehicle *vehiclePtr[]) {
  if (existsVeh("modificar")) return;
  const int escolha = getEscolha(vehiclePtr);
  if (verEscolha(escolha)) {
    vehiclePtr[escolha]->setTransmiss();
    return;
  }
  system("cls||clear");
  cout << "Digite um veiculo especificado!\n";
}

void setSuspens(Vehicle *vehiclePtr[]) {
  if (existsVeh("modificar")) return;
  const int escolha = getEscolha(vehiclePtr);
  if (verEscolha(escolha)) {
    vehiclePtr[escolha]->setSuspens();
    return;
  }
  system("cls||clear");
  cout << "Digite um veiculo especificado!\n";
}

void setChassis(Vehicle *vehiclePtr[]) {
  if (existsVeh("modificar")) return;
  const int escolha = getEscolha(vehiclePtr);
  if (verEscolha(escolha)) {
    vehiclePtr[escolha]->setChassis();
    return;
  }
  system("cls||clear");
  cout << "Digite um veiculo especificado!\n";
}

void exitProgram(Vehicle *vehiclePtr[]) {
  const int numVehicle = Vehicle::getNumVehicle();
  for (int i = 0; i < numVehicle; i++) {
    delete vehiclePtr[i]; vehiclePtr[i] = 0;
  }
  system("clear||cls");
  cout << "Ate a proxima vez!\n";
}

const int getEscolha(Vehicle *vehiclePtr[]) {
  const int numVehicle = Vehicle::getNumVehicle();
  int escolha;
  system("cls||clear");
  while (1) {
    string input;
    for (int i = 0; i < numVehicle; i++)
      cout << i << " - " << vehiclePtr[i] << "\n";
    cout << "Qual opcao voce escolhe? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> escolha) break;
    system("cls||clear");
    cout << "Entrada invalida! Tente de novo!\n";
  }
  return escolha;
}

const bool existsVeh(const char *action) {
  const int numVehicle = Vehicle::getNumVehicle();
  if (!numVehicle) {
    system("cls||clear");
    printf("Nao ha veiculos para %s!\n", action);
    return 1;
  }
  return 0;
}

const bool maximumVehicles() {
  const int numVehicle = Vehicle::getNumVehicle();
  if (numVehicle + 1 > MAXVEHICLES) {
    system("cls||clear");
    cout << "Estamos no maximo de veiculos!\n";
    return 1;
  }
  return 0;
}

const bool verEscolha(const int escolha) {
  const int numVehicle = Vehicle::getNumVehicle();
  return (0 <= escolha && escolha < numVehicle);
}

const bool verCreate(const int escolha) {
  return (1 <= escolha && escolha <= 1);
}

const bool verName(const string &nameCar) {
  const int MAXLEN = Vehicle::getMaxLen();
  return (nameCar.length() <= MAXLEN);
}

const bool verHpStock(const int hpStock) {
  const int MINHP = Carros::getMinHP();
  const int MAXHP = Carros::getMaxHP();
  return (MINHP <= hpStock && hpStock <= MAXHP);
}