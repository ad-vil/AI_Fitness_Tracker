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
#include "WorkoutHistoryGUI.h"

// main GUI for fitness tracker
class FitnessTrackerGUI : public QWidget {
    Q_OBJECT

public:
    explicit FitnessTrackerGUI(QWidget *parent = nullptr); // ctor

    private slots:
        void logWorkout(); // handle log workout
    void onProfileUpdated(); // handle profile update
    void onWorkoutLogged(const QString& type, const QMap<QString, QString>& data); // handle logged workout

private:
    QTabWidget *tabWidget; // tab widget for sections
    UserProfileGUI *profileGui; // profile GUI
    QPushButton *logWorkoutButton; // log workout button
    AIRecommendationsGUI *aiTab; // AI recommendations tab
    WorkoutManager workoutManager; // manages workouts
    WorkoutHistoryGUI *historyTab; // workout history tab
};

#endif // FITNESS_TRACKER_GUI_H