// This file mocks the functions defined in exec_proto.h

#include "mock_exec_proto.hpp"
#include "sim_services/Executive/include/exec_proto.h"

double simTime = 0.0;

namespace Trick {
class Event {};
} // namespace Trick

/**
 * Returns mocked current simulation time. Use set_sim_time(double newTime) to set the new
 * simulation time. This function is provided by Trick.
 *
 * @return The mocked simulation time as a double.
 */
double exec_get_sim_time(void) { return simTime; }

double event_manager_add_event(Trick::Event *in_event) { return 0.0; }

long long exec_get_time_tics(void) { return 0.0; } // TODO - improve return value

int exec_get_time_tic_value(void) { return 0; } // TODO - improve return value