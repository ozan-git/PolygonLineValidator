//
// Created by orhan on 5/3/2023.
//

#include <algorithm>
#include "Operations.h"

bool io::isPointInsidePolygon(Point point, const Polygon &polygon) {
    int intersections = Polygon::calculateIntersections(point, polygon);
    return intersections % 2 == 1;
}

bool io::isPassable(Point start, Point end, const std::vector<Polygon> &polygons,
                    const std::vector<LineSegment> &passages, double max_distance = 1.0) {
    if (distance(start, end) > max_distance)
        return false;

    for (const Polygon &polygon: polygons)
        if (isPointInsidePolygon(start, polygon) && isPointInsidePolygon(end, polygon))
            return true;

    return std::any_of(passages.begin(), passages.end(), [&](const LineSegment &passage) {
        return LineSegment::doLineSegmentsIntersect({start, end}, passage);
    });
}

std::vector<std::pair<Point, Point>> io::readStartEndPoints(std::ifstream &inputFile) {
    std::vector<std::pair<Point, Point>> startEndPoints;
    std::string line;
    while (getline(inputFile, line) && !line.empty())
        startEndPoints.push_back(Point::parsePointPair(line));
    return startEndPoints;
}

std::vector<LineSegment> io::readPassages(std::ifstream &inputFile) {
    std::vector<LineSegment> passages;
    for (auto pointPair: readStartEndPoints(inputFile))
        passages.emplace_back(pointPair.first, pointPair.second);
    return passages;
}

std::vector<Polygon> io::readPolygons(std::ifstream &inputFile) {
    std::vector<Polygon> polygons;
    std::string line;
    while (getline(inputFile, line) && !line.empty())
        polygons.push_back(Polygon::parsePolygon(line));
    return polygons;
}

void io::processTestPoints(const std::vector<Polygon> &polygons,
                           const std::vector<LineSegment> &passages,
                           const std::vector<std::pair<Point, Point>> &testPoints, std::ofstream &outputFile) {
    for (const auto &testPoint: testPoints) {
        outputFile << (isPassable(testPoint.first, testPoint.second, polygons, passages) ? "1" : "0")
                   << std::endl;
    }
}

void io::processFiles() {
    std::ifstream inputFile(io::INPUT_FILE_PATH);
    std::ofstream outputFile(io::OUTPUT_FILE_PATH);

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open input file." << std::endl;
        return;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Unable to open output file." << std::endl;
        return;
    }

    try {
        std::vector<Polygon> polygons = io::readPolygons(inputFile);
        std::vector<LineSegment> passages = io::readPassages(inputFile);
        std::vector<std::pair<Point, Point>> testPoints = io::readStartEndPoints(inputFile);

        io::processTestPoints(polygons, passages, testPoints, outputFile);
    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

