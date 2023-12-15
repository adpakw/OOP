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

Kitchen_cabinet::Kitchen_cabinet(const Vector &position, const Vector &size, std::string material):
Item(position, size) {
    this->material = material;
}

Kitchen_cabinet::Kitchen_cabinet(const Kitchen_cabinet &kitchen_cabinet): Item((Item&) kitchen_cabinet) {
    this->material = kitchen_cabinet.material;
}

ItemType Kitchen_cabinet::type() const {
    return ItemType::TCabinet;
}

void Kitchen_cabinet::show() const{
    Item::show();
    std::cout<<"Material is "<<get_material()<<std::endl;
    std::cout<<std::endl;
}

bool Kitchen_cabinet::isCollision(const Item &item) const{
    return (
            (Item::isCollision(item)) ||
                    ( item.type()==ItemType::TCabinet &&(
                    (get_position().distance(((Kitchen_cabinet &)item).get_position())<2 &&
                        get_material()!=((Kitchen_cabinet &)item).get_material()) ||
                    (get_material()==((Kitchen_cabinet &)item).get_material())
                    ))
            );
            
}

