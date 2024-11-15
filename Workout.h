//
// Created by adil_ on 11/11/2024.
//

#ifndef WORKOUT_H
#define WORKOUT_H

#include <string>
#include <iostream>

using namespace std;

// base class for workouts, holding common workout attributes like date, duration, and calories burned
class Workout {
protected:
    string date;
    int duration;  // duration in minutes
    int caloriesBurned;

public:
    // constructor: initializes workout with date, duration, and calories burned
    Workout(const string& date, int duration, int caloriesBurned);

    // displays details of the workout (pure virtual function for polymorphism)
    virtual void displayWorkout() const = 0;

    // virtual destructor
    virtual ~Workout() {}
};

#endif // WORKOUT_H
