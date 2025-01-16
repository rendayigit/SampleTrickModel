/*************************************************************************
PURPOSE: ( A sample trick model created to demonstrate inter model communication between ModelX and
ModelY.)
**************************************************************************/
#pragma once

#include "common/dataFlow.hpp"

class ModelX {
public:
  OutFlow<int> outFlow; /* cm    sample outFlow value */

  ModelX();
};