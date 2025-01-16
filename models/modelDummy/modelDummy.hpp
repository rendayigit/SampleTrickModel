/* PURPOSE: A sample trick model that only showcases minimal sim features. */

#pragma once

class ModelDummy {
public:
  double a[2]; /* m     sample a value */
  double b[2]; /* m/s   sample b value */
  int c;       /* cm    sample c value */

  ModelDummy();

  /**
   * A sample function that calls a trick specific function (get_sim_time) to return the
   * simulation time. This function is used to test mocking in the unit tests.
   *
   * @return The simulation time as a double.
   */
  static double getSimTime();

private:
  // Notice clangd suggests abiding by the set naming conventions.
  int test;
};