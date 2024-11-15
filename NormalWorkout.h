//
// Created by adil_ on 11/12/2024.
//

#ifndef NORMALWORKOUT_H
#define NORMALWORKOUT_H

#include "Workout.h"

// class for normal/strength workouts
class NormalWorkout : public Workout {
private:
    string exerciseType;  // type of exercise
    int sets;
    int reps;

public:
    // set up normal workout with date, duration, calories, type, sets, reps
    NormalWorkout(const string& date, int duration, int caloriesBurned, const string& exerciseType, int sets, int reps);

    // show strength workout info
    void displayWorkout() const override;
};

#endif // NORMALWORKOUT_H
