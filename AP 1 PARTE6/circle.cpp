#include <iostream>
#include "Circle.h"
#include "Point.h"

Circle::Circle() : m_center(Point(0, 0)), m_radius(1.0) {}

Circle::Circle(Point& p, double radius) : m_center(p), m_radius(radius) {}

void Circle::setRadius(double radius) {
    m_radius = radius;
}

void Circle::setCenter(Point& p) {
    m_center = p;
}

Point& Circle::getCenter() {
    return m_center;
}

double Circle::getRadius() {
    return m_radius;
}

double Circle::area() {
    return 3.14159 * m_radius * m_radius;
}

bool Circle::contains(Point& p) {
    double distance = m_center.distance(p);
    return distance <= m_radius;
}
