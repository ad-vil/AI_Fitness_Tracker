//
// Created by adil_ on 11/11/2024.
//

#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <string>
#include <iostream>

using namespace std;

class UserProfile {
private:
    string name;
    int age;
    double weight; // in lbs
    double height; // in inches
    string goal; // e.g., "weight loss" or "muscle gain"
    string gender;

public:
    // constructor
    UserProfile(const string &name, int age, double weight, double height, const string &goal, const string &gender);

    // updates user profile with new weight and height
    void updateProfile(double newWeight, double newHeight);

    // displays user profile details
    void displayProfile() const;
};

#endif // USERPROFILE_H
