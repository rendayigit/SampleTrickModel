/*************************************************************************
PURPOSE: ( A sample trick model created to demonstrate inter model communication between ModelX and
ModelY.)
PROGRAMMERS:
    ((Renda Yiğit) (Turkish Aerospace) (01 July 2024))
**************************************************************************/
#ifndef MODELX_HPP
#define MODELX_HPP

#include "common/dataFlow.hpp"

class ModelX {
public:
  OutFlow<int> c; /* cm    sample c value */

  ModelX();

  /**
   * Establish connections between modelX and modelY.
   */
  void establishConnections();
};

#endif // MODELX_HPP