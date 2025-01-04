//
// Created by adil_ on 12/22/2024.
//

#include "WorkoutGUI.h"
#include <QMessageBox>

WorkoutGUI::WorkoutGUI(QWidget *parent) : QDialog(parent) {
    setupUI();
}

void WorkoutGUI::setupUI() {
    // Workout type selection
    workoutTypeDropdown = new QComboBox(this);
    workoutTypeDropdown->addItem("Normal Workout");
    workoutTypeDropdown->addItem("Cardio Workout");

    // Common inputs
    durationInput = new QLineEdit(this);
    durationInput->setPlaceholderText("Duration (minutes)");
    caloriesInput = new QLineEdit(this);
    caloriesInput->setPlaceholderText("Calories burned");

    // Normal workout inputs
    setsInput = new QLineEdit(this);
    setsInput->setPlaceholderText("Number of sets");
    repsInput = new QLineEdit(this);
    repsInput->setPlaceholderText("Number of reps");

    // Cardio workout inputs
    distanceInput = new QLineEdit(this);
    distanceInput->setPlaceholderText("Distance (km)");

    // Submit button and feedback
    submitButton = new QPushButton("Log Workout", this);
    feedbackLabel = new QLabel(this);

    // Layout
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new QLabel("Workout Type:"));
    mainLayout->addWidget(workoutTypeDropdown);
    mainLayout->addWidget(new QLabel("Duration:"));
    mainLayout->addWidget(durationInput);
    mainLayout->addWidget(new QLabel("Calories:"));
    mainLayout->addWidget(caloriesInput);
    mainLayout->addWidget(new QLabel("Sets:"));
    mainLayout->addWidget(setsInput);
    mainLayout->addWidget(new QLabel("Reps:"));
    mainLayout->addWidget(repsInput);
    mainLayout->addWidget(new QLabel("Distance:"));
    mainLayout->addWidget(distanceInput);
    mainLayout->addWidget(submitButton);
    mainLayout->addWidget(feedbackLabel);

    // Connect signals
    connect(workoutTypeDropdown, &QComboBox::currentTextChanged,
            this, &WorkoutGUI::handleWorkoutTypeChange);
    connect(submitButton, &QPushButton::clicked, [this]() {
        if (workoutTypeDropdown->currentText() == "Normal Workout") {
            logNormalWorkout();
        } else {
            logCardioWorkout();
        }
    });

    handleWorkoutTypeChange(workoutTypeDropdown->currentText());
}

void WorkoutGUI::handleWorkoutTypeChange(const QString &type) {
    if (type == "Normal Workout") {
        setsInput->show();
        repsInput->show();
        distanceInput->hide();
    } else {
        setsInput->hide();
        repsInput->hide();
        distanceInput->show();
    }
}

bool WorkoutGUI::validateInputs() {
    if (durationInput->text().isEmpty() || caloriesInput->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in duration and calories burned.");
        return false;
    }
    return true;
}

void WorkoutGUI::logNormalWorkout() {
    if (!validateInputs() || setsInput->text().isEmpty() || repsInput->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    QMap<QString, QString> workoutData;
    workoutData["date"] = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    workoutData["duration"] = durationInput->text();
    workoutData["calories"] = caloriesInput->text();
    workoutData["sets"] = setsInput->text();
    workoutData["reps"] = repsInput->text();

    emit workoutLogged("normal", workoutData);
    accept();
}

void WorkoutGUI::logCardioWorkout() {
    if (!validateInputs() || distanceInput->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    QMap<QString, QString> workoutData;
    workoutData["date"] = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    workoutData["duration"] = durationInput->text();
    workoutData["calories"] = caloriesInput->text();
    workoutData["distance"] = distanceInput->text();

    emit workoutLogged("cardio", workoutData);
    accept();
}

WorkoutGUI::~WorkoutGUI() = default;