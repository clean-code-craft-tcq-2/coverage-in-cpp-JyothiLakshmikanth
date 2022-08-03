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

/*#include <iostream>
#include <map>
using namespace std;

struct Pair_First_Equal {
    template <typename Pair>
    bool operator() (Pair const &lhs, Pair const &rhs) const {
        return lhs.first == rhs.first;
    }
};

template <typename Map>
bool key_compare (Map const &lhs, Map const &rhs) {
    return lhs.size() == rhs.size()
        && std::equal(lhs.begin(), lhs.end(),
                      rhs.begin(),
                      Pair_First_Equal()); // predicate instance
}

int main () {
    using namespace std;

    map<string,string> a, b;

    a["Foo"] = "0";
    a["Bar"] = "1";
    a["Frob"] = "2";

    b["Foo"] = "0";
    b["Bar"] = "1";
    b["Frob"] = "2";

    cout << "a == b? " << key_compare (a,b) << " (should be 1)\n";
    b["Foo"] = "1";
    cout << "a == b? " << key_compare (a,b) << " (should be 1)\n";

    map<string,string> c;
    cout << "a == c? " << key_compare (a,c)  << " (should be 0)\n";
}*/
/*
#include<iostream>
using namespace std;
 
class A
{
    protected:
    int a;
   
    public:
        void set_A(int x)
        {
             a=x;           
        }
   
        void disp_A()
        {
            cout<<endl<<"Value of A="<<a;
        }
};
 
class B: public A
{
    public:

    int b,p;
     
        void set_B(int x,int y)
        {
            set_A(x);
            b=y;
        }
         
        void disp_B()
        {
            disp_A();
            cout<<endl<<"Value of B="<<b;
        }
         
        void cal_product()
        {
            p=a*b;
            cout<<endl<<"Product of "<<a<<" * "<<b<<" = "<<p;
        }
         
};
 
int main()
{
    B b;
    b.set_B(4,5);
    b.cal_product();
    b.disp_B();
    cout<<b.a<<endl;
    
    return 0;
}*/
/*
// C++ Program to demonstrate Virtual
// functions in derived classes
#include <iostream>
using namespace std;

class A {
public:
A();
virtual ~A();
	virtual void fun() { cout << "\n A::fun() called "; }
	protected:
	int a;
};

A::A()
{
    cout<<"A const"<<endl;
}

A::~A()
{
    cout<<"A destructor"<<endl;
}

class B : public A {
public:
B();
virtual ~B() ;
	void fun() { cout << "\n B::fun() called "; }
	private:
	void updateValue();
	void disp();
};
B::B()
{
    cout<<"B const"<<endl;
    updateValue();
    disp();
}
 B::~B()
 {
     cout<<"B destructor"<<endl;
 }
void B::updateValue()
{
    a=5;
}

void B::disp()
{
    cout<<a<<endl;
}

int main()
{
	// An object of class C
	//C c;

	// A pointer of class B pointing
	// to memory location of c
	//B* b = &c;
A* b = new B;
	// this line prints "C::fun() called"
	b->fun();
delete b;
	getchar(); // to get the next character
	return 0;
}
*/
/*
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> vec(5, 3);
    try
    {
        for (int i = 0; i < vec.size(); ++i)
            std::cout << vec.at(i) << " ";
    }
    catch (std::out_of_range& ex)
    {
        std::cout << "\nOut of range exception caught.\n" << ex.what() << std::endl;
    }
}*/
#endif
