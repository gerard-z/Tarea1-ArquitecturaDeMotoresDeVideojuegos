#include "point.h"

// Permite la suma entre dos puntos, sumando coordenada a coordenada y obteniendo un nuevo punto.
Point& operator+(const Point &point1, const Point &point2) {
    Point* point = new Point{point1.x + point2.x, point1.y + point2.y};
    return *point;
};

// Permite obtener la impresión del punto como par ordenado.
std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "(" << point.x << ", " << point.y << ")";
    return out;
};