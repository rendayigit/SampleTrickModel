#include "sim_services/Executive/include/exec_proto.h"

double exec_get_sim_time(void) {
  static double time = 0;
  return time++;
}