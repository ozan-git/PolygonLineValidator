//
// Created by orhan on 5/2/2023.
//

#include "Point.h"
#include <cmath>
#include <sstream>

Point::Point(double x, double y) : x(x), y(y) {}

Point Point::parsePoint(const std::string &pointStr) {
    std::stringstream ss(pointStr);
    std::string coordinate;
    getline(ss, coordinate, ',');
    double x = stod(coordinate);
    getline(ss, coordinate, ',');
    double y = stod(coordinate);
    return Point{x, y};
}

std::pair<Point, Point> Point::parsePointPair(const std::string &line) {
    std::stringstream ss(line);
    std::string point;
    getline(ss, point, ';');
    Point p1 = Point::parsePoint(point);
    getline(ss, point, ';');
    Point p2 = Point::parsePoint(point);
    return {p1, p2};
}

double distance(Point a, Point b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}