#include "fordf150.cpp"

const argTrucks Mammoth::ARGS = {"Henessey Mammoth 1000", 1000, .13};

Mammoth::Mammoth(): Trucks(ARGS) {}

Mammoth::Mammoth(const Mammoth &other): Trucks(other) {}

Vehicle *Mammoth::clone() { return new Mammoth(*this); }