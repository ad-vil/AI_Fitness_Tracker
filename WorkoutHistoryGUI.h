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
    QTableWidget* historyTable; // table for history
    QPushButton* refreshButton; // button for refresh
    WorkoutManager* workoutManager;

    void setupUI(); // setting up UI
    void fillTable(); // adding info to table

    private slots:
        void handleRefresh();
};

#endif // WORKOUTHISTORYGUI_H