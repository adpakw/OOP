#ifndef LAB2_KITCHEN_CABINET_H
#define LAB2_KITCHEN_CABINET_H

#include "Vector.h"
#include "Item.h"
#include <string>

class Kitchen_cabinet final : public Item{
private:
    std::string material;
public:
    const std::string get_material() const;
    void set_material(std::string value);

    Kitchen_cabinet();
    Kitchen_cabinet(const Vector &position, const Vector &size, std::string material);
    Kitchen_cabinet(const Kitchen_cabinet &kitchen_cabinet);

    ItemType type() const override;
    void show() const override;

    bool isCollision(const Item &item) const override;
};

#endif