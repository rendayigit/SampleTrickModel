/*************************************************************************
PURPOSE: ( A sample trick model to demonstrate loads. )
PROGRAMMERS:
    ((Renda Yiğit) (Turkish Aerospace) (24 July 2024))
**************************************************************************/
#ifndef MODELWITHLOAD_HPP
#define MODELWITHLOAD_HPP

#include "common/load.hpp"

class ModelWithLoad : public Load {
public:
  enum ModelWithLoadStates { ON = 1, OFF = 0 };

  ModelWithLoad();

  /*
   * Logical model update or step function.
   */
  void update();

  /*
   * Turn the component/model On.
   */
  void turnOn();

  /*
   * Turn the component/model Off.
   */
  void turnOff();

  [[nodiscard]] ModelWithLoadStates getState() const { return m_state; }

private:
  ModelWithLoadStates m_state;
};

#endif // MODELWITHLOAD_HPP