cmake_minimum_required(VERSION 3.29)
project(AI_Fitness_Tracker)

set(CMAKE_CXX_STANDARD 20)


add_executable(Main main.cpp UserProfile.cpp Workout.cpp CardioWorkout.cpp NormalWorkout.cpp)
