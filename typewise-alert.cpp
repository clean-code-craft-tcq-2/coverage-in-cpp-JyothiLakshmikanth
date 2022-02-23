#include "typewise-alert.h"

using namespace std;
using namespace InfoTypes;

TypeWiseAlert::TypeWiseAlert()
{
    updateMaps();
    prepareAlerterMap();
};

TypeWiseAlert::~TypeWiseAlert()
{
    m_coolingTypeLimits.clear();
    m_breachTypeStringMap.clear();
    m_emailRecepientList.clear();
    m_controllerList.clear();
};

void TypeWiseAlert::updateMaps()
{
    prepareCoolingTypeLimitsMap();
    prepareBreachTypeStringMap();
    prepareEmailRecepientList();
    prepareControllerList();
}

void TypeWiseAlert::prepareCoolingTypeLimitsMap()
{
    m_coolingTypeLimits.insert({PASSIVE_COOLING , Limits(0.0, 35.0)});
    m_coolingTypeLimits.insert({HI_ACTIVE_COOLING , Limits(0.0, 45.0)});
    m_coolingTypeLimits.insert({MED_ACTIVE_COOLING , Limits(0.0, 40.0)});
}

void TypeWiseAlert::prepareBreachTypeStringMap()
{
    m_breachTypeStringMap.insert({InfoTypes::TOO_LOW, "Hi, the temperature is too low"});
    m_breachTypeStringMap.insert({InfoTypes::TOO_HIGH, "Hi, the temperature is too high"});
    m_breachTypeStringMap.insert({InfoTypes::NORMAL, "Hi, the temperature is NORMAL"});
}

void TypeWiseAlert::prepareEmailRecepientList()
{
  m_emailRecepientList.push_back("a.b@c.com");
}

void TypeWiseAlert::prepareControllerList()
{
  m_controllerList.push_back(0xfeed);
}

void TypeWiseAlert::prepareAlerterMap()
{
    m_alerterMap[TO_CONTROLLER] = &TypeWiseAlert::sendToController;
    m_alerterMap[TO_EMAIL] = &TypeWiseAlert::sendToEmail;
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
     (this->*(alerterMapIt->second))(breachType);
  }
}

void TypeWiseAlert::sendToController(BreachType breachType)
{
   ControllerList::iterator controllerListIt =  m_controllerList.begin();
  for(; controllerListIt !=  m_controllerList.end(); ++controllerListIt)
  {
    printf("%x : %x\n", *controllerListIt, breachType);
  }
}

void TypeWiseAlert::sendToEmail(BreachType breachType) 
{
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
