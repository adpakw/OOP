#include <iostream>

#include "Kitchen_cabinet.h"

void Kitchen_cabinet::set_material(std::string value) {
    material = value;
}

void Kitchen_cabinet::set_position(const Geometry &value) {
    position = value;
}

void Kitchen_cabinet::set_size(const Geometry &value) {
    if(value.get_x()>0 && value.get_y()>0 && value.get_z()>0){
        size = Geometry(value);
    }
    else{
        std::cout<<"Wrong size";
    }
}


const Geometry Kitchen_cabinet::get_position() const {
    return position;
}

const Geometry Kitchen_cabinet::get_size() const {
    return size;
}

const std::string Kitchen_cabinet::get_material() const {
    return material;
}



Kitchen_cabinet::Kitchen_cabinet(){
    material = "wooden";
    position = Geometry();
    size = Geometry(1, 1, 1);
}

Kitchen_cabinet::Kitchen_cabinet(std::string material, const Geometry &position, const Geometry &size) {
    this->material = material;
    this->position = Geometry(position);
    this->size = Geometry(size);
}

Kitchen_cabinet::Kitchen_cabinet(const Kitchen_cabinet &kitchen_cabinet) {
    this->material = kitchen_cabinet.material;
    this->position = Geometry(kitchen_cabinet.position);
    this->size = Geometry(kitchen_cabinet.size);
}

void Kitchen_cabinet::print_() {
    std::cout<<"Material:"<<get_material()<<std::endl;
    std::cout<<"Position:";
    get_position().print_();
    std::cout<<std::endl;
    std::cout<<"Size:";
    get_size().print_();
    std::cout<<std::endl;
}

bool Kitchen_cabinet::isCollision(const Kitchen_cabinet &kitchen_cabinet) {
    return (((abs(get_position().get_x() - kitchen_cabinet.position.get_x()) <
                get_size().get_x() + kitchen_cabinet.size.get_x()) &&
            (abs(get_position().get_y() - kitchen_cabinet.position.get_y()) <
                get_size().get_y() + kitchen_cabinet.size.get_y()) &&
            (abs(get_position().get_z() - kitchen_cabinet.position.get_z()) <
                get_size().get_z() + kitchen_cabinet.size.get_z())) ||
                    (
                    (get_position().distance(kitchen_cabinet.get_position())<2 &&
                        get_material()!=kitchen_cabinet.get_material()) ||
                    (get_material()==kitchen_cabinet.get_material())
                    ));
}

bool Kitchen_cabinet::is_in_air(){
    return get_position().get_z() != 0;
}