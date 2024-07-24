#include "modelDummy.hpp"
#include "mocks/exec_proto/mock_exec_proto.hpp"
#include <gtest/gtest.h>

TEST(ModelX, GetSimTime) {
  EXPECT_EQ(ModelDummy::getSimTime(), 0);

  set_sim_time(1);
  EXPECT_EQ(ModelDummy::getSimTime(), 1);

  set_sim_time(2);
  EXPECT_EQ(ModelDummy::getSimTime(), 2);
}