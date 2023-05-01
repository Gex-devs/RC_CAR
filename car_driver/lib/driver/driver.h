#ifndef DRIVER_H
#define DRIVER_H

#include <Arduino.h>


class Vroom{
  public:
    void Left();
    void Right();
    void Forward();
    void BackWard();
    void Stop();
};




#endif
