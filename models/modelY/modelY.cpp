#include "modelY.hpp"

#include <iostream>

ModelY::ModelY() {
  inFlow2.setUpdateFunction([this](int incomingValue) {
    std::cout << "modelY.inFlow2 update function called with argument: " << incomingValue
              << std::endl;
    std::cout << "ModelY inFlow2 variable set via update callback function: " << inFlow2.getValue()
              << std::endl;
    std::cout << "ModelY inFlow1 variable: " << inFlow1.getValue() << std::endl;
  });
}
