#include "gtest/gtest.h"

#include "./src/op_test.hpp"
#include "./src/Rand_test.hpp"
#include "./src/Mult_test.hpp"
#include "./src/div_test.hpp"
#include "./src/add_test.hpp"
#include "./src/sub_test.hpp"
#include "./src/pow_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
