#ifndef LAB2_KITCHEN_CABINET_H
#define LAB2_KITCHEN_CABINET_H

#include "Geometry.h"
#include "Item.h"
#include <string>

class Kitchen_cabinet final : public Item{
private:
    std::string material;
public:
    const std::string get_material() const;
    void set_material(std::string value);

    Kitchen_cabinet();
    Kitchen_cabinet(const Geometry &position, const Geometry &size, std::string material);
    Kitchen_cabinet(const Kitchen_cabinet &kitchen_cabinet);

    std::string type() const override;
    void show() override;

    bool isCollision(const Item &item);
    bool is_in_air();
};

#endif