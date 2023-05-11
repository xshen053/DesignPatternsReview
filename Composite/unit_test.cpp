#include "gtest/gtest.h"

#include "./src/op_test.hpp"
#include "./src/Rand_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
