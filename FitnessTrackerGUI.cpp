#include "FitnessTrackerGUI.h"
#include <QDateTime>

// ctor
FitnessTrackerGUI::FitnessTrackerGUI(QWidget *parent) : QWidget(parent) {
    auto *mainLayout = new QVBoxLayout(this); // creates main vertical layout
    tabWidget = new QTabWidget(this); // main tab widget for sections

    // creates gui for UserProfile
    profileGui = new UserProfileGUI(this);

    // create workout button
    logWorkoutButton = new QPushButton("Log Workout", this);

    // creates profile container
    auto *profileContainer = new QWidget(this); // container for profile
    auto *profileLayout = new QVBoxLayout(profileContainer); // layout for profile
    profileLayout->addWidget(profileGui); // adds profile GUI
    profileLayout->addWidget(logWorkoutButton); // adds log workout button

    // creates AI recommendations tab
    aiTab = new AIRecommendationsGUI(this);


    // creates workout history tab
    historyTab = new WorkoutHistoryGUI(&workoutManager, this);

    // add tabs to main widget
    tabWidget->addTab(profileContainer, "Profile");
    tabWidget->addTab(aiTab, "AI Recommendations");
    tabWidget->addTab(historyTab, "Workout History");

    mainLayout->addWidget(tabWidget); // add tab widget to layout


    // connect signals for buttons and profile updates
    connect(logWorkoutButton, &QPushButton::clicked, this, &FitnessTrackerGUI::logWorkout); // handle log workout btn click
    connect(profileGui, &UserProfileGUI::profileUpdated, this, &FitnessTrackerGUI::onProfileUpdated); // update on profile change

    setLayout(mainLayout); // set layout for main GUI
    setMinimumSize(400, 600);
}

// handles log workout button click
void FitnessTrackerGUI::logWorkout() {
    auto *workoutDialog = new WorkoutGUI(this); // opens workout dialog
    connect(workoutDialog, &WorkoutGUI::workoutLogged, this, &FitnessTrackerGUI::onWorkoutLogged); // handles workout logged
    workoutDialog->exec(); // show dialog
}

// updates AI recommendations when profile changes
void FitnessTrackerGUI::onProfileUpdated() {
    if (UserProfile* profile = profileGui->getCurrentProfile()) {
        aiTab->updateRecommendations(profile); // updates AI tab with new profile data
    }
}

// logs workout and refreshes data
void FitnessTrackerGUI::onWorkoutLogged(const QString& type, const QMap<QString, QString>& data) {
    try {
        // log normal workout
        if (type == "normal") {
            workoutManager.addNormalWorkout(
                data["date"].toStdString(),
                data["duration"].toInt(),
                data["calories"].toInt(),
                "General",
                data["sets"].toInt(),
                data["reps"].toInt()
            );
        }
        // log cardio workout
        else if (type == "cardio") {
            workoutManager.addCardioWorkout(
                data["date"].toStdString(),
                data["duration"].toInt(),
                data["calories"].toInt(),
                data["distance"].toDouble()
            );
        }


        // Refresh the workout history tab
        historyTab->refreshHistory(); // refresh workout history

        // Update AI recommendations with new workout data
        if (UserProfile* profile = profileGui->getCurrentProfile()) {
            aiTab->updateRecommendations(profile); // refresh AI recommendations
        }
    } catch (const std::exception& e) {
        qDebug() << "Error logging workout:" << e.what(); // log error
    }
}