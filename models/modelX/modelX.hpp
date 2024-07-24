/*************************************************************************
PURPOSE: ( A sample trick model created using only cpp. ModelX. )
LIBRARY DEPENDENCIES:
    ((modelX.o))
PROGRAMMERS:
    ((Renda Yiğit) (Turkish Aerospace) (01 July 2024))
**************************************************************************/
#ifndef MODELX_HPP
#define MODELX_HPP

#include "common/dataFlow.hpp"
#include "common/load.hpp"

class ModelX : public Load {
public:
  double a[2];    /* m     sample a value */
  double b[2];    /* m/s   sample b value */
  OutFlow<int> c; /* cm    sample c value */

  enum ModelXStates { ON = 1, OFF = 0 };

  ModelX();

  /**
   * A sample function that calls a trick specific function (get_sim_time) to return the
   * simulation time. This function is used to test mocking in the unit tests.
   *
   * @return The simulation time as a double.
   */
  static double getSimeTime();

  /**
   * Establish connections between modelX and modelY.
   */
  void establishConnections();

  /*
   * Logical model update or step function.
   */
  void update();

  /*
   * Turn the component/model On.
   */
  void turnOn();

  /*
   * Turn the component/model On.
   */
  void turnOff();

  [[nodiscard]] ModelXStates getState() const { return m_state; }

private:
  // Notice clangd suggests abiding by the set naming conventions.
  int deneme;

  ModelXStates m_state;

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