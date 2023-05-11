#include "gtest/gtest.h"


#include "iterator_test.hpp"
// #include "math_test.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}