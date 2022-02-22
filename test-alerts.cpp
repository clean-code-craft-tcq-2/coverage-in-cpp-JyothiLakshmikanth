#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"
#define private public
#include "typewise-alert.h"

using namespace InfoTypes;
TypeWiseAlert typeWiseAlert;

TEST_CASE("infers the breach according to limits") {

  Limits low_limits(20, 30);
  REQUIRE(typeWiseAlert.inferBreach(12, low_limits) == TOO_LOW);
  Limits high_limits(20, 45);
  REQUIRE(typeWiseAlert.inferBreach(50, high_limits) == TOO_HIGH);
  Limits normal_limits(20, 45);
  REQUIRE(typeWiseAlert.inferBreach(30, normal_limits) == NORMAL);
}

TEST_CASE("checkAndAlert")
{
  BatteryCharacter batteryChar;
  batteryChar.coolingType = PASSIVE_COOLING;
  typeWiseAlert.checkAndAlert(TO_CONTROLLER, batteryChar, 45);
}

TEST_CASE("check_limits_for_PASSIVE_COOLING")
{
  Limits limits;
  limits = typeWiseAlert.getTheLimitsForCoolingType(PASSIVE_COOLING);
  REQUIRE(limits.getLowerLimit() == 0.0);
  REQUIRE(limits.getUpperLimit() == 35.0);
}

TEST_CASE("check_limits_for_HI_ACTIVE_COOLING")
{
  Limits limits;
  limits = typeWiseAlert.getTheLimitsForCoolingType(HI_ACTIVE_COOLING);
  REQUIRE(limits.getLowerLimit() == 0.0);
  REQUIRE(limits.getUpperLimit() == 45.0);
}

TEST_CASE("check_limits_for_MED_ACTIVE_COOLING")
{
  Limits limits;
  limits = typeWiseAlert.getTheLimitsForCoolingType(MED_ACTIVE_COOLING);
  REQUIRE(limits.getLowerLimit() == 0.0);
  REQUIRE(limits.getUpperLimit() == 40.0);
}
