#include "WorkoutGUI.h"
#include <QMessageBox>

/* flow:
 * user fills out form
 * click submit
 * code emit signal with workout info
 * close form
 */

// ctor
WorkoutGUI::WorkoutGUI(QWidget *parent) : QDialog(parent) {
    setupUI();
}

void WorkoutGUI::setupUI() {
    // select workout type via dropdown
    workoutTypeDropdown = new QComboBox(this);
    workoutTypeDropdown->addItem("Normal Workout");
    workoutTypeDropdown->addItem("Cardio Workout");

    // common inputs for workout types
    durationInput = new QLineEdit(this);
    durationInput->setPlaceholderText("Duration (minutes)");
    caloriesInput = new QLineEdit(this);
    caloriesInput->setPlaceholderText("Calories burned");

    // normal specific inputs
    setsInput = new QLineEdit(this);
    setsInput->setPlaceholderText("Number of sets");
    repsInput = new QLineEdit(this);
    repsInput->setPlaceholderText("Number of reps");

    // cardio specific inputs
    distanceInput = new QLineEdit(this);
    distanceInput->setPlaceholderText("Distance (km)");

    // submit and feedback
    submitButton = new QPushButton("Log Workout", this);
    feedbackLabel = new QLabel(this);

    // put everything into layout
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

    // connect signals
    connect(workoutTypeDropdown, &QComboBox::currentTextChanged,
            this, &WorkoutGUI::handleWorkoutTypeChange);
    connect(submitButton, &QPushButton::clicked, [this]() {
        // logging either normal or cardio workout
        if (workoutTypeDropdown->currentText() == "Normal Workout") {
            logNormalWorkout();
        } else {
            logCardioWorkout();
        }
    });

    handleWorkoutTypeChange(workoutTypeDropdown->currentText());
}

// slot hanfles change in workout type
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

// validate input before logging workout
// if nto all fields are filled dont let the user proceed
bool WorkoutGUI::validateInputs() {
    if (durationInput->text().isEmpty() || caloriesInput->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in duration and calories burned.");
        return false;
    }
    return true;
}

// logging normal workout
void WorkoutGUI::logNormalWorkout() {
    if (!validateInputs() || setsInput->text().isEmpty() || repsInput->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    // uses map o collect workout data
    QMap<QString, QString> workoutData;
    workoutData["date"] = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    workoutData["duration"] = durationInput->text();
    workoutData["calories"] = caloriesInput->text();
    workoutData["sets"] = setsInput->text();
    workoutData["reps"] = repsInput->text();

    // emit signal w data and close dialog
    emit workoutLogged("normal", workoutData); // broadcasts signal to finish logging
    accept(); // closes form and completes logging
}

// logging cardio
void WorkoutGUI::logCardioWorkout() {
    if (!validateInputs() || distanceInput->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }


    // map to collect, emit, and close
    QMap<QString, QString> workoutData;
    workoutData["date"] = QDateTime::currentDateTime().toString("yyyy-MM-dd");
    workoutData["duration"] = durationInput->text();
    workoutData["calories"] = caloriesInput->text();
    workoutData["distance"] = distanceInput->text();

    emit workoutLogged("cardio", workoutData);
    accept();
}

// destructor
WorkoutGUI::~WorkoutGUI() = default;