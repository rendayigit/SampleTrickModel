#include "modelDummy.hpp"
#include "mocks/exec_proto/mock_exec_proto.hpp"
#include <gtest/gtest.h>

TEST(ModelX, GetSimTime) {
  EXPECT_EQ(ModelDummy::getSimTime(), 0);

  setSimTime(1);
  EXPECT_EQ(ModelDummy::getSimTime(), 1);

  setSimTime(2);
  EXPECT_EQ(ModelDummy::getSimTime(), 2);
}