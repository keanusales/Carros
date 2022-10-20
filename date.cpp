#include "carros.h"

ostream &operator<<(ostream &output, const Date *date) {
  output << date->dia << "/" << date->mes << "/" << date->ano << "\n";
  return output;
}

Date::Date() {
  time_t now = time(0);
  tm *ltm = localtime(&now);
  this -> dia = ltm->tm_mday;
  this -> mes = 1 + ltm->tm_mon;
  this -> ano = 1900 + ltm->tm_year;
}

Date::~Date() {}

bool Date::checkDate(const int dia) const {
  const int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (dia > 0 && dia <= diasMes[mes]) return 1;
  const bool resul = (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0));
  if (mes == 2 && dia == 29 && resul) return 1;
  return 0;
}