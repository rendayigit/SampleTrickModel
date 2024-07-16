/*************************************************************************
PURPOSE: ( The Root of all models. This model is a container of all other models. )
LIBRARY DEPENDENCIES:
    ((root.o))
PROGRAMMERS:
    (((Yusuf Can Anar) (Turkish Aerospace) (09 July 2024))
     ((Renda Yigit) (Turkish Aerospace) (09 July 2024)))
**************************************************************************/
#ifndef ROOT_HPP
#define ROOT_HPP

#include "math/math.hpp"
#include "modelX/modelX.hpp"
#include "modelY/modelY.hpp"

#include "sim_services/Executive/include/exec_proto.h"

class Root {
public:
  static Root &getInstance() {
    static Root instance;
    return instance;
  }

  // Model instances
  ModelX *modelX;
  ModelY *modelY;

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

private:
  Root();
};

#endif // ROOT_HPP