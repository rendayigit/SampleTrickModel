#include "modelX.hpp"

#include <iostream>

#include "root/root.hpp"

ModelX::ModelX() {
  outFlow.setValue(900);

  // Notice dataFlow connections must be made after all related models including root are
  // instantiated. Hence these connections are made in Root::initialization().
}