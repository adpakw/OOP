#include "Vector.h"
#include <cmath>
#include <iostream>

void Vector::set_x(int value) { x = value; }

void Vector::set_y(int value) { y = value; }

void Vector::set_z(int value) { z = value; }

const float Vector::get_x() const { return x; }

const float Vector::get_y() const { return y; }

const float Vector::get_z() const { return z; }

Vector::Vector() {
  x = 0;
  y = 0;
  z = 0;
}

Vector::Vector(float x, float y, float z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

Vector::Vector(const Vector &vector) {
  this->x = vector.x;
  this->y = vector.y;
  this->z = vector.z;
}

void Vector::print_() const {
  std::cout << "x = " << get_x() << "\ny = " << get_y() << "\nz = " << get_z();
}

float Vector::distance(const Vector &vector) const {
  return sqrt(pow(get_x() - vector.get_x(), 2) +
              pow(get_y() - vector.get_y(), 2) +
              pow(get_z() - vector.get_z(), 2));
}