#include "modelWithEvents.hpp"
#include "common/modelEvent.hpp"
#include <iostream>

#include "sim_services/Executive/include/exec_proto.h"

void ModelWithEvents::createOneShotEvent() {
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

void ModelWithEvents::createScheduledEvent() {
  // Create a model event
  auto *event = new ModelEvent;

  // Set the event callback function
  event->setEventFunction([this]() {
    std::cout << "Scheduled event setEventFunction Entered \t@ " << exec_get_sim_time()
              << std::endl;
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