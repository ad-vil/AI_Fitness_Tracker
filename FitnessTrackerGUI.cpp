//
// Created by adil_ on 12/22/2024.
//

#include "FitnessTrackerGUI.h"

FitnessTrackerGUI::FitnessTrackerGUI(QWidget *parent) : QWidget(parent) {
    // Set up the layout
    auto *layout = new QVBoxLayout(this);

    // Name input
    nameInput = new QLineEdit(this);
    nameInput->setPlaceholderText("Enter your name");
    layout->addWidget(nameInput);

    // Profile label
    profileLabel = new QLabel("Profile: [Empty]", this);
    layout->addWidget(profileLabel);

    // Update profile button
    updateProfileButton = new QPushButton("Update Profile", this);
    layout->addWidget(updateProfileButton);

    // Log workout button
    logWorkoutButton = new QPushButton("Log Workout", this);
    layout->addWidget(logWorkoutButton);

    // Connect signals to slots
    connect(updateProfileButton, &QPushButton::clicked, this, &FitnessTrackerGUI::updateProfile);
    connect(logWorkoutButton, &QPushButton::clicked, this, &FitnessTrackerGUI::logWorkout);
}

void FitnessTrackerGUI::updateProfile() {
    QString name = nameInput->text();
    profileLabel->setText("Profile: " + name);
}

void FitnessTrackerGUI::logWorkout() {
    // Create and show the workout GUI
    WorkoutGUI workoutGui(this);
    workoutGui.exec(); // Show the workout GUI as a modal dialog
}
