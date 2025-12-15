#include "ClockAngle.h"
#include <cmath>
#include <iostream>
using namespace std;
int ClockType::Angle(int t) { //But how is t = RHO even going to be an argument?
    if (fmod(t, 2*RHO) > 0 && fmod(t, 2*RHO) < RHO)
    {
        return (11/120)*fmod(t, 2*RHO);
    }
    else if (fmod(t, 2*RHO) > RHO && fmod(t, 2*RHO) < 2*RHO)
    {
        return (180 - (11/120)*fmod(t, 2*RHO));
    }
    else if (fmod(t, 2*RHO)==RHO)
    {
        return 180;
    }
    else {
        return 0;
    }
}