/*************************************************************************
PURPOSE: ( The Root of all models. This model is a container of all other models. )
LIBRARY DEPENDENCIES:
    ((Root.o))
PROGRAMMERS:
    (((Yusuf Can Anar) (Turkish Aerospace) (09 July 2024)
**************************************************************************/
#ifndef ROOT_HPP
#define ROOT_HPP

// #include "modelX/ModelX.hpp"
#include "modelY/ModelY.hpp"

class Root {
public:
//   ModelX *modelX;
  ModelY *modelY;

  static Root &getInstance() {
    static Root instance;
    return instance;
  }

private:
  Root() : modelY(new ModelY) {}
};

#endif // ROOT_HPP