#ifndef MODELY_HPP
#define MODELY_HPP

#include "common/dataFlow.hpp"

class ModelY {
public:

  // This variable is connected without the update callback function.
  InFlow<int> inFlow1; /* -- */

  // This variable is connected with the update callback function. See constructor.
  InFlow<int> inFlow2; /* -- */

  ModelY();
};

#endif // MODELY_HPP