const double RHO = 21600.0/11.0;
enum MeridianTime {
    AM, PM, NA
};
class ClockType {
    private:
        int hours_time;
        int minutes_time;
        int seconds_time;
        int total_seconds;
        int angle;
        bool Military_Time;
    public:
        ClockType();
        int Calculate_Angle(int t);
        int Calculate_Seconds(int m, int h, int s, bool mt, MeridianTime MeT);
        void setMilitaryTime(bool mt);
        void setTotal_Seconds(int s);
        void setHours_Time(int h);
        void setMinutes_Time(int m);
        void setSeconds_Time(int s);
        void setAngle(int a);
        bool getMilitaryTime();
        int getTotal_Seconds();
        int getHours_Time();
        int getMinutes_Time();
        int getSeconds_Time();
        int getAngle();

};
