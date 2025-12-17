#include "ClockAngle.h"
#include <cmath>
#include <iostream>
using namespace std;
ClockType::ClockType() {
    hours_time = 0;
    minutes_time = 0;
    seconds_time = 0;
    total_seconds = 0;
    Military_Time = false;
}
int ClockType::Calculate_Angle(int t) { //But how is t = RHO even going to be an argument?
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
} //If military_time is set to true, MeridianTime should be set to NA.

int ClockType::Calculate_Seconds(int h, int m, int s, bool mt, MeridianTime MeT) {
    if (h == 12 && MeT == AM)
    {
        h = 0;
    }
    int time_in_seconds = (3600*h)+(60*m)+s;

    if (MeT == PM)
    {
        time_in_seconds +=(86400/2);
    }
    setTotal_Seconds(time_in_seconds);
    return time_in_seconds;
}

void ClockType::setMilitaryTime(bool mt) {
    Military_Time = mt;
}

void ClockType::setTotal_Seconds(int s) {
    total_seconds = s;
}
void ClockType::setHours_Time(int h) {
    hours_time = h;
}

void ClockType::setMinutes_Time(int m) {
    minutes_time = m;
}
void ClockType::setSeconds_Time(int s) {
    seconds_time = s; 
}
void ClockType::setAngle(int a) {
    angle = a;
}

bool ClockType::getMilitaryTime() {
    if (Military_Time)
    {
        cout << "True.\n";
        return true;
    }
    cout << "False.\n";
    return false;
}

int ClockType::getTotal_Seconds() {
    return total_seconds;
}
int ClockType::getHours_Time() {
    return hours_time;
}
int ClockType::getMinutes_Time() {
    return minutes_time;
}
int ClockType::getSeconds_Time() {
    return seconds_time;
}

int ClockType::getAngle() {
    return angle;
}