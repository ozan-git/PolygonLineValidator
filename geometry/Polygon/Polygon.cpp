//
// Created by orhan on 5/2/2023.
//

#include <sstream>
#include "Polygon.h"

bool Polygon::isPointOnEdge(Point point, Point edgeStart, Point edgeEnd) {
    double min_x = std::min(edgeStart.x, edgeEnd.x);
    double max_x = std::max(edgeStart.x, edgeEnd.x);

    return point.y == edgeStart.y && point.y == edgeEnd.y &&
           point.x >= min_x && point.x <= max_x;
}

Point Polygon::getEdgeStart(Polygon polygon, int index) {
    return polygon.vertices[index];
}

Point Polygon::getEdgeEnd(Polygon polygon, int index) {
    return polygon.vertices[(index + 1) % polygon.vertices.size()];
}

double Polygon::calculateX(Point edgeStart, Point edgeEnd, Point point) {
    double delta_y = edgeEnd.y - edgeStart.y;
    if (delta_y == 0)
        return point.x;

    double delta_x = edgeEnd.x - edgeStart.x;
    double slope = delta_x / delta_y;
    return edgeStart.x + slope * (point.y - edgeStart.y);
}

int Polygon::calculateIntersections(Point point, const Polygon &polygon) {
    int intersections = 0;
    for (int i = 0; i < polygon.vertices.size(); i++) {
        Point edgeStart = getEdgeStart(polygon, i);
        Point edgeEnd = getEdgeEnd(polygon, i);
        if (edgeStart.y > edgeEnd.y) {
            std::swap(edgeStart, edgeEnd);
        }
        if (point.y >= edgeStart.y && point.y < edgeEnd.y) {
            double x = calculateX(edgeStart, edgeEnd, point);
            if (x > point.x) {
                intersections++;
            } else if (isPointOnEdge(point, edgeStart, edgeEnd)) {
                return true;
            }
        }
    }
    return intersections;
}

Polygon Polygon::parsePolygon(const std::string &line) {
    Polygon polygon;
    std::stringstream ss(line);
    std::string pointString;

    while (getline(ss, pointString, ';'))
        polygon.vertices.emplace_back(Point::parsePoint(pointString));

    return polygon;
}