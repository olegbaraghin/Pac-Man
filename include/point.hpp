/**
 * @file point.hpp
 * @brief Structură auxiliară pentru coordonate 2D.
 * @author Student
 * @date 2025
 */

#pragma once
#include <iostream>

/**
 * @struct Point
 * @brief Reprezintă o pereche de coordonate (x, y).
 */
struct Point {
    int x;
    int y;

   /**
    * @brief Constructor implicit și parametrizat.
    * @param _x Coordonata X (default 0).
    * @param _y Coordonata Y (default 0).
    */
   Point(int _x = 0, int _y = 0);
   
   Point(const Point& other);
   Point& operator=(const Point& other);
   bool operator==(const Point& other) const;
};

std::istream& operator>>(std::istream& in, Point& point);
std::ostream& operator<<(std::ostream& out, const Point& point);
