/*************************************************************************
PURPOSE: ( The Root of all models. This model is a container of all other models. )
LIBRARY DEPENDENCIES:
    ((root.o))
PROGRAMMERS:
    (((Yusuf Can Anar) (Turkish Aerospace) (09 July 2024))
     ((Renda Yigit) (Turkish Aerospace) (09 July 2024)))
**************************************************************************/

#include "root.hpp"
#include "modelX/modelX.hpp"
#include <iostream>

Root::Root() : modelX(new ModelX()), modelY(new ModelY()) {
  std::cout << "Root object created \t\t\t\t@ " << exec_get_sim_time() << std::endl;
};

int Root::default_data() {
  std::cout << "Default Data Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;
  return 0;
}

int Root::init() {
  std::cout << "Initialization Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;

  // Create a one shot event.
  modelWithEvents->createOneShotEvent();

  // Create a scheduled event.
  modelWithEvents->createScheduledEvent();

  // Connection establishment must done after all models including root are instantiated.
  modelX->establishConnections();

  return 0;
}

int Root::scheduled() {
  std::cout << "Scheduled Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;

  /* Models that are loads can be controled similar to this way */
  if (modelWithLoad->getState() == ModelWithLoad::ON) {
    modelWithLoad->turnOff();
  } else {
    modelWithLoad->turnOn();
  }

  return 0;
}

int Root::shutdown() {
  std::cout << "Shutdown Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;
  return 0;
}