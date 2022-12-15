#include "trucks.cpp"

const argCarros CorvetteZ06::ARGS = {"Chevy Corvette C6 Z06", 512, .15, 1.3};

CorvetteZ06::CorvetteZ06(): Carros(ARGS) {}

CorvetteZ06::CorvetteZ06(const CorvetteZ06 &other): Carros(other) {}

Vehicle *CorvetteZ06::clone() { return new CorvetteZ06(*this); }