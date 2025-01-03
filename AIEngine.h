//
// Created by adil_ on 11/11/2024.
//

// AIEngine.h
#ifndef AIENGINE_H
#define AIENGINE_H

#include <string>
#include <vector>
#include <map>
#include "UserProfile.h"
#include "Workout.h"

class AIEngine {
private:
    // Workout recommendation parameters
    struct WorkoutParameters {
        int recommendedDuration;
        int recommendedSets;
        int recommendedReps;
        double recommendedIntensity;

        // Constructor for easy initialization
        WorkoutParameters(int duration = 0, int sets = 0, int reps = 0, double intensity = 0.0)
            : recommendedDuration(duration), recommendedSets(sets),
              recommendedReps(reps), recommendedIntensity(intensity) {}
    };

    // Maps fitness goals to typical workout parameters
    std::map<std::string, WorkoutParameters> goalParameters;

    // Helper functions
    WorkoutParameters calculateWorkoutParameters(const UserProfile& profile) const;
    std::vector<std::string> getExercisesForMuscleGroup(const std::string& muscleGroup) const;

public:
    AIEngine();

    // Main recommendation functions
    std::vector<std::string> generateWorkoutPlan(const UserProfile& profile);
    std::string generateWorkoutAdvice(const UserProfile& profile, const std::vector<Workout*>& workoutHistory);

    // Workout adjustment functions
    void adjustWorkoutIntensity(UserProfile& profile, const std::vector<Workout*>& workoutHistory);
    std::string suggestNextWorkout(const UserProfile& profile, const std::vector<Workout*>& recentWorkouts);

    // Progress analysis
    double calculateProgressScore(const std::vector<Workout*>& workoutHistory);
    std::map<std::string, double> analyzeWorkoutTrends(const std::vector<Workout*>& workoutHistory);
};

#endif