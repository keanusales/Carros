#include "carros.cpp"

const int MAXCARS = Carros::getMaxCars();

int selectOption() {
  while (1) {
    string input; int opcao;
    cout << "1 - Criar um novo carro\n"
      << "2 - Copiar um carro ja existente\n"
      << "3 - Deletar um carro existente\n"
      << "4 - Printar estado atual dos carros\n"
      << "5 - Printar modificacoes feitas\n"
      << "6 - Deletar uma modificacao feita\n"
      << "7 - Setar internos de um carro\n"
      << "8 - Setar turbo de um carro\n"
      << "9 - Setar intake de um carro\n"
      << "10 - Setar exaust de um carro\n"
      << "11 - Setar eletronics de um carro\n"
      << "12 - Setar transmission de um carro\n"
      << "13 - Setar suspension de um carro\n"
      << "14 - Setar chassis de um carro\n"
      << "15 - Sair do programa\n"
      << "Qual opcao voce escolhe? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> opcao) return opcao;
    system("clear||cls");
    cout << "Entrada invalida! Tente de novo!\n";
  }
}

void createCar(Carros *carroPtr[]) {
  const int numCars = Carros::getNumCars();
  system("cls||clear");
  if (numCars + 1 > MAXCARS) {
    cout << "Estamos no maximo de carros!\n";
    return;
  }
  string nameCar; int hpStock;
  while (1) {
    cout << "Digite o nome do carro: ";
    getline(cin, nameCar);
    if (verifyName(nameCar)) break;
    system("cls||clear");
    cout << "Nome muito grande! Diminua!\n";
  }
  while (1) {
    string input;
    cout << "Digite a potencia do carro: ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> hpStock)
      if (verifyHP(hpStock)) break;
    system("cls||clear");
    cout << "Hp deve ficar entre 100 e 1000!\n";
  }
  carroPtr[numCars] = new Carros(nameCar, hpStock);
  system("cls||clear");
  cout << "Carro adicionado com sucesso!\n";
}

