//
// Created by adil_ on 11/11/2024.
//
#ifndef WORKOUT_H
#define WORKOUT_H

#include <string>
#include <iostream>

using namespace std;

// base workout class
class Workout {
protected:
    string date;
    int duration;  // in minutes
    int caloriesBurned;

public:
    // constructor to set up date, duration, and calories
    Workout(const string& date, int duration, int caloriesBurned);

    // virtual method for displaying the workout, to be defined by derived classes
    virtual void displayWorkout() const = 0;

    // destructor
    virtual ~Workout() {}

    int getDuration() const { return duration; }
};

#endif // WORKOUT_H
