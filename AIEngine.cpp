//
// Created by adil_ on 11/11/2024.
//

#include "AIEngine.h"

AIEngine::AIEngine() {
    // Initialize goal parameters
    goalParameters["muscle gain"] = WorkoutParameters(60, 4, 12, 0.8);
    goalParameters["weight loss"] = WorkoutParameters(45, 3, 15, 0.7);
    goalParameters["endurance"] = WorkoutParameters(90, 3, 20, 0.6);
    goalParameters["strength"] = WorkoutParameters(45, 5, 5, 0.9);
}

std::vector<std::string> AIEngine::generateWorkoutPlan(const UserProfile& profile) {
    std::vector<std::string> plan;
    WorkoutParameters params = calculateWorkoutParameters(profile);

    // Generate workout based on user's goal
    std::string goal = profile.getGoal();
    if (goal == "muscle gain") {
        plan.push_back("Day 1: Push (Chest, Shoulders, Triceps)");
        plan.push_back("Day 2: Pull (Back, Biceps)");
        plan.push_back("Day 3: Legs");
        plan.push_back("Day 4: Rest");
        plan.push_back("Recommended sets: " + std::to_string(params.recommendedSets));
        plan.push_back("Recommended reps: " + std::to_string(params.recommendedReps));
    }
    // Add more goal-specific plans...

    return plan;
}

std::string AIEngine::generateWorkoutAdvice(const UserProfile& profile,
                                          const std::vector<Workout*>& workoutHistory) {
    std::string advice;

    // Analyze recent progress
    double progressScore = calculateProgressScore(workoutHistory);

    if (progressScore < 0.5) {
        advice = "Consider increasing workout frequency. ";
    } else if (progressScore > 0.8) {
        advice = "Great progress! Consider increasing intensity. ";
    }

    // Add goal-specific advice
    if (profile.getGoal() == "muscle gain") {
        advice += "Focus on progressive overload and proper form. ";
    }

    return advice;
}

double AIEngine::calculateProgressScore(const std::vector<Workout*>& workoutHistory) {
    if (workoutHistory.empty()) return 0.0;

    // Calculate progress based on workout frequency and intensity
    int totalWorkouts = workoutHistory.size();
    int totalDuration = 0;

    for (const auto& workout : workoutHistory) {
        totalDuration += workout->getDuration();
    }

    // Simple scoring algorithm (can be made more sophisticated)
    double frequencyScore = std::min(1.0, totalWorkouts / 30.0);  // Normalized to 30 days
    double durationScore = std::min(1.0, totalDuration / (60.0 * totalWorkouts));

    return (frequencyScore + durationScore) / 2.0;
}

AIEngine::WorkoutParameters AIEngine::calculateWorkoutParameters(const UserProfile& profile) const {
    // Get base parameters for the user's goal
    auto it = goalParameters.find(profile.getGoal());
    if (it == goalParameters.end()) {
        // Return default parameters if goal not found
        return WorkoutParameters();
    }

    WorkoutParameters params = it->second;

    // Adjust based on user's characteristics
    if (profile.getAge() > 50) {
        params.recommendedIntensity *= 0.9;
        params.recommendedDuration *= 0.9;
    }

    return params;
}