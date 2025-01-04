//
// Created by adil_ on 11/11/2024.
//

#include "AIEngine.h"

std::vector<std::string> AIEngine::generateWorkoutPlan(const UserProfile& profile) {
    std::vector<std::string> plan;
    std::string goal = profile.getGoal();

    if (goal == "weight loss") {
        plan = {
            "Day 1: 30 minutes cardio (running or cycling)",
            "Day 2: Full body circuit training - 3 sets of 15 reps",
            "Day 3: HIIT workout - 20 minutes",
            "Day 4: Rest day with light stretching",
            "Day 5: 45 minutes cardio + core exercises"
        };
    } else if (goal == "muscle gain") {
        plan = {
            "Day 1: Chest and Triceps - 4 sets of 8-12 reps",
            "Day 2: Back and Biceps - 4 sets of 8-12 reps",
            "Day 3: Rest day",
            "Day 4: Legs and Shoulders - 4 sets of 8-12 reps",
            "Day 5: Core and Recovery exercises"
        };
    } else if (goal == "endurance") {
        plan = {
            "Day 1: Long distance running - 45 minutes",
            "Day 2: Swimming or cycling - 30 minutes",
            "Day 3: Light cardio and stretching",
            "Day 4: Interval training - 30 minutes",
            "Day 5: Endurance circuit training"
        };
    } else {  // strength or default
        plan = {
            "Day 1: Upper body strength - 5 sets of 5 reps",
            "Day 2: Lower body strength - 5 sets of 5 reps",
            "Day 3: Rest day",
            "Day 4: Full body power exercises",
            "Day 5: Core and compound lifts"
        };
    }

    return plan;
}

std::string AIEngine::generateWorkoutAdvice(const UserProfile& profile, const std::vector<Workout*>& workoutHistory) {
    std::string advice;
    std::string goal = profile.getGoal();

    if (workoutHistory.empty()) {
        advice = "Welcome! Start with lighter weights/intensity and focus on proper form. "
                "Aim to workout 3-5 times per week consistently.";
    } else {
        if (goal == "weight loss") {
            advice = "Try to maintain a caloric deficit and combine cardio with strength training. "
                    "Keep your heart rate elevated during workouts.";
        } else if (goal == "muscle gain") {
            advice = "Focus on progressive overload and ensure adequate protein intake. "
                    "Don't forget to get enough rest between workouts.";
        } else if (goal == "endurance") {
            advice = "Gradually increase your workout duration. Stay hydrated and maintain "
                    "a steady pace during cardio sessions.";
        } else {
            advice = "Focus on compound movements and proper form. Ensure adequate rest "
                    "between sets for maximum strength gains.";
        }
    }

    return advice;
}

double AIEngine::calculateProgressScore(const std::vector<Workout*>& workoutHistory) {
    if (workoutHistory.empty()) {
        return 0.0;
    }

    // Simple scoring: 0.0 to 1.0 based on number of workouts
    // More workouts = higher score, max out at 10 workouts
    return std::min(1.0, workoutHistory.size() / 10.0);
}