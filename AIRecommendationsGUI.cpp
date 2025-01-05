#include "AIRecommendationsGUI.h"
#include <QScrollArea>

// ctor for gui
AIRecommendationsGUI::AIRecommendationsGUI(QWidget *parent) : QWidget(parent) {
    auto* layout = new QVBoxLayout(this);

    // title
    auto* titleLabel = new QLabel("AI Workout Recommendations", this);
    titleLabel->setStyleSheet("font-size: 16px; font-weight: bold;");
    layout->addWidget(titleLabel);

    // TODO: add filters maybe? would be nice to sort by difficulty/type
    workoutPlanList = new QListWidget(this);
    workoutPlanList->setMinimumHeight(200); // make dynamic if time
    layout->addWidget(workoutPlanList);

    // where ai gives advice - needs work
    adviceLabel = new QLabel(this);
    adviceLabel->setWordWrap(true);
    adviceLabel->setStyleSheet("background: #f0f0f0; padding: 10px; border-radius: 5px;");
    layout->addWidget(adviceLabel);

    // progress tracking - super buggy rn
    progressLabel = new QLabel(this);
    progressLabel->setWordWrap(true);
    layout->addWidget(progressLabel);

    // button to get new stuff from ai
    generateButton = new QPushButton("Generate New Recommendations", this);
    layout->addWidget(generateButton);

    connect(generateButton, &QPushButton::clicked,
            this, &AIRecommendationsGUI::handleGenerateRecommendations);

    setLayout(layout);

    // styling
    workoutPlanList->setStyleSheet(
        "QListWidget { background: #2b2b2b; color: white; padding: 10px; "
        "border-radius: 5px; }"
    );

    adviceLabel->setStyleSheet(
        "QLabel { background: #2b2b2b; color: white; padding: 10px; "
        "border-radius: 5px; margin: 10px; }"
    );

    progressLabel->setStyleSheet(
        "QLabel { background: #2b2b2b; color: white; padding: 10px; "
        "border-radius: 5px; }"
    );

    // button styling
    generateButton->setStyleSheet(
        "QPushButton { background: #4CAF50; color: white; padding: 8px; "
        "border-radius: 4px; }"
        "QPushButton:hover { background: #45a049; }"
    );
}

// updates ai info based on profile
void AIRecommendationsGUI::updateRecommendations(UserProfile* profile) {
    if (!profile) {
        adviceLabel->setText("Make a profile first!");
        return;
    }

    // generate workout ideas
    std::vector<std::string> workoutPlan = aiEngine.generateWorkoutPlan(*profile);
    displayWorkoutPlan(workoutPlan);

    std::vector<Workout*> workoutHistory;
    std::string advice = aiEngine.generateWorkoutAdvice(*profile, workoutHistory);
    adviceLabel->setText(QString::fromStdString("AI Advice:\n" + advice));

    // progress calc - doesn't really work rn but my code breaks if i remove it so ig its staying
    double progressScore = aiEngine.calculateProgressScore(workoutHistory);
    progressLabel->setText(QString("Progress: %1%")
                         .arg(progressScore * 100, 0, 'f', 1));
}

void AIRecommendationsGUI::handleGenerateRecommendations() {
    // temporary test profile
    UserProfile sampleProfile("", 25, 70.0, 175.0, "muscle gain", "male");
    updateRecommendations(&sampleProfile);
}

// display workout plan on gui
void AIRecommendationsGUI::displayWorkoutPlan(const std::vector<std::string>& plan) {
    workoutPlanList->clear();
    for (const auto& item : plan) {
        workoutPlanList->addItem(QString::fromStdString(item));
    }
}