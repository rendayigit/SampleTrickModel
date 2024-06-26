#include "ModelX.hpp"
#include "mocks/exec_proto/mock_exec_proto.hpp"
#include <gtest/gtest.h>

TEST(ModelX, Addition) {
  EXPECT_EQ(ModelX::add(1, 2), 3);
  EXPECT_EQ(ModelX::add(2, -1), 1);
}

TEST(ModelX, Subtraction) {
  EXPECT_EQ(ModelX::sub(1, 2), -1);
  EXPECT_EQ(ModelX::sub(2, -1), 3);
}

TEST(ModelX, Multiplication) {
  EXPECT_EQ(ModelX::mul(1, 2), 2);
  EXPECT_EQ(ModelX::mul(2, -1), -2);
}

TEST(ModelX, GetSimTime) {
  EXPECT_EQ(ModelX::getSimeTime(), 0);

  set_sim_time(1);
  EXPECT_EQ(ModelX::getSimeTime(), 1);

  set_sim_time(2);
  EXPECT_EQ(ModelX::getSimeTime(), 2);
}