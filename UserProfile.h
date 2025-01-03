//
// Created by adil_ on 11/11/2024.
//

#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <string>

class UserProfile {
private:
    std::string name;
    int age;
    double weight;
    double height;
    std::string goal;
    std::string gender;

public:
    UserProfile(const std::string& name = "", int age = 0, double weight = 0.0, double height = 0.0,
                const std::string& goal = "", const std::string& gender = "");

    // Getters
    std::string getName() const;
    int getAge() const;
    double getWeight() const;
    double getHeight() const;
    std::string getGoal() const;
    std::string getGender() const;

    // Setters
    void setName(const std::string& name);
    void setAge(int age);
    void updateProfile(double weight, double height);

    // Additional functions
    std::string getProfileInfo() const;
};

#endif
