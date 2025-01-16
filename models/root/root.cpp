#include "root.hpp"

#include <iostream>

int Root::initialization() {
  std::cout << "Initialization Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;

  // Create a one shot event.
  // modelWithEvents.createOneShotEvent();

  // Create a scheduled event.
  // modelWithEvents.createScheduledEvent();

  // Connection establishment must done after all models including root are instantiated.

  // Connect modelY inflow variables to modelX outflow variable
  modelX.outFlow.connect(&modelY.inFlow1);
  std::cout << "ModelY inFlow1 connection established, inFlow1 value: " << modelY.inFlow1.getValue()
            << std::endl;
  modelX.outFlow.connect(&modelY.inFlow2);
  std::cout << "ModelY inFlow2 connection established, inFlow2 value: " << modelY.inFlow2.getValue()
            << std::endl;

  // Test dataflow connections
  modelX.outFlow.setValue(256);
  std::cout << "ModelX OutFlow value set, outFlow: " << modelX.outFlow.getValue() << std::endl;
  std::cout << "ModelY inFlow1 value: " << modelY.inFlow1.getValue() << std::endl;
  std::cout << "ModelY inFlow2 value: " << modelY.inFlow2.getValue() << std::endl;

  return 0;
}

// TODO: implement
// int Root::scheduled() {
//   std::cout << "Scheduled Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;

//   /* Models that are loads can be controled similar to this way */
//   if (modelWithLoad.getState() == ModelWithLoad::ON) {
//     modelWithLoad.turnOff();
//   } else {
//     modelWithLoad.turnOn();
//   }

//   return 0;
// }

int Root::shutdown() {
  std::cout << "Shutdown Entered \t\t\t\t@ " << exec_get_sim_time() << std::endl;
  return 0;
}