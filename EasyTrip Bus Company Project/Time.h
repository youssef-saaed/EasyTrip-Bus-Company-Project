#pragma once
#include <iostream>
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

    void addSeconds(int seconds);

    void handlingTime();

    bool isWorkingHours() const;

    string display() const;
    int getHour();
    int getMinute();
    int getSecond();
};



