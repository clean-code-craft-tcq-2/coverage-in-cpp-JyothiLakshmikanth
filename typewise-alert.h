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
  void sendEmailsToClients(::string data);

    T_CoolingTypeLimits      m_coolingTypeLimits;
    T_BreachTypeStringMap    m_breachTypeStringMap;
    EmailRecepientList       m_emailRecepientList ;
    ControllerList           m_controllerList;
    T_AlerterMap             m_alerterMap;
};

/* #include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void updateStr(::std::string& up_str)
{
    std::cout <<"before - "<<up_str.c_str() << std::endl;
    up_str = "efg";
    std::cout <<"after - "<<up_str.c_str() << std::endl;
}

void withPointer()
{
    const char *sz = "hello";
    std::cout << sizeof(sz) << std::endl;
    std::cout <<sz[0] << std::endl;
    ::std::string str = "abc";
    const char *updated = str.c_str();
    std::cout <<updated << std::endl;
    ::std::string up = updated;
    updateStr((up));
    std::cout <<up.c_str() << std::endl;
}

void withArray()
{
    const char sz[] = "hello";
    std::cout << sizeof(sz) << std::endl;
    std::cout <<sz[0] << std::endl;
}
int main() {
withPointer();
::std::vector<string> a = {"hello", "hi","hallo","hey"};
int key = 2;
if(key>0)
{
    a[key].clear();
}
for(int i = 0; i<a.size(); i++)
{
    cout<<i<<" - "<<a[i]<<endl;
}

::std::map<char, string> str_map;
str_map['a'] = "hello";
str_map['b'] = "Hi";
str_map['c'] = "Hey";
str_map['d'] = "Hallo";

char k = 'c';
if(k!=0)
{
    str_map[k].clear();
}
::std::map<char, string>::const_iterator str_mapIt = str_map.begin();
for(; str_mapIt != str_map.end(); str_mapIt++)
{
    cout<<str_mapIt->first<<" - "<<str_mapIt->second<<endl;
}

	return 0;
}*/

#endif
