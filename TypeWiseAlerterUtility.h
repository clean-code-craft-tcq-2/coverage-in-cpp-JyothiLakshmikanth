#ifndef TYPEWISEALERTERUTILITY_H
#define TYPEWISEALERTERUTILITY_H
#include <map>
#include <vector>
#include "InfoTypes.h"

using namespace std;
using namespace InfoTypes;

class TypeWiseAlerterUtility
{
public:
   typedef ::std::map< CoolingType, Limits> T_CoolingTypeLimits;
   typedef ::std::map< InfoTypes::BreachType, string> T_BreachTypeStringMap;
   typedef ::std::vector< const char* > EmailRecepientList;
   typedef ::std::vector< const unsigned short> ControllerList;

  static void getCoolingTypeLimitsMap(T_CoolingTypeLimits& coolingTypeLimits);
  static void getBreachTypeStringMap(T_BreachTypeStringMap& breachTypeStringMap);
  static void getEmailRecepientList(EmailRecepientList& emailRecepientList);
  static void getControllerList(ControllerList& controllerList);

private:
  static T_CoolingTypeLimits prepareCoolingTypeLimitsMap();
  static T_BreachTypeStringMap prepareBreachTypeStringMap();
  static EmailRecepientList prepareEmailRecepient();
  static ControllerList prepareControllerList();

};

T_CoolingTypeLimits TypeWiseAlerterUtility::prepareCoolingTypeLimitsMap()
{
   T_CoolingTypeLimits coolingTypeLimits;
    coolingTypeLimits.insert({InfoTypes::PASSIVE_COOLING , 0.0, 35.0});
    coolingTypeLimits.insert({InfoTypes::HI_ACTIVE_COOLING , 0.0, 45.0});
    coolingTypeLimits.insert({InfoTypes::MED_ACTIVE_COOLING , 0.0, 40.0});
   return coolingTypeLimits;
}

T_BreachTypeStringMap TypeWiseAlerterUtility::prepareBreachTypeStringMap()
{
   T_BreachTypeStringMap breachTypeStringMap;
    breachTypeStringMap.insert({InfoTypes::TOO_LOW, "Hi, the temperature is too low"});
    breachTypeStringMap.insert({InfoTypes::TOO_HIGH, "Hi, the temperature is too high"});
    breachTypeStringMap.insert({InfoTypes::NORMAL, "Hi, the temperature is NORMAL"});
   return breachTypeStringMap;
}

EmailRecepientList TypeWiseAlerterUtility::prepareEmailRecepient();
{
   EmailRecepientList emailRecepientList;
  emailRecepientList.push_bach("a.b@c.com");
   return emailRecepientList;
}

ControllerList TypeWiseAlerterUtility::prepareControllerList()
{
   ControllerList controllerList;
  controllerList.push_back(0xfeed);
   return controllerList;
}

void TypeWiseAlerterUtility::getCoolingTypeLimitsMap(T_CoolingTypeLimits& coolingTypeLimits)
{
   coolingTypeLimits = TypeWiseAlerterUtility::prepareCoolingTypeLimitsMap();
}

void TypeWiseAlerterUtility::getBreachTypeStringMap(T_BreachTypeStringMap& breachTypeStringMap)
{
  breachTypeStringMap = TypeWiseAlerterUtility::prepareBreachTypeStringMap();
}

void TypeWiseAlerterUtility::getEmailRecepientList(EmailRecepientList& emailRecepientList)
{
  emailRecepientList = TypeWiseAlerterUtility::prepareEmailRecepientList();
}

void TypeWiseAlerterUtility::getControllerList(ControllerList& controllerList)
{
  controllerList = TypeWiseAlerterUtility::prepareControllerList();
}
#endif
