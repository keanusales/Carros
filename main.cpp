#include "carros.cpp"
#include <iostream>
using namespace std;

int main() {
  int opcao, level;
  Carros lancerEvoX;
  system("clear||cls");
  while (1) {
    cout << "1 - Printar estado atual do carro\n"
      << "2 - Fazer uma atualizacao no carro\n"
      << "3 - Sair do programa\n"
      << "Qual opcao voce escolhe? ";
    cin >> opcao;
    switch (opcao) {
      case 1: {
        system("clear||cls");
        lancerEvoX.printState();
        break;
      }
      case 2: {
        system("clear||cls");
        cout << "Digite um valor entre [0, 5]: ";
        cin >> level;
        if (0 <= level && level <= 5) {
          lancerEvoX.upgrade(level);
          system("clear||cls");
          cout << "Atualizacao realizada com sucesso!\n";
        } else {
          cin.clear(); cin.ignore();
          system("clear||cls");
          cout << "Digite um valor no intevalo dado!\n";
        } break;
      }
      case 3: {
        system("clear||cls");
        cout << "Ate a proxima vez!\n";
        exit(0);
      }
      default: {
        cin.clear(); cin.ignore();
        system("clear||cls");
        cout << "Valor Invalido! Tente de novo.\n";
        break;
      }
    }
  }
}