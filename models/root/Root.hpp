/*************************************************************************
PURPOSE: ( The Root of all models. This model is a container of all other models. )
PROGRAMMERS:
    ((Yusuf Can Anar) (Turkish Aerospace) (09 July 2024))
**************************************************************************/
#ifndef ROOT_HPP
#define ROOT_HPP

#include "modelX/ModelX.hpp"
#include "modelY/ModelY.hpp"

#include "sim_services/Executive/include/exec_proto.h"

class Root {
public:
  ModelX *modelX;
  ModelY *modelY;

  static Root &getInstance() {
    static Root instance;
    return instance;
  }

private:
  Root() : modelX(new ModelX()), modelY(new ModelY()) {
    std::cout << "Root object created \t\t@ " << exec_get_sim_time() << std::endl;
  };
};

#endif // ROOT_HPP