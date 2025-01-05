#ifndef WORKOUT_H
#define WORKOUT_H

#include <string>
#include <iostream>

using namespace std;

// base workout class
class Workout {
protected:
    string date;
    int duration;  // in minutes
    int caloriesBurned;

public:
    // ctor
    Workout(const string& date, int duration, int caloriesBurned);

    // virtual method for displaying the workout, to be defined by derived classes
    virtual void displayWorkout() const = 0;

    // destructor
    virtual ~Workout() {}

    // getters
    int getDuration() const { return duration; }

    virtual std::string getDate() const { return date; }
    virtual int getCaloriesBurned() const { return caloriesBurned; }
};

#endif // WORKOUT_H
