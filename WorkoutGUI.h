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
    // ctor and dtor
    explicit WorkoutGUI(QWidget *parent = nullptr);
    ~WorkoutGUI();

    // signal emitted when workout is logged
    signals:

        void workoutLogged(const QString& type, const QMap<QString, QString>& workoutData);

    private slots:
        void handleWorkoutTypeChange(const QString &type); // cardio vs normal
        void logCardioWorkout(); // cardio
        void logNormalWorkout(); // normal


private:
    // UI elements
    QComboBox *workoutTypeDropdown; // dropdown for workout type
    QLineEdit *setsInput; // input fields
    QLineEdit *repsInput;
    QLineEdit *distanceInput;
    QLineEdit *durationInput;
    QLineEdit *caloriesInput;
    QLabel *feedbackLabel; // label shows feedback
    QVBoxLayout *mainLayout; // layout manager for all dialog
    QPushButton *submitButton;

    void setupUI();
    bool validateInputs();
};

#endif // WORKOUTGUI_H