//
// Created by adil_ on 11/11/2024.
//

#include "UserProfile.h"

// constructor init user profile attributes
UserProfile::UserProfile(const string& name, int age, double weight, double height, const string& goal, const string& gender)
    : name(name), age(age), weight(weight), height(height), goal(goal), gender(gender) {}

// update weight and height in user profile
void UserProfile::updateProfile(double newWeight, double newHeight) {
    weight = newWeight;
    height = newHeight;
}

// displays profile
void UserProfile::displayProfile() const {
    cout << "name: " << name << endl;
    cout << "age: " << age << endl;
    cout << "weight: " << weight << " lbs" << endl;
    cout << "height: " << height << " inches" << endl;
    cout << "goal: " << goal << endl;
    cout << "gender: " << gender << endl;
}
