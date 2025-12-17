#include "ClockAngle.h"
using namespace std;
#include <iostream>
int main() {
   int response1, response2, response3; //For hour, minute, second.
   ClockType clock;
   cout << "Please type the time xx:yy:zz.\n";
   cin>>response1;
   while (response1 < 0 || response1 > 23)
   {
      cout << "Invalid number for hour.\n";
      cin >> response1;
   }
}
