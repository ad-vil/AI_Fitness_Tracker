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
#include <QTabWidget>
#include "WorkoutGUI.h"
#include "AIRecommendationsGUI.h"
#include "UserProfileGUI.h"

class FitnessTrackerGUI : public QWidget {
    Q_OBJECT

public:
    explicit FitnessTrackerGUI(QWidget *parent = nullptr);

    private slots:
        void logWorkout();
    void onProfileUpdated();

private:
    QTabWidget *tabWidget;
    UserProfileGUI *profileGui;
    QPushButton *logWorkoutButton;
    AIRecommendationsGUI *aiTab;
};

#endif // FITNESS_TRACKER_GUI_H