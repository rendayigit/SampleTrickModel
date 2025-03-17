/* PURPOSE: Model */

#pragma once

#include "common/dataFlow.hpp"

class OutClass {
public:
  OutFlow<int> outflow;
};

class InClass {
public:
  InFlow<int> inflow;
};

class Model {
public:
  int initialization();
  int scheduled();

  OutClass out;
  InClass in;
};