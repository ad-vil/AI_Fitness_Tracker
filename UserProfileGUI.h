//
// Created by adil_ on 12/23/2024.
//

#ifndef USERPROFILEGUI_H
#define USERPROFILEGUI_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include "UserProfile.h"

class UserProfileGUI : public QWidget {
    Q_OBJECT

signals:
    void profileUpdated(); // New signal

private:
    QLineEdit* nameInput;
    QSpinBox* ageInput;
    QDoubleSpinBox* weightInput;
    QDoubleSpinBox* heightInput;
    QComboBox* goalInput;
    QComboBox* genderInput;
    QLabel* profileDisplay;
    QPushButton* updateProfileButton;
    QVBoxLayout* mainLayout;

    UserProfile* userProfile;

public:
    explicit UserProfileGUI(QWidget* parent = nullptr);
    UserProfile* getCurrentProfile() const { return userProfile; }

    private slots:
        void handleUpdateProfile();
    void refreshProfileDisplay();
};

#endif