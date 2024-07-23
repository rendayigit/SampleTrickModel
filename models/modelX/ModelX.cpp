/********************************* TRICK HEADER *******************************
PURPOSE: ( A sample trick model created using only cpp. ModelX. )
LIBRARY DEPENDENCY:
    ((ModelX.o))
PROGRAMMERS:
    (((Renda Yiğit) (Turkish Aerospace) (01 July 2024)
*******************************************************************************/
#include "ModelX.hh"
#include "common/modelEvent.hh"
#include "root/Root.hh"

#include <iostream>
#include <vector>

#include "sim_services/Executive/include/exec_proto.h"

int ModelX::init() {
  std::cout << "Initialization Entered \t\t@ " << exec_get_sim_time() << std::endl;
  c.set(11);

  auto *event = new ModelEvent;

  event->setEventFunction(
      []() { std::cout << "setEventFunction Entered \t@ " << exec_get_sim_time() << std::endl; });
  event->set_name("My Sample Model Event");
  event->set_cycle(0);
  event->setTriggerTime(2.2);
  event->activate();

  event_manager_add_event(event);
  c.set(256);
  return 0;
}
