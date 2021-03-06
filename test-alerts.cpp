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
  REQUIRE(typeWiseAlert.checkAndAlert(TO_CONTROLLER, batteryChar, 45) == SUCCESS);
  REQUIRE(typeWiseAlert.checkAndAlert(TO_EMAIL, batteryChar, 45)== SUCCESS);
}

TEST_CASE("checkAndAlert_If_No_Controllers_Available")
{
   typeWiseAlert.m_controllerList.clear();
   BatteryCharacter batteryChar;
   batteryChar.coolingType = PASSIVE_COOLING;
   REQUIRE(typeWiseAlert.checkAndAlert(TO_CONTROLLER, batteryChar, 45) == FAILURE);
}

TEST_CASE("checkAndAlert_If_No_EMAIL_Recepients_Available")
{
   typeWiseAlert.m_emailRecepientList.clear();
   BatteryCharacter batteryChar;
   batteryChar.coolingType = PASSIVE_COOLING;
   REQUIRE(typeWiseAlert.checkAndAlert(TO_EMAIL, batteryChar, 45) == FAILURE);
}

TEST_CASE("sendToEmail_If_No_Breach_Value_Present_inMap")
{
   typeWiseAlert.m_breachTypeStringMap.clear();
   REQUIRE(typeWiseAlert.sendToEmail(NORMAL) == FAILURE);
}

TEST_CASE("check_limits_for_different_cooling_Type")
{
  Limits limits;
  limits = typeWiseAlert.getTheLimitsForCoolingType(PASSIVE_COOLING);
  REQUIRE(limits.getLowerLimit() == 0.0);
  REQUIRE(limits.getUpperLimit() == 35.0);
  limits = typeWiseAlert.getTheLimitsForCoolingType(HI_ACTIVE_COOLING);
  REQUIRE(limits.getLowerLimit() == 0.0);
  REQUIRE(limits.getUpperLimit() == 45.0);
  limits = typeWiseAlert.getTheLimitsForCoolingType(MED_ACTIVE_COOLING);
  REQUIRE(limits.getLowerLimit() == 0.0);
  REQUIRE(limits.getUpperLimit() == 40.0);
}

TEST_CASE("check_classifyTemperatureBreach_ForPASSIVE_COOLINGType")
{
  REQUIRE(typeWiseAlert.classifyTemperatureBreach(PASSIVE_COOLING,40) == TOO_HIGH);
  REQUIRE(typeWiseAlert.classifyTemperatureBreach(PASSIVE_COOLING,-1) == TOO_LOW);
  REQUIRE(typeWiseAlert.classifyTemperatureBreach(PASSIVE_COOLING,25) == NORMAL);
}

TEST_CASE("check_classifyTemperatureBreach_ForHI_ACTIVE_COOLINGType")
{
  REQUIRE(typeWiseAlert.classifyTemperatureBreach(HI_ACTIVE_COOLING,50) == TOO_HIGH);
  REQUIRE(typeWiseAlert.classifyTemperatureBreach(HI_ACTIVE_COOLING,-1) == TOO_LOW);
  REQUIRE(typeWiseAlert.classifyTemperatureBreach(HI_ACTIVE_COOLING,25) == NORMAL);
}

TEST_CASE("check_classifyTemperatureBreach_ForMED_ACTIVE_COOLINGType")
{
  REQUIRE(typeWiseAlert.classifyTemperatureBreach(MED_ACTIVE_COOLING,45) == TOO_HIGH);
  REQUIRE(typeWiseAlert.classifyTemperatureBreach(MED_ACTIVE_COOLING,-1) == TOO_LOW);
  REQUIRE(typeWiseAlert.classifyTemperatureBreach(MED_ACTIVE_COOLING,25) == NORMAL);
}
