#include "CardioWorkout.h"

// initialize cardio workout details
CardioWorkout::CardioWorkout(const string& date, int duration, int caloriesBurned, double distance)
    : Workout(date, duration, caloriesBurned), distance(distance) {}

// display cardio workout info
void CardioWorkout::displayWorkout() const {
    cout << "cardio workout on " << date << endl;
    cout << "duration: " << duration << " minutes" << endl;
    cout << "calories burned: " << caloriesBurned << endl;
    cout << "distance: " << distance << " miles" << endl;
}
