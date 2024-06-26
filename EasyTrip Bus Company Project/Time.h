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

    Time operator+(int minutes) const;

    Time operator+(Time t) const;

    Time operator-(Time t) const;
    bool operator==(Time t) const;
    void addSeconds(int seconds);

    void handlingTime();

    bool isWorkingHours() const;

    string display() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    Time CalcAvgTimeOfTrip(const Time& t, int n);
};



