#include "mammoth.cpp"

void calling(const unsigned opcao, vecVeh &vehtor) {
  typedef void (*action)(vecVeh &);
  const action actions[] = {
    &createCar, &copyExtCar, &deleteCar, &getStatus, &tiraTeima,
    &setInterns, &setTurbos, &setIntake, &setExaust, &setECUnit,
    &setTransm, &setSuspens, &setChassis, &exitProgram
  };
  (*actions[opcao])(vehtor);
}

void createCar(vecVeh &vehtor) {
  unsigned type;
  system("cls||clear");
  while (1) {
    string input;
    cout << "1 - O novo veiculo e uma F150\n"
      << "2 - O novo veiculo e uma Mammoth\n"
      << "3 - O novo veiculo e uma Corvette\n"
      << "4 - O novo veiculo e uma 911 GT2\n"
      << "5 - O novo veiculo e um Carro\n" 
      << "Qual tipo de veiculo voce quer? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> type &&
      Vehicle::verCreate(type)) break;
    system("cls||clear");
    cout << "Digite um dos tipos especificados!\n";
  }
  vehtor.push_back(Vehicle::create(type));
  system("cls||clear");
  cout << "Carro adicionado com sucesso!\n";
}

void copyExtCar(vecVeh &vehtor) {
  if (notexts("copiar", vehtor)) return;
  const unsigned escolha = getEscolha(vehtor);
  vehtor.push_back(vehtor[escolha]->clone());
  system("cls||clear");
  cout << "Carro adicionado com sucesso!\n";
}

void deleteCar(vecVeh &vehtor) {
  if (notexts("deletar", vehtor)) return;
  const unsigned escolha = getEscolha(vehtor);
  delete vehtor[escolha];
  vehtor.erase(vehtor.begin() + escolha);
  system("cls||clear");
  cout << "Carro deletado com sucesso!\n";
}

void getStatus(vecVeh &vehtor) {
  if (notexts("mostrar", vehtor)) return;
  const unsigned escolha = getEscolha(vehtor);
  system("cls||clear");
  cout << *vehtor[escolha];
}

void tiraTeima(vecVeh &vehtor) {
  if (notexts("tirar-teima", vehtor)) return;
  vehtor[getEscolha(vehtor)]->tiraTeima();
}

void setInterns(vecVeh &vehtor) {
  if (notexts("modificar", vehtor)) return;
  vehtor[getEscolha(vehtor)]->setInterns();
}

void setTurbos(vecVeh &vehtor) {
  if (notexts("modificar", vehtor)) return;
  vehtor[getEscolha(vehtor)]->setTurbos();
}

void setIntake(vecVeh &vehtor) {
  if (notexts("modificar", vehtor)) return;
  vehtor[getEscolha(vehtor)]->setIntake();
}

void setExaust(vecVeh &vehtor) {
  if (notexts("modificar", vehtor)) return;
  vehtor[getEscolha(vehtor)]->setExaust();
}

void setECUnit(vecVeh &vehtor) {
  if (notexts("modificar", vehtor)) return;
  vehtor[getEscolha(vehtor)]->setECUnit();
}

void setTransm(vecVeh &vehtor) {
  if (notexts("modificar", vehtor)) return;
  vehtor[getEscolha(vehtor)]->setTransm();
}

void setSuspens(vecVeh &vehtor) {
  if (notexts("modificar", vehtor)) return;
  vehtor[getEscolha(vehtor)]->setSuspens();
}

void setChassis(vecVeh &vehtor) {
  if (notexts("modificar", vehtor)) return;
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

const bool notexts(const char *action, vecVeh &vehtor) {
  if (!vehtor.size()) {
    system("cls||clear");
    cout << "Nao ha carros para " << action << "!\n";
    return 1;
  }
  return 0;
}