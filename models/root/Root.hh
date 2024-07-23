/*************************************************************************
PURPOSE: ( The Root of all models. This model is a container of all other models. )
LIBRARY DEPENDENCIES:
    ((Root.o))
PROGRAMMERS:
    (((Yusuf Can Anar) (Turkish Aerospace) (09 July 2024)
**************************************************************************/
#ifndef ROOT_HH
#define ROOT_HH

#include "modelX/ModelX.hh"
#include "modelY/ModelY.hh"
#include <iostream>

class Root {
public:
  ModelX *modelX;
  ModelY *modelY;

  static Root &getInstance() {
    static Root instance;
    return instance;
  }

  void init() {
    modelX = new ModelX();
    modelY = new ModelY();

    modelX->a = 24;

  };

  void scheduled() {
    modelX->a += 1;
    std::cout<< "counter a -> @"<< modelX->a;
    std::cout<< " now\n";

  }

  // private:
  //   Root() : modelX(new ModelX), modelY(new ModelY) {}
};

#endif // ROOT_HH