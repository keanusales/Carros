#include "mainf.cpp"

int main() {
  vecVeh vehtor;
  vehtor.push_back(new Carros("Nissan GTR", {630, .15, 1.2}));
  vehtor.push_back(new Carros("Lancer Evo X", {270, .17, 1.4}));
  vehtor.push_back(new Trucks("Ford F150 Raptor", {456, .16}));
  system("cls||clear");
  while (1) {
    unsigned opcao;
    while (1) {
      string input;
      cout << "0 - Criar um novo veiculo\n"
        << "1 - Copiar um veiculo ja existente\n"
        << "2 - Deletar um veiculo existente\n"
        << "3 - Printar estado atual de um veiculo\n"
        << "4 - Tira-Teima com um adversario\n"
        << "5 - Setar internos de um veiculo\n"
        << "6 - Setar turbo de um veiculo\n"
        << "7 - Setar intake de um veiculo\n"
        << "8 - Setar exaust de um veiculo\n"
        << "9 - Setar eletronics de um veiculo\n"
        << "10 - Setar transmission de um veiculo\n"
        << "11 - Setar suspension de um veiculo\n"
        << "12 - Setar chassis de um veiculo\n"
        << "13 - Sair do programa (apaga tudo)\n"
        << "Qual opcao voce escolhe? ";
      getline(cin, input);
      stringstream stream(input);
      if (stream >> opcao && opcao <= 13) break;
      system("clear||cls");
      cout << "Entrada invalida! Tente de novo!\n";
    }
    calling(opcao, vehtor);
  }
}