/********************************* TRICK HEADER *******************************
PURPOSE: ( A sample trick model created using only cpp. ModelX. )
LIBRARY DEPENDENCY:
    ((ModelX.o))
PROGRAMMERS:
    (((Renda Yiğit) (Turkish Aerospace) (01 July 2024)
*******************************************************************************/
#include "ModelX.hpp"
#include "common/modelEvent.hpp"

#include <iostream>
#include <vector>

#include "sim_services/Executive/include/exec_proto.h"

int ModelX::default_data() {
  std::cout << "Default Data Entered \t\t@ " << exec_get_sim_time() << std::endl;
  a[0] = 0.0;
  a[1] = 6578000.0;
  b[0] = 7905.0;
  b[1] = 0.0;
  c = 900;

  std::vector<int> myList;

  // Notice clangd suggests using range-based for loop instead
  for (int i = 0; i < myList.size(); i++) {
    myList.at(i) = 0;
  }

  return 0;
}

int ModelX::init() {
  std::cout << "Initialization Entered \t\t@ " << exec_get_sim_time() << std::endl;
  b[1] = add(1, 2);
  c = sub(500, 2);

  auto *event = new ModelEvent;

  event->setEventFunction(
      []() { std::cout << "setEventFunction Entered \t@ " << exec_get_sim_time() << std::endl; });
  event->set_name("My Sample Model Event");
  event->set_cycle(0);
  event->setTriggerTime(2.2);
  event->activate();

  event_manager_add_event(event);

  return 0;
}

int ModelX::scheduled() {
  std::cout << "Scheduled Entered \t\t@ " << exec_get_sim_time() << std::endl;
  c++;
  return 0;
}

int ModelX::shutdown() {
  std::cout << "Shutdown Entered \t\t@ " << exec_get_sim_time() << std::endl;
  std::cout << "Sim Time: " << exec_get_sim_time() << std::endl;
  return 0;
}

double ModelX::getSimeTime() { return exec_get_sim_time(); }

int ModelX::add(int a, int b) { return a + b; }

int ModelX::sub(int a, int b) { return a - b; }

int ModelX::mul(int a, int b) { return a * b; }

int ModelX::div(int a, int b) { return a / b; }