// This file contains functions that manupulate the mocked functions defined in exec_proto.h

#ifndef MOCK_EXEC_PROTO_HH
#define MOCK_EXEC_PROTO_HH

extern double simTime;

/**
 * Sets the mocked current simulation time. This function is used in the unit tests.
 *
 * @param newTime The new simulation time as a double.
 */
inline void set_sim_time(double newTime) { simTime = newTime; }

#endif