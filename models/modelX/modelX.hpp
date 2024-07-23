#ifndef MODELX_HPP
#define MODELX_HPP

#include "common/dataFlow.hpp"

class ModelX {
public:
  double a[2];    /* m     sample a value */
  double b[2];    /* m/s   sample b value */
  OutFlow<int> c; /* cm    sample c value */

  ModelX();

  /**
   * A sample function that calls a trick specific function (get_sim_time) to return the
   * simulation time. This function is used to test mocking in the unit tests.
   *
   * @return The simulation time as a double.
   */
  static double getSimTime();

  /**
   * Establish connections between modelX and modelY.
   */
  void establishConnections();

private:
  // Notice clangd suggests abiding by the set naming conventions.
  int deneme;

  /**
   * Create a one shot event.
   */
  void createOneShotEvent();

  /**
   * Create a scheduled event.
   */
  void createScheduledEvent();
};

#endif // MODELX_HPP