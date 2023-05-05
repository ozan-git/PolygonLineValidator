//
// Created by orhan on 5/3/2023.
//

#ifndef POLYGONLINEVALIDATOR_LINESEGMENT_H
#define POLYGONLINEVALIDATOR_LINESEGMENT_H


#include <array>
#include "../Point/Point.h"

class LineSegment {
public:

    Point start;
    Point end;

    LineSegment(Point start, Point end);
    static bool doLineSegmentsIntersect(const LineSegment &segmentFirst, const LineSegment &segmentSecond);

private:
    static std::array<double, 4> getSegmentCoordinates(const LineSegment &segment);
    static bool isWithinRange(double coordinate, double first, double second);
    static double calculateDenominator(double x1, double y1, double x2, double y2, double x3, double y3,
                                       double x4, double y4);

};

#endif //POLYGONLINEVALIDATOR_LINESEGMENT_H
