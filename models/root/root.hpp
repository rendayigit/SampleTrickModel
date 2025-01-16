/*************************************************************************
PURPOSE: ( The Root of all models. This model is a container of all other models. )
**************************************************************************/
#pragma once

#include "modelDummy/modelDummy.hpp"
// #include "modelWithEvents/modelWithEvents.hpp"
#include "modelX/modelX.hpp"
#include "modelY/modelY.hpp"

#include "sim_services/Executive/include/exec_proto.h"

class Root {
public:
  // Model instances
  ModelX modelX;
  ModelY modelY;
  // ModelWithEvents modelWithEvents; // TODO: implement
  ModelDummy modelDummy;

  /**
   * @brief Trick initialization function. This function is called at the beginning of the
   * simulation.
   *
   * @return 0 indicating successful initialization
   */
  int initialization();

  /**
   * @brief Trick termination function. This function is called at the end of the simulation.
   *
   * @return 0 indicating successful initialization
   */
  int shutdown();
};