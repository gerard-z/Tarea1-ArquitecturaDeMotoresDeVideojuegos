#pragma once
#include <iostream>

/*
Struct Point;
Estructura que almacena las coordenadas x y, para utilizarla en la grilla.
*/
struct Point {
    float x;
    float y;
};

Point& operator+(const Point &point1, const Point &point2);

std::ostream& operator<<(std::ostream& out, const Point& point);