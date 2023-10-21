#include <iostream>
#include "Item.h"

const Geometry Item::get_position() const {
    return position;
}

void Item::set_position(const Geometry &value) {
    position = value;
}

const Geometry Item::get_size() const {
    return size;
}

void Item::set_size(const Geometry &value) {
    if(value.get_x()>0 && value.get_y()>0 && value.get_z()>0){
        size =  Geometry(value);
    }
    else{
        std::cout<<"Inappropriate value";
    }
}

Item::Item() {
    position = Geometry();
    size = Geometry(1, 1, 1);
}

Item::Item(const Geometry &position, const Geometry &size) {
    this->position = Geometry(position);
    this->size = Geometry(size);
}

Item::Item(const Item &item) {
    this->position = Geometry(item.position);
    this->size = Geometry(item.size);
}


std::string Item::type() const {
    return "Item";
}

void Item::show() {
    std::cout<<type()<<std::endl;
    std::cout<<"Position is ";
    get_position().print_();
    std::cout<<std::endl;

    std::cout<<"Size is ";
    get_size().print_();
    std::cout<<std::endl;
}

bool Item::isCollision(const Item &item) {
    return
            ((abs(get_position().get_x() - item.position.get_x()) <
              get_size().get_x() + item.size.get_x()) &&
             (abs(get_position().get_y() - item.position.get_y()) <
              get_size().get_y() + item.size.get_y()) &&
             (abs(get_position().get_z() - item.position.get_z()) <
              get_size().get_z() + item.size.get_z()));
}