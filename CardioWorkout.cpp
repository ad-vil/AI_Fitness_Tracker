//
// Created by adil_ on 11/15/2024.
//

#include "CardioWorkout.h"

// init cardio workout attributes
CardioWorkout::CardioWorkout(const string& date, int duration, int caloriesBurned, double distance)
    : Workout(date, duration, caloriesBurned), distance(distance) {}

// display cardio workout details
void CardioWorkout::displayWorkout() const {
    cout << "cardio workout on " << date << endl;
    cout << "duration: " << duration << " minutes" << endl;
    cout << "calories burned: " << caloriesBurned << endl;
    cout << "distance: " << distance << " miles" << endl;
}
