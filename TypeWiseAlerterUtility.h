#ifndef TYPEWISEALERTERUTILITY_H
#define TYPEWISEALERTERUTILITY_H
#include <map>
#include <vector>
#include "InfoTypes.h"

class TypeWiseAlerterUtility
{
public:
  typedef ::std::map< CoolingType, Limits> T_CoolingTypeLimits;
  typedef ::std::map< InfoTypes::BreachType, string> T_BreachTypeStringMap;
  ::std::vector< const char* > emailRecepientList;
  ::std::vector< const unsigned short> controllerList;
  static T_CoolingTypeLimits getCoolingTypeLimitsMap();
  static T_BreachTypeStringMap getBreachTypeStringMap();
  static emailRecepientList getEmailRecepientList();
  static controllerList getControllerList();

private:
  static void prepareCoolingTypeLimitsMap();
  static void prepareBreachTypeStringMap();
  static void prepareEmailRecepient();
  static void prepareControllerList();
  T_CoolingTypeLimits  m_coolingTypeLimits;
  T_BreachTypeStringMap m_breachTypeStringMap ;
  emailRecepientList m_emailRecepientList;
  controllerList m_controllerList;
};

m_coolingTypeLimits = TypeWiseAlerterUtility::prepareCoolingTypeLimitsMap();
m_breachTypeStringMap = TypeWiseAlerterUtility::prepareBreachTypeStringMap();
m_emailRecepientList = TypeWiseAlerterUtility::prepareEmailRecepientList();
m_controllerList = TypeWiseAlerterUtility::prepareControllerList();

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
  return m_coolingTypeLimits;
}

T_BreachTypeStringMap TypeWiseAlerterUtility::getBreachTypeStringMap()
{
  return m_breachTypeStringMap;
}

emailRecepientList TypeWiseAlerterUtility::getEmailRecepientList()
{
  return m_emailRecepientList;
}

controllerList TypeWiseAlerterUtility::getControllerList()
{
  return m_controllerList;
}
#endif
