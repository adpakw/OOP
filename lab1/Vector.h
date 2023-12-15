#ifndef LAB1_VECTOR_H
#define LAB1_VECTOR_H

class Vector {
private:
  float x;
  float y;
  float z;

public:
  void set_x(int value);
  void set_y(int value);
  void set_z(int value);

  const float get_x() const;
  const float get_y() const;
  const float get_z() const;

  Vector();
  Vector(float x, float y, float z);
  Vector(const Vector &vector);

  float distance(const Vector &vector) const;
  void print_() const;
};

#endif