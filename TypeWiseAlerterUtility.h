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
   typedef ::std::vector< const char* > emailRecepientList;
   typedef ::std::vector< const unsigned short> controllerList;

  static T_CoolingTypeLimits getCoolingTypeLimitsMap();
  static T_BreachTypeStringMap getBreachTypeStringMap();
  static emailRecepientList getEmailRecepientList();
  static controllerList getControllerList();

private:
  static void prepareCoolingTypeLimitsMap();
  static void prepareBreachTypeStringMap();
  static void prepareEmailRecepient();
  static void prepareControllerList();

};

void TypeWiseAlerterUtility::prepareCoolingTypeLimitsMap()
{
    m_coolingTypeLimits.insert({InfoTypes::PASSIVE_COOLING , 0.0, 35.0});
    m_coolingTypeLimits.insert({InfoTypes::HI_ACTIVE_COOLING , 0.0, 45.0});
    m_coolingTypeLimits.insert({InfoTypes::MED_ACTIVE_COOLING , 0.0, 40.0}); 
}

void TypeWiseAlerterUtility::prepareBreachTypeStringMap()
{
    m_breachTypeStringMap.insert({InfoTypes::TOO_LOW, "Hi, the temperature is too low"});
    m_breachTypeStringMap.insert({InfoTypes::TOO_HIGH, "Hi, the temperature is too high"});
    m_breachTypeStringMap.insert({InfoTypes::NORMAL, "Hi, the temperature is NORMAL"});
}

void TypeWiseAlerterUtility::prepareEmailRecepient();
{
  m_emailRecepientList.push_bach("a.b@c.com");
}

void TypeWiseAlerterUtility::prepareControllerList()
{
  m_controllerList.push_back(0xfeed);
}

T_CoolingTypeLimits TypeWiseAlerterUtility::getCoolingTypeLimitsMap()
{
   T_CoolingTypeLimits  m_coolingTypeLimits = TypeWiseAlerterUtility::prepareCoolingTypeLimitsMap();
   return m_coolingTypeLimits;
}

T_BreachTypeStringMap TypeWiseAlerterUtility::getBreachTypeStringMap()
{
   T_BreachTypeStringMap m_breachTypeStringMap = TypeWiseAlerterUtility::prepareBreachTypeStringMap();
  return m_breachTypeStringMap;
}

emailRecepientList TypeWiseAlerterUtility::getEmailRecepientList()
{
   emailRecepientList m_emailRecepientList = TypeWiseAlerterUtility::prepareEmailRecepientList();
  return m_emailRecepientList;
}

controllerList TypeWiseAlerterUtility::getControllerList()
{
  controllerList m_controllerList = TypeWiseAlerterUtility::prepareControllerList();
  return m_controllerList;
}
#endif
