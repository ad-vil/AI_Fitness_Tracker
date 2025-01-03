//
// Created by adil_ on 12/22/2024.
//

// FitnessTrackerGUI.h
#ifndef FITNESS_TRACKER_GUI_H
#define FITNESS_TRACKER_GUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QTabWidget>  // Add this
#include "WorkoutGUI.h"
#include "AIRecommendationsGUI.h"  // Add this

class FitnessTrackerGUI : public QWidget {
    Q_OBJECT

public:
    explicit FitnessTrackerGUI(QWidget *parent = nullptr);

    private slots:
        void updateProfile();
    void logWorkout();

private:
    QLineEdit *nameInput;
    QLabel *profileLabel;
    QPushButton *updateProfileButton;
    QPushButton *logWorkoutButton;
    QTabWidget *tabWidget;           // Add this
    AIRecommendationsGUI *aiTab;     // Add this
};

#endif // FITNESS_TRACKER_GUI_H
