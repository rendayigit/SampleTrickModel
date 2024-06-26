/*************************************************************************
PURPOSE: ( A sample trick model created using only cpp. ModelX. )
LIBRARY DEPENDENCIES:
    ((ModelX.o))
**************************************************************************/
#ifndef MODELX_HPP
#define MODELX_HPP

class ModelX {
public:
  double a[2];            /* m     sample a value */
  double b[2];            /* m/s   sample b value */
  unsigned long long c;   /* cm    sample c value */

  /**
   * Trick data initialization function. This function is called at the beginning of the
   * simulation before the initialization function. This function is used to set the internal
   * variables of the models.
   *
   * @return 0 indicating successful initialization
   */
  int default_data(); // Notice clangd suggests abiding by the set naming conventions.

  /**
   * Trick initialization function. This function is called at the beginning of the
   * simulation.
   *
   * @return 0 indicating successful initialization
   */
  int init();

  /**
   * Trick scheduled function. This function is called at every time step.
   *
   * @return 0 indicating successful execution
   */
  int scheduled();

  /**
   * Trick shutdown function. This function is called at the end of the simulation.
   *
   * @return 0 indicating successful shutdown
   */
  int shutdown();

  /**
   * A sample addition function to test unit testing and coverage.
   *
   * @param a The first value
   * @param b The second value
   * @return The sum of the two values
   */
  static int add(int a, int b);

  /**
   * A sample subtraction function to test unit testing and coverage.
   *
   * @param a The first value
   * @param b The second value
   * @return The difference of the two values
   */
  static int sub(int a, int b);

  /**
   * A sample multiplication function to test unit testing and coverage.
   *
   * @param a The first value
   * @param b The second value
   * @return The product of the two values
   */
  static int mul(int a, int b);

  /**
   * A sample division function to test unit testing and coverage.
   *
   * @param a The first value
   * @param b The second value
   * @return The quotient of the two values
   */
  static int div(int a, int b);

  /**
   * A sample function that calls a trick specific function (get_sim_time) to return the
   * simulation time. This function is used to test mocking in the unit tests.
   *
   * @return The simulation time as a double.
   */
  static double getSimeTime();

private:
  int deneme; // Notice clangd suggests abiding by the set naming conventions.
};

#endif // MODELX_HPP