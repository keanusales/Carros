#include "carros.cpp"

const int maxCars = Carros::getMaxCars();

void createCar(vector <Carros*> carroPtr) {
  system("cls||clear");
  if (carroPtr.size() + 1 > maxCars) {
    cout << "Estamos no maximo de carros!\n";
    return;
  }
  string nameCar; int hpStock;
  while (1) {
    cout << "Digite o nome do carro: ";
    cin.ignore(); getline(cin, nameCar);
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
  carroPtr.push_back(new Carros(nameCar, hpStock));
  system("cls||clear");
  cout << "Carro adicionado com sucesso!\n";
}

void copyExtCar(vector <Carros*> carroPtr) {
  const int numCars = carroPtr.size();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para copiar!\n";
    return;
  }
  if (numCars + 1 > maxCars) {
    system("cls||clear");
    cout << "Estamos no maximo de carros!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (vEscolha(escolha, numCars)) {
    carroPtr.push_back(new Carros(*carroPtr[escolha]));
    system("cls||clear");
    cout << "Carro adicionado com sucesso!\n";
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void deleteCar(vector <Carros*> carroPtr) {
  const int numCars = carroPtr.size();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para deletar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (vEscolha(escolha, numCars)) {
    delete carroPtr[escolha];
    for (int i = escolha; i < numCars; i++)
      carroPtr[i] = carroPtr[i+1];
    carroPtr.pop_back();
    system("cls||clear");
    cout << "Carro deletado com sucesso!\n";
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void displayArray(vector <Carros*> carroPtr) {
  system("cls||clear");
  if (!carroPtr.size()) {
    cout << "Nao ha carros para mostrar!\n";
    return;
  }
  for (Carros *elem : carroPtr) {
    const int hp = elem->getHpAtual();
    const int up = elem->getUpLevel();
    const string name = elem->getNameCar();
    const string tires = elem->getTTires();
    const string engine = elem->getTEngine();
    cout << "Horsepower do " << name << ": " << hp << "\n";
    cout << "UpLevel do " << name << ": " << up << "\n";
    cout << "Pneu do " << name << ": " << tires << "\n";
    cout << "Motor do " << name << ": " << engine << "\n\n";
  }
}

void modifyCar(vector <Carros*> carroPtr) {
  const int numCars = carroPtr.size();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para modificar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (vEscolha(escolha, numCars)) {
    int level;
    while (1) {
      string input;
      cout << "Qual a mofificacao desejada? [0, 6]: ";
      getline(cin, input);
      stringstream stream(input);
      if (stream >> level) break;
      system("cls||clear");
      cout << "Entrada invalida! Tente de novo!\n";
    }
    carroPtr[escolha]->verifyLevel(level);
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void accessList(vector <Carros*> carroPtr) {
  const int numCars = carroPtr.size();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para mostrar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (vEscolha(escolha, numCars)) {
    carroPtr[escolha]->getToDoList();
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void addToList(vector <Carros*> carroPtr) {
  const int numCars = carroPtr.size();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para mostrar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (vEscolha(escolha, numCars)) {
    string newTarefa;
    cout << "Digite o nova tarefa: ";
    getline(cin, newTarefa);
    carroPtr[escolha]->addToList(newTarefa);
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void popFromList(vector <Carros*> carroPtr) {
  const int numCars = carroPtr.size();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para mostrar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (vEscolha(escolha, numCars)) {
    carroPtr[escolha]->getListIndex();
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void getPerigoso(vector <Carros*> carroPtr) {
  const int numCars = carroPtr.size();
  if (!numCars) {
    system("cls||clear");
    cout << "Nao ha carros para mostrar!\n";
    return;
  }
  int escolha = getEscolha(carroPtr);
  if (vEscolha(escolha, numCars)) {
    carroPtr[escolha]->getPerigoso();
    return;
  }
  system("cls||clear");
  cout << "Digite um carro especificado!\n";
}

void exitProgram(vector <Carros*> carroPtr) {
  for (Carros *elem : carroPtr) delete elem;
  system("clear||cls");
  cout << "Ate a proxima vez!\n";
}

int getEscolha(vector <Carros*> carroPtr) {
  system("cls||clear");
  int escolha;
  while (1) {
    string input;
    for (int i = 0; i < carroPtr.size(); i++) {
      const string name = carroPtr[i]->getNameCar();
      cout << i << " - " << name << "\n";
    }
    cout << "Qual opcao voce escolhe? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> escolha) break;
    system("cls||clear");
    cout << "Entrada invalida! Tente de novo!\n";
  }
  return escolha;
}

bool vEscolha(const int escolha, const int numCars) {
  return (0 <= escolha && escolha < numCars);
}

bool verifyName(const string &nameCar) {
  const int maxLen = Carros::getMaxLen();
  return (nameCar.length() <= maxLen);
}

bool verifyHP(const int hpStock) {
  const int minHP = Carros::getMinHP();
  const int maxHP = Carros::getMaxHP();
  return (minHP <= hpStock && hpStock <= maxHP);
}