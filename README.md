# AI Powered Fitness Tracker

### Project by Adil Siddiqui

## Table of Contents
- [Project Description](#project-description)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Installation](#installation)
- [Usage](#usage)
- [Class Design](#class-design)
- [Contributing](#contributing)

---

## Project Description

The **AI Powered Fitness Tracker** is a C++ application aimed at helping people get started with fitness, refine their routines, and visualize their progress. With an easy-to-use GUI, users can log their workouts, track progress, and receive personalized workout suggestions. The app integrates external health APIs to tailor recommendations, providing an intuitive and tailored fitness experience.

---

## Features

- **User Profiles**: Users can create profiles, input health data, and set fitness goals.
- **Workout Logging**: Users can log details of both strength and cardio workouts.
- **Progress Tracking**: Visualize workout progress with charts and statistics.
- **AI-Powered Suggestions**: Personalized workout recommendations based on user data.
- **User-Friendly Interface**: An intuitive GUI makes navigation and tracking seamless.

---

## Technologies Used

- **Programming Language**: C++
- **GUI Framework**: Qt
- **Database**: Memory

---

## Installation

### Prerequisites
1. **CLion IDE** (or any C++ IDE of choice)
2. **Qt Framework** - for GUI elements
3. **MySQL** - for database setup

### Steps
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/ad-vil/AI_Fitness_Tracker.git
   cd AI_Fitness_Tracker
2. **Install Dependencies**:
   Follow the setup instructions for installing and linking **Qt**.

3. **Build the Project**:
   Open the project in CLion and build it using the IDE’s build system.

---

## Usage

1. **Start the Application**:
   Run the compiled executable from the command line or from within CLion.
   
2. **Create a Profile**:
   Input your personal details such as weight, height, and fitness goals.

3. **Log Workouts**:
   Add details of your workouts, specifying type, duration, and any other details.

4. **View Progress**:
   Track your progress with visualized charts showing performance and improvement over time.

5. **AI Recommendations**:
   Receive personalized workout suggestions based on your goals and history.

---

## Class Design

The project follows object-oriented principles to keep the code organized, maintainable, and scalable.

### Classes

1. **UserProfile**:
   - Manages user information such as age, weight, height, and fitness goals.
   - Contains methods to update and display user profile data.

2. **Workout** (Base Class):
   - A base class for logging workout details, inherited by specialized workout types.

3. **NormalWorkout** and **CardioWorkout** (Derived Classes):
   - `NormalWorkout`: Handles strength workouts with details like sets and reps.
   - `CardioWorkout`: Handles cardio workouts with details like distance.

4. **AIEngine**:
   - Uses user profile data to generate personalized workout suggestions.

5. **APIClient**:
   - Handles communication with external APIs to fetch health data, adding value to the AIEngine’s recommendations.

6. **GUI (Various classes)**:
   - Manages the graphical user interface, allowing users to interact with and navigate the application.

---

## Contributing

Contributions are welcome! Please follow these steps:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -m "Added new feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

---
