//
// Created by adil_ on 11/12/2024.
//

#ifndef NORMALWORKOUT_H
#define NORMALWORKOUT_H

#include "Workout.h"

// derived class for strength workouts
class NormalWorkout : public Workout {
private:
    string exerciseType;  // type of exercise
    int sets;
    int reps;

public:
    // constructor
    NormalWorkout(const string& date, int duration, int caloriesBurned, const string& exerciseType, int sets, int reps);

    // display details of the strength workout in console
    void displayWorkout() const override;
};

#endif // NORMALWORKOUT_H
