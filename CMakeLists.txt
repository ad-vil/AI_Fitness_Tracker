cmake_minimum_required(VERSION 3.15)
project(FitnessTracker)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Path to Qt installation
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.1/mingw_64/lib/cmake")

# Find Qt modules
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Enable Qt's MOC (Meta-Object Compiler)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


# Define all source files
set(SOURCES
        main.cpp
        FitnessTrackerGUI.cpp
        UserProfile.cpp
        Workout.cpp
        CardioWorkout.cpp
        NormalWorkout.cpp
        WorkoutGUI.cpp
        UserProfileGUI.cpp
        AIEngine.cpp
        AIRecommendationsGUI.cpp
        WorkoutHistoryGUI.cpp
        APIClient.cpp
)

# Create the executable
add_executable(FitnessTracker ${SOURCES})

# Link libraries
target_link_libraries(FitnessTracker PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)

# Add vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "[path_to_vcpkg]/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")