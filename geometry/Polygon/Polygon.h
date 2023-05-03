//
// Created by orhan on 5/2/2023.
//

#ifndef POLYGONLINEVALIDATOR_POLYGON_H
#define POLYGONLINEVALIDATOR_POLYGON_H


#include <vector>
#include "../Point/Point.h"

class Polygon {
public:
    std::vector<Point> vertices;

    static int calculateIntersections(Point point, const Polygon &polygon);

    static Polygon parsePolygon(const std::string& line);

private:

    static bool isPointOnEdge(Point point, Point edgeStart, Point edgeEnd);

    static Point getEdgeStart(Polygon polygon, int index);

    static Point getEdgeEnd(Polygon polygon, int index);

    static double calculateX(Point edgeStart, Point edgeEnd, Point point);

};


#endif //POLYGONLINEVALIDATOR_POLYGON_H
