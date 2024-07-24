/*************************************************************************
PURPOSE: ( A sample trick model created using only cpp. ModelX. )
LIBRARY DEPENDENCIES:
    ((modelX.o))
PROGRAMMERS:
    ((Renda Yiğit) (Turkish Aerospace) (01 July 2024))
**************************************************************************/
#include "modelX.hpp"
#include "root/root.hpp"
#include "sim_services/Executive/include/exec_proto.h"

#include <iostream>
#include <vector>

ModelX::ModelX() {
  a[0] = 0.0;
  a[1] = 6578000.0;
  b[0] = 7905.0;
  b[1] = 0.0;
  deneme = 0;
  c.setValue(900);

  std::vector<int> myList;

  // Notice clangd suggests using range-based for loop instead
  for (int i = 0; i < myList.size(); i++) {
    myList.at(i) = 0;
  }

  // Notice establishConnections() must be called after all related models including root are
  // instantiated. Hence this function is called in Root::init().
  // establishConnections();
}

void ModelX::establishConnections() {
  // Connect modelY inflow variables to modelX outflow variable
  c.connect(&Root::getInstance().modelY->inFlow1);
  std::cout << "ModelY inFlow1 connection established, inFlow1 value: "
            << Root::getInstance().modelY->inFlow1.getValue() << std::endl;
  c.connect(&Root::getInstance().modelY->inFlow2);
  std::cout << "ModelY inFlow2 connection established, inFlow2 value: "
            << Root::getInstance().modelY->inFlow2.getValue() << std::endl;

  // Test dataflow connections
  c.setValue(256);
  std::cout << "ModelX OutFlow value set, c: " << c.getValue() << std::endl;
  std::cout << "ModelY inFlow1 value: " << Root::getInstance().modelY->inFlow1.getValue()
            << std::endl;
  std::cout << "ModelY inFlow2 value: " << Root::getInstance().modelY->inFlow2.getValue()
            << std::endl;
}

double ModelX::getSimeTime() { return exec_get_sim_time(); }