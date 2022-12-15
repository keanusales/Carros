#include "vehicle.cpp"

// IMPLEMENTAÇÃO

Carros::Carros(const argCarros &args):
  Vehicle(args.nameVeh), myEngine(args.hpStock),
  myTransm(args.timeSwap), myChassis(args.gForce) {}

Carros::Carros(const Carros &other):
  Vehicle(other), myEngine(other.myEngine),
  myTransm(other.myTransm), myChassis(other.myChassis) {}

Vehicle *Carros::clone() { return new Carros(*this); }

void Carros::output(ostream &output) const { output << *this; }

void Carros::tiraTeima() const {
  const unsigned hpAtual = myEngine.getHpower();
  const double timeSwap = myTransm.getTime();
  const double resul = 14 - log(hpAtual) + timeSwap;
  const double adver = resul + Vehicle::random();
  system("cls||clear");
  cout << "Seu tempo foi de " << resul << "s!\n";
  cout << "Seu adversaio fez " << adver << "s!\n";
  if (resul < adver) {
    cout << "Voce venceu seu adversario!\n\n";
    return;
  }
  if (resul > adver) {
    cout << "Voce perdeu pro adversario!\n\n";
    return;
  }
  cout << "Voce empatou com seu adversario!\n\n";
}

void Carros::setInterns() {
  const bool resul = myEngine.setInterns();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setTurbos() {
  const bool resul = myEngine.setTurbos();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos sao originais!\n"
    << "Faca um upgrade dos internos!\n";
}

void Carros::setIntake() {
  const bool resul = myEngine.setIntake();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos sao originais!\n"
    << "Faca um upgrade dos internos!\n";
}

void Carros::setExaust() {
  const bool resul = myEngine.setExaust();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos sao originais!\n"
    << "Faca um upgrade dos internos!\n";
}

void Carros::setECUnit() {
  const bool resul = myEngine.setECUnit();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "Internos sao originais!\n"
    << "Faca um upgrade dos internos!\n";
}

void Carros::setTransm() {
  const bool resul = myTransm.setTransm();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setSuspens() {
  const bool resul = myChassis.setSuspens();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

void Carros::setChassis() {
  const bool resul = myChassis.setChassis();
  system("cls||clear");
  if (resul) {
    cout << "Atualizacao feita com sucesso!\n";
    return;
  }
  cout << "A parte selecionada ja esta no carro!\n";
}

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Carros &carro) {
  output << "Motor:\n" << carro.myEngine << "\n";
  output << "Transmisao:\n" << carro.myTransm << "\n";
  output << "Chassis:\n" << carro.myChassis << "\n";
  return output;
}