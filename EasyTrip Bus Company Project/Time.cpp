#include "Time.h"
#pragma once
#include <iostream>
using namespace std;

// Constructor
Time::Time(int h, int m, int s) {
    hour = h;
    minute = m;
    second = s;
}
// Overload + operator for adding minutes
Time Time::operator+(int minutes) {
    Time outcome(*this);
    outcome.minute += minutes;
    outcome.handlingTime();
    return outcome;
}

Time Time::operator+(Time t) {
    Time outcome(*this);
    outcome.hour += t.hour;
    outcome.minute += t.minute;
    outcome.second += t.second;
    outcome.handlingTime();
    return outcome;
}

Time Time::operator-(Time t) {
    Time outcome(*this);
    outcome.second -= t.second;
    if (outcome.second < 0)
    {
        outcome.second = 60 + outcome.second;
        outcome.minute--;
    }
    outcome.minute -= t.minute;
    if (outcome.minute < 0)
    {
        outcome.minute = 60 + outcome.minute;
        outcome.hour--;
    }
    outcome.hour -= t.hour;
    return outcome;
}

bool Time::operator==(Time t)
{
    return (hour == t.hour && minute == t.minute && second == t.second);
}

bool Time::operator<(Time t)
{
    return hour < t.hour && minute < t.minute && second < t.second;
}

void Time::addSeconds(int seconds) {
    second += seconds;
    handlingTime();
}

// Function to handle time (hours, minutes, and seconds)
void Time::handlingTime() {
    int additionalMinutes = second / 60;
    second %= 60;
    minute += additionalMinutes;

    int additionalHours = minute / 60;
    minute %= 60;
    hour += additionalHours;
    hour = hour % 24;
}

// Function to check if the current time is working hours
bool Time::isWorkingHours() {
    return (hour >= 4 && hour < 10);
}

// Function to display the time
string Time::display() {
    string time = to_string(hour) + ":" + std::to_string(minute);
    return time;
}

int Time::getHour() {
    return hour;
}

int Time::getMinute() {
    return minute;
}

int Time::getSecond() {
    return second;
}

Time Time::CalcAvgTimeOfTrip(Time& t, int n) {

    int totalMinutes = ((t.getHour() * 60) + t.getMinute());

    int avgMinutes = totalMinutes / std::max(n, 1);

    int resultHour, resultMin;
    if (avgMinutes < 60) {
        resultHour = 0;
        resultMin = avgMinutes;
    }

    else {
        resultHour = avgMinutes / 60;
        resultMin = avgMinutes % 60;

    }

    return Time(resultHour, resultMin);
}