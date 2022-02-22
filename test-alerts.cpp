#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#define private public
#include "test/catch.hpp"
#include "typewise-alert.h"

using namespace InfoTypes;

TEST_CASE("infers the breach according to limits") {
  TypeWiseAlert typeWiseAlert;
  InfoTypes::Limits limits(20, 30);
  REQUIRE(typeWiseAlert.inferBreach(12, limits) == TOO_LOW);
}
