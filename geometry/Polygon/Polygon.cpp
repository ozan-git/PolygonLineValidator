//
// Created by orhan on 5/2/2023.
//

#include <sstream>
#include "Polygon.h"

bool Polygon::isPointOnEdge(Point point, Point edgeStart, Point edgeEnd) {
    return point.y == edgeStart.y && point.y == edgeEnd.y && point.x >= std::min(edgeStart.x, edgeEnd.x) &&
           point.x <= std::max(edgeStart.x, edgeEnd.x);
}

Point Polygon::getEdgeStart(Polygon polygon, int index) {
    return polygon.vertices[index];
}

Point Polygon::getEdgeEnd(Polygon polygon, int index) {
    return polygon.vertices[(index + 1) % polygon.vertices.size()];
}

double Polygon::calculateX(Point edgeStart, Point edgeEnd, Point point) {
    return edgeStart.x + (point.y - edgeStart.y) * (edgeEnd.x - edgeStart.x) / (edgeEnd.y - edgeStart.y);
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
    std::string point;

    while (getline(ss, point, ';')) {
        Point p = Point::parsePoint(point);
        polygon.vertices.push_back(p);
    }

    return polygon;
}


