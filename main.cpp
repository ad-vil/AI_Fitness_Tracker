//
// Created by adil_ on 11/15/2024.
//
//
// #include <iostream>
// #include "UserProfile.h"
// #include "CardioWorkout.h"
// #include "NormalWorkout.h"
//
//
//
// using namespace std;
//
// int main() {
//     // create user profile
//     UserProfile user("person1", 25, 180, 70, "muscle gain", "male");
//
//     cout << "User Profile:" << endl;
//     user.displayProfile();
//     cout << endl;
//
//     // update profile data
//     cout << "Updating profile..." << endl;
//     user.updateProfile(185, 72);
//
//     cout << "Updated User Profile:" << endl;
//     user.displayProfile();
//     cout << endl;
//
//     // create cardio workout
//     CardioWorkout cardio("2024-11-10", 45, 400, 5.5);
//
//     cout << "Cardio Workout Details:" << endl;
//     cardio.displayWorkout();
//     cout << endl;
//
//     // create strength workout
//     NormalWorkout strength("2024-11-11", 60, 500, "Bench Press", 4, 10);
//
//     cout << "Strength Workout Details:" << endl;
//     strength.displayWorkout();
//     cout << endl;
//
//     return 0;
// }


#include <QApplication>
#include "FitnessTrackerGUI.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FitnessTrackerGUI tracker;
    tracker.setWindowTitle("AI Fitness Tracker");
    tracker.resize(400, 300);
    tracker.show();

    return app.exec();
}
