#ifndef MAINF_H
#define MAINF_H

#include "trucks.h"

const int selectOption();
void createCar(Vehicle *[]);
void copyExtCar(Vehicle *[]);
void deleteCar(Vehicle *[]);
void getAtributes(Vehicle *[]);
void setInternals(Vehicle *[]);
void setTurbos(Vehicle *[]);
void setIntake(Vehicle *[]);
void setExaust(Vehicle *[]);
void setECUnit(Vehicle *[]);
void setTransmiss(Vehicle *[]);
void setSuspens(Vehicle *[]);
void setChassis(Vehicle *[]);
void exitProgram(Vehicle *[]);
const int getEscolha(Vehicle *[]);
const bool existsVeh(const char*);
const bool maximumVehicles();
const bool verEscolha(const int);
const bool verCreate(const int);
const bool verName(const string &);
const bool verHpStock(const int);

#endif