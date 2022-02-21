#ifndef INFOTYPES_H
#define INFOTYPES_H

using namespace std;

namespace InfoTypes
{
    typedef enum
    {
         PASSIVE_COOLING,
         HI_ACTIVE_COOLING,
         MED_ACTIVE_COOLING
    } CoolingType;

    typedef enum 
    {
        NORMAL,
        TOO_LOW,
        TOO_HIGH
    } BreachType;

    typedef enum 
    {
        TO_CONTROLLER,
        TO_EMAIL
    } AlertTarget;

    typedef struct 
    {
        CoolingType coolingType;
         char brand[48];
    } BatteryCharacter;

    typedef struct 
    {
        double lowerLimit = 0.0;
        double upperLimit = 0.0;
    }Limits;
}
#endif
