#ifndef AIENGINE_H
#define AIENGINE_H

#include <string>
#include <vector>
#include "UserProfile.h"
#include "Workout.h"

class AIEngine {
public:
    AIEngine() = default;
    std::vector<std::string> generateWorkoutPlan(const UserProfile& profile);
    std::string generateWorkoutAdvice(const UserProfile& profile, const std::vector<Workout*>& workoutHistory);
    double calculateProgressScore(const std::vector<Workout*>& workoutHistory);
};

#endif