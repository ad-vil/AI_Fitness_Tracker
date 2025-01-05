#include <QApplication>
#include "FitnessTrackerGUI.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FitnessTrackerGUI tracker;
    tracker.setWindowTitle("AI Fitness Tracker");
    tracker.resize(400, 300);
    tracker.show();

    return app.exec();
}