//
// Created by adil_ on 1/3/2025.
//

#include "AIRecommendationsGUI.h"
#include <QScrollArea>

AIRecommendationsGUI::AIRecommendationsGUI(QWidget *parent) : QWidget(parent) {
    auto* layout = new QVBoxLayout(this);

    // Create title
    auto* titleLabel = new QLabel("AI Workout Recommendations", this);
    titleLabel->setStyleSheet("font-size: 16px; font-weight: bold;");
    layout->addWidget(titleLabel);

    // Create workout plan list
    workoutPlanList = new QListWidget(this);
    workoutPlanList->setMinimumHeight(200);
    layout->addWidget(workoutPlanList);

    // Create advice section
    adviceLabel = new QLabel(this);
    adviceLabel->setWordWrap(true);
    adviceLabel->setStyleSheet("background-color: #f0f0f0; padding: 10px; border-radius: 5px;");
    layout->addWidget(adviceLabel);

    // Create progress section
    progressLabel = new QLabel(this);
    progressLabel->setWordWrap(true);
    layout->addWidget(progressLabel);

    // Create generate button
    generateButton = new QPushButton("Generate New Recommendations", this);
    layout->addWidget(generateButton);

    connect(generateButton, &QPushButton::clicked,
            this, &AIRecommendationsGUI::handleGenerateRecommendations);

    setLayout(layout);

    workoutPlanList->setStyleSheet(
        "QListWidget { background-color: #2b2b2b; color: white; padding: 10px; "
        "border-radius: 5px; }"
    );

    adviceLabel->setStyleSheet(
        "QLabel { background-color: #2b2b2b; color: white; padding: 10px; "
        "border-radius: 5px; margin: 10px; }"
    );

    progressLabel->setStyleSheet(
        "QLabel { background-color: #2b2b2b; color: white; padding: 10px; "
        "border-radius: 5px; }"
    );

    generateButton->setStyleSheet(
        "QPushButton { background-color: #4CAF50; color: white; padding: 8px; "
        "border-radius: 4px; }"
        "QPushButton:hover { background-color: #45a049; }"
    );
}

void AIRecommendationsGUI::updateRecommendations(UserProfile* profile) {
    if (!profile) {
        adviceLabel->setText("Please create a user profile first.");
        return;
    }

    // Generate workout plan
    std::vector<std::string> workoutPlan = aiEngine.generateWorkoutPlan(*profile);
    displayWorkoutPlan(workoutPlan);

    // Generate advice
    std::vector<Workout*> workoutHistory;  // This should be populated from your workout history
    std::string advice = aiEngine.generateWorkoutAdvice(*profile, workoutHistory);
    adviceLabel->setText(QString::fromStdString("AI Advice:\n" + advice));

    // Calculate and display progress
    double progressScore = aiEngine.calculateProgressScore(workoutHistory);
    progressLabel->setText(QString("Current Progress Score: %1%")
                         .arg(progressScore * 100, 0, 'f', 1));
}

void AIRecommendationsGUI::handleGenerateRecommendations() {
    // This should be connected to your current user profile
    // For now, we'll create a sample profile
    UserProfile sampleProfile("User", 25, 70.0, 175.0, "muscle gain", "male");
    updateRecommendations(&sampleProfile);
}

void AIRecommendationsGUI::displayWorkoutPlan(const std::vector<std::string>& plan) {
    workoutPlanList->clear();
    for (const auto& item : plan) {
        workoutPlanList->addItem(QString::fromStdString(item));
    }
}