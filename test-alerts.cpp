#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#define private public
#include "typewise-alert.h"

using namespace InfoTypes;

TEST_CASE("infers the breach according to limits") {
  TypeWiseAlert typeWiseAlert;
  Limits low_limits(20, 30);
  REQUIRE(typeWiseAlert.inferBreach(12, low_limits) == TOO_LOW);
  Limits high_limits(20, 45);
  REQUIRE(typeWiseAlert.inferBreach(50, high_limits) == TOO_HIGH);
  Limits normal_limits(20, 45);
  REQUIRE(typeWiseAlert.inferBreach(30, normal_limits) == NORMAL);
}
