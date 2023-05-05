//
// Created by orhan on 5/3/2023.
//

#ifndef POLYGONLINEVALIDATOR_OPERATIONS_H
#define POLYGONLINEVALIDATOR_OPERATIONS_H

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../geometry/Point/Point.h"
#include "../geometry/LineSegment/LineSegment.h"
#include "../geometry/Polygon/Polygon.h"

namespace io {
    // Test file paths
    // const std::string INPUT_FILE_PATH = "C:/Users/orhan/CLionProjects/PolygonLineValidator/test/input/q1_input[514].txt";
    // const std::string OUTPUT_FILE_PATH = "C:/Users/orhan/CLionProjects/PolygonLineValidator/test/results/q1_first_output.txt";

    // Example file paths
     const std::string INPUT_FILE_PATH = "C:/Users/orhan/CLionProjects/PolygonLineValidator/test/input/q1_example_input[516].txt";
     const std::string OUTPUT_FILE_PATH = "C:/Users/orhan/CLionProjects/PolygonLineValidator/test/results/q1_example_output[512].txt";

    std::vector<std::pair<Point, Point>> readStartEndPoints(std::ifstream &inputFile);
    std::vector<LineSegment> readPassages(std::ifstream &inputFile);
    std::vector<Polygon> readPolygons(std::ifstream &inputFile);
    void processTestPoints(const std::vector<Polygon> &polygons,
                           const std::vector<LineSegment> &passages,
                           const std::vector<std::pair<Point, Point>> &testPoints, std::ofstream &outputFile);
    void processFiles();

    bool
    isPassable(Point start, Point end, const std::vector<Polygon> &polygons, const std::vector<LineSegment> &passages,
               double max_distance);

    bool isPointInsidePolygon(Point point, const Polygon &polygon);
}

#endif //POLYGONLINEVALIDATOR_OPERATIONS_H
