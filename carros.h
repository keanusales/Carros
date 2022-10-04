#ifndef CARROS_H
#define CARROS_H

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <sstream>
using std::stringstream;

#include <cmath>
using std::ceil;

#include <iostream>
using std::getline;
using std::string;
using std::cout;
using std::cin;

class Carros {
  public:
    Carros(const string &, const int);
    Carros(const Carros &);
    ~Carros();
    void verifyLevel(const int);
    void getToDoList() const;
    void addToList(const string &);
    void getListIndex();
    void getPerigoso() const;
    string getNameCar() const;
    string getTTires() const;
    string getTEngine() const;
    int getHpAtual() const;
    int getUpLevel() const;
    static int getNumCars();
    static int getMaxLen();
    static int getMinHP();
    static int getMaxHP();
    static int getMaxCars();

  private:
    void setStatus(const int);
    void mapModHP(const int);
    void mapTypeTires(const int);
    void mapTypeEngine(const int);
    void verifyIndex(const int);
    void popFromList(const int);
    int* intAtributes;
    string* strAtributes;
    string* toDoList;
    int lenList, maxLenList;
    vector <bool> perigoso;
    static const int MAXLEN = 30;
    static const int MINHP = 100;
    static const int MAXHP = 1000;
    static const int MAXCARS = 10;
    static const int HPSTOCK = 0;
    static const int HPATUAL = 1;
    static const int UPLEVEL = 2;
    static const int NAMECAR = 0;
    static const int TYPETIRES = 1;
    static const int TYPENGINE = 2;
    static const int ATRIBUTES = 3;
};

void createCar(vector <Carros*>);
void copyExtCar(vector <Carros*>);
void deleteCar(vector <Carros*>);
void displayArray(vector <Carros*>);
void modifyCar(vector <Carros*>);
void accessList(vector <Carros*>);
void addToList(vector <Carros*>);
void popFromList(vector <Carros*>);
void getPerigoso(vector <Carros*>);
void exitProgram(vector <Carros*>);
int getEscolha(vector <Carros*>);
bool vEscolha(const int, const int);
bool verifyName(const string &);
bool verifyHP(const int);

#endif