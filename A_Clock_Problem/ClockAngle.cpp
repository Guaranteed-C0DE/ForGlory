#include "ClockAngle.h"

int ClockType::Angle(int t) { //But how is t = RHO even going to be an argument?
    if (t%(2*RHO) > 0 && t%(2*RHO) < RHO)
    {
        return (11 * (t%(2*RHO)))/120;
    }
    else if (t%2*RHO > RHO && t%2*RHO < 2*RHO)
    {
        return (180 - (11*(t%RHO)/120));
    }
    else {
        return 0;
    }
}