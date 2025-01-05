#include "UserProfileGUI.h"
#include <QGroupBox>
#include <QFormLayout>

// ctor
UserProfileGUI::UserProfileGUI(QWidget* parent) : QWidget(parent), userProfile(nullptr) {
    mainLayout = new QVBoxLayout(this);

    // form for user info
    auto* formLayout = new QFormLayout();

    nameInput = new QLineEdit(this);
    nameInput->setPlaceholderText("Your name");

    ageInput = new QSpinBox(this);
    ageInput->setRange(10, 100);
    ageInput->setValue(25); // default value

    weightInput = new QDoubleSpinBox(this);
    weightInput->setRange(40, 200);
    weightInput->setValue(70);
    weightInput->setSuffix(" kg");
    weightInput->setDecimals(1);

    heightInput = new QDoubleSpinBox(this);
    heightInput->setRange(120, 220);
    heightInput->setValue(170);
    heightInput->setSuffix(" cm");
    heightInput->setDecimals(1);

    goalInput = new QComboBox(this);
    goalInput->addItems({"weight loss", "muscle gain", "endurance", "strength"});

    genderInput = new QComboBox(this);
    genderInput->addItems({"male", "female", "other"});

    // insert everything into the form
    formLayout->addRow("Name:", nameInput);
    formLayout->addRow("Age:", ageInput);
    formLayout->addRow("Weight:", weightInput);
    formLayout->addRow("Height:", heightInput);
    formLayout->addRow("Goal:", goalInput);
    formLayout->addRow("Gender:", genderInput);

    auto* groupBox = new QGroupBox("Profile Info", this);
    groupBox->setLayout(formLayout);
    mainLayout->addWidget(groupBox);

    // display area for profile
    profileDisplay = new QLabel(this);
    profileDisplay->setStyleSheet(
        "QLabel { background: #2b2b2b; color: white; padding: 10px; "
        "border-radius: 5px; margin: 10px; }"
    );
    profileDisplay->setMinimumHeight(150);
    mainLayout->addWidget(profileDisplay);

    // update button
    updateProfileButton = new QPushButton("Update Profile", this);
    updateProfileButton->setStyleSheet(
        "QPushButton { background: #4CAF50; color: white; padding: 8px; "
        "border-radius: 4px; }"
        "QPushButton:hover { background: #45a049; }"
    );
    mainLayout->addWidget(updateProfileButton);

    setLayout(mainLayout);

    connect(updateProfileButton, &QPushButton::clicked,
            this, &UserProfileGUI::handleUpdateProfile);
}

void UserProfileGUI::handleUpdateProfile() {
    if (!userProfile) {
        userProfile = new UserProfile();
    }

    // update everything
    userProfile->setName(nameInput->text().toStdString());
    userProfile->setAge(ageInput->value());
    userProfile->setWeight(weightInput->value());
    userProfile->setHeight(heightInput->value());
    userProfile->setGoal(goalInput->currentText().toStdString());
    userProfile->setGender(genderInput->currentText().toStdString());

    refreshProfileDisplay();
    emit profileUpdated();
}

// refreshes user profile info
void UserProfileGUI::refreshProfileDisplay() {
    if (!userProfile) return;
    QString profileInfo = QString::fromStdString(userProfile->getProfileInfo());
    profileDisplay->setText(profileInfo);
}