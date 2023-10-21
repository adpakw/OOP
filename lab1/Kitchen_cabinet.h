#ifndef LAB1_KITCHEN_CABINET_H
#define LAB1_KITCHEN_CABINET_H

#include "Geometry.h"
#include <string>

class Kitchen_cabinet{
private:
    std::string material;
    Geometry position;
    Geometry size;

public:
    void set_material(std::string value);
    void set_position(const Geometry &value);
    void set_size(const Geometry &value);

    const std::string get_material() const;
    const Geometry get_position() const;
    const Geometry get_size() const;

    Kitchen_cabinet();
    Kitchen_cabinet(std::string material, const Geometry &position, const Geometry &size);
    Kitchen_cabinet(const Kitchen_cabinet &kitchen_cabinet);

    void print_();
    bool isCollision(const Kitchen_cabinet &kitchen_cabinet);
    bool is_in_air();

};

#endif