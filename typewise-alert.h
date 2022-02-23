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

class TypeWiseAlert
{
public:
  TypeWiseAlert();
  ~TypeWiseAlert();
  
   typedef ::std::map< CoolingType, Limits> T_CoolingTypeLimits;
   typedef ::std::map< InfoTypes::BreachType, string> T_BreachTypeStringMap;
   typedef ::std::vector< ::std::string > EmailRecepientList;
   typedef ::std::vector< unsigned short> ControllerList;
   typedef void (TypeWiseAlert::*fnptr)(BreachType);
   typedef ::std::map< InfoTypes::AlertTarget , fnptr> T_AlerterMap;

  void checkAndAlert( AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

private:
  BreachType inferBreach(double value,Limits limits);
  BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);
  void prepareCoolingTypeLimitsMap();
  void prepareBreachTypeStringMap();
  void prepareEmailRecepientList();
  void prepareControllerList();
  void sendToController(BreachType breachType);
  void sendToEmail(BreachType breachType);
  void updateAlerter(AlertTarget alertTarget, BreachType breachType);
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
