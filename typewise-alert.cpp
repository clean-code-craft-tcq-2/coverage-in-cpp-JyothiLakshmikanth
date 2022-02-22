#include "typewise-alert.h"
#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;
using namespace InfoTypes;

TypeWiseAlert::TypeWiseAlert()
{
    TypeWiseAlerterUtility::getCoolingTypeLimitsMap(m_coolingTypeLimits);
    TypeWiseAlerterUtility::getBreachTypeStringMap(m_breachTypeStringMap);
    TypeWiseAlerterUtility::getEmailRecepientList(m_emailRecepientList);
    TypeWiseAlerterUtility::getControllerList(m_controllerList);
    prepareAlerterMap();
};

TypeWiseAlert::~TypeWiseAlert()
{
    m_coolingTypeLimits.clear();
    m_breachTypeStringMap.clear();
    m_emailRecepientList.clear();
    m_controllerList.clear();
};

void TypeWiseAlert::prepareAlerterMap()
{
   m_alerterMap.emplace( TO_CONTROLLER, &TypeWiseAlert::sendToController );
  m_alerterMap.emplace(TO_EMAIL, &TypeWiseAlert::sendToEmail);
}

Limits TypeWiseAlert::getTheLimitsForCoolingType(CoolingType coolingType)
{
  Limits limits;
  T_CoolingTypeLimits::iterator coolingTypeLimitsIt = m_coolingTypeLimits.find(coolingType);
  if(coolingTypeLimitsIt != m_coolingTypeLimits.end())
  {
    limits = coolingTypeLimitsIt->second;
  }
  return limits;
}

BreachType TypeWiseAlert::inferBreach(double value, Limits limits) {
  if(value < limits.getLowerLimit()) {
    return TOO_LOW;
  }
  if(value > limits.getUpperLimit()) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType TypeWiseAlert::classifyTemperatureBreach( CoolingType coolingType, double temperatureInC)
{
  return inferBreach(temperatureInC, getTheLimitsForCoolingType(coolingType));
}

void TypeWiseAlert::checkAndAlert( AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  updateAlerter(alertTarget, breachType);
}

void TypeWiseAlert::updateAlerter(AlertTarget alertTarget, BreachType breachType)
{
  T_AlerterMap::iterator alerterMapIt = m_alerterMap.find(alertTarget);
  if(alerterMapIt != m_alerterMap.end())
  {
     (*alerterMapIt->second)(breachType);
  }
}

void TypeWiseAlert::sendToController(BreachType breachType) {
   ControllerList::iterator controllerListIt =  m_controllerList.begin();
  for(; controllerListIt !=  m_controllerList.end(); ++controllerListIt)
  {
    printf("%x : %x\n", *controllerListIt, breachType);
  }
}

void TypeWiseAlert::sendToEmail(BreachType breachType) {
  EmailRecepientList::iterator emailRecepientListIt = m_emailRecepientList.begin() ;
  for(; emailRecepientListIt !=  m_emailRecepientList.end(); ++emailRecepientListIt)
  {
    ::std::string recepient = *emailRecepientListIt;
    T_BreachTypeStringMap::iterator breachTypeStringMapIt = m_breachTypeStringMap.find(breachType);
    if(breachTypeStringMapIt != m_breachTypeStringMap.end())
    {
      printf("%s\n",breachTypeStringMapIt->second.c_str());
    }
  }
}
