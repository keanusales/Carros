#include "carros.cpp"

int main() {
  int opcao, level, escolha;
  Carros carro1("Nissan GTR", 630);
  Carros carro2("Lancer Evo X", 280);
  Carros carro3(carro2);
  Carros carro4("Golf GTI", 230);
  Carros carro5("Aventador", 770);
  system("clear||cls");
  while (1) {
    cout << "1 - Printar estado atual dos carros\n"
      << "2 - Fazer uma atualizacao em um dos carros\n"
      << "3 - Sair do programa\n"
      << "Qual opcao voce escolhe? ";
    cin >> opcao;
    switch (opcao) {
      case 1:
        system("clear||cls");
        carro1.getStatus();
        carro2.getStatus();
        carro3.getStatus();
        break;
      case 2:
        system("clear||cls");
        cout << "1: " << carro1.getName()
          << ", 2: " << carro2.getName()
          << ", 3: " << carro3.getName()
          << "\nQual opcao voce escolhe? ";
        cin >> escolha;
        cout << "Digite o nivel da atualizacao [0, 6]: ";
        cin >> level;
        switch (escolha) {
          case 1:
            carro1.setStatus(level);
            break;
          case 2:
            carro2.setStatus(level);
            break;
          case 3:
            carro3.setStatus(level);
            break;
          default:
            system("clear||cls");
            cout << "Escolha um dos carros mostrados!\n";
            break;
        }
        break;
      case 3:
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