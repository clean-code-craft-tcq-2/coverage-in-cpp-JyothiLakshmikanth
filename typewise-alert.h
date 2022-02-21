#pragma once
#ifndef TYPEWISEALERT_H
#define TYPEWISEALERT_H

#include "TypeWiseAlerterUtility.h"
#include "InfoTypes.h"

using namespace std;
using namespace InfoTypes;

class TypeWiseAlert : public TypeWiseAlerterUtility
{
public:
  TypeWiseAlert();
  ~TypeWiseAlert();

  void checkAndAlert(
      AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

private:
  BreachType inferBreach(double value, double lowerLimit, double upperLimit);
  BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
  void sendToController(BreachType breachType);
  void sendToEmail(BreachType breachType);
  void updateAlerter(AlertTarget alertTarget, BreachType breachType);
  
  typedef ::std::map< CoolingType, Limits> T_CoolingTypeLimits  m_coolingTypeLimits;
   typedef ::std::map< InfoTypes::BreachType, string> T_BreachTypeStringMap m_breachTypeStringMap;
   ::std::vector< const char* > emailRecepientList m_emailRecepientList ;
   ::std::vector< const unsigned short> controllerList m_controllerList;
   typedef ::std::map< InfoTypes::AlertTarget , void(*fnptr)(BreachType)> T_AlerterMap m_alerterMap;
};
#endif
