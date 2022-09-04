#include "carros.cpp"

int main() {
  int opcao, level, escolha;
  Carros lancerEvoX, audiTTRS;
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
        lancerEvoX.printState("Lancer");
        audiTTRS.printState("TTRS");
        break;
      case 2:
        system("clear||cls");
        cout << "Digite o nivel da att [0, 5]: ";
        cin >> level;
        if (0 <= level && level <= 5) {
          cout << "1: Lancer, 2: TTRS - Escolha: ";
          cin >> escolha;
          switch (escolha) {
            case 1:
              lancerEvoX.upgrade(level);
              system("clear||cls");
              cout << "Atualizacao realizada com sucesso!\n";
              break;
            case 2:
              audiTTRS.upgrade(level);
              system("clear||cls");
              cout << "Atualizacao realizada com sucesso!\n";
              break;
            default:
              system("clear||cls");
              cout << "Escolha um dos carros mostrados!\n";
              break;
          }
        } else {
          cin.clear(); cin.ignore();
          system("clear||cls");
          cout << "Digite um valor no intevalo dado!\n";
        } break;
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