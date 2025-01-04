//
// Created by adil_ on 12/22/2024.
//

#include "FitnessTrackerGUI.h"

FitnessTrackerGUI::FitnessTrackerGUI(QWidget *parent) : QWidget(parent) {
    // Main layout
    auto *mainLayout = new QVBoxLayout(this);

    // Create tab widget
    tabWidget = new QTabWidget(this);

    // Create UserProfileGUI
    profileGui = new UserProfileGUI(this);

    // Create workout button
    logWorkoutButton = new QPushButton("Log Workout", this);

    // Create a container widget for profile tab
    auto *profileContainer = new QWidget(this);
    auto *profileLayout = new QVBoxLayout(profileContainer);
    profileLayout->addWidget(profileGui);
    profileLayout->addWidget(logWorkoutButton);
    profileContainer->setLayout(profileLayout);

    // Create AI tab
    aiTab = new AIRecommendationsGUI(this);

    // Add tabs
    tabWidget->addTab(profileContainer, "Profile");
    tabWidget->addTab(aiTab, "AI Recommendations");

    // Add tab widget to main layout
    mainLayout->addWidget(tabWidget);

    // Connect signals to slots
    connect(logWorkoutButton, &QPushButton::clicked, this, &FitnessTrackerGUI::logWorkout);
    connect(profileGui, &UserProfileGUI::profileUpdated, this, &FitnessTrackerGUI::onProfileUpdated);

    setLayout(mainLayout);
    setMinimumSize(400, 600);  // Set a reasonable minimum size
}

void FitnessTrackerGUI::logWorkout() {
    WorkoutGUI workoutGui(this);
    workoutGui.exec();
}

void FitnessTrackerGUI::onProfileUpdated() {
    // You can add any additional logic here that needs to happen when the profile is updated
    // For example, updating the AI recommendations based on the new profile
    if (UserProfile* profile = profileGui->getCurrentProfile()) {
        // Update AI recommendations or other components based on the profile
        // aiTab->updateRecommendations(profile);
    }
}