//
// Created by adil_ on 1/4/2025.
//

#include "WorkoutHistoryGUI.h"
#include <QHeaderView>
#include <QLabel>

WorkoutHistoryGUI::WorkoutHistoryGUI(WorkoutManager* manager, QWidget* parent)
    : QWidget(parent), workoutManager(manager) {
    setupUI();
    populateTable();
}

void WorkoutHistoryGUI::setupUI() {
    auto* layout = new QVBoxLayout(this);

    // Title
    auto* titleLabel = new QLabel("Workout History", this);
    titleLabel->setStyleSheet("font-size: 16px; font-weight: bold; margin: 10px;");
    layout->addWidget(titleLabel);

    // Create table
    historyTable = new QTableWidget(this);
    historyTable->setColumnCount(6);
    historyTable->setHorizontalHeaderLabels({
        "Date", "Type", "Duration (min)", "Calories", "Sets/Distance", "Reps"
    });

    // Style the table
    historyTable->setAlternatingRowColors(true);
    historyTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    historyTable->setEditTriggers(QTableWidget::NoEditTriggers);
    historyTable->setSelectionBehavior(QTableWidget::SelectRows);
    historyTable->setStyleSheet(
        "QTableWidget { background-color: grey; alternate-background-color: grey; }"
        "QHeaderView::section { background-color: #2b2b2b; color: white; padding: 6px; }"
        "QTableWidget::item { padding: 4px; }"
    );

    layout->addWidget(historyTable);

    // Refresh button
    refreshButton = new QPushButton("Refresh History", this);
    refreshButton->setStyleSheet(
        "QPushButton { background-color: #4CAF50; color: white; padding: 8px; border-radius: 4px; }"
        "QPushButton:hover { background-color: #45a049; }"
    );
    layout->addWidget(refreshButton);

    connect(refreshButton, &QPushButton::clicked, this, &WorkoutHistoryGUI::handleRefresh);

    setLayout(layout);
}

void WorkoutHistoryGUI::populateTable() {
    const auto& history = workoutManager->getWorkoutHistory();
    historyTable->setRowCount(history.size());

    int row = 0;
    for (const auto& workout : history) {
        // Common fields
        historyTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(workout->getDate())));
        historyTable->setItem(row, 2, new QTableWidgetItem(QString::number(workout->getDuration())));
        historyTable->setItem(row, 3, new QTableWidgetItem(QString::number(workout->getCaloriesBurned())));

        // Check workout type and handle specific fields
        if (auto* normal = dynamic_cast<NormalWorkout*>(workout.get())) {
            historyTable->setItem(row, 1, new QTableWidgetItem("Normal"));
            historyTable->setItem(row, 4, new QTableWidgetItem(QString::number(normal->getSets())));
            historyTable->setItem(row, 5, new QTableWidgetItem(QString::number(normal->getReps())));
        }
        else if (auto* cardio = dynamic_cast<CardioWorkout*>(workout.get())) {
            historyTable->setItem(row, 1, new QTableWidgetItem("Cardio"));
            historyTable->setItem(row, 4, new QTableWidgetItem(QString::number(cardio->getDistance()) + " km"));
            historyTable->setItem(row, 5, new QTableWidgetItem("-"));
        }

        row++;
    }
}

void WorkoutHistoryGUI::handleRefresh() {
    populateTable();
}

void WorkoutHistoryGUI::refreshHistory() {
    populateTable();
}