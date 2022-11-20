#include "derived.cpp"

Sports sport1("Nissan GTR", 630);
Sports sport2(sport1);
SUVs suv1("Lamborghini Urus", 650);
SUVs suv2(suv1);
Trucks truck1("Actros 470", 470);
Trucks truck2(truck1);

const unsigned selectOption();
const unsigned getEscolha();
void exitProgram();

int main() {
  system("cls||clear");
  while (1) {
    unsigned opcao = selectOption();
    if (opcao == 9) exitProgram();
    unsigned escolha = getEscolha();
    switch (escolha) {
      case 1:
        (::sport1.*sport1.actions[opcao])();
        break;
      case 2:
        (::sport2.*sport2.actions[opcao])();
        break;
      case 3:
        (::suv1.*suv1.actions[opcao])();
        break;
      case 4:
        (::suv2.*suv2.actions[opcao])();
      case 5:
        (::truck1.*truck1.actions[opcao])();
        break;
      case 6:
        (::truck2.*truck2.actions[opcao])();
        break;
      default:
        cout << "Escolha errada!\n";
        break;
    }
  }
}

const unsigned selectOption() {
  while (1) {
    string input; unsigned opcao;
    cout << "0 - Printar estado de um veiculo\n"
      << "1 - Setar internos de um veiculo\n"
      << "2 - Setar turbo de um veiculo\n"
      << "3 - Setar intake de um veiculo\n"
      << "4 - Setar exaust de um veiculo\n"
      << "5 - Setar eletronics de um veiculo\n"
      << "6 - Setar transmission de um veiculo\n"
      << "7 - Setar suspension de um veiculo\n"
      << "8 - Setar chassis de um veiculo\n"
      << "9 - Sair do programa (apaga tudo)\n"
      << "Qual opcao voce escolhe? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> opcao && opcao < 10) return opcao;
    system("clear||cls");
    cout << "Entrada invalida/Valor invalido!\n";
  }
}

const unsigned getEscolha() {
  unsigned escolha;
  system("cls||clear");
  while (1) {
    string input;
    cout << 1 << " - " << ::sport1.getName() << "\n"
      << 2 << " - " << ::sport2.getName() << "\n"
      << 3 << " - " << ::suv1.getName() << "\n"
      << 4 << " - " << ::suv2.getName() << "\n"
      << 5 << " - " << ::truck1.getName() << "\n"
      << 6 << " - " << ::truck2.getName() << "\n"
      << "Qual opcao voce escolhe? ";
    getline(cin, input);
    stringstream stream(input);
    if (stream >> escolha) return escolha;
    system("cls||clear");
    cout << "Entrada invalida! Tente de novo!\n";
  }
}

void exitProgram() {
  system("cls||clear");
  cout << "Ate a proxima!\n";
  exit(0);
}