#include "carros.cpp"

int main() {
  int opcao, level, escolha;
  Carros *carro[Carros::getMaxCars()];
  carro[0] = new Carros("Nissan GTR", 630);
  carro[1] = new Carros("Lancer Evo X", 280);
  carro[2] = new Carros("Aventador", 770);
  system("clear||cls");
  while (1) {
    cout << "1 - Criar um novo carro\n"
      << "2 - Copiar um carro ja existente\n"
      << "3 - Deletar um carro existente\n"
      << "4 - Printar estado atual dos carros\n" 
      << "5 - Modificar um dos carros\n"
      << "6 - Sair do programa\n"
      << "Qual opcao voce escolhe? ";
    cin >> opcao;
    switch (opcao) {
      case 1:
        Carros::setNewCar(carro);
        break;
      case 2:
        Carros::copyExtCar(carro);
        break;
      case 3:
        Carros::deleteCar(carro);
        break;
      case 4:
        Carros::getStatusArray(carro);
        break;
      case 5:
        Carros::chooseCar(carro);
        break;
      case 6:
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