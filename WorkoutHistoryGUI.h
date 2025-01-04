//
// Created by adil_ on 1/4/2025.
//

#ifndef WORKOUTHISTORYGUI_H
#define WORKOUTHISTORYGUI_H

#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "WorkoutManager.h"

class WorkoutHistoryGUI : public QWidget {
    Q_OBJECT

public:
    explicit WorkoutHistoryGUI(WorkoutManager* manager, QWidget* parent = nullptr);
    void refreshHistory();

private:
    QTableWidget* historyTable;
    QPushButton* refreshButton;
    WorkoutManager* workoutManager;

    void setupUI();
    void populateTable();

    private slots:
        void handleRefresh();
};

#endif // WORKOUTHISTORYGUI_H