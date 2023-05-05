//
// Created by orhan on 5/3/2023.
//

#include "LineSegment.h"

LineSegment::LineSegment(Point start, Point end) : start(start), end(end) {}


std::array<double, 4> LineSegment::getSegmentCoordinates(const LineSegment &segment) {
    return {segment.start.x, segment.start.y, segment.end.x, segment.end.y};
}

bool LineSegment::isWithinRange(double coordinate, double first, double second) {
    return (coordinate >= first && coordinate <= second) || (coordinate >= second && coordinate <= first);
}

double LineSegment::calculateDenominator(double x1, double y1, double x2, double y2, double x3, double y3, double x4,
                                         double y4) {
    return (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
}

bool LineSegment::doLineSegmentsIntersect(const LineSegment &segmentFirst, const LineSegment &segmentSecond) {
    auto [x1, y1, x2, y2] = getSegmentCoordinates(segmentFirst);
    auto [x3, y3, x4, y4] = getSegmentCoordinates(segmentSecond);

    double denominator = calculateDenominator(x1, y1, x2, y2, x3, y3, x4, y4);

    if (denominator == 0.0) return false;

    double intersectionX = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / denominator;
    double intersectionY = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / denominator;

    bool isXWithinRangeOfSegments = isWithinRange(intersectionX, x1, x2) && isWithinRange(intersectionX, x3, x4);
    bool isYWithinRangeOfSegments = isWithinRange(intersectionY, y1, y2) && isWithinRange(intersectionY, y3, y4);

    return isXWithinRangeOfSegments && isYWithinRangeOfSegments;
}