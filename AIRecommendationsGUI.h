#ifndef AIRECOMMENDATIONSGUI_H
#define AIRECOMMENDATIONSGUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include "AIEngine.h"
#include "UserProfile.h"

// class for GUI to display AI recs
class AIRecommendationsGUI : public QWidget {
    Q_OBJECT

public:
    explicit AIRecommendationsGUI(QWidget *parent = nullptr);
    void updateRecommendations(UserProfile* profile); // update recs for user

private:
    AIEngine aiEngine; // ai engine obj
    QListWidget* workoutPlanList; // list widget for plans
    QLabel* adviceLabel; // label for advice
    QLabel* progressLabel; // label for progress
    QPushButton* generateButton; // btn for new recs

    private slots:
        void handleGenerateRecommendations(); // handle btn click
    void displayWorkoutPlan(const std::vector<std::string>& plan); // display plan
};

#endif
