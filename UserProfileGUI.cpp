//
// Created by adil_ on 12/23/2024.
//

// UserProfileGUI.cpp

#include "UserProfileGUI.h"
#include <QGroupBox>
#include <QFormLayout>

UserProfileGUI::UserProfileGUI(QWidget* parent) : QWidget(parent), userProfile(nullptr) {
    // Create main layout
    mainLayout = new QVBoxLayout(this);

    // Create form layout for inputs
    auto* formLayout = new QFormLayout();

    // Create input widgets
    nameInput = new QLineEdit(this);
    nameInput->setPlaceholderText("Enter your name");

    ageInput = new QSpinBox(this);
    ageInput->setRange(13, 100);
    ageInput->setValue(25);

    weightInput = new QDoubleSpinBox(this);
    weightInput->setRange(40, 200);
    weightInput->setValue(70);
    weightInput->setSuffix(" kg");

    heightInput = new QDoubleSpinBox(this);
    heightInput->setRange(120, 220);
    heightInput->setValue(170);
    heightInput->setSuffix(" cm");

    goalInput = new QComboBox(this);
    goalInput->addItems({"weight loss", "muscle gain", "endurance", "strength"});

    genderInput = new QComboBox(this);
    genderInput->addItems({"male", "female", "other"});

    // Add widgets to form layout
    formLayout->addRow("Name:", nameInput);
    formLayout->addRow("Age:", ageInput);
    formLayout->addRow("Weight:", weightInput);
    formLayout->addRow("Height:", heightInput);
    formLayout->addRow("Goal:", goalInput);
    formLayout->addRow("Gender:", genderInput);

    // Create group box for form
    auto* groupBox = new QGroupBox("Profile Information", this);
    groupBox->setLayout(formLayout);
    mainLayout->addWidget(groupBox);

    // Create profile display
    profileDisplay = new QLabel(this);
    profileDisplay->setStyleSheet(
        "QLabel { background-color: #2b2b2b; color: white; padding: 10px; "
        "border-radius: 5px; margin: 10px; }"
    );
    mainLayout->addWidget(profileDisplay);

    // Create update button
    updateProfileButton = new QPushButton("Update Profile", this);
    updateProfileButton->setStyleSheet(
        "QPushButton { background-color: #4CAF50; color: white; padding: 8px; "
        "border-radius: 4px; }"
        "QPushButton:hover { background-color: #45a049; }"
    );
    mainLayout->addWidget(updateProfileButton);

    // Set main layout
    setLayout(mainLayout);

    // Connect signals
    connect(updateProfileButton, &QPushButton::clicked, this, &UserProfileGUI::handleUpdateProfile);
}

void UserProfileGUI::handleUpdateProfile() {
    // Create or update user profile
    if (!userProfile) {
        userProfile = new UserProfile(
            nameInput->text().toStdString(),
            ageInput->value(),
            weightInput->value(),
            heightInput->value(),
            goalInput->currentText().toStdString(),
            genderInput->currentText().toStdString()
        );
    } else {
        userProfile->setName(nameInput->text().toStdString());
        userProfile->setAge(ageInput->value());
        userProfile->updateProfile(weightInput->value(), heightInput->value());
    }

    refreshProfileDisplay();
}

void UserProfileGUI::refreshProfileDisplay() {
    if (!userProfile) return;

    QString profileInfo = QString::fromStdString(userProfile->getProfileInfo());
    profileDisplay->setText(profileInfo);
}