#ifndef HIKER_INCLUDED
#define HIKER_INCLUDED

#include <stdbool.h>

bool isInRange(float, float, float);
bool checkHigh(float);
bool checkLow(float);
bool checkSpeed(float);
const char* displayStatus(float, float, float);

#endif
