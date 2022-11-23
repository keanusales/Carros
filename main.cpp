#include "SUVs.cpp"

int main() {
  Vehicle *vehPtr[] = {
    new Sports("Nissan GTR", 630),
    new Sports(*vehPtr[0]),
    new SUVs("Lamborghini Urus", 650),
    new SUVs(*vehPtr[2]),
    new Trucks("Actros 470", 470),
    new Trucks(*vehPtr[4])
  };
  system("cls||clear");
  while (1) {
    unsigned opcao;
    while (1) {
      string input;
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
      if (stream >> opcao && opcao <= 9) break;
      system("clear||cls");
      cout << "Entrada invalida/Valor invalido!\n";
    }
    if (opcao == 9) break;
    unsigned escol;
    system("cls||clear");
    while (1) {
      string input; unsigned cont = 0;
      for (Vehicle *elem : vehPtr)
        cout << cont++ << " - " << elem->getName() << "\n";
      cout << "Qual opcao voce escolhe? ";
      getline(cin, input);
      stringstream stream(input);
      if (stream >> escol && escol < cont) break;
      system("cls||clear");
      cout << "Entrada invalida! Tente de novo!\n";
    }
    vehPtr[escol]->calling(opcao);
  }
  for (Vehicle *elem : vehPtr) {
    delete elem; elem = 0;
  }
  system("cls||clear");
  cout << "Ate a proxima!\n";
  return 0;
}