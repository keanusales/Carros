#include "trucks.cpp"

const unsigned Sports::HPOWER = 100;

Sports::Sports(const string &nameCar, const unsigned hpStock)
: Carros(nameCar, hpStock + Sports::HPOWER) {}

Sports::Sports(const Sports &other)
: Carros(static_cast <Carros> (other)) {}

Sports::Sports(const Vehicle &other)
: Sports(*dynamic_cast <Sports*> (const_cast <Vehicle*> (&other))) {}

void Sports::calling(const unsigned opcao) {
  typedef void (Sports::*action)();
  const action actions[] = {
    &Sports::printState, &Sports::setInterns, &Sports::setTurbos,
    &Sports::setIntake, &Sports::setExaust, &Sports::setECUnit,
    &Sports::setTransm, &Sports::setSuspens, &Sports::setChassis
  };
  ((*this).*actions[opcao])();
}

void Sports::printState() {
  system("cls||clear"); cout << *this;
}

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const Sports &sport) {
  output << static_cast <Carros> (sport);
  output << "HP Bonus: " << Sports::HPOWER << "\n\n";
  return output;
}