#ifndef WORKOUTMANAGER_H
#define WORKOUTMANAGER_H

#include <fstream>
#include <vector>
#include <memory>
#include "Workout.h"
#include "NormalWorkout.h"
#include "CardioWorkout.h"


// handles all the workout info
class WorkoutManager {
private:
    std::vector<std::unique_ptr<Workout>> workoutHistory; // using unique ptr to auto manage memory

public:
    // default ctor
    WorkoutManager() = default;

    // adds any type of workout to history
    void addWorkout(std::unique_ptr<Workout> workout) {
        workoutHistory.push_back(std::move(workout)); // using move to hand off workout and prevent sharing ptrs
    }

    // helper func for adding reg workouts
    void addNormalWorkout(const string& date, int duration, int calories,
                         const string& exerciseType, int sets, int reps) {
        workoutHistory.push_back(std::make_unique<NormalWorkout>(
            date, duration, calories, exerciseType, sets, reps));
    }

    // cardio workouts
    void addCardioWorkout(const string& date, int duration, int calories, double distance) {
        workoutHistory.push_back(std::make_unique<CardioWorkout>(
            date, duration, calories, distance));
    }

    // gets all workouts stored
    const std::vector<std::unique_ptr<Workout>>& getWorkoutHistory() const {
        return workoutHistory;
    }


    // converts the unique ptrs to raw ptrs for the ai engine
    // needed cuz ai engine expects raw ptrs
    std::vector<Workout*> getWorkoutHistoryRaw() const {
        std::vector<Workout*> rawHistory;
        for (const auto& workout : workoutHistory) {
            rawHistory.push_back(workout.get());
        }
        return rawHistory;
    }

};


#endif // WORKOUTMANAGER_H