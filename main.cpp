#include "carros.cpp"

int main() {

  system("clear||cls");

  Carros carro1("Nissan GTR", 630);
  Carros carro2("Lancer Evo X", 280);
  Carros carro3(carro2);
  const Carros CARRO4("Golf GTI", 230);
  Carros carro5("Aventador", 770);

  carro1.getStatus();
  carro2.getStatus();
  carro3.getStatus();
  CARRO4.getStatus();
  carro5.getStatus();

  Carros::getNumCars();

  carro1.setStatus(6);
  carro2.setStatus(4);
  carro5.setStatus(6);

  cout << "Att: " << carro1.getName() << "\n";
  carro1.getStatus();
  carro1.getDanger();
  cout << "Att: " << carro2.getName() << "\n";
  carro2.getStatus();
  carro2.getDanger();
  cout << "Att: " << carro5.getName() << "\n";
  carro5.getStatus();
  carro5.getDanger();

  Carros::getNumDone();

}