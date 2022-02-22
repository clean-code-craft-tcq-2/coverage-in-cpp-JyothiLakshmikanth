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
 
typedef ::std::map< CoolingType, Limits> T_CoolingTypeLimits;
typedef ::std::map< InfoTypes::BreachType, string> T_BreachTypeStringMap;
::std::vector< const char* > EmailRecepientList;
::std::vector< const unsigned short> ControllerList;
typedef void (*fnptr)(BreachType);
typedef ::std::map< InfoTypes::AlertTarget , fnptr> T_AlerterMap;

private:
  BreachType inferBreach(double value, double lowerLimit, double upperLimit);
  BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
  void sendToController(BreachType breachType);
  void sendToEmail(BreachType breachType);
  void updateAlerter(AlertTarget alertTarget, BreachType breachType);
  void prepareAlerterMap();
  
    T_CoolingTypeLimits      m_coolingTypeLimits;
    T_BreachTypeStringMap    m_breachTypeStringMap;
    EmailRecepientList       m_emailRecepientList ;
    ControllerList           m_controllerList;
    T_AlerterMap             m_alerterMap;
};
#endif
