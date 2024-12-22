#cmake_minimum_required(VERSION 3.29)
#project(AI_Fitness_Tracker)
#
#set(CMAKE_CXX_STANDARD 20)
#
#add_executable(Main main.cpp UserProfile.cpp Workout.cpp CardioWorkout.cpp NormalWorkout.cpp)


cmake_minimum_required(VERSION 3.15)
project(FitnessTracker)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Path to Qt installation
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.1/mingw_64/lib/cmake")

# Find Qt modules
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Add sources and headers
set(SOURCES
        main.cpp
        FitnessTrackerGUI.cpp
        UserProfile.cpp
        CardioWorkout.cpp
)

set(HEADERS
        FitnessTrackerGUI.h
        UserProfile.h
        CardioWorkout.h
)

# Enable Qt's MOC (Meta-Object Compiler)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Create the executable
add_executable(FitnessTracker main.cpp UserProfile.cpp Workout.cpp CardioWorkout.cpp NormalWorkout.cpp FitnessTrackerGUI.cpp WorkoutGUI.cpp)

# Link Qt libraries
target_link_libraries(FitnessTracker Qt6::Core Qt6::Gui Qt6::Widgets)
