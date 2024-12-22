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

    // Input fields
    setsInput = new QLineEdit(this);
    repsInput = new QLineEdit(this);
    distanceInput = new QLineEdit(this);

    // Labels for the input fields
    QLabel *setsLabel = new QLabel("Sets:");
    QLabel *repsLabel = new QLabel("Reps:");
    QLabel *distanceLabel = new QLabel("Distance:");

    // Submit button
    submitButton = new QPushButton("Submit", this);

    // Layout
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(new QLabel("Workout Type:"));
    mainLayout->addWidget(workoutTypeDropdown);
    mainLayout->addWidget(setsLabel);
    mainLayout->addWidget(setsInput);
    mainLayout->addWidget(repsLabel);
    mainLayout->addWidget(repsInput);
    mainLayout->addWidget(distanceLabel);
    mainLayout->addWidget(distanceInput);
    mainLayout->addWidget(submitButton);

    setLayout(mainLayout);

    // Initially hide cardio-specific fields
    distanceLabel->hide();
    distanceInput->hide();

    // Connect signals and slots
    connect(workoutTypeDropdown, &QComboBox::currentTextChanged, this, &WorkoutGUI::handleWorkoutTypeChange);
    connect(submitButton, &QPushButton::clicked, this, &WorkoutGUI::handleSubmit);
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

void WorkoutGUI::handleSubmit() {
    QString type = workoutTypeDropdown->currentText();
    QString details;

    if (type == "Normal Workout") {
        details = QString("Sets: %1, Reps: %2")
                      .arg(setsInput->text())
                      .arg(repsInput->text());
    } else if (type == "Cardio Workout") {
        details = QString("Distance: %1").arg(distanceInput->text());
    }

    QMessageBox::information(this, "Workout Logged", QString("Type: %1\n%2").arg(type, details));
}
