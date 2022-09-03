#ifndef CARROS_H
#define CARROS_H

class Carros {
  public:
    Carros();
    ~Carros();
    void upgrade(int level);
    void printState() const;

  private:
    int horsepower;
    int upgradeLevel;
};

#endif //CARROS_H