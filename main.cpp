#include "mainf.cpp"

int main() {
  Carros *carroPtr[MAXCARS];
  for (Carros *elem : carroPtr) elem = 0;
  carroPtr[0] = new Carros("Nissan GTR", 630);
  carroPtr[1] = new Carros("Lancer Evo X", 280);
  carroPtr[2] = new Carros("Aventador", 770);
  int opcao;
  system("clear||cls");
  while (1) {
    opcao = selectOption();
    switch (opcao) {
      case 1:
        createCar(carroPtr);
        break;
      case 2:
        copyExtCar(carroPtr);
        break;
      case 3:
        deleteCar(carroPtr);
        break;
      case 4:
        getAtributes(carroPtr);
        break;
      case 5:
        getModsDone(carroPtr);
        break;
      case 6:
        delModsDone(carroPtr);
        break;
      case 7:
        setInternals(carroPtr);
        break;
      case 8:
        setTurbo(carroPtr);
        break;
      case 9:
        setIntake(carroPtr);
        break;
      case 10:
        setExaust(carroPtr);
        break;
      case 11:
        setEletronic(carroPtr);
        break;
      case 12:
        setTransmission(carroPtr);
        break;
      case 13:
        setSuspension(carroPtr);
        break;
      case 14:
        setChassis(carroPtr);
        break;
      case 15:
        exitProgram(carroPtr);
        exit(0);
      default:
        system("clear||cls");
        cout << "Valor Invalido! Tente de novo.\n";
        break;
    }
  }
  return 0;
}