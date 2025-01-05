#ifndef NORMALWORKOUT_H
#define NORMALWORKOUT_H

#include "Workout.h"

// class for normal/strength workoutsss
class NormalWorkout : public Workout {
private:
    string exerciseType;  // type of exercise
    int sets;
    int reps;

public:
    // set up normal workout with date, duration, calories, type, sets, reps
    NormalWorkout(const string& date, int duration, int caloriesBurned, const string& exerciseType, int sets, int reps);

    // show normal workout info
    void displayWorkout() const override;

    int getSets() const { return sets; }
    int getReps() const { return reps; }
    std::string getExerciseType() const { return exerciseType; }
};

#endif // NORMALWORKOUT_H
