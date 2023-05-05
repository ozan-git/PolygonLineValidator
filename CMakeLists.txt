cmake_minimum_required(VERSION 3.25)
project(PolygonLineValidator)

set(CMAKE_CXX_STANDARD 17)

add_executable(PolygonLineValidator src/execute/main.cpp src/geometry/Point/Point.cpp src/geometry/Point/Point.h src/geometry/Point/Point.h src/geometry/Polygon/Polygon.cpp src/geometry/Polygon/Polygon.h src/geometry/LineSegment/LineSegment.cpp src/geometry/LineSegment/LineSegment.h src/io/Operations.cpp src/io/Operations.h)
