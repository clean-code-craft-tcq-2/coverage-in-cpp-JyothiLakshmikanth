#pragma once
#ifndef TYPEWISEALERT_H
#define TYPEWISEALERT_H

#include <iostream>
#include <stdio.h>

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

typedef void (TypeWiseAlert::*fnptr)(BreachType);
typedef ::std::map< InfoTypes::AlertTarget , fnptr> T_AlerterMap;

private:
  BreachType inferBreach(double value,Limits limits);
  BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
  void sendToController(BreachType breachType);
  void sendToEmail(BreachType breachType);
  void updateAlerter(AlertTarget alertTarget, BreachType breachType);
  void prepareAlerterMap();
  void update()
  Limits getTheLimitsForCoolingType(CoolingType coolingType);
  
    T_CoolingTypeLimits      m_coolingTypeLimits;
    T_BreachTypeStringMap    m_breachTypeStringMap;
    EmailRecepientList       m_emailRecepientList ;
    ControllerList           m_controllerList;
    T_AlerterMap             m_alerterMap;
};

#endif
