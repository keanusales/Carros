#include "mainf.cpp"

int main() {
  Vehicle *vehiclePtr[MAXVEHICLES];
  for (Vehicle *elem : vehiclePtr) elem = 0;
  vehiclePtr[0] = new Carros("Nissan GTR", 630);
  vehiclePtr[1] = new Carros("Lancer Evo X", 280);
  vehiclePtr[2] = new Carros("Aventador", 770);
  int opcao;
  system("clear||cls");
  while (1) {
    opcao = selectOption();
    switch (opcao) {
      case 1:
        createCar(vehiclePtr);
        break;
      case 2:
        copyExtCar(vehiclePtr);
        break;
      case 3:
        deleteCar(vehiclePtr);
        break;
      case 4:
        getAtributes(vehiclePtr);
        break;
      case 5:
        setInternals(vehiclePtr);
        break;
      case 6:
        setTurbos(vehiclePtr);
        break;
      case 7:
        setIntake(vehiclePtr);
        break;
      case 8:
        setExaust(vehiclePtr);
        break;
      case 9:
        setECUnit(vehiclePtr);
        break;
      case 10:
        setTransmiss(vehiclePtr);
        break;
      case 11:
        setSuspens(vehiclePtr);
        break;
      case 12:
        setChassis(vehiclePtr);
        break;
      case 13:
        exitProgram(vehiclePtr);
        exit(0);
      default:
        system("clear||cls");
        cout << "Valor Invalido! Tente de novo.\n";
        break;
    }
  }
  return 0;
}