/*************************************************************************
PURPOSE: ( A sample trick model created using only cpp. ModelY. )
LIBRARY DEPENDENCIES:
    ((ModelY.o))
PROGRAMMERS:
    (((Yusuf Can Anar) (Turkish Aerospace) (09 July 2024)

ICG: (No)
**************************************************************************/
#ifndef MODELY_HPP
#define MODELY_HPP

#include "common/InFlow.hpp"
class ModelY {
public:
  InFlow<int> yData; /* -- */
  void update();
};

#endif // MODELY_HPP