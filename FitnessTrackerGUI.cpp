//
// Created by adil_ on 12/22/2024.
//

#include "FitnessTrackerGUI.h"
#include <QDateTime>

FitnessTrackerGUI::FitnessTrackerGUI(QWidget *parent) : QWidget(parent) {
    auto *mainLayout = new QVBoxLayout(this);
    tabWidget = new QTabWidget(this);

    // Create and setup UserProfileGUI
    profileGui = new UserProfileGUI(this);

    // Create workout button
    logWorkoutButton = new QPushButton("Log Workout", this);

    // Create profile container
    auto *profileContainer = new QWidget(this);
    auto *profileLayout = new QVBoxLayout(profileContainer);
    profileLayout->addWidget(profileGui);
    profileLayout->addWidget(logWorkoutButton);

    // Create AI recommendations tab
    aiTab = new AIRecommendationsGUI(this);

    // Create workout history tab
    historyTab = new WorkoutHistoryGUI(&workoutManager, this);

    // Add tabs
    tabWidget->addTab(profileContainer, "Profile");
    tabWidget->addTab(aiTab, "AI Recommendations");
    tabWidget->addTab(historyTab, "Workout History");  // Add the history tab

    mainLayout->addWidget(tabWidget);

    // Connect signals
    connect(logWorkoutButton, &QPushButton::clicked, this, &FitnessTrackerGUI::logWorkout);
    connect(profileGui, &UserProfileGUI::profileUpdated, this, &FitnessTrackerGUI::onProfileUpdated);

    setLayout(mainLayout);
    setMinimumSize(400, 600);
}

void FitnessTrackerGUI::logWorkout() {
    auto *workoutDialog = new WorkoutGUI(this);
    connect(workoutDialog, &WorkoutGUI::workoutLogged, this, &FitnessTrackerGUI::onWorkoutLogged);
    workoutDialog->exec();
}

void FitnessTrackerGUI::onProfileUpdated() {
    if (UserProfile* profile = profileGui->getCurrentProfile()) {
        aiTab->updateRecommendations(profile);
    }
}

void FitnessTrackerGUI::onWorkoutLogged(const QString& type, const QMap<QString, QString>& data) {
    try {
        if (type == "normal") {
            workoutManager.addNormalWorkout(
                data["date"].toStdString(),
                data["duration"].toInt(),
                data["calories"].toInt(),
                "General",  // You might want to add an exercise type field
                data["sets"].toInt(),
                data["reps"].toInt()
            );
        } else if (type == "cardio") {
            workoutManager.addCardioWorkout(
                data["date"].toStdString(),
                data["duration"].toInt(),
                data["calories"].toInt(),
                data["distance"].toDouble()
            );
        }

        // Refresh the workout history after logging a new workout
        historyTab->refreshHistory();

        // Update AI recommendations with new workout data
        if (UserProfile* profile = profileGui->getCurrentProfile()) {
            aiTab->updateRecommendations(profile);
        }
    } catch (const std::exception& e) {
        qDebug() << "Error logging workout:" << e.what();
    }
}