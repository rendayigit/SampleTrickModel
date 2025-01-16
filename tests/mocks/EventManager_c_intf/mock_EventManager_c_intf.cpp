#include "mock_EventManager_c_intf.hpp"

std::vector<Trick::Event *> simulationEvents;

int event_manager_add_event(Trick::Event *event) { // NOLINT(readability-identifier-naming)
  simulationEvents.push_back(event);
  event->add();
  return 0;
}

int event_manager_remove_event(Trick::Event *in_event) { // NOLINT(readability-identifier-naming)
  simulationEvents.erase(std::find(simulationEvents.begin(), simulationEvents.end(), in_event));
  in_event->remove();
  return 0;
}