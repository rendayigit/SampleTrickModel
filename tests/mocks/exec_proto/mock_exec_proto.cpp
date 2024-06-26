// This file mocks the functions defined in exec_proto.h

#include "mock_exec_proto.hpp"
#include "sim_services/Executive/include/exec_proto.h"

double simTime = 0.0;

/**
 * Returns mocked current simulation time. Use set_sim_time(double newTime) to set the new
 * simulation time. This function is provided by Trick.
 *
 * @return The mocked simulation time as a double.
 */
double exec_get_sim_time(void) { return simTime; }