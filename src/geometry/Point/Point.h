//
// Created by orhan on 5/2/2023.
//

#ifndef POLYGONLINEVALIDATOR_POINT_H
#define POLYGONLINEVALIDATOR_POINT_H


// Point.h
#pragma once

#include <string>

class Point {
public:
    double x;
    double y;

    explicit Point(double x = 0, double y = 0);

    static Point parsePoint(const std::string &pointStr);

    static std::pair<Point, Point> parsePointPair(const std::string &line);

    friend double distance(Point a, Point b);
};


#endif //POLYGONLINEVALIDATOR_POINT_H
