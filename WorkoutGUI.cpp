//
// Created by adil_ on 12/22/2024.
//

#include "WorkoutGUI.h"
#include <QMessageBox>

WorkoutGUI::WorkoutGUI(QWidget *parent) : QDialog(parent) {
    // Dropdown for workout type
    workoutTypeDropdown = new QComboBox(this);
    workoutTypeDropdown->addItem("Normal Workout");
    workoutTypeDropdown->addItem("Cardio Workout");

    // Input fields for Normal Workout
    setsInput = new QLineEdit(this);
    setsInput->setPlaceholderText("Enter number of sets");
    repsInput = new QLineEdit(this);
    repsInput->setPlaceholderText("Enter number of reps");

    // Input field for Cardio Workout
    distanceInput = new QLineEdit(this);
    distanceInput->setPlaceholderText("Enter distance (e.g., km or miles)");

    // Feedback label
    feedbackLabel = new QLabel(this);

    // Submit button
    submitButton = new QPushButton("Submit", this);

    // Layout
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new QLabel("Workout Type:"));
    mainLayout->addWidget(workoutTypeDropdown);
    mainLayout->addWidget(new QLabel("Sets:"));
    mainLayout->addWidget(setsInput);
    mainLayout->addWidget(new QLabel("Reps:"));
    mainLayout->addWidget(repsInput);
    mainLayout->addWidget(new QLabel("Distance:"));
    mainLayout->addWidget(distanceInput);
    mainLayout->addWidget(submitButton);
    mainLayout->addWidget(feedbackLabel);

    setLayout(mainLayout);

    // Initially hide cardio-specific fields
    distanceInput->hide();

    // Connect signals and slots
    connect(workoutTypeDropdown, &QComboBox::currentTextChanged, this, &WorkoutGUI::handleWorkoutTypeChange);
    connect(submitButton, &QPushButton::clicked, [this]() {
        QString type = workoutTypeDropdown->currentText();
        if (type == "Normal Workout") {
            logNormalWorkout();
        } else if (type == "Cardio Workout") {
            logCardioWorkout();
        }
    });
}

WorkoutGUI::~WorkoutGUI() = default;

void WorkoutGUI::handleWorkoutTypeChange(const QString &type) {
    if (type == "Normal Workout") {
        setsInput->show();
        repsInput->show();
        distanceInput->hide();
    } else if (type == "Cardio Workout") {
        setsInput->hide();
        repsInput->hide();
        distanceInput->show();
    }
}

void WorkoutGUI::logCardioWorkout() {
    QString distance = distanceInput->text();
    if (distance.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter the distance for the cardio workout.");
        return;
    }

    feedbackLabel->setText("Logged Cardio Workout: Distance = " + distance);
}

void WorkoutGUI::logNormalWorkout() {
    QString sets = setsInput->text();
    QString reps = repsInput->text();

    if (sets.isEmpty() || reps.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in both sets and reps for the normal workout.");
        return;
    }

    feedbackLabel->setText("Logged Normal Workout: Sets = " + sets + ", Reps = " + reps);
}
