//
// Created by adil_ on 1/3/2025.
//

#ifndef AIRECOMMENDATIONSGUI_H
#define AIRECOMMENDATIONSGUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include "AIEngine.h"
#include "UserProfile.h"

class AIRecommendationsGUI : public QWidget {
    Q_OBJECT

public:
    explicit AIRecommendationsGUI(QWidget *parent = nullptr);
    void updateRecommendations(UserProfile* profile);

private:
    AIEngine aiEngine;
    QListWidget* workoutPlanList;
    QLabel* adviceLabel;
    QLabel* progressLabel;
    QPushButton* generateButton;

    private slots:
        void handleGenerateRecommendations();
    void displayWorkoutPlan(const std::vector<std::string>& plan);
};

#endif
