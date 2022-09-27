#include "carros.cpp"

int main() {
  int opcao, level, escolha;
  Carros *carroPtr[Carros::getMaxCars()];
  carroPtr[0] = new Carros("Nissan GTR", 630);
  carroPtr[1] = new Carros("Lancer Evo X", 280);
  carroPtr[2] = new Carros("Aventador", 770);
  system("clear||cls");
  while (1) {
    cout << "1 - Criar um novo carro\n"
      << "2 - Copiar um carro ja existente\n"
      << "3 - Deletar um carro existente\n"
      << "4 - Printar estado atual dos carros\n" 
      << "5 - Mostrar numero de modificacoes\n"
      << "6 - Modificar um dos carros\n"
      << "7 - Sair do programa\n"
      << "Qual opcao voce escolhe? ";
    cin >> opcao;
    switch (opcao) {
      case 1:
        Carros::createCar(carroPtr);
        break;
      case 2:
        Carros::copyExtCar(carroPtr);
        break;
      case 3:
        Carros::deleteCar(carroPtr);
        break;
      case 4:
        Carros::displayArray(carroPtr);
        break;
      case 5:
        Carros::getModDone(carroPtr);
        break;
      case 6:
        Carros::modifyCar(carroPtr);
        break;
      case 7:
        system("clear||cls");
        cout << "Ate a proxima vez!\n";
        exit(0);
      default:
        cin.clear(); cin.ignore();
        system("clear||cls");
        cout << "Valor Invalido! Tente de novo.\n";
        break;
    }
  }
}