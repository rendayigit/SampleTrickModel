/*************************************************************************
PURPOSE: ( A sample trick model created to demonstrate inter model communication between ModelX and
ModelY.)
**************************************************************************/
#pragma once

#include "common/dataFlow.hpp"

class ModelY {
public:
  // This variable is updated without the update callback function.
  InFlow<int> inFlow1; /* cm    sample inFlow value */

  // This variable is updated with the update callback function. See constructor.
  InFlow<int> inFlow2; /* cm    sample inFlow value */

  ModelY();
};