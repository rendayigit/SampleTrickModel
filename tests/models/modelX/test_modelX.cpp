#include "modelX.hpp"
#include "mocks/exec_proto/mock_exec_proto.hpp"
#include <gtest/gtest.h>

TEST(ModelX, GetSimTime) {
  EXPECT_EQ(ModelX::getSimTime(), 0);

  set_sim_time(1);
  EXPECT_EQ(ModelX::getSimTime(), 1);

  set_sim_time(2);
  EXPECT_EQ(ModelX::getSimTime(), 2);
}