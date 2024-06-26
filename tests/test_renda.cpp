#include "Renda.hpp"
#include <gtest/gtest.h>

TEST(Renda, Addition) {
  EXPECT_EQ(Renda::add(1, 2), 3);
  EXPECT_EQ(Renda::add(2, -1), 1);
}

TEST(Renda, Subtraction) {
  EXPECT_EQ(Renda::sub(1, 2), -1);
  EXPECT_EQ(Renda::sub(2, -1), 3);
}

TEST(Renda, Multiplication) {
  EXPECT_EQ(Renda::mul(1, 2), 2);
  EXPECT_EQ(Renda::mul(2, -1), -2);
}

TEST(Renda, GetSimTime) {
  EXPECT_EQ(Renda::getSimeTime(), 0);
  EXPECT_EQ(Renda::getSimeTime(), 1);
  EXPECT_EQ(Renda::getSimeTime(), 2);
}