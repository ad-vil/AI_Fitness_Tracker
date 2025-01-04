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
#include <QTabWidget>
#include "WorkoutGUI.h"
#include "AIRecommendationsGUI.h"
#include "UserProfileGUI.h"
#include "WorkoutManager.h"
#include "WorkoutHistoryGUI.h"  // Add this include

class FitnessTrackerGUI : public QWidget {
    Q_OBJECT

public:
    explicit FitnessTrackerGUI(QWidget *parent = nullptr);

    private slots:
        void logWorkout();
    void onProfileUpdated();
    void onWorkoutLogged(const QString& type, const QMap<QString, QString>& data);

private:
    QTabWidget *tabWidget;
    UserProfileGUI *profileGui;
    QPushButton *logWorkoutButton;
    AIRecommendationsGUI *aiTab;
    WorkoutManager workoutManager;
    WorkoutHistoryGUI *historyTab;  // Add this member
};

#endif // FITNESS_TRACKER_GUI_H