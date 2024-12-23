//
// Created by adil_ on 12/22/2024.
//

#ifndef WORKOUTGUI_H
#define WORKOUTGUI_H

#include <QDialog>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class WorkoutGUI : public QDialog {
    Q_OBJECT

public:
    explicit WorkoutGUI(QWidget *parent = nullptr);
    ~WorkoutGUI();

    private slots:
        void handleWorkoutTypeChange(const QString &type); // Changes UI based on workout type
    void logCardioWorkout();                          // Handles cardio workout submission
    void logNormalWorkout();                          // Handles normal workout submission

private:
    QComboBox *workoutTypeDropdown;
    QLineEdit *setsInput;
    QLineEdit *repsInput;
    QLineEdit *distanceInput;
    QLabel *feedbackLabel;
    QVBoxLayout *mainLayout;
    QPushButton *submitButton;
};

#endif // WORKOUTGUI_H
