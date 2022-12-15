#include "porscheGT2.cpp"

const argTrucks FordF150::ARGS = {"Ford F150 Raptor R", 756, .15};

FordF150::FordF150(): Trucks(ARGS) {}

FordF150::FordF150(const FordF150 &other): Trucks(other) {}

Vehicle *FordF150::clone() { return new FordF150(*this); }