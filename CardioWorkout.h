//
// Created by adil_ on 11/15/2024.
//

#ifndef CARDIOWORKOUT_H
#define CARDIOWORKOUT_H

#include "Workout.h"

// manages details specific to cardio workouts, such as distance covered
class CardioWorkout : public Workout {
private:
    double distance;  // in miles

public:
    // constructor: initializes cardio workout with date, duration, calories burned, and distance
    CardioWorkout(const string& date, int duration, int caloriesBurned, double distance);

    // displays details of cardio workout in console
    void displayWorkout() const override;
};

#endif // CARDIOWORKOUT_H
