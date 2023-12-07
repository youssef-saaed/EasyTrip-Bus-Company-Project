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
Time Time::operator+(int minutes) const {
    Time outcome(*this);
    outcome.minute += minutes;
    outcome.handlingTime();
    return outcome;
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
}

// Function to check if the current time is working hours
bool Time::isWorkingHours() const {
    return (hour >= 4 && hour < 10);
}

// Function to display the time
string Time::display() const {
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
