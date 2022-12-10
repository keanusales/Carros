#ifndef MAINF_H
#define MAINF_H

#include "trucks.h"

typedef vector <Vehicle*> vecVeh;
void calling(const unsigned, vecVeh &);
void createCar(vecVeh &);
void copyExtCar(vecVeh &);
void deleteCar(vecVeh &);
void getStatus(vecVeh &);
void setInterns(vecVeh &);
void setTurbos(vecVeh &);
void setIntake(vecVeh &);
void setExaust(vecVeh &);
void setECUnit(vecVeh &);
void setTransm(vecVeh &);
void setSuspens(vecVeh &);
void setChassis(vecVeh &);
void exitProgram(vecVeh &);
const unsigned getEscolha(vecVeh &);
const bool nexists(const char *, vecVeh &);

#endif