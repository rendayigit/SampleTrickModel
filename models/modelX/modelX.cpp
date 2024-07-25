#include "modelX.hpp"
#include "root/root.hpp"
#include <iostream>

ModelX::ModelX() {
  outFlow.setValue(900);

  // Notice establishConnections() must be called after all related models including root are
  // instantiated. Hence this function is called in Root::init().
  // establishConnections();
}

void ModelX::establishConnections() {
  // Connect modelY inflow variables to modelX outflow variable
  outFlow.connect(&Root::getInstance().modelY->inFlow1);
  std::cout << "ModelY inFlow1 connection established, inFlow1 value: "
            << Root::getInstance().modelY->inFlow1.getValue() << std::endl;
  outFlow.connect(&Root::getInstance().modelY->inFlow2);
  std::cout << "ModelY inFlow2 connection established, inFlow2 value: "
            << Root::getInstance().modelY->inFlow2.getValue() << std::endl;

  // Test dataflow connections
  outFlow.setValue(256);
  std::cout << "ModelX OutFlow value set, outFlow: " << outFlow.getValue() << std::endl;
  std::cout << "ModelY inFlow1 value: " << Root::getInstance().modelY->inFlow1.getValue()
            << std::endl;
  std::cout << "ModelY inFlow2 value: " << Root::getInstance().modelY->inFlow2.getValue()
            << std::endl;
}