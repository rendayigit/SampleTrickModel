#include "root.hpp"
#include <iostream>
#include <string>

#define SAMPLE_SERVER_PORT 3310

Root::Root() { std::cout << "Root object created \t\t\t\t@ " << exec_get_sim_time() << std::endl; };

int Root::default_data() {
  std::cout << "Default Data Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;
  return 0;
}

int Root::init() {
  std::cout << "Initialization Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;

  // Create a one shot event.
  // modelWithEvents.createOneShotEvent();

  // Create a scheduled event.
  // modelWithEvents.createScheduledEvent();

  // Connection establishment must done after all models including root are instantiated.
  modelX.establishConnections();

  return 0;
}

int Root::scheduled() {
  std::cout << "Scheduled Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;

  /* Models that are loads can be controled similar to this way */
  if (modelWithLoad.getState() == ModelWithLoad::ON) {
    modelWithLoad.turnOff();
  } else {
    modelWithLoad.turnOn();
  }

  return 0;
}

int Root::shutdown() {
  std::cout << "Shutdown Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;
  return 0;
}