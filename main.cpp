#include "carros.cpp"

int main() {
  int opcao, level, escolha;
  Carros *carro[Carros::getMaxCars()];
  carro[0] = new Carros("Nissan GTR", 630);
  carro[1] = new Carros("Lancer Evo X", 280);
  carro[2] = new Carros(*carro[1]);
  carro[3] = new Carros("Aventador", 770);
  system("clear||cls");
  while (1) {
    cout << "1 - Criar um novo carro\n"
      << "2 - Deletar um carro existente\n"
      << "3 - Printar estado atual dos carros\n" 
      << "4 - Fazer uma atualizacao em um dos carros\n"
      << "5 - Sair do programa\n"
      << "Qual opcao voce escolhe? ";
    cin >> opcao;
    switch (opcao) {
      case 1: {
        string nameCar;
        int hpStock;
        system("clear||cls");
        cout << "Digite o nome do carro: ";
        cin >> nameCar;
        cout << "Digite a potencia do carro: ";
        cin >> hpStock;
        Carros::construct(carro, nameCar, hpStock);
      } break;
      case 2:
        Carros::namesArray(carro);
        cout << "Qual opcao voce escolhe? ";
        cin >> escolha;
        Carros::destuct(carro, escolha);
        break;
      case 3:
        system("clear||cls");
        Carros::statusArray(carro);
        break;
      case 4:
        system("clear||cls");
        Carros::namesArray(carro);
        cout << "Qual opcao voce escolhe? ";
        cin >> escolha;
        cout << "Digite o nivel da atualizacao [0, 6]: ";
        cin >> level;
        if (Carros::verifyEscolha(escolha))
          carro[escolha]->setStatus(level);
        else cout << "Digite um valor especificado!\n";
        break;
      case 5:
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