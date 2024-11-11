cmake_minimum_required(VERSION 3.29)
project(AI_Fitness_Tracker)

set(CMAKE_CXX_STANDARD 20)

add_executable(AIEngine AIEngine.cpp)
add_executable(APIClient APIClient.cpp)
add_executable(UserProfile UserProfile.cpp)
add_executable(Workout Workout.cpp)
add_executable(GUI GUI.cpp)