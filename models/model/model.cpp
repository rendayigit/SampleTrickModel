#include "model.hpp"

int Model::initialization() {
  // Connect the flows here
  out.outflow.connect(&in.inflow);

  // Set an initial value, this should set both flows to the same value.
  out.outflow.setValue(1);

  return 0;
}

int Model::scheduled() {
  // Increment outFlow every second
  out.outflow.setValue(out.outflow.getValue() + 1);

  return 0;
}
