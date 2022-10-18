#ifndef CARROS_H
#define CARROS_H

#include <vector>
using std::vector;

#include <sstream>
using std::stringstream;

#include <iostream>
using std::ostream;
using std::getline;
using std::string;
using std::cout;
using std::cin;

class Carros {
  friend ostream &operator<<(ostream &, const Carros*);

  public:
    Carros(const string &, const int);
    Carros(const Carros &);
    ~Carros();
    void verifyLevel(const int);
    void getAtributes() const;
    void getModsDone() const;
    void delModsDone(const int);
    void setInternals(const int);
    void setTurbo(const int);
    void setIntake(const int);
    void setExaust(const int);
    void setEletronic(const int);
    void setTransmission(const int);
    void setSuspension(const int);
    void setChassis(const int);
    static int getNumCars();
    static int getMaxLen();
    static int getMinHP();
    static int getMaxHP();
    static int getMaxCars();

  public: //Bibliotecas
    static const struct hpGain {
      string part;
      int hpGain;
    } turbos[], intake[],
    exaust[], eletronics[];
    static const struct hpResis {
      string part;
      int hpResis;
    } internals[];
    static const struct change {
      string part;
      double time;
    } trasmission[];
    static const struct gForce {
      string part;
      double gForce;
    } suspension[], chassis[];

  private:
    struct Atributes {
      int hpStock;
      int hpAtual;
      // int upLevel;
      string nameCar;
    } atributes;
    struct ModsDone {
      hpGain turbo;
      hpGain intake;
      hpGain exaust;
      hpGain eletronic;
      hpResis internals;
      change trasmission;
      gForce suspension;
      gForce chassis;
    } modsDone;
    static int numCars;
    static const int MAXLEN;
    static const int MINHP;
    static const int MAXHP;
    static const int MINLVL;
    static const int MAXLVL;
    static const int MAXCARS;
};

int selectOption();
void createCar(Carros *[]);
void copyExtCar(Carros *[]);
void deleteCar(Carros *[]);
void getAtributes(Carros *[]);
void getModsDone(Carros *[]);
void delModsDone(Carros *[]);
void setInternals(Carros *[]);
void setTurbo(Carros *[]);
void setIntake(Carros *[]);
void setExaust(Carros *[]);
void setEletronic(Carros *[]);
void setTransmission(Carros *[]);
void setSuspension(Carros *[]);
void setChassis(Carros *[]);
void exitProgram(Carros *[]);
int getEscolha(Carros *[]);
bool verifyEscolha(const int);
bool verifyName(const string &);
bool verifyHP(const int);

#endif