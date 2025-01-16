#include "modelWithEvents.hpp"

#include <iostream>

#include "sim_services/Executive/include/exec_proto.h"

ModelWithEvents::ModelWithEvents() {}

void ModelWithEvents::createOneShotEvent() {
  // Set the event callback function
  m_oneShotEvent.setEventFunction([this]() {
    std::cout << "One shot event setEventFunction Entered \t@ " << exec_get_sim_time() << std::endl;
  });

  // Set the event cycle
  m_oneShotEvent.setCycleTime(0);

  // Set the event trigger time. The event will be triggered at this time.
  m_oneShotEvent.setTriggerTime(2.2);

  // Activate the event
  m_oneShotEvent.activate();
}

void ModelWithEvents::createScheduledEvent() {
  // Set the event callback function
  m_scheduledEvent.setEventFunction([this]() {
    std::cout << "Scheduled event setEventFunction Entered \t@ " << exec_get_sim_time()
              << std::endl;
  });

  // Set the event cycle
  m_scheduledEvent.setCycleTime(1);

  // Set the event trigger time. The event will be triggered at this time. This will be ignored if
  // set_cycle is not 0.
  m_scheduledEvent.setTriggerTime(2.2);

  // Activate the event
  m_scheduledEvent.activate();
}