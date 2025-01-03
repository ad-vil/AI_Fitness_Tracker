//
// Created by adil_ on 11/11/2024.
//

#include "UserProfile.h"

UserProfile::UserProfile(const std::string& name, int age, double weight, double height,
                         const std::string& goal, const std::string& gender)
    : name(name), age(age), weight(weight), height(height), goal(goal), gender(gender) {}

std::string UserProfile::getName() const { return name; }
int UserProfile::getAge() const { return age; }
double UserProfile::getWeight() const { return weight; }
double UserProfile::getHeight() const { return height; }
std::string UserProfile::getGoal() const { return goal; }
std::string UserProfile::getGender() const { return gender; }

void UserProfile::setName(const std::string& newName) { name = newName; }
void UserProfile::setAge(int newAge) { age = newAge; }

void UserProfile::updateProfile(double newWeight, double newHeight) {
    weight = newWeight;
    height = newHeight;
}

std::string UserProfile::getProfileInfo() const {
    return "Name: " + name + "\nAge: " + std::to_string(age) +
           "\nHeight: " + std::to_string(height) + " inches" +
           "\nWeight: " + std::to_string(weight) + " lbs" +
           "\nGoal: " + goal + "\nGender: " + gender;
}

