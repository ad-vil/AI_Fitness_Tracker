//
// Created by adil_ on 12/22/2024.
//

#include "FitnessTrackerGUI.h"

FitnessTrackerGUI::FitnessTrackerGUI(QWidget *parent) : QWidget(parent) {
    // Main layout
    auto *mainLayout = new QVBoxLayout(this);

    // Create tab widget
    tabWidget = new QTabWidget(this);

    // Create main profile widget
    auto *profileWidget = new QWidget(this);
    auto *profileLayout = new QVBoxLayout(profileWidget);

    // Profile components
    nameInput = new QLineEdit(this);
    nameInput->setPlaceholderText("Enter your name");
    profileLayout->addWidget(nameInput);

    profileLabel = new QLabel("Profile: [Empty]", this);
    profileLayout->addWidget(profileLabel);

    updateProfileButton = new QPushButton("Update Profile", this);
    profileLayout->addWidget(updateProfileButton);

    logWorkoutButton = new QPushButton("Log Workout", this);
    profileLayout->addWidget(logWorkoutButton);

    profileWidget->setLayout(profileLayout);

    // Create AI tab
    aiTab = new AIRecommendationsGUI(this);

    // Add tabs
    tabWidget->addTab(profileWidget, "Profile");
    tabWidget->addTab(aiTab, "AI Recommendations");

    // Add tab widget to main layout
    mainLayout->addWidget(tabWidget);

    // Connect signals to slots
    connect(updateProfileButton, &QPushButton::clicked, this, &FitnessTrackerGUI::updateProfile);
    connect(logWorkoutButton, &QPushButton::clicked, this, &FitnessTrackerGUI::logWorkout);

    setLayout(mainLayout);
}

void FitnessTrackerGUI::updateProfile() {
    QString name = nameInput->text();
    profileLabel->setText("Profile: " + name);
}

void FitnessTrackerGUI::logWorkout() {
    WorkoutGUI workoutGui(this);
    workoutGui.exec();
}