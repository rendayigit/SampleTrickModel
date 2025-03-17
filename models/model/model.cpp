#include "model.hpp"

int Model::initialization() {
  // Connect the flows here
  outflow.connect(&inflow);

  // Set an initial value, this should set both flows to the same value.
  outflow.setValue(1);

  return 0;
}

int Model::scheduled() {
  outflow.setValue(outflow.getValue() + 1);

  return 0;
}
