#pragma once
#ifndef TYPEWISEALERT_H
#define TYPEWISEALERT_H

#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>

#include "InfoTypes.h"

using namespace std;
using namespace InfoTypes;

typedef enum
{
  SUCCESS,
  FAILURE
}Result;

class TypeWiseAlert
{
public:
  TypeWiseAlert();
  ~TypeWiseAlert();
  
   typedef ::std::map< CoolingType, Limits> T_CoolingTypeLimits;
   typedef ::std::map< InfoTypes::BreachType, string> T_BreachTypeStringMap;
   typedef ::std::vector< ::std::string > EmailRecepientList;
   typedef ::std::vector< unsigned short> ControllerList;
   typedef Result(TypeWiseAlert::*fnptr)(BreachType);
   typedef ::std::map< InfoTypes::AlertTarget , fnptr> T_AlerterMap;

  Result checkAndAlert( AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

private:
  BreachType inferBreach(double value,Limits limits);
  BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
  void prepareCoolingTypeLimitsMap();
  void prepareBreachTypeStringMap();
  void prepareEmailRecepientList();
  void prepareControllerList();
  Result sendToController(BreachType breachType);
  Result sendToEmail(BreachType breachType);
  Result updateAlerter(AlertTarget alertTarget, BreachType breachType);
  void prepareAlerterMap();
  void updateMaps();
  Limits getTheLimitsForCoolingType(CoolingType coolingType);

    T_CoolingTypeLimits      m_coolingTypeLimits;
    T_BreachTypeStringMap    m_breachTypeStringMap;
    EmailRecepientList       m_emailRecepientList ;
    ControllerList           m_controllerList;
    T_AlerterMap             m_alerterMap;
};

#endif
