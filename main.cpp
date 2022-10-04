#include "mainf.cpp"

int main() {
  vector <Carros*> carroPtr;
  carroPtr.push_back(new Carros("Nissan GTR", 630));
  carroPtr.push_back(new Carros("Lancer Evo X", 280));
  carroPtr.push_back(new Carros("Aventador", 770));
  int opcao;
  system("clear||cls");
  while (1) {
    while (1) {
      string input;
      cout << "1 - Criar um novo carro\n"
        << "2 - Copiar um carro ja existente\n"
        << "3 - Deletar um carro existente\n"
        << "4 - Printar estado atual dos carros\n"
        << "5 - Modificar um dos carros\n"
        << "6 - Acessar a lista de tarefas\n"
        << "7 - Adicionar uma nova terefa\n"
        << "8 - Apagar uma tarefa da lista\n"
        << "9 - Ver modificacoes perigosas\n"
        << "10 - Sair do programa\n"
        << "Qual opcao voce escolhe? ";
      getline(cin, input);
      stringstream stream(input);
      if (stream >> opcao) break;
      system("clear||cls");
      cout << "Entrada invalida! Tente de novo!\n";
    }
    switch (opcao) {
      case 1:
        createCar(carroPtr);
        break;
      case 2:
        copyExtCar(carroPtr);
        break;
      case 3:
        deleteCar(carroPtr);
        break;
      case 4:
        displayArray(carroPtr);
        break;
      case 5:
        modifyCar(carroPtr);
        break;
      case 6:
        accessList(carroPtr);
        break;
      case 7:
        addToList(carroPtr);
        break;
      case 8:
        popFromList(carroPtr);
        break;
      case 9:
        getPerigoso(carroPtr);
        break;
      case 10:
        exitProgram(carroPtr);
        exit(0);
      default:
        system("clear||cls");
        cout << "Valor Invalido! Tente de novo.\n";
        break;
    }
  }
  return 0;
}