#ifndef AIENGINE_H
#define AIENGINE_H

#include <string>
#include <vector>
#include "UserProfile.h"
#include "Workout.h"

// handles all the ai workout recommendations
class AIEngine {
public:
    // default ctor
    AIEngine() = default;

    // returns vector of strings w/ daily workouts
    std::vector<std::string> generateWorkoutPlan(const UserProfile& profile);

    // returns string w/ advice
    std::string generateWorkoutAdvice(const UserProfile& profile, const std::vector<Workout*>& workoutHistory);

    // calcs how well user is doing (0.0 to 1.0) - this doesn't work ngl
    double calculateProgressScore(const std::vector<Workout*>& workoutHistory);
};

#endif