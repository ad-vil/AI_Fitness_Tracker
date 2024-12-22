//
// Created by adil_ on 12/22/2024.
//

#ifndef FITNESS_TRACKER_GUI_H
#define FITNESS_TRACKER_GUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include "WorkoutGUI.h" // Include the Workout GUI

class FitnessTrackerGUI : public QWidget {
    Q_OBJECT

public:
    explicit FitnessTrackerGUI(QWidget *parent = nullptr);

    private slots:
        void updateProfile();         // Slot for updating the profile
    void logWorkout();            // Slot to open Workout GUI for logging workouts

private:
    QLineEdit *nameInput;
    QLabel *profileLabel;
    QPushButton *updateProfileButton;
    QPushButton *logWorkoutButton;
};

#endif // FITNESS_TRACKER_GUI_H
