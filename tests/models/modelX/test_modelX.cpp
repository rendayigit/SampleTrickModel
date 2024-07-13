#include "modelX.hpp"
#include "mocks/exec_proto/mock_exec_proto.hpp"
#include <gtest/gtest.h>

TEST(ModelX, GetSimTime) {
  EXPECT_EQ(ModelX::getSimeTime(), 0);

  set_sim_time(1);
  EXPECT_EQ(ModelX::getSimeTime(), 1);

  set_sim_time(2);
  EXPECT_EQ(ModelX::getSimeTime(), 2);
}