void copyExtCar(Carros *carroPtr[]) {
  const int numCars = Carros::getNumCars();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para copiar!\n";
    return;
  }
  if (numCars + 1 > MAXCARS) {
    system("cls||clear");
    cout << "Estamos no maximo de carros!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (verifyEscolha(escolha)) {
    carroPtr[numCars] = new Carros(*carroPtr[escolha]);
    system("cls||clear");
    cout << "Carro adicionado com sucesso!\n";
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void deleteCar(Carros *carroPtr[]) {
  int numCars = Carros::getNumCars();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para deletar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (verifyEscolha(escolha)) {
    delete carroPtr[escolha]; numCars--;
    for (int i = escolha; i < numCars; i++)
      carroPtr[i] = carroPtr[i+1];
    carroPtr[numCars] = 0;
    system("cls||clear");
    cout << "Carro deletado com sucesso!\n";
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void getAtributes(Carros *carroPtr[]) {
  const int numCars = Carros::getNumCars();
  system("cls||clear");
  if (!numCars) {
    cout << "Nao ha carros para mostrar!\n";
    return;
  }
  for (int i = 0; i < numCars; i++)
    carroPtr[i]->getAtributes();
}

void getModsDone(Carros *carroPtr[]) {
  const int numCars = Carros::getNumCars();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para mostrar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (verifyEscolha(escolha)) {
    system("cls||clear");
    carroPtr[escolha]->getModsDone();
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void delModsDone(Carros *carroPtr[]) {
  const int numCars = Carros::getNumCars();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para mostrar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (verifyEscolha(escolha)) {
    int opcao;
    system("cls||clear");
    while (1) {
      string input;
      cout << "0 - Turbo\n"
        << "1 - Intake\n"
        << "2 - Exaust\n"
        << "3 - Eletronics\n"
        << "4 - Internals\n"
        << "5 - Transmission\n"
        << "6 - Suspension\n"
        << "7 - Chassis\n"
        << "Qual opcao voce escolhe? ";
      getline(cin, input);
      stringstream stream(input);
      if (stream >> opcao) break;
      system("clear||cls");
      cout << "Entrada invalida! Tente de novo!\n";
    }
    carroPtr[escolha]->delModsDone(opcao);
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void setInternals(Carros *carroPtr[]) {
  const int numCars = Carros::getNumCars();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para modificar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (verifyEscolha(escolha)) {
    int opcao;
    system("cls||clear");
    while (1) {
      string input;
      for (Carros::hpResis elem : Carros::internals)
        cout << elem.part << " - " << elem.hpResis << "\n";
      cout << "Qual opcao voce escolhe? ";
      getline(cin, input);
      stringstream stream(input);
      if (stream >> opcao && 0 <= opcao <= 5) break;
      system("clear||cls");
      cout << "Entrada invalida! Tente de novo!\n";
    }
    carroPtr[escolha]->setInternals(opcao);
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void setTurbo(Carros *carroPtr[]) {
  const int numCars = Carros::getNumCars();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para modificar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (verifyEscolha(escolha)) {
    int opcao;
    system("cls||clear");
    while (1) {
      string input;
      for (Carros::hpGain elem : Carros::turbos)
        cout << elem.part << " - " << elem.hpGain << "\n";
      cout << "Qual opcao voce escolhe? ";
      getline(cin, input);
      stringstream stream(input);
      if (stream >> opcao && 0 <= opcao <= 5) break;
      system("clear||cls");
      cout << "Entrada invalida! Tente de novo!\n";
    }
    carroPtr[escolha]->setTurbo(opcao);
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void setIntake(Carros *carroPtr[]) {
 const int numCars = Carros::getNumCars();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para modificar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (verifyEscolha(escolha)) {
    int opcao;
    system("cls||clear");
    while (1) {
      string input;
      for (Carros::hpGain elem : Carros::intake)
        cout << elem.part << " - " << elem.hpGain << "\n";
      cout << "Qual opcao voce escolhe? ";
      getline(cin, input);
      stringstream stream(input);
      if (stream >> opcao && 0 <= opcao <= 5) break;
      system("clear||cls");
      cout << "Entrada invalida! Tente de novo!\n";
    }
    carroPtr[escolha]->setIntake(opcao);
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void setExaust(Carros *carroPtr[]) {
  const int numCars = Carros::getNumCars();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para modificar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (verifyEscolha(escolha)) {
    int opcao;
    system("cls||clear");
    while (1) {
      string input;
      for (Carros::hpGain elem : Carros::exaust)
        cout << elem.part << " - " << elem.hpGain << "\n";
      cout << "Qual opcao voce escolhe? ";
      getline(cin, input);
      stringstream stream(input);
      if (stream >> opcao && 0 <= opcao <= 5) break;
      system("clear||cls");
      cout << "Entrada invalida! Tente de novo!\n";
    }
    carroPtr[escolha]->setExaust(opcao);
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void setEletronic(Carros *carroPtr[]) {
  const int numCars = Carros::getNumCars();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para modificar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (verifyEscolha(escolha)) {
    int opcao;
    system("cls||clear");
    while (1) {
      string input;
      for (Carros::hpGain elem : Carros::eletronics)
        cout << elem.part << " - " << elem.hpGain << "\n";
      cout << "Qual opcao voce escolhe? ";
      getline(cin, input);
      stringstream stream(input);
      if (stream >> opcao && 0 <= opcao <= 5) break;
      system("clear||cls");
      cout << "Entrada invalida! Tente de novo!\n";
    }
    carroPtr[escolha]->setEletronic(opcao);
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void setTransmission(Carros *carroPtr[]) {
  const int numCars = Carros::getNumCars();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para modificar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (verifyEscolha(escolha)) {
    int opcao;
    system("cls||clear");
    while (1) {
      string input;
      for (Carros::change elem : Carros::trasmission)
        cout << elem.part << " - " << elem.time << "\n";
      cout << "Qual opcao voce escolhe? ";
      getline(cin, input);
      stringstream stream(input);
      if (stream >> opcao && 0 <= opcao <= 5) break;
      system("clear||cls");
      cout << "Entrada invalida! Tente de novo!\n";
    }
    carroPtr[escolha]->setTransmission(opcao);
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void setSuspension(Carros *carroPtr[]) {
  const int numCars = Carros::getNumCars();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para modificar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (verifyEscolha(escolha)) {
    int opcao;
    system("cls||clear");
    while (1) {
      string input;
      for (Carros::gForce elem : Carros::suspension)
        cout << elem.part << " - " << elem.gForce << "\n";
      cout << "Qual opcao voce escolhe? ";
      getline(cin, input);
      stringstream stream(input);
      if (stream >> opcao && 0 <= opcao <= 5) break;
      system("clear||cls");
      cout << "Entrada invalida! Tente de novo!\n";
    }
    carroPtr[escolha]->setSuspension(opcao);
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void setChassis(Carros *carroPtr[]) {
  const int numCars = Carros::getNumCars();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para modificar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (verifyEscolha(escolha)) {
    int opcao;
    system("cls||clear");
    while (1) {
      string input;
      for (Carros::gForce elem : Carros::chassis)
        cout << elem.part << " - " << elem.gForce << "\n";
      cout << "Qual opcao voce escolhe? ";
      getline(cin, input);
      stringstream stream(input);
      if (stream >> opcao && 0 <= opcao <= 5) break;
      system("clear||cls");
      cout << "Entrada invalida! Tente de novo!\n";
    }
    carroPtr[escolha]->setChassis(opcao);
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void exitProgram(Carros *carroPtr[]) {
  const int numCars = Carros::getNumCars();
  for (int i = 0; i < numCars; i++) {
    delete carroPtr[i]; carroPtr[i] = 0;
  }
  system("clear||cls");
  cout << "Ate a proxima vez!\n";
}

int getEscolha(Carros *carroPtr[]) {
  const int numCars = Carros::getNumCars();
  system("cls||clear");
  int escolha;
  while (1) {
    string input;
    for (int i = 0; i < numCars; i++)
      cout << i << " - " << carroPtr[i] << "\n";
    cout << "Qual opcao voce escolhe? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> escolha) break;
    system("cls||clear");
    cout << "Entrada invalida! Tente de novo!\n";
  }
  return escolha;
}

bool verifyEscolha(const int escolha) {
  const int numCars = Carros::getNumCars();
  return (0 <= escolha && escolha < numCars);
}

bool verifyName(const string &nameCar) {
  const int MAXLEN = Carros::getMaxLen();
  return (nameCar.length() <= MAXLEN);
}

bool verifyHP(const int hpStock) {
  const int MINHP = Carros::getMinHP();
  const int MAXHP = Carros::getMaxHP();
  return (MINHP <= hpStock && hpStock <= MAXHP);
}