#pragma once

#include <string>
using namespace std;
class Time {
private:
    int hour;
    int minute;
    int second;

public:

    Time(int h = 0, int m = 0, int s = 0);

    Time operator+(int minutes);

    Time operator+(Time t);
    Time operator-(Time t);
    bool operator==(Time t);
    bool operator<(Time t);
    void addSeconds(int seconds);

    void handlingTime();

    bool isWorkingHours();

    string display();
    int getHour();
    int getMinute();
    int getSecond();
    Time CalcAvgTimeOfTrip(Time& t, int n);
};



