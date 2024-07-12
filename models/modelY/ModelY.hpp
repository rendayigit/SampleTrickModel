/*************************************************************************
PURPOSE: ( A sample trick model. See ModelX for more details. )
LIBRARY DEPENDENCIES:
    ((ModelY.o))
PROGRAMMERS:
    ((Yusuf Can Anar) (Turkish Aerospace) (09 July 2024))
**************************************************************************/
#ifndef MODELY_HPP
#define MODELY_HPP

#include "common/DataFlow.hpp"

class ModelY {
public:
  InFlow<int> inFlow; /* -- */

  void update(); // TODO(renda): Implement dataflow update callback function
};

#endif // MODELY_HPP