#include "modelX.hpp"
#include "common/modelEvent.hpp"
#include "root/root.hpp"

#include <iostream>
#include <vector>

#include "sim_services/Executive/include/exec_proto.h"

ModelX::ModelX() {
  a[0] = 0.0;
  a[1] = 6578000.0;
  b[0] = 7905.0;
  b[1] = 0.0;
  deneme = 0;
  c.setValue(900);

  std::vector<int> myList;

  // Notice clangd suggests using range-based for loop instead
  for (int i = 0; i < myList.size(); i++) {
    myList.at(i) = 0;
  }

  createOneShotEvent();

  createScheduledEvent();

  // Notice establishConnections() must be called after all related models including root are
  // instantiated. Hence this function is called in Root::init().
  // establishConnections();
}

void ModelX::createOneShotEvent() {
  // Create a model event
  auto *event = new ModelEvent;

  // Set the event callback function
  event->setEventFunction([this]() {
    std::cout << "One shot event setEventFunction Entered \t@ " << exec_get_sim_time() << std::endl;
  });

  // Set the event name
  event->set_name("My Sample Model One Shot Event");

  // Set the event cycle
  event->set_cycle(0);

  // Set the event trigger time. The event will be triggered at this time.
  event->setTriggerTime(2.2);

  // Activate the event
  event->activate();

  // Add the event to the event manager
  event_manager_add_event(event);
}

void ModelX::createScheduledEvent() {
  // Create a model event
  auto *event = new ModelEvent;

  // Set the event callback function
  event->setEventFunction([this]() {
    std::cout << "Scheduled event setEventFunction Entered \t@ " << exec_get_sim_time()
              << std::endl;
    c.setValue(c.getValue() + 1);
  });

  // Set the event name
  event->set_name("My Sample Model Scheduled Event");

  // Set the event cycle
  event->set_cycle(1);

  // Set the event trigger time. The event will be triggered at this time. This will be ignored if
  // set_cycle is not 0.
  event->setTriggerTime(2.2);

  // Activate the event
  event->activate();

  // Add the event to the event manager
  event_manager_add_event(event);
}

void ModelX::establishConnections() {
  // Connect modelY inflow variables to modelX outflow variable
  c.connect(&Root::getInstance().modelY->inFlow1);
  std::cout << "ModelY inFlow1 connection established, inFlow1 value: "
            << Root::getInstance().modelY->inFlow1.getValue() << std::endl;
  c.connect(&Root::getInstance().modelY->inFlow2);
  std::cout << "ModelY inFlow2 connection established, inFlow2 value: "
            << Root::getInstance().modelY->inFlow2.getValue() << std::endl;

  // Test dataflow connections
  c.setValue(256);
  std::cout << "ModelX OutFlow value set, c: " << c.getValue() << std::endl;
  std::cout << "ModelY inFlow1 value: " << Root::getInstance().modelY->inFlow1.getValue()
            << std::endl;
  std::cout << "ModelY inFlow2 value: " << Root::getInstance().modelY->inFlow2.getValue()
            << std::endl;
}

double ModelX::getSimTime() { return exec_get_sim_time(); }