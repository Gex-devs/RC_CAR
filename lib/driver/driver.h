#ifndef DRIVER_H
#define DRIVER_H

#include <Arduino.h>


class Vroom{
  public:
    int hallomyGst(int a, int b);
    void Left();
    void Right();
    void Forward();
    void BackWard();
};




#endif
