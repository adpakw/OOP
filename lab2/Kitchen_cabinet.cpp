#include <iostream>

#include "Kitchen_cabinet.h"

const std::string Kitchen_cabinet::get_material() const {
    return material;
}

void Kitchen_cabinet::set_material(std::string value) {
    material = value;
}

Kitchen_cabinet::Kitchen_cabinet():Item(){
    material="wood";
}

Kitchen_cabinet::Kitchen_cabinet(const Geometry &position, const Geometry &size, std::string material):
Item(position, size) {
    this->material = material;
}

Kitchen_cabinet::Kitchen_cabinet(const Kitchen_cabinet &kitchen_cabinet): Item((Item&) kitchen_cabinet) {
    this->material = kitchen_cabinet.material;
}

std::string Kitchen_cabinet::type() const {
    return "Kitchen_cabinet";
}

void Kitchen_cabinet::show() {
    Item::show();
    std::cout<<"Material is "<<get_material()<<std::endl;
    std::cout<<std::endl;
}

bool Kitchen_cabinet::isCollision(const Item &item) {
    return (
            (Item::isCollision(item)) ||
                    ( item.type()=="Cabinet" &&(
                    (get_position().distance(((Kitchen_cabinet &)item).get_position())<2 &&
                        get_material()!=((Kitchen_cabinet &)item).get_material()) ||
                    (get_material()==((Kitchen_cabinet &)item).get_material())
                    ))
            );
            
}

bool Kitchen_cabinet::is_in_air(){
    return get_position().get_z() != 0;
}