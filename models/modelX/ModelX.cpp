/*************************************************************************
PURPOSE: ( A sample trick model created using only cpp. ModelX. )
LIBRARY DEPENDENCIES:
    ((ModelX.o))
PROGRAMMERS:
    ((Renda Yiğit) (Turkish Aerospace) (01 July 2024))
**************************************************************************/
#include "ModelX.hpp"
#include "common/modelEvent.hpp"
#include "root/Root.hpp"

#include <iostream>
#include <vector>

#include "sim_services/Executive/include/exec_proto.h"

int ModelX::default_data() {
  std::cout << "Default Data Entered \t\t@ " << exec_get_sim_time() << std::endl;
  
  // Initialize model variables with random default values
  a[0] = 0.0;
  a[1] = 6578000.0;
  b[0] = 7905.0;
  b[1] = 0.0;
  c.setValue(900);

  std::vector<int> myList;

  // Notice clangd suggests using range-based for loop instead
  for (int i = 0; i < myList.size(); i++) {
    myList.at(i) = 0;
  }

  return 0;
}

int ModelX::init() {
  std::cout << "Initialization Entered \t\t@ " << exec_get_sim_time() << std::endl;
  
  // Set an array variable
  b[1] = add(1, 2);

  // Create a model event
  auto *event = new ModelEvent;

  event->setEventFunction(
      []() { std::cout << "setEventFunction Entered \t@ " << exec_get_sim_time() << std::endl; });
  event->set_name("My Sample Model Event");
  event->set_cycle(0);
  event->setTriggerTime(2.2);
  event->activate();

  event_manager_add_event(event);

  // Connect modelY inflow variable to modelX outflow variable
  c.connect(Root::getInstance().modelY->inFlow);

  // Test dataflow connection
  c.setValue(256);
  std::cout << Root::getInstance().modelY->inFlow.getValue() << std::endl;
  
  return 0;
}

int ModelX::scheduled() {
  std::cout << "Scheduled Entered \t\t@ " << exec_get_sim_time() << std::endl;
  c.setValue(c.getValue() + 1);
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