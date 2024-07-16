#include "math.hpp"
#include <gtest/gtest.h>

TEST(Math, Addition) {
  EXPECT_EQ(Math::add(1, 2), 3);
  EXPECT_EQ(Math::add(2, -1), 1);
}

TEST(Math, Subtraction) {
  EXPECT_EQ(Math::sub(1, 2), -1);
  EXPECT_EQ(Math::sub(2, -1), 3);
}

TEST(Math, Multiplication) {
  EXPECT_EQ(Math::mul(1, 2), 2);
  EXPECT_EQ(Math::mul(2, -1), -2);
}