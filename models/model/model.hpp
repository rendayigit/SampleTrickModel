/* PURPOSE: Model */

#pragma once

#include "common/dataFlow.hpp"

class Model {
public:
  int initialization();
  int scheduled();

  InFlow<int> inflow;
  OutFlow<int> outflow;
};