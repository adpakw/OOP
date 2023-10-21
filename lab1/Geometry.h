#ifndef LAB1_GEOMETRY_H
#define LAB1_GEOMETRY_H

class Geometry{
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

    Geometry();
    Geometry(float x, float y, float z);
    Geometry(const Geometry &geometry);

    float distance(const Geometry &geometry) const;
    void print_() const;
};

#endif 