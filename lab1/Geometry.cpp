#include <iostream>
#include <cmath>
#include "Geometry.h"

void Geometry::set_x(int value) {
    x = value;
}

void Geometry::set_y(int value) {
    y = value;
}

void Geometry::set_z(int value) {
    z = value;
}


const float Geometry::get_x() const {
    return x;
}

const float Geometry::get_y() const {
    return y;
}

const float Geometry::get_z() const {
    return z;
}


Geometry::Geometry() {
    x = 0;
    y = 0;
    z = 0;
}

Geometry::Geometry(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Geometry::Geometry(const Geometry &geometry) {
    this->x = geometry.x;
    this->y = geometry.y;
    this->z = geometry.z;
}

void Geometry::print_() const {
    std::cout<<"x = "<<get_x()<<"\ny = "<<get_y()<<"\nz = "<<get_z();
}

float Geometry::distance(const Geometry &geometry) const {
    return sqrt(pow(get_x()-geometry.get_x(), 2)\
            + pow(get_y()-geometry.get_y(), 2)\
            + pow(get_z()-geometry.get_z(), 2));
}