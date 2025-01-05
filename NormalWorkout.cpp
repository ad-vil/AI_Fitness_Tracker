#include "NormalWorkout.h"

// initialize normal workout attributes
NormalWorkout::NormalWorkout(const string& date, int duration, int caloriesBurned, const string& exerciseType, int sets, int reps)
    : Workout(date, duration, caloriesBurned), exerciseType(exerciseType), sets(sets), reps(reps) {}

// display strength workout info
void NormalWorkout::displayWorkout() const {
    cout << "strength workout on " << date << endl;
    cout << "duration: " << duration << " minutes" << endl;
    cout << "calories burned: " << caloriesBurned << endl;
    cout << "exercise: " << exerciseType << endl;
    cout << "sets: " << sets << ", reps: " << reps << endl;
}
