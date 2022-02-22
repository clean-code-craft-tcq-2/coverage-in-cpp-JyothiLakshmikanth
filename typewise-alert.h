#pragma once
#ifndef TYPEWISEALERT_H
#define TYPEWISEALERT_H

#include "TypeWiseAlerterUtility.h"

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
typedef ::std::vector< ::std::string > EmailRecepientList;
typedef ::std::vector< unsigned short > ControllerList;
typedef void (*fnptr)(BreachType);
typedef ::std::map< InfoTypes::AlertTarget , fnptr> T_AlerterMap;

private:
  BreachType inferBreach(double value,Limits limits);
  BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
  void sendToController(BreachType breachType);
  void sendToEmail(BreachType breachType);
  void updateAlerter(AlertTarget alertTarget, BreachType breachType);
  void prepareAlerterMap();
  Limits getTheLimitsForCoolingType(CoolingType coolingType);
  
    T_CoolingTypeLimits      m_coolingTypeLimits;
    T_BreachTypeStringMap    m_breachTypeStringMap;
    EmailRecepientList       m_emailRecepientList ;
    ControllerList           m_controllerList;
    T_AlerterMap             m_alerterMap;
};
#endif
