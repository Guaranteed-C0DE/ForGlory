#include "ClockAngle.h"
#include <cmath>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
ClockType::ClockType() {
    hours_time = 0;
    minutes_time = 0;
    seconds_time = 0;
    total_seconds = 0;
    Military_Time = false;
    MeTime = NA;
    angle = 0;
}
int ClockType::Calculate_Angle(int t) { //But how is t = RHO even going to be an argument?
    if (fmod(t, 2*RHO) > 0 && fmod(t, 2*RHO) < RHO)
    {
        setAngle((11/120)*fmod(t, 2*RHO));
        return (11/120)*fmod(t, 2*RHO);
    } 
    else if (fmod(t, 2*RHO) > RHO && fmod(t, 2*RHO) < 2*RHO)
    {
        setAngle((180 - (11/120)*fmod(t, 2*RHO)));
        return (180 - (11/120)*fmod(t, 2*RHO));
    }
    else if (fmod(t, 2*RHO)==RHO)
    {
        setAngle(180);
        return 180;
    }
    else {
        setAngle(0);
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
void ClockType::setMeridianTime(MeridianTime MeT) {
    MeTime = MeT;
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
string ClockType::getMeridianTime(MeridianTime MeT) {
    string names[] = {"A.M.", "P.M.", "N/A"};
    return names[MeT];
}
void ClockType::DisplayTime() {
    cout << "The time on the clock is:\n";
    cout << hours_time << ":" << minutes_time << ":" << seconds_time;
     if (MeTime == AM || MeTime == PM)
    {
        cout << getMeridianTime(getMeTMeridianTime()) << endl;
    }
    if (Military_Time)
    {
        cout << "This is in military time.\n";
    }
   
}

MeridianTime ClockType::getMeTMeridianTime() {
    return MeTime;
}
void ClockType::DefaultMenu() {
    char default_response;
    cout << "Would you like to:\n";
    cout << "A. Change the clock time\n";
    cout << "B. See the angle between the minute and hour hands\n";
    cout << "C. See the angle betwen the second and minute hands\n";
    cout << "D. See the angle between the second and hour hands\n";
    cout << "E. See how many seconds are occurring now\n";
    cout << "F. Display the clock time\n";
    cout << "X. Quit\n";
    cin >> default_response;
    while (!(tolower(default_response) == 'a' || tolower(default_response) == 'b' || tolower(default_response) == 'c' || tolower(default_response) == 'd' || tolower(default_response) == 'e' || tolower(default_response) == 'f'|| tolower(default_response) == 'x'))
{
    cout << "Invalid response. Please try again.\n";
    cin >> default_response;
}
    default_response = tolower(default_response);
    if (default_response == 'a')
    {
        RequestTime();
    }
    else if (default_response == 'b')
    {
        DisplayAngle1();
    }
    else if (default_response == 'c')
    {
        DisplayAngle2();
    }
    else if (default_response == 'd')
    {
        DisplayAngle3();
    }
    else if (default_response == 'e')
    {
        DisplayTotalSeconds();
    }
    else if (default_response == 'f')
    {
        DisplayTime();
    }
    else if (default_response == 'x')
    {
        return;
    }
}
void ClockType::DisplayAngle1() {
cout << "The angle between the minute hand and the hour hand at the current time is " << getAngle() << endl;
DefaultMenu();
}
void ClockType::RequestTime() {
    int response1, response2, response3; //For hour, minute, second.
   char response4, response5;  
   ClockType clock;
   cout << "Please type the time xx:yy:zz.\n";
   cin>>response1;
   while (response1 < 0 || response1 > 23)
   {
      cout << "Invalid number for hour.\n";
      cin >> response1;
   }
   cout << response1 << ":";
   setHours_Time(response1);
   cin>>response2;
   while (response2 < 0 && response2 > 59)
   {
      cout << "Invalid number for minute.\n";
      cin >> response2;
   }
   setMinutes_Time(response2);
   cout << response1 << ":" << response2 << ":";

   cin >>response3;
   while (response3 < 0 && response3 > 59)
   {
      cout << "Invalid number for second.\n";
      cin >> response3;
   }
   setSeconds_Time(response3);
   if (getHours_Time() > 12)
   {
      setMilitaryTime(true);
      setMeridianTime(NA);
   }
   else {
   cout << "Is this in military time?\n";
   cout << "A. Yes\nB. No\n";
   cin >> response4;
   while (tolower(response4) != 'a' && tolower(response4) != 'b')
   {
      cout << "Invalid response. Please type 'a' or 'b'\n";
      cin>>response4;
   }
   if (response4 == 'a')
   {
      setMilitaryTime(true);
   }
   cout << "Is this in A.M. or P.M.?\nA. A.M.\nB. P.M.\n";
   cin >> response5;
   while (tolower(response5) != 'a' && tolower(response5) != 'b')
   {
        cout << "Invalid response. Please type 'a' or 'b'\n";
      cin>>response5;
   }
   response5 = tolower(response5);
   if (response5 == 'a')
   {
      setMeridianTime(AM);
   }
   else {
      setMeridianTime(PM);
   }
}
Calculate_Seconds(getHours_Time(), getMinutes_Time(), getSeconds_Time(), getMilitaryTime(), getMeTMeridianTime());
DisplayTime();
DefaultMenu();
}