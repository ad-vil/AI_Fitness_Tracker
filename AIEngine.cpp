#include "AIEngine.h"

std::vector<std::string> AIEngine::generateWorkoutPlan(const UserProfile& profile) {
    std::vector<std::string> plan;
    std::string goal = profile.getGoal();

    // diff workouts for diff goals
    if (goal == "weight loss") {
        plan = {
            "day 1: 30min cardio (run/cycle)",
            "day 2: full body circuit - 3x15",
            "day 3: hiit - 20min",
            "day 4: rest + stretching",
            "day 5: 45min cardio + abs"
        };
    } else if (goal == "muscle gain") {
        plan = {
            "day 1: chest/tri - 4x8-12",
            "day 2: back/bi - 4x8-12",
            "day 3: rest",
            "day 4: legs/shoulders - 4x8-12",
            "day 5: core + recovery"
        };
    } else if (goal == "endurance") {
        plan = {
            "day 1: long run - 45min",
            "day 2: swim/cycle - 30min",
            "day 3: light cardio + stretch",
            "day 4: intervals - 30min",
            "day 5: endurance circuit"
        };
    } else {  // strength/default
        plan = {
            "day 1: upper strength - 5x5",
            "day 2: lower strength - 5x5",
            "day 3: rest",
            "day 4: full body power",
            "day 5: core + compounds"
        };
    }

    return plan;
}

std::string AIEngine::generateWorkoutAdvice(const UserProfile& profile, const std::vector<Workout*>& workoutHistory) {
    std::string advice;
    std::string goal = profile.getGoal();

    // no workouts yet - give starter advice
    if (workoutHistory.empty()) {
        advice = "welcome! start light and focus on form. try to workout 3-5x per week";
    } else {
        // specific advice based on goals
        if (goal == "weight loss") {
            advice = "keep a caloric deficit and mix cardio w/ strength. keep hr up during workouts";
        } else if (goal == "muscle gain") {
            advice = "focus on progressive overload and eat enough protein. dont forget rest days";
        } else if (goal == "endurance") {
            advice = "slowly increase workout time. stay hydrated and keep steady pace";
        } else {
            advice = "focus on compound lifts and good form. rest well between sets";
        }
    }

    return advice;
}

double AIEngine::calculateProgressScore(const std::vector<Workout*>& workoutHistory) {
    if (workoutHistory.empty()) {
        return 0.0;
    }

    // basic score calc - more workouts = better score
    // caps at 10 workouts for max score
    return std::min(1.0, workoutHistory.size() / 10.0);
}