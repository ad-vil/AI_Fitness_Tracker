//
// Created by adil_ on 11/14/2024.
//

#ifndef CARDIOWORKOUT_H
#define CARDIOWORKOUT_H

#include "Workout.h"

// class for cardio workouts
class CardioWorkout : public Workout {
private:
    double distance;  // distance in miles

public:
    // set up cardio workout with date, duration, calories, and distance
    CardioWorkout(const string& date, int duration, int caloriesBurned, double distance);

    // display cardio workout details
    void displayWorkout() const override;

    double getDistance() const { return distance; }

};

#endif // CARDIOWORKOUT_H
