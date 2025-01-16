// This file contains functions that manupulate the mocked functions defined in exec_proto.h

#ifndef MOCK_EXEC_PROTO_HPP
#define MOCK_EXEC_PROTO_HPP

#include "mocks/EventManager_c_intf/mock_EventManager_c_intf.hpp"
#include "sim_services/Executive/include/exec_proto.h"

constexpr double TIME_PROGRESS = 0.1;

extern double simTime;
extern bool isProgressingByEachSimTimeCall;

/**
 * Sets the mocked simulation time. This function is used in the unit tests.
 *
 * @param newTime The new simulation time as a double.
 */
inline void setSimTime(double newTime) { simTime = newTime; }

/**
 * @brief Progresses the mocked simulation time.
 *
 * @param seconds The number of seconds to progress the simulation time.
 */
inline void progressSimulation(double seconds) {
  // Set new simulation time
  simTime += seconds;

  // Iterate through all events in the simulation
  for (auto &event : simulationEvents) {
    if (event->is_active()) {
      double cycle = event->get_cycle();
      // If the event is periodic
      if (cycle > 0) {
        // Process the event enough cycles for the given amount of time
        double timeProgress = 0.0;
        while (timeProgress < seconds) {
          // Process the event
          event->process(0);

          timeProgress += event->get_cycle();
        }
        // If the event is single shotl
      } else {
        // Process the event if its schedule is due
        if ((event->get_next_tics() / 1000000) <= simTime) {
          // Process the event
          event->process(0);
        }
      }
    }
  }
}

/**
 * @brief Sets whether every `exec_get_sim_time` call should progress the mocked simulation time by
 * `TIME_PROGRESS`.
 *
 * @param isProgress Whether to progress or not.
 */
inline void setIsProgressingByEachSimTimeCall(bool isProgress) { isProgressingByEachSimTimeCall = isProgress; }

#endif