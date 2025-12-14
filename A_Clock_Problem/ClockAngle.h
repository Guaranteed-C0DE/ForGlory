const double RHO = 21600/11;
class ClockType {
    private:
        int seconds_time;
        bool Military_Time;
    public:
        int Angle(int t);
        int Calculate_Seconds(int m, int h);

};
