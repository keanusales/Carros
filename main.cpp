#include "mainf.cpp"

int main() {
  vecVeh vehtor;
  vehtor.push_back(new Carros("Nissan GTR", 630));
  vehtor.push_back(new Carros("Lancer Evo X", 270));
  vehtor.push_back(new Trucks("Actros 470", 470));
  system("cls||clear");
  while (1) {
    unsigned opcao;
    while (1) {
      string input;
      cout << "0 - Criar um novo veiculo\n"
        << "1 - Copiar um veiculo ja existente\n"
        << "2 - Deletar um veiculo existente\n"
        << "3 - Printar estado atual de um veiculo\n"
        << "4 - Setar internos de um veiculo\n"
        << "5 - Setar turbo de um veiculo\n"
        << "6 - Setar intake de um veiculo\n"
        << "7 - Setar exaust de um veiculo\n"
        << "8 - Setar eletronics de um veiculo\n"
        << "9 - Setar transmission de um veiculo\n"
        << "10 - Setar suspension de um veiculo\n"
        << "11 - Setar chassis de um veiculo\n"
        << "12 - Sair do programa (apaga tudo)\n"
        << "Qual opcao voce escolhe? ";
      getline(cin, input);
      stringstream stream(input);
      if (stream >> opcao && opcao < 13) break;
      system("clear||cls");
      cout << "Entrada invalida! Tente de novo!\n";
    }
    calling(opcao, vehtor);
  }
}