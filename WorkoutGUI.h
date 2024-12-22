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
        void handleWorkoutTypeChange(const QString &type);
    void handleSubmit();

private:
    QComboBox *workoutTypeDropdown;
    QLineEdit *setsInput;
    QLineEdit *repsInput;
    QLineEdit *distanceInput;
    QVBoxLayout *mainLayout;
    QPushButton *submitButton;
};

#endif // WORKOUTGUI_H
