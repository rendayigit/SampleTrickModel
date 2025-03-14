// This file contains functions that manupulate the mocked functions defined in
// EventManager_c_intf.h

#pragma once

#include "trick/Event.hh"
#include <vector>

extern std::vector<Trick::Event *> simulationEvents;

// This function is not a trick function, it is used to improve unit test coverage
inline void event_dummy_checkpoint_restart() { // NOLINT(readability-identifier-naming)
  for (auto &event : simulationEvents) {
    event->restart();
  }
}