#pragma once
#ifndef TYPEWISEALERT_H
#define TYPEWISEALERT_H

#include <iostream>
#include <stdio.h>

// #include "TypeWiseAlerterUtility.h"

class TypeWiseAlerterUtility;

using namespace std;
using namespace InfoTypes;

class TypeWiseAlert
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
  void update();
  Limits getTheLimitsForCoolingType(CoolingType coolingType);
  
    TypeWiseAlerterUtility::T_CoolingTypeLimits      m_coolingTypeLimits;
    TypeWiseAlerterUtility::T_BreachTypeStringMap    m_breachTypeStringMap;
    TypeWiseAlerterUtility::EmailRecepientList       m_emailRecepientList ;
    TypeWiseAlerterUtility::ControllerList           m_controllerList;
    T_AlerterMap             m_alerterMap;
};

// TypeWiseAlert::TypeWiseAlert()
// {
//     update();
//     prepareAlerterMap();
// };

// TypeWiseAlert::~TypeWiseAlert()
// {
//     m_coolingTypeLimits.clear();
//     m_breachTypeStringMap.clear();
//     m_emailRecepientList.clear();
//     m_controllerList.clear();
// };

// void TypeWiseAlert::update()
// {
//     getCoolingTypeLimitsMap(m_coolingTypeLimits);
//     getBreachTypeStringMap(m_breachTypeStringMap);
//     getEmailRecepientList(m_emailRecepientList);
//     getControllerList(m_controllerList);
// }

// void TypeWiseAlert::prepareAlerterMap()
// {
//     m_alerterMap[TO_CONTROLLER] = &TypeWiseAlert::sendToController;
//     m_alerterMap[TO_EMAIL] = &TypeWiseAlert::sendToEmail;
// }

// Limits TypeWiseAlert::getTheLimitsForCoolingType(CoolingType coolingType)
// {
//   Limits limits;
//   T_CoolingTypeLimits::iterator coolingTypeLimitsIt = m_coolingTypeLimits.find(coolingType);
//   if(coolingTypeLimitsIt != m_coolingTypeLimits.end())
//   {
//     limits = coolingTypeLimitsIt->second;
//   }
//   return limits;
// }

// BreachType TypeWiseAlert::inferBreach(double value, Limits limits) {
//   if(value < limits.getLowerLimit()) {
//     return TOO_LOW;
//   }
//   if(value > limits.getUpperLimit()) {
//     return TOO_HIGH;
//   }
//   return NORMAL;
// }

// BreachType TypeWiseAlert::classifyTemperatureBreach( CoolingType coolingType, double temperatureInC)
// {
//   return inferBreach(temperatureInC, getTheLimitsForCoolingType(coolingType));
// }

// void TypeWiseAlert::checkAndAlert( AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
// {
//   BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
//   updateAlerter(alertTarget, breachType);
// }

// void TypeWiseAlert::updateAlerter(AlertTarget alertTarget, BreachType breachType)
// {
//   T_AlerterMap::iterator alerterMapIt = m_alerterMap.find(alertTarget);
//   if(alerterMapIt != m_alerterMap.end())
//   {
//      (this->*(alerterMapIt->second))(breachType);
//   }
// }

// void TypeWiseAlert::sendToController(BreachType breachType)
// {
//    ControllerList::iterator controllerListIt =  m_controllerList.begin();
//   for(; controllerListIt !=  m_controllerList.end(); ++controllerListIt)
//   {
//     printf("%x : %x\n", *controllerListIt, breachType);
//   }
// }

// void TypeWiseAlert::sendToEmail(BreachType breachType) 
// {
//   EmailRecepientList::iterator emailRecepientListIt = m_emailRecepientList.begin() ;
//   for(; emailRecepientListIt !=  m_emailRecepientList.end(); ++emailRecepientListIt)
//   {
//     ::std::string recepient = *emailRecepientListIt;
//    T_BreachTypeStringMap::iterator breachTypeStringMapIt = m_breachTypeStringMap.find(breachType);
//     if(breachTypeStringMapIt != m_breachTypeStringMap.end())
//     {
//       printf("%s\n",breachTypeStringMapIt->second.c_str());
//     }
//   }
// }
#endif
