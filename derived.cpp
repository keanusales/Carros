#include "trucks.cpp"

// CLASSE SPORTS

const unsigned Sports::HPOWER = 100;

Sports::Sports(const string &nameCar, const unsigned hpStock)
: Carros(nameCar, hpStock + Sports::HPOWER) {}

Sports::Sports(const Sports &other)
: Carros(static_cast <Carros> (other)) {}

// CLASSE SUVs

const unsigned SUVs::HPOWER = 50;

SUVs::SUVs(const string &nameCar, const unsigned hpStock)
: Carros(nameCar, hpStock + SUVs::HPOWER) {}

SUVs::SUVs(const SUVs &other)
: Carros(static_cast <Carros> (other)) {}