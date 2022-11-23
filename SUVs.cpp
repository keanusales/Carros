#include "sports.cpp"

const unsigned SUVs::HPOWER = 50;

SUVs::SUVs(const string &nameCar, const unsigned hpStock)
: Carros(nameCar, hpStock + SUVs::HPOWER) {}

SUVs::SUVs(const SUVs &other)
: Carros(static_cast <Carros> (other)) {}

SUVs::SUVs(const Vehicle &other)
: SUVs(*dynamic_cast <SUVs*> (const_cast <Vehicle*> (&other))) {}

void SUVs::calling(const unsigned opcao) {
  typedef void (SUVs::*action)();
  const action actions[] = {
    &SUVs::printState, &SUVs::setInterns, &SUVs::setTurbos,
    &SUVs::setIntake, &SUVs::setExaust, &SUVs::setECUnit,
    &SUVs::setTransm, &SUVs::setSuspens, &SUVs::setChassis
  };
  ((*this).*actions[opcao])();
}

void SUVs::printState() {
  system("cls||clear"); cout << *this;
}

// SOBRECARGAS DA CLASSE

ostream &operator<<(ostream &output, const SUVs &suv) {
  output << static_cast <Carros> (suv);
  output << "HP Bonus: " << SUVs::HPOWER << "\n\n";
  return output;
}