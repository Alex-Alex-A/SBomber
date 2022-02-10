
#include "Visitor.h"


void LogVisitor::log(Bomb* element) {
    std::pair<double, double> dir = element->GetDirection();
    MyTools::LoggerSingleton::getInstance().WriteToLog(
        "Bomb logging, speed: " + std::to_string(element->GetSpeed()) +
        ", direction: x=" +
        std::to_string(std::get<0>(dir)) +
        ", y=" +
        std::to_string(std::get<1>(dir)));
}

void LogVisitor::log(Plane* element) {
    std::pair<double, double> dir = element->GetDirection();
    MyTools::LoggerSingleton::getInstance().WriteToLog(
        "Plane logging, speed: " + std::to_string(element->GetSpeed()) +
        ", direction: x=" +
        std::to_string(std::get<0>(dir)) +
        ", y=" +
        std::to_string(std::get<1>(dir)));
}



