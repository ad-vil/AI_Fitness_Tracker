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
#include <QMap>
#include <QDateTime>

class WorkoutGUI : public QDialog {
    Q_OBJECT

public:
    explicit WorkoutGUI(QWidget *parent = nullptr);
    ~WorkoutGUI();

    signals:
        void workoutLogged(const QString& type, const QMap<QString, QString>& workoutData);

    private slots:
        void handleWorkoutTypeChange(const QString &type);
    void logCardioWorkout();
    void logNormalWorkout();

private:
    QComboBox *workoutTypeDropdown;
    QLineEdit *setsInput;
    QLineEdit *repsInput;
    QLineEdit *distanceInput;
    QLineEdit *durationInput;
    QLineEdit *caloriesInput;
    QLabel *feedbackLabel;
    QVBoxLayout *mainLayout;
    QPushButton *submitButton;

    void setupUI();
    bool validateInputs();
};

#endif // WORKOUTGUI_H