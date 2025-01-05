#include "UserProfile.h"

// ctor sets up all the basic user info
UserProfile::UserProfile(const std::string& name, int age, double weight, double height,
                         const std::string& goal, const std::string& gender)
    : name(name), age(age), weight(weight), height(height), goal(goal), gender(gender) {}

// getters
    std::string UserProfile::getName() const {
        return name;
    }
    int UserProfile::getAge() const {
        return age;
    }
    double UserProfile::getWeight() const {
        return weight;
    }
    double UserProfile::getHeight() const {
        return height;
    }
    std::string UserProfile::getGoal() const {
        return goal;
    }
    std::string UserProfile::getGender() const {
        return gender;
    }

    // setters
    void UserProfile::setName(const std::string& newName) {
        name = newName;
    }
    void UserProfile::setAge(int newAge) {
        age = newAge;
    }
    void UserProfile::setWeight(double newWeight) {
        weight = newWeight;
    }
    void UserProfile::setHeight(double newHeight) {
        height = newHeight;
    }
    void UserProfile::setGoal(const std::string& newGoal) {
        goal = newGoal;
    }
    void UserProfile::setGender(const std::string& newGender) {
        gender = newGender;
    }

    // updates physical stats
    void UserProfile::updateProfile(double newWeight, double newHeight) {
        weight = newWeight;
        height = newHeight;
    }

// formats all user info into string
std::string UserProfile::getProfileInfo() const {
    return "Name: " + name +
           "\nAge: " + std::to_string(age) +
           "\nHeight: " + std::to_string(height) + " cm" +
           "\nWeight: " + std::to_string(weight) + " kg" +
           "\nGoal: " + goal +
           "\nGender: " + gender;
}