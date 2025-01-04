//
// Created by adil_ on 1/4/2025.
//

#ifndef WORKOUTMANAGER_H
#define WORKOUTMANAGER_H

#include <vector>
#include <memory>
#include "Workout.h"
#include "NormalWorkout.h"
#include "CardioWorkout.h"

class WorkoutManager {
private:
    std::vector<std::unique_ptr<Workout>> workoutHistory;

public:
    WorkoutManager() = default;

    void addWorkout(std::unique_ptr<Workout> workout) {
        workoutHistory.push_back(std::move(workout));
    }

    void addNormalWorkout(const string& date, int duration, int calories,
                         const string& exerciseType, int sets, int reps) {
        workoutHistory.push_back(std::make_unique<NormalWorkout>(
            date, duration, calories, exerciseType, sets, reps));
    }

    void addCardioWorkout(const string& date, int duration, int calories, double distance) {
        workoutHistory.push_back(std::make_unique<CardioWorkout>(
            date, duration, calories, distance));
    }

    const std::vector<std::unique_ptr<Workout>>& getWorkoutHistory() const {
        return workoutHistory;
    }

    // Convert unique_ptr vector to raw pointer vector for AI Engine
    std::vector<Workout*> getWorkoutHistoryRaw() const {
        std::vector<Workout*> rawHistory;
        for (const auto& workout : workoutHistory) {
            rawHistory.push_back(workout.get());
        }
        return rawHistory;
    }
};

#endif // WORKOUTMANAGER_H