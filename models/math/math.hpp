/*************************************************************************
PURPOSE: ( A sample math model. )
LIBRARY DEPENDENCIES:
    ((math.o))
PROGRAMMERS:
    ((Renda Yiğit) (Turkish Aerospace) (01 July 2024))
**************************************************************************/
#ifndef MATH_HPP
#define MATH_HPP

class Math {
public:
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
};

#endif // MATH_HPP