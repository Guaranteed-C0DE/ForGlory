#include "ClockAngle.h"
#include <string>
#include <cctype>
using namespace std;
#include <iostream>
int main() {
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
   clock.setHours_Time(response1);
   cin>>response2;
   while (response2 < 0 && response2 > 59)
   {
      cout << "Invalid number for minute.\n";
      cin >> response2;
   }
   clock.setMinutes_Time(response2);
   cout << response1 << ":" << response2;

   cin >>response3;
   while (response3 < 0 && response3 > 59)
   {
      cout << "Invalid number for second.\n";
      cin >> response3;
   }
   clock.setSeconds_Time(response3);
   if (clock.getHours_Time() > 12)
   {
      clock.setMilitaryTime(true);
      clock.setMeridianTime(NA);
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
      clock.setMilitaryTime(true);
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
      clock.setMeridianTime(AM);
   }
   else {
      clock.setMeridianTime(PM);
   }
}
clock.DisplayTime();
}
