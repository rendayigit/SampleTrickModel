/*************************************************************************
PURPOSE: ( A sample trick model that only showcases minimal sim features. )
PROGRAMMERS:
    ((Renda Yiğit) (Turkish Aerospace) (01 July 2024))
**************************************************************************/
#include "modelDummy.hpp"
#include "sim_services/Executive/include/exec_proto.h"

#include <vector>

// Notice clangd suggests using initializer lists and doesn't like magic numbers
ModelDummy::ModelDummy() {
  a[0] = 0.0;
  a[1] = 6578000.0;
  b[0] = 7905.0;
  b[1] = 0.0;
  test = 0;
  c = 900;

  std::vector<int> myList;

  // Notice clangd suggests using range-based for loop instead
  for (int i = 0; i < myList.size(); i++) {
    myList.at(i) = 0;
  }
}

double ModelDummy::getSimTime() { return exec_get_sim_time(); }