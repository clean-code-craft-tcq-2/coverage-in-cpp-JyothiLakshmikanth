#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#define private public
#include "typewise-alert.h"

using namespace InfoTypes;

TEST_CASE("infers the breach according to limits") {
  TypeWiseAlert typeWiseAlert;
  Limits limits(20, 30);
  REQUIRE(typeWiseAlert.inferBreach(12, limits) == TOO_LOW);
}
