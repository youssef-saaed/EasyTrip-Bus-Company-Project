#include "Time.h"
#pragma once
#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int second;

public:
    // Constructor
    Time(int h = 0, int m = 0, int s = 0) {
        hour = h;
        minute = m,
            second = s;
    }

    // Overload + operator for adding minutes
    Time operator+(int minutes) const {
        Time outcome(*this);
        outcome.minute += minutes;
        outcome.handlingTime();
        return outcome;
    }

    void addSeconds(int seconds) {
        second += seconds;
        handlingTime();
    }

    // Function to handle time ( hours, minutes, and seconds)
    void handlingTime() {
        int additionalMinutes = second / 60;
        second %= 60;
        minute += additionalMinutes;

        int additionalHours = minute / 60;
        minute %= 60;
        hour += additionalHours;

    }

    // Function to check if the current time is working hours

    bool isWorkingHours() const {
        return (hour >= 4 && hour < 10);
    }

    // Function to display the time
    void display() const {
        cout << hour << ":" << minute << ":" << second;


    }
};

int main()
{
    //create object

    Time t1(8, 45, 0);

    // Display the initial time
    cout << "Initial Time: ";
    t1.display();
    cout << endl;

    // Add 5 minutes using operator+

    cout << "Time after adding 5 minutes: ";

    Time t2 = t1 + 5;

    t2.display();

    cout << endl;

    // Add 20 minutes using operator+

    cout << "Time after adding 20 minutes: ";

    t2 = t2 + 20;

    t2.display();

    cout << endl;

    // Add 65 seconds using addSeconds function

    cout << "Time after adding 65 seconds: ";

    t2.addSeconds(65);

    t2.display();
    cout << endl;



}


