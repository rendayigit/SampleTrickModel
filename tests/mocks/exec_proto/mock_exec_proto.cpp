// This file mocks the functions defined in exec_proto.h

#include "mocks/exec_proto/mock_exec_proto.hpp"

double simTime = 0.0;
bool isProgressingByEachSimTimeCall = false;

/**
 * Returns mocked current simulation time. Use set_sim_time(double newTime) to set the new
 * simulation time. This function is provided by Trick.
 *
 * @return The mocked simulation time as a double.
 */
double exec_get_sim_time(void) { // NOLINT(readability-identifier-naming)
  if (isProgressingByEachSimTimeCall) {
    simTime += TIME_PROGRESS;
  }

  return simTime;
}

long long exec_get_time_tics(void) { // NOLINT(readability-identifier-naming)
  static long long ticks = 0;
  return ++ticks;
}

int exec_get_time_tic_value(void) { // NOLINT(readability-identifier-naming)
  static int ticks = 0;
  return ++ticks;
}