cmake_minimum_required(VERSION 3.25)
project(PolygonLineValidator)

set(CMAKE_CXX_STANDARD 17)

add_executable(PolygonLineValidator Main/main.cpp geometry/Point/Point.cpp geometry/Point/Point.h geometry/Point/Point.h geometry/Polygon/Polygon.cpp geometry/Polygon/Polygon.h geometry/LineSegment/LineSegment.cpp geometry/LineSegment/LineSegment.h io/Operations.cpp io/Operations.h)
