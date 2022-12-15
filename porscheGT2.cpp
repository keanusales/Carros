#include "corvetteZ06.cpp"

const argCarros PorscheGT2::ARGS = {"Porsche 911 GT2 RS", 720, .1, 2};

PorscheGT2::PorscheGT2(): Carros(ARGS) {}

PorscheGT2::PorscheGT2(const PorscheGT2 &other): Carros(other) {}

Vehicle *PorscheGT2::clone() { return new PorscheGT2(*this); }