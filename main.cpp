#include "carros.cpp"

int main() {
  int opcao, level, escolha;
  Carros nissanGTR(630);
  Carros lancerEvoX(280);
  Carros lancerEvoIX(lancerEvoX);
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
        lancerEvoX.getStatus("Lancer X");
        nissanGTR.getStatus("GTR R35");
        lancerEvoIX.getStatus("Lancer 9");
        break;
      case 2:
        system("clear||cls");
        cout << "1: Lancer X, 2: GTR, 3: Lancer 9 - ";
        cin >> escolha;
        cout << "Digite o nivel da atualizacao [0, 6]: ";
        cin >> level;
        switch (escolha) {
          case 1:
            lancerEvoX.setStatus(level);
            break;
          case 2:
            nissanGTR.setStatus(level);
            break;
          case 3:
            lancerEvoIX.setStatus(level);
